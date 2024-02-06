function get_star_count()
    local courseMax = 25
    local courseMin = 1
    return save_file_get_total_star_count(get_current_save_file_num() - 1, courseMin - 1, courseMax - 1)
end

local repack = function(value, pack_fmt, unpack_fmt)
    return string.unpack(unpack_fmt, string.pack(pack_fmt, value))
end

---@param m MarioState
---@return boolean
local function is_bubbled(m)
    return m.action == ACT_BUBBLED
end


E_MODEL_RED_WARP_PIPE = smlua_model_util_get_id("warp_pipe_red_geo")

-- custom cage for boss

COL_CAGE = smlua_collision_util_get("eight_star_cage_collision")
E_MODEL_8_STAR_CAGE = smlua_model_util_get_id("eight_star_cage_geo")

---@param o Object
function eight_star_cage_init(o)
    o.oIntangibleTimer = 0
    o.header.gfx.skipInViewCheck = true
    o.collisionData = COL_CAGE
end

function eight_star_cage_loop(o)
    load_object_collision_model()
    if get_star_count() >= 8 then
        obj_mark_for_deletion(o)
    end
end

bhv8StarCage = hook_behavior(nil, OBJ_LIST_SURFACE, true, eight_star_cage_init, eight_star_cage_loop)

-- big mushrooms

E_MODEL_STRAIGHT_MUSHROOM = smlua_model_util_get_id("straight_mushroom_geo")
COL_STRAIGHT_MUSHROOM = smlua_collision_util_get("straight_mushroom_collision")

---@param obj Object
function bhv_mushroom_init(obj)
    obj.collisionData = COL_STRAIGHT_MUSHROOM
    obj.oCollisionDistance = 1000
    obj.header.gfx.skipInViewCheck = true
end

--taken from MOPs

---@param obj Object
function bhv_mushroom_loop(obj)
    load_object_collision_model()
    local m = gMarioStates[0]
    local y_spd = 64

    if cur_obj_is_mario_on_platform() == 1 and not is_bubbled(m) then
        m.peakHeight = m.pos.y
        m.faceAngle.y = m.intendedYaw
        --this is awful -- It really is -Sunk
        -- Jump. If A is pressed during the jump, increase y_spd.
        if m.controller.buttonPressed & A_BUTTON ~= 0 then
            y_spd = y_spd + 12 -- I feel like this should increase with oBehParams2ndByte
            spawn_mist_particles()
        end
        set_mario_action(m, ACT_DOUBLE_JUMP, 0)

        -- Calculates y speed
        local intermediate_y_spd = repack(y_spd, "f", "I")
        intermediate_y_spd = intermediate_y_spd + (obj.oBehParams2ndByte << 16)
        y_spd = repack(intermediate_y_spd, "I", "f")
        m.vel.y = y_spd
    end
end

id_bhvStraightMushroom = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_mushroom_init, bhv_mushroom_loop,
    "id_bhvStraightMushroom")

-- another one :D

E_MODEL_CURVED_MUSHROOM = smlua_model_util_get_id("curved_mushroom_geo")
COL_CURVED_MUSHROOM = smlua_collision_util_get("curved_mushroom_collision")

---@param obj Object
function bhv_mushroom_curved_init(obj)
    obj.collisionData = COL_CURVED_MUSHROOM
    obj.oCollisionDistance = 2500
    obj.header.gfx.skipInViewCheck = true
end

id_bhvCurvedMushroom = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_mushroom_curved_init, bhv_mushroom_loop,
    'id_bhvCurvedMushroom')

-- seesaw platform but badass

E_MODEL_GREEN_SEESAW = smlua_model_util_get_id("green_seesaw_geo")
COL_GREEN_SEESAW = smlua_collision_util_get("green_seesaw_collision")


define_custom_obj_fields({
    oEndPointX = "f32",
    oEndPointZ = "f32",
    oDoneEndPoint = "s32"
})

---@param obj Object
function seesaw_green_init(obj)
    obj.oDoneEndPoint = 0
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL
    obj.collisionData = COL_GREEN_SEESAW
    obj.oCollisionDistance = 2500
    obj.header.gfx.skipInViewCheck = true
    obj.oHomeX = obj.oPosX
    obj.oHomeY = obj.oPosY
    obj.oHomeZ = obj.oPosZ
    network_init_object(obj, true, {"oEndPointX", "oEndPointZ", "oDoneEndPoint"})

    -- more things
    o = obj
    if o.oHomeY == 1620 then
        o.oFaceAnglePitch = 2000
        obj.oFaceAngleYaw = obj.oFaceAngleYaw + 16384
        obj.oMoveAngleYaw = obj.oMoveAngleYaw + 16384
        o.oEndPointX = 1494
    end

    if o.oHomeX == 3341 then
        o.oFaceAnglePitch = 0
        o.oEndPointZ = -12855
    end

    if o.oHomeX == 4401 then
        o.oFaceAnglePitch = 0
        o.oEndPointZ = -11426
    end

    if o.oHomeX == 6675 then
        o.oFaceAnglePitch = 0
       o.oEndPointZ = -9309
    end

    if o.oHomeX == 3497 then
        obj.oFaceAngleYaw = obj.oFaceAngleYaw + 16384
        obj.oMoveAngleYaw = obj.oMoveAngleYaw + 16384
        o.oEndPointX = 5437
    end

    if o.oHomeX == 5874 then
        obj.oFaceAngleYaw = obj.oFaceAngleYaw - 16384
        obj.oMoveAngleYaw = obj.oMoveAngleYaw - 16384
        o.oEndPointX = -1546
        o.oFaceAnglePitch = -2000
    end
end

---@param o Object
function seesaw_green_loop(o)
    load_object_collision_model()
    ---@type MarioState
    local m = gMarioStates[0]
   --djui_chat_message_create(tostring(m.floor.object.oPosX))

    if m.controller.buttonDown & U_JPAD == 0 then
        o.oForwardVel = 0
    end

    if cur_obj_is_mario_on_platform() == 0 and m.controller.buttonDown & U_JPAD ~= 0 then
        o.oForwardVel = 0
    end

    if cur_obj_is_mario_on_platform() ~= 0 and o.oHomeY == 1620 and not is_bubbled(m) and o.oDoneEndPoint == 0 then
        if m.controller.buttonDown & U_JPAD ~= 0 then
            o.oForwardVel = 20
            o.oPosY = o.oPosY - 3.9
        else
            o.oForwardVel = 0
        end

    end

    if cur_obj_is_mario_on_platform() ~= 0 and (o.oHomeX == 3341 or o.oHomeX == 4401 or o.oHomeX == 6675 or o.oHomeX == 3497) and not is_bubbled(m) and o.oDoneEndPoint == 0 then
        if m.controller.buttonDown & U_JPAD ~= 0 then
            o.oForwardVel = 20
        else
            o.oForwardVel = 0
        end
    end

    if cur_obj_is_mario_on_platform() ~= 0 and o.oHomeX == 5874 and not is_bubbled(m) and o.oDoneEndPoint == 0 then
        if m.controller.buttonDown & U_JPAD ~= 0 then
            o.oForwardVel = 20
            o.oPosY = o.oPosY + 1.7
        else
            o.oForwardVel = 0
        end
    end

    if o.oPosX == o.oEndPointX then
        o.oForwardVel = 0
        o.oDoneEndPoint = 1
    end

    if o.oPosZ == o.oEndPointZ then
        o.oForwardVel = 0
        o.oDoneEndPoint = 1
    end

    if o.oDoneEndPoint == 1 then
        o.oSubAction = o.oSubAction + 1
    end

    -- return 

    if o.oSubAction > 400 then
        o.oPosX = o.oHomeX
        o.oPosY = o.oHomeY
        o.oPosZ = o.oHomeZ
        o.oDoneEndPoint = 0
        o.oSubAction = 0
    end
end

id_bhvGreenSeesaw = hook_behavior(nil, OBJ_LIST_SURFACE, true, seesaw_green_init, seesaw_green_loop, "id_bhvGreenSeesaw")


id_bhvPeachCustom = hook_behavior(nil, OBJ_LIST_GENACTOR, true, function(o)
    o.oFlags = OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.oAnimations = gObjectAnimations.peach_seg5_anims_0501C41C
    o.oInteractType = INTERACT_TEXT
    o.hitboxRadius = 90
    o.hitboxHeight = 150
    cur_obj_init_animation(5)
    bhv_toad_message_init()
end, function (o)
    o.oIntangibleTimer = 0
    bhv_toad_message_loop()
end)
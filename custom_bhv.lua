function get_star_count()
    local courseMax = 25
    local courseMin = 1
    return save_file_get_total_star_count(get_current_save_file_num() - 1, courseMin - 1, courseMax - 1)
end

function get_world_star_count(world)
    local course1
    local course2
    local stars_world = 0
    if world == 1 then
        course1 = COURSE_BOB
        course2 = COURSE_WF
    end

    if world == 2 then
        course1 = COURSE_JRB
        course2 = COURSE_CCM
    end

    for i = course1, course2 do
        local starFlags = save_file_get_star_flags(get_current_save_file_num() - 1, i - 1)
        for star = 0, 6 do
            if starFlags & (1 << star) ~= 0 then
                stars_world = stars_world + 1
            end
        end
    end
    return stars_world
end

local repack = function(value, pack_fmt, unpack_fmt)
    return string.unpack(unpack_fmt, string.pack(pack_fmt, value))
end

---@param m MarioState
---@return boolean
local function is_bubbled(m)
    return m.action == ACT_BUBBLED
end
local platformTimer = 0
local soundPlayed = false

E_MODEL_RED_WARP_PIPE = smlua_model_util_get_id("warp_pipe_red_geo")
E_MODEL_BLUE_WARP_PIPE = smlua_model_util_get_id("warp_pipe_blue_geo")
E_MODEL_BLOCKED_WARP_PIPE = smlua_model_util_get_id("warp_pipe_blocked_geo")
E_MODEL_PIPE_COVER = smlua_model_util_get_id("pipe_cover_geo")
COL_PIPE_COVER = smlua_collision_util_get("pipe_cover_collision")

-- custom cage for boss

COL_CAGE = smlua_collision_util_get("eight_star_cage_collision")
E_MODEL_8_STAR_CAGE = smlua_model_util_get_id("eight_star_cage_geo")
COL_WORLD_CANNON = smlua_collision_util_get("world_cannon_collision")
E_MODEL_WORLD_CANNON = smlua_model_util_get_id("world_cannon_geo")

---@param o Object
function eight_star_cage_init(o)
    o.oIntangibleTimer = 0
    o.header.gfx.skipInViewCheck = true
    o.collisionData = COL_CAGE
end

function eight_star_cage_loop(o)
    --djui_chat_message_create(tostring(get_world_star_count(2)))
    load_object_collision_model()
    if get_world_star_count(1) >= 8 and o.oBehParams2ndByte == 1 then
        obj_mark_for_deletion(o)
    end

    if get_world_star_count(2) >= 8 and o.oBehParams2ndByte == 2 then
        obj_mark_for_deletion(o)
    end
end

---@param o Object
function world_cannon_init(o)
    o.oInteractType = 0
    o.oIntangibleTimer = 0
    o.header.gfx.skipInViewCheck = true
    o.collisionData = COL_WORLD_CANNON
    o.hitboxRadius = 10000
    o.hitboxHeight = 10000
end

stuck = false
stuckTimer = 0
stuckX = false
stuckY = false
stuckHud = false

function world_cannon_loop(o)
    load_object_collision_model()
    m = gMarioStates[0]

    if stuck then
        vec3f_set(m.pos, o.oPosX, o.oPosY + 400, o.oPosZ)
        m.freeze = 1
        if soundPlayed == false then
            play_sound(SOUND_GENERAL_CANNON_UP, m.marioObj.header.gfx.cameraToObject)
            soundPlayed = true
        end
    end

    if m.action == ACT_SHOT_FROM_CANNON and m.vel.y >= 0 then
        stuckTimer = stuckTimer + 1
    end

    if stuckTimer > 50 then
        warp_to_warpnode(warpsforlevels[worldSelected].level, warpsforlevels[worldSelected].area, 1,
            warpsforlevels[worldSelected].warpid)
        stuckTimer = 0
    end

    if m.controller.buttonPressed & A_BUTTON ~= 0 and world_unlocked(worldSelected) and m.pos.y == (o.oPosY + 400) then
        stuckHud = false
        stuck = false
        soundPlayed = false
        vec3f_set(m.pos, o.oPosX, o.oPosY + 800, o.oPosZ)
        m.action = ACT_SHOT_FROM_CANNON
        m.faceAngle.y = 23039.6484375
        m.vel.y = 60
        m.forwardVel = 90
    end
end

function world_cannon_warp()
    if gMarioStates[0].area.warpNodes.node.id == 11 and gNetworkPlayers[0].currLevelNum == (LEVEL_CASTLE_COURTYARD) then
        set_mario_action(gMarioStates[0], ACT_SHOT_FROM_CANNON, 0)
    end
    -- djui_chat_message_create(tostring(gMarioStates[0].area.warpNodes.node.id))
end

hook_event(HOOK_ON_WARP, world_cannon_warp)


function pipe_cover_init(o)
    o.oIntangibleTimer = 0
    o.header.gfx.skipInViewCheck = true
    o.collisionData = COL_PIPE_COVER
end

function pipe_cover_loop(o)
    load_object_collision_model()
    if operation(COURSE_BOB, 3) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 1 then
        obj_mark_for_deletion(o)
    end

    if operation(COURSE_CCM, 5) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 2 then
        obj_mark_for_deletion(o)
    end
end

bhvPipeCover = hook_behavior(nil, OBJ_LIST_SURFACE, true, pipe_cover_init, pipe_cover_loop)
bhv8StarCage = hook_behavior(nil, OBJ_LIST_SURFACE, true, eight_star_cage_init, eight_star_cage_loop)
bhvWorldCannon = hook_behavior(nil, OBJ_LIST_SURFACE, true, world_cannon_init, world_cannon_loop)

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
    network_init_object(obj, true, { "oEndPointX", "oEndPointZ", "oDoneEndPoint" })

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
    o.oFlags = OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO |
        OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.oAnimations = gObjectAnimations.peach_seg5_anims_0501C41C
    o.oInteractType = INTERACT_TEXT
    o.hitboxRadius = 90
    o.hitboxHeight = 150
    cur_obj_init_animation(5)
    bhv_toad_message_init()
end, function(o)
    o.oIntangibleTimer = 0
    bhv_toad_message_loop()
end)

--dancing hill :D

E_MODEL_DANCING_HILL = smlua_model_util_get_id("dancing_hill_geo")

---@param o Object
function bhv_dancing_hill_init(o)
    o.header.gfx.skipInViewCheck = true
    obj_set_model_extended(o, E_MODEL_DANCING_HILL)
end

function bhv_dancing_hill_loop(o)
    o.oAnimState = o.oAnimState + 1
end

id_bhvDancingHill = hook_behavior(nil, OBJ_LIST_GENACTOR, true, bhv_dancing_hill_init, bhv_dancing_hill_loop)

function bhv_fake_pipe_init(o)
    o.header.gfx.skipInViewCheck = true
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = gGlobalObjectCollisionData.warp_pipe_seg3_collision_03009AC8
end

---@param o Object
function fake_pipe_loop(o)
    load_object_collision_model()
if o.oBehParams2ndByte == 0 then
        o.oSubAction = o.oSubAction + 1
    end

    if o.oSubAction > 100 then
        spawn_sync_object(id_bhvAnt, E_MODEL_ANT, o.oPosX, o.oPosY, -8443, function(o)
            
        end)
        o.oSubAction = 0
    end

    if operation(COURSE_BOB, 1) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 1 then
        obj_set_model_extended(o, E_MODEL_BITS_WARP_PIPE)
    end
    if operation(COURSE_WF, 0) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 2 then
        obj_set_model_extended(o, E_MODEL_BITS_WARP_PIPE)
    end
    if operation(COURSE_WF, 4) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 3 then
        obj_set_model_extended(o, E_MODEL_BITS_WARP_PIPE)
    end
end

id_bhvFakeWarpPipe = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_fake_pipe_init, fake_pipe_loop)


--- gombba :D
E_MODEL_GOOMBOSS = smlua_model_util_get_id("king_goomba_geo")

---@param o Object
function bhv_goomboss_init(o)
    o.oInteractType = INTERACT_DAMAGE
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.header.gfx.skipInViewCheck = true
    o.oAnimations = gObjectAnimations.goomba_seg8_anims_0801DA4C
    o.hitboxRadius = 320
    o.hitboxHeight = 300
    cur_obj_init_animation(0)
end

ACT_GOOMBA_BOSS_RUNNING_TO_WALL = 0
ACT_GOOMBA_BOSS_ON_GROUND = 1

---@param o Object
function bhv_goomboss_loop(o)
    o.oInteractStatus = 0
    local m = gMarioStates[0]
    object_step()
    if o.oAction == ACT_GOOMBA_BOSS_RUNNING_TO_WALL then
        o.oForwardVel = 30
        o.oSubAction = o.oSubAction + 1
    end

    if o.oAction == ACT_GOOMBA_BOSS_ON_GROUND then
        o.header.gfx.angle.x = 16384
        o.oForwardVel = 0
    end

    if o.oSubAction > 50 then
        o.oAction = ACT_GOOMBA_BOSS_ON_GROUND
        o.oSubAction = 0
    end

    -- other

    if o.oAction == ACT_GOOMBA_BOSS_ON_GROUND and m.action == ACT_GROUND_POUND and dist_between_objects(o, m.marioObj) < 100 then
        o.oAction = 3
    end
end

id_bhvGoomboss = hook_behavior(nil, OBJ_LIST_GENACTOR, true, bhv_goomboss_init, bhv_goomboss_loop)

--bouncer

COL_BOUNCY_PLATFROM = smlua_collision_util_get("bouncy_platform_collision")
E_MODEL_BOUNCY_PLATFORM = smlua_model_util_get_id("bouncy_platform_geo")

function bhv_bouncy_platform_init(o)
    o.header.gfx.skipInViewCheck = true
    o.collisionData = COL_BOUNCY_PLATFROM
    obj_set_model_extended(o, E_MODEL_BOUNCY_PLATFORM)
end

function bhv_bouncy_platform_loop(obj)
    load_object_collision_model()
    local m = gMarioStates[0]

    obj.oPosX = obj.oPosX

    if cur_obj_is_mario_on_platform() == 1 and not is_bubbled(m) then
        if m.action == ACT_GROUND_POUND_LAND then
            set_anim_to_frame(m, 0)
            set_mario_action(m, ACT_TRIPLE_JUMP, 0)
            m.vel.y = 140
            bounceMultiplier = 3
        else
            set_anim_to_frame(m, 0)
            set_mario_action(m, ACT_TRIPLE_JUMP, 0)
            m.vel.y = (140 / 3) * bounceMultiplier
            if bounceMultiplier < 3 then
                bounceMultiplier = bounceMultiplier + 1
            end
        end
    end
end

id_bhvBouncyPlatform = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_bouncy_platform_init, bhv_bouncy_platform_loop)


---@param o Object
function bhv_ant_init(o)
    o.oInteractType = INTERACT_BOUNCE_TOP
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE
    o.header.gfx.skipInViewCheck = true
    o.oAnimations = gObjectAnimations.goomba_seg8_anims_0801DA4C
    o.oForwardVel = 10
    o.hurtboxRadius = 72
    o.hurtboxHeight = 50
    o.oIntangibleTimer = 0
    o.oNumLootCoins = 1
    o.oGraphYOffset = -45
    obj_scale(o, 2.5)
    cur_obj_init_animation(0)
end

hit_acts = {
    [ACT_PUNCHING] = true,
    [ACT_MOVE_PUNCHING] = true,
    [ACT_JUMP_KICK] = true,
    [ACT_GROUND_POUND_LAND] = true,
    [ACT_DIVE] = true,
    [ACT_CAT_DIVE] = true
}

E_MODEL_ANT = smlua_model_util_get_id("ant_geo")

---@param o Object
function bhv_ant_loop(o)
    o.oInteractStatus = 0
    o.oMoveAnglePitch = 90
    o.oMoveAngleYaw = 90
    m = gMarioStates[0]
    if obj_check_hitbox_overlap(o, m.marioObj) then
        if hit_acts[m.action] then
            o.oAction = 1
        end
    end

    if o.oAction == 1 or o.oInteractStatus == 49155 then
        o.oHealth = 0
        obj_die_if_health_non_positive()
    end

    if o.oPosZ > -5322 then
        obj_mark_for_deletion(o)
    end
end

id_bhvAnt = hook_behavior(nil, OBJ_LIST_GENACTOR, true, bhv_ant_init, bhv_ant_loop, nil)

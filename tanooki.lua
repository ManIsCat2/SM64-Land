--// Tanooki Leaf behavior and abilities. //--

E_MODEL_TANOOKI_MARIO = smlua_model_util_get_id("tanooki_mario_geo")
E_MODEL_TANOOK_LEAF = smlua_model_util_get_id("tanooki_leaf_geo")
smlua_anim_util_register_animation("anim_flutter",
    0,
    0,
    0,
    0,
    9, { 0x0000, 0x00AA, 0x0000, 0x0000, 0x3FFF, 0x0000, 0x0000, 0x0000, 0x3FC6,
        0x2683, 0xEFB9, 0xE999, 0xE54A, 0x1304, 0x003C, 0x0001, 0xFFFE, 0xC170,
        0xE643, 0xD713, 0xEC60, 0xFFFF, 0xFFFF, 0xFFF5, 0x00A8, 0xF983, 0xE96A,
        0x0001, 0xFFFE, 0xC170, 0x3BC7, 0x49B0, 0xC9DC, 0x0000, 0xFFFF, 0xE8F2,
        0xFFFF, 0xFFFF, 0xED8B, 0x0000, 0x0000, 0xBF5E, 0x00E1, 0xEB1E, 0x705E,
        0x0000, 0xFFFF, 0x4C57, 0x002B, 0xFFCE, 0xD5EB, 0x0000, 0x0000, 0xBF5E,
        0x0FEA, 0x02C6, 0xC52E, 0xFFFF, 0x0000, 0x0A3A, 0xFE60, 0xFF2B, 0xEE9E,
        0x0000, 0xFAA0, 0xF1D1, 0xEE28, 0xEC06, 0xEAAA, 0xEB6A, 0xED46, 0xF003,
        0xF427, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000,
        0xFFFF, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF,
        0xFFFF, 0x0000, 0xFFFF, },
    { 0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0003, 0x0001,
        0x0004, 0x0001, 0x0005, 0x0001, 0x0006, 0x0001, 0x0007, 0x0001, 0x0008,
        0x0001, 0x0009, 0x0001, 0x000A, 0x0001, 0x000B, 0x0001, 0x000C, 0x0001,
        0x000D, 0x0001, 0x000E, 0x0001, 0x000F, 0x0001, 0x0010, 0x0001, 0x0011,
        0x0001, 0x0012, 0x0001, 0x0013, 0x0001, 0x0014, 0x0001, 0x0015, 0x0001,
        0x0016, 0x0001, 0x0017, 0x0001, 0x0018, 0x0001, 0x0019, 0x0001, 0x001A,
        0x0001, 0x001B, 0x0001, 0x001C, 0x0001, 0x001D, 0x0001, 0x001E, 0x0001,
        0x001F, 0x0001, 0x0020, 0x0001, 0x0021, 0x0001, 0x0022, 0x0001, 0x0023,
        0x0001, 0x0024, 0x0001, 0x0025, 0x0001, 0x0026, 0x0001, 0x0027, 0x0001,
        0x0028, 0x0001, 0x0029, 0x0001, 0x002A, 0x0001, 0x002B, 0x0001, 0x002C,
        0x0001, 0x002D, 0x0001, 0x002E, 0x0001, 0x002F, 0x0001, 0x0030, 0x0001,
        0x0031, 0x0001, 0x0032, 0x0001, 0x0033, 0x0001, 0x0034, 0x0001, 0x0035,
        0x0001, 0x0036, 0x0001, 0x0037, 0x0001, 0x0038, 0x0001, 0x0039, 0x0001,
        0x003A, 0x0001, 0x003B, 0x0001, 0x003C, 0x0001, 0x003D, 0x0001, 0x003E,
        0x000A, 0x003F, 0x000A, 0x0049, 0x000A, 0x0053, })

local tanooki = false
local flutterTimer = 40
local wallSlideTimer = 0

local ACT_FAKE_JUMP = allocate_mario_action(ACT_GROUP_AIRBORNE | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
local flutterActions = {
    [ACT_JUMP] = true,
    [ACT_DOUBLE_JUMP] = true,
    [ACT_TRIPLE_JUMP] = true,
    [ACT_LONG_JUMP] = true,
    [ACT_SIDE_FLIP] = true,
    [ACT_GROUND_POUND_JUMP] = true,
    [ACT_FORWARD_ROLLOUT] = true,
    [ACT_BACKWARD_ROLLOUT] = true,
    [ACT_WALL_KICK_AIR] = true,
    [ACT_FAKE_JUMP] = true,
    [ACT_FREEFALL] = true
}

---@param obj Object
function bhv_leaf_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_model_extended(obj, E_MODEL_TANOOK_LEAF)
    obj_scale(obj, 0.5)
    obj.oFaceAngleYaw = obj.oFaceAngleYaw - 32768 -- watchr is so not awesome
    obj.hitboxRadius = 1500
    obj.hitboxHeight = 1500
    obj.oGravity = 3
    obj.oFriction = 0.8
    obj.oBuoyancy = 1
    network_init_object(obj, true, nil)
end

---@param obj Object
function bhv_leaf_loop(obj)
    object_step()
    load_object_collision_model()
    local m = gMarioStates[0]
    local distance = dist_between_objects(obj, m.marioObj)
    if distance < 50 then
        obj_mark_for_deletion(obj)
        play_sound(SOUND_GENERAL_COLLECT_1UP, m.marioObj.header.gfx.cameraToObject)
        cloud = false
        bee = false
        fludd = false
        tanooki = true
        gPlayerSyncTable[0].modelId = E_MODEL_TANOOKI_MARIO
    end
end

id_bhvWingCap = hook_behavior(id_bhvWingCap, OBJ_LIST_GENACTOR, true, bhv_leaf_init, bhv_leaf_loop)

function tanooki_loop(m)
    if m.playerIndex == 0 then
        if gPlayerSyncTable[0].modelId == E_MODEL_TANOOKI_MARIO and tanooki then
            if m.action == ACT_WALL_SLIDE then
                wallSlideTimer = 0
            elseif m.action == ACT_WALL_KICK_AIR and m.forwardVel > 0 then
                wallSlideTimer = wallSlideTimer + 1
            else
                wallSlideTimer = 0
            end
            if flutterActions[m.action] then
                if m.controller.buttonPressed & A_BUTTON ~= 0 and m.action & ACT_FLAG_AIR ~= 0 then
                    startTimer = false
                    if m.pos.y > (m.floorHeight + 100) then
                        if wallSlideTimer >= 4 and m.action == ACT_WALL_KICK_AIR then
                            set_mario_action(m, ACT_FAKE_JUMP, 0)
                            wallSlideTimer = 0
                            smlua_anim_util_set_animation(m.marioObj, "anim_flutter")
                        elseif m.action ~= ACT_WALL_KICK_AIR then
                            set_mario_action(m, ACT_FAKE_JUMP, 0)
                            wallSlideTimer = 0
                            smlua_anim_util_set_animation(m.marioObj, "anim_flutter")
                        end
                        play_sound(SOUND_ACTION_SPIN, m.marioObj.header.gfx.cameraToObject)
                        startTimer = true
                        flutterTimer = 0
                    end
                end
                if startTimer then
                    flutterTimer = flutterTimer + 1
                    if flutterTimer < 10 then
                        if m.vel.y < -7.5 then
                            m.vel.y = -7.5
                        end
                    else
                        startTimer = false
                        flutterTimer = 0
                    end
                else
                    flutterTimer = 0
                end
            end
        end
    end
    if m.action == ACT_JUMP and tanooki then
        smlua_anim_util_set_animation(m.marioObj, "anim_flutter")
    end
end

local function act_fake_jump(m)
    if m.playerIndex ~= 0 then return end

    if m.controller.buttonPressed & B_BUTTON ~= 0 then
        if m.forwardVel >= 28 then
            set_mario_action(m, ACT_DIVE, 0)
        else
            set_mario_action(m, ACT_JUMP_KICK, 0)
        end
    end

    if (m.controller.buttonPressed & Z_TRIG) ~= 0 then
        set_mario_action(m, ACT_GROUND_POUND, 0)
    end

    common_air_action_step(m, ACT_JUMP_LAND, MARIO_ANIM_SINGLE_JUMP,
    AIR_STEP_CHECK_LEDGE_GRAB | AIR_STEP_CHECK_HANG)
end

hook_mario_action(ACT_FAKE_JUMP, { every_frame = act_fake_jump })

hook_event(HOOK_MARIO_UPDATE, tanooki_loop)

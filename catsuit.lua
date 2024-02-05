--// Catsuit behavior and abilities. //--

catsuit = false
E_MODEL_CAT_MARIO = smlua_model_util_get_id("cat_mario_geo")
E_MDOEL_SUPER_BELL = smlua_model_util_get_id("super_bell_geo")

ACT_CAT_DIVE = allocate_mario_action(ACT_GROUP_AIRBORNE | ACT_FLAG_AIR | ACT_FLAG_MOVING |
    ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)

---@param obj Object
function bhv_catsuit_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_model_extended(obj, E_MDOEL_SUPER_BELL)
    obj_scale(obj, 0.5)
    obj.oFaceAngleYaw = obj.oFaceAngleYaw - 32768 -- watchr is so not awesome
    obj.hitboxRadius = 100
    obj.hitboxHeight = 100
    obj.oGravity = 3
    obj.oFriction = 0.8
    obj.oBuoyancy = 1
    network_init_object(obj, true, nil)
end

---@param obj Object
function bhv_catsuit_loop(obj)
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
        tanooki = false
        catsuit = true
        gPlayerSyncTable[0].modelId = E_MODEL_CAT_MARIO
    end
end

id_bhvMetalCap = hook_behavior(id_bhvMetalCap, OBJ_LIST_GENACTOR, true, bhv_catsuit_init, bhv_catsuit_loop)

---@param m MarioState
function catsuit_power_loop(m)
    if m.playerIndex == 0 then
        if catsuit then
            if m.controller.buttonDown & Y_BUTTON ~= 0 and m.action & ACT_FLAG_AIR ~= 0 then
                set_mario_action(m, ACT_CAT_DIVE, 0)
            end
        end
    end
end

function cat_dive(m)
    update_walking_speed(m)
    perform_air_step(m, 0)
    m.actionTimer = m.actionTimer + 1
    perform_air_step(m, 0)
    set_mario_animation(m, MARIO_ANIM_DIVE)
    m.forwardVel = 20
    if m.controller.buttonDown & Y_BUTTON == 0 then
        return set_mario_action(m, ACT_FREEFALL, 0)
    end

    if perform_air_step(m, 0) == AIR_STEP_LANDED then
        set_mario_action(m, ACT_FREEFALL_LAND, 0)
    end

    return 0
end

function cat_dive_gravity(m)
    m.vel.y = m.vel.y - 4.5
end

hook_event(HOOK_MARIO_UPDATE, catsuit_power_loop)
hook_mario_action(ACT_CAT_DIVE, { every_frame = cat_dive, gravity = cat_dive_gravity }, INT_FAST_ATTACK_OR_SHELL)

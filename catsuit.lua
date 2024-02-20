--// Catsuit behavior and abilities. //--

catsuit = false
didDive = false

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
    obj.hitboxRadius = 50
    obj.hitboxHeight = 50
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
    if obj_check_hitbox_overlap(m.marioObj,obj) then
        obj_mark_for_deletion(obj)
        cloud = false
        bee = false
        fludd = false
        tanooki = false
        catsuit = true
        powerup = true
    end
    if catsuit then
        gPlayerSyncTable[0].modelId = E_MODEL_CAT_MARIO
    end
end

id_bhvSuperBell = hook_behavior(id_bhvMetalCap, OBJ_LIST_GENACTOR, true, bhv_catsuit_init, bhv_catsuit_loop)

---@param m MarioState
function catsuit_power_loop(m)
    if m.playerIndex == 0 then
        if catsuit then
            if m.pos.y > (m.floorHeight + 100) and not didDive then
                if m.controller.buttonPressed & B_BUTTON ~= 0 and m.action & ACT_FLAG_AIR ~= 0 then
                    set_mario_action(m, ACT_CAT_DIVE, 0)
                    didDive = true
                end
            end
            if m.action & ACT_FLAG_AIR == 0 and didDive then
                didDive = false
            end
        end
    end
end

function cat_dive(m)
    m.actionTimer = m.actionTimer + 1
    
    if m.prevAction ~= ACT_DIVE then
        if m.actionTimer == 2 then
            common_air_action_step(m, ACT_GROUND_POUND, MARIO_ANIM_GROUND_POUND,
            AIR_STEP_CHECK_HANG)
            m.forwardVel = 0
        elseif m.actionTimer >= 6 then
            play_mario_sound(m, CHAR_SOUND_HOOHOO, CHAR_SOUND_HOOHOO)
            common_air_action_step(m, ACT_DIVE, MARIO_ANIM_DIVE,
            AIR_STEP_CHECK_HANG)
            m.forwardVel = 40
        end
    else
        if m.actionTimer == 2 then
            common_air_action_step(m, ACT_GROUND_POUND, MARIO_ANIM_START_GROUND_POUND,
            AIR_STEP_CHECK_HANG)
            m.forwardVel = 0
        elseif m.actionTimer >= 6 then
            common_air_action_step(m, ACT_DIVE, MARIO_ANIM_DIVE,
            AIR_STEP_CHECK_HANG)
            m.forwardVel = 40
        end
    end
    

    if m.controller.buttonPressed == Z_TRIG then
        set_mario_action(m, ACT_GROUND_POUND, 0)
    end

    if perform_air_step(m, 0) == AIR_STEP_LANDED then
        set_mario_action(m, ACT_FREEFALL_LAND, 0)
    end
end

function cat_dive_gravity(m)
    if m.pos.y < (m.floorHeight + 100) then
        m.vel.y = m.vel.y 
    else
        m.vel.y = -10
    end
end

hook_event(HOOK_MARIO_UPDATE, catsuit_power_loop)
hook_mario_action(ACT_CAT_DIVE, { every_frame = cat_dive, gravity = cat_dive_gravity }, INT_FAST_ATTACK_OR_SHELL)

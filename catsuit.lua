--// Catsuit behavior and abilities. //--

catsuit = false
E_MODEL_CAT_MARIO = smlua_model_util_get_id("cat_mario_geo")
E_MDOEL_SUPER_BELL = smlua_model_util_get_id("super_bell_geo")

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
                set_mario_animation(m, MARIO_ANIM_DIVE)
                m.forwardVel = 40
                m.vel.y = -9
            end
        end
    end
end

function models(m)
    if gPlayerSyncTable[m.playerIndex].modelId ~= nil then
        obj_set_model_extended(m.marioObj, gPlayerSyncTable[m.playerIndex].modelId)
    end
end

hook_event(HOOK_MARIO_UPDATE, models)
hook_event(HOOK_MARIO_UPDATE, catsuit_power_loop)

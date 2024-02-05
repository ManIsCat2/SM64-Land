--// Tanooki Leaf behavior and abilities. //--

E_MODEL_TANOOKI_MARIO = smlua_model_util_get_id("tanooki_mario_geo")
E_MODEL_TANOOK_LEAF = smlua_model_util_get_id("tanooki_leaf_geo")
local tanooki = false

---@param obj Object
function bhv_leaf_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_model_extended(obj, E_MODEL_TANOOK_LEAF)
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
            if m.action == ACT_JUMP or m.action == ACT_DOUBLE_JUMP or m.action == ACT_TRIPLE_JUMP or m.action == ACT_LONG_JUMP or m.action == ACT_SIDE_FLIP then
                if m.controller.buttonPressed & A_BUTTON ~= 0 then
                    if m.pos.y > (m.floorHeight + 100) then
                        m.vel.y = 2
                        play_sound(SOUND_ENV_WIND1, m.marioObj.header.gfx.cameraToObject)
                    end
                end
            end
        end
    end
end

hook_event(HOOK_MARIO_UPDATE, tanooki_loop)
hook_event(HOOK_ON_WARP, on_death_warp)

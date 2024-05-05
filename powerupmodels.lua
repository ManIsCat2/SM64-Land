-- Placed here to remove the need of setting models for every powerup
-- Uses the definitive model check

-- Models

E_MODEL_TANOOKI_MARIO = smlua_model_util_get_id("tanooki_mario_geo")
E_MODEL_KITSUNE_LUIGI = smlua_model_util_get_id("kitsune_luigi_geo")
E_MODEL_TANOOKI_TOAD = smlua_model_util_get_id("tanooki_toad_geo")
E_MODEL_TANOOKI_WARIO = smlua_model_util_get_id("tanooki_wario_geo")
E_MODEL_KITSUNE_WALUIGI = smlua_model_util_get_id("kitsune_waluigi_geo")
E_MODEL_CAT_MARIO = smlua_model_util_get_id("cat_mario_geo")
E_MODEL_BEE_MARIO = smlua_model_util_get_id("bee_mario_geo")

-- Powerups enum

NORMAL = 0
TANOOKI = 1
CAT = 2
BEE = 3

activePowerup = NORMAL -- Current Powerup, set to NORMAL to disable any powerup

characterPowerupModels = {
    [CT_MARIO] = {tanooki = E_MODEL_TANOOKI_MARIO, cat = E_MODEL_CAT_MARIO, bee = E_MODEL_BEE_MARIO},
    [CT_LUIGI] = {tanooki = E_MODEL_KITSUNE_LUIGI, cat = nil, bee = nil},
    [CT_TOAD] = {tanooki = E_MODEL_TANOOKI_TOAD, cat = nil, bee = nil},
    [CT_WARIO] = {tanooki = E_MODEL_TANOOKI_WARIO, cat = nil, bee = nil},
    [CT_WALUIGI] = {tanooki = E_MODEL_KITSUNE_WALUIGI, cat = nil, bee = nil},
}

-- Powerup States, to add more powerups here, you must first add them to the enum and assign a number
function get_character_model(m)
    if m.playerIndex ~= 0 then return end
    CPM = characterPowerupModels[m.character.type] -- To get the model easily
    CPMM = characterPowerupModels[CT_MARIO] -- To get Mario's model easily
    powerupStates = {
        [NORMAL] = {modelId = nil},
        [TANOOKI] = {modelId = CPM.tanooki and CPM.tanooki or CPMM.tanooki},
        [CAT] = {modelId = CPM.cat and CPM.cat or CPMM.cat},
        [BEE] = {modelId = CPM.bee and CPM.bee or CPMM.bee}
    }
end

hook_event(HOOK_MARIO_UPDATE, get_character_model)

-- Powerup Model Functions --

function powerups()
    gPlayerSyncTable[0].modelId = powerupStates[activePowerup].modelId
end

hook_event(HOOK_OBJECT_SET_MODEL, function (o)
    if obj_has_behavior_id(o, id_bhvMario) ~= 0 then
        local i = network_local_index_from_global(o.globalPlayerIndex)
        if stuck then
            gPlayerSyncTable[i].modelId = E_MODEL_NONE
        end
        if gPlayerSyncTable[i].modelId ~= nil and obj_has_model_extended(o, gPlayerSyncTable[i].modelId) == 0 then
            obj_set_model_extended(o, gPlayerSyncTable[i].modelId)
        end
    end
end)

-- Resets the player stats when leaving a level or dying

function on_death_warp()
    activePowerup = NORMAL
    timer = 0
    score = 0
    scoreCounter = 0
end

-- Removes the player's powerup on damage

function damage_check(m)
    if m.playerIndex ~= 0 then return end
    if m.hurtCounter > 0 or m.action == ACT_BURNING_GROUND or m.action == ACT_BURNING_JUMP then
        activePowerup = NORMAL
    end
    if m.action & ACT_FLAG_SWIMMING ~= 0 and activePowerup == BEE then
        activePowerup = NORMAL
    end
end

hook_event(HOOK_UPDATE, powerups)
hook_event(HOOK_MARIO_UPDATE, damage_check)
hook_event(HOOK_ON_DEATH, on_death_warp)
hook_event(HOOK_ON_WARP, on_death_warp)
-- Placed here to remove the need of setting models for every powerup
-- Uses the definitive model check

-- Models

E_MODEL_TANOOKI_MARIO = smlua_model_util_get_id("tanooki_mario_geo")
E_MODEL_CAT_MARIO = smlua_model_util_get_id("cat_mario_geo")
E_MODEL_BEE_MARIO = smlua_model_util_get_id("bee_mario_geo")

-- Powerups enum

NORMAL = 0
TANOOKI = 1
CAT = 2
BEE = 3

activePowerup = NORMAL -- Current Powerup, set to NORMAL to disable any powerup

-- Powerup States, to add more powerups here, you must first add them to the enum and assign a number
powerupStates = {
    [NORMAL] = {modelId = nil},
    [TANOOKI] = {modelId = E_MODEL_TANOOKI_MARIO},
    [CAT] = {modelId = E_MODEL_CAT_MARIO},
    [BEE] = {modelId = E_MODEL_BEE_MARIO}
}

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
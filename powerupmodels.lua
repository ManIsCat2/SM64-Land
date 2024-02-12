-- Placed here to remove the need of setting models for every powerup
-- Uses the definitive model check

hook_event(HOOK_OBJECT_SET_MODEL, function (o)
    if obj_has_behavior_id(o, id_bhvMario) ~= 0 then
        local i = network_local_index_from_global(o.globalPlayerIndex)
        if gPlayerSyncTable[i].modelId ~= nil and obj_has_model_extended(o, gPlayerSyncTable[i].modelId) == 0 then
            obj_set_model_extended(o, gPlayerSyncTable[i].modelId)
        end
    end
end)

powerup = false

function powerup_check()
    if powerup == false then
        cloud = false
        bee = false
        fludd = false
        tanooki = false
        catsuit = false
        gPlayerSyncTable[0].modelId = nil
    end
end

function on_death_warp()
    powerup = false
    timer = 0
    score = 0
    scoreAdder = 0
end

function damage_check(m)
    if m.hurtCounter > 0 then
        powerup = false
    end
end

hook_event(HOOK_UPDATE, powerup_check)
hook_event(HOOK_MARIO_UPDATE, damage_check)
hook_event(HOOK_ON_DEATH, on_death_warp)
hook_event(HOOK_ON_WARP, on_death_warp)
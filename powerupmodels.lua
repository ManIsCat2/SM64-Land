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

function on_death_warp()
    gPlayerSyncTable[0].modelId = nil
    tanooki = false
    catsuit = false
    timer = 0
    score = 0
end

hook_event(HOOK_ON_DEATH, on_death_warp)
hook_event(HOOK_ON_WARP, on_death_warp)
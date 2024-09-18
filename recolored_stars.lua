-- Multi Colored Stars --

-- Star Models --

E_MODEL_STAR_W2 = smlua_model_util_get_id("star_w2_geo")
E_MODEL_STAR_W3 = smlua_model_util_get_id("star_w3_geo")
E_MODEL_STAR_W4 = smlua_model_util_get_id("star_w4_geo")
E_MODEL_STAR_W5 = smlua_model_util_get_id("star_w5_geo")
E_MODEL_STAR_W6 = smlua_model_util_get_id("star_w6_geo")
E_MODEL_STAR_W7 = smlua_model_util_get_id("star_w7_geo")
E_MODEL_STAR_W8 = smlua_model_util_get_id("star_w8_geo")

local worldSpecificStarModels = {
    E_MODEL_STAR,
    E_MODEL_STAR_W2,
    E_MODEL_STAR_W3,
    E_MODEL_STAR_W4,
    E_MODEL_STAR_W5,
    E_MODEL_STAR_W6,
    E_MODEL_STAR_W7,
    E_MODEL_STAR_W8
}


-- Model Replacement Function --

function bhv_star_loop(o)
    if obj_has_model_extended(o, E_MODEL_TRANSPARENT_STAR) == 0 then
        if (gNetworkPlayers[0].currLevelNum == LEVEL_CASTLE_GROUNDS or gNetworkPlayers[0].currLevelNum == LEVEL_CASTLE_COURTYARD) and worldSpecificStarModels[curWorld] ~= nil then
            obj_set_model_extended(o, worldSpecificStarModels[curWorld])
        end

        if gNetworkPlayers[0].currLevelNum == LEVEL_BOB or gNetworkPlayers[0].currLevelNum == LEVEL_WF then
            obj_set_model_extended(o, E_MODEL_STAR)
        end

        if gNetworkPlayers[0].currLevelNum == LEVEL_CCM or gNetworkPlayers[0].currLevelNum == LEVEL_JRB then
            obj_set_model_extended(o, E_MODEL_STAR_W2)
        end

        if gNetworkPlayers[0].currLevelNum == LEVEL_BBH and gNetworkPlayers[0].currAreaIndex == 1 or gNetworkPlayers[0].currLevelNum == LEVEL_SSL and gNetworkPlayers[0].currAreaIndex == 1 or gNetworkPlayers[0].currLevelNum == LEVEL_HMC and gNetworkPlayers[0].currAreaIndex == 1 then
            obj_set_model_extended(o, E_MODEL_STAR_W3)
        end

        if gNetworkPlayers[0].currLevelNum == LEVEL_TTC and gNetworkPlayers[0].currAreaIndex == 2 or gNetworkPlayers[0].currLevelNum == LEVEL_WDW or gNetworkPlayers[0].currLevelNum == LEVEL_SL and gNetworkPlayers[0].currAreaIndex == 2 then
            obj_set_model_extended(o, E_MODEL_STAR_W4)
        end

        if gNetworkPlayers[0].currLevelNum == LEVEL_DDD or gNetworkPlayers[0].currLevelNum == LEVEL_SL and gNetworkPlayers[0].currAreaIndex == 1 or gNetworkPlayers[0].currLevelNum == LEVEL_HMC and gNetworkPlayers[0].currAreaIndex == 2 then
            obj_set_model_extended(o, E_MODEL_STAR_W5)
        end

        if gNetworkPlayers[0].currLevelNum == LEVEL_RR or gNetworkPlayers[0].currLevelNum == LEVEL_THI and gNetworkPlayers[0].currAreaIndex == 2 or gNetworkPlayers[0].currLevelNum == LEVEL_TTC and gNetworkPlayers[0].currAreaIndex == 1 then
            obj_set_model_extended(o, E_MODEL_STAR_W7)
        end
    end
end

hook_behavior(id_bhvStar, OBJ_LIST_GENACTOR, false, nil, bhv_star_loop)
hook_behavior(id_bhvCelebrationStar, OBJ_LIST_GENACTOR, false, nil, bhv_star_loop)
hook_behavior(id_bhvStarSpawnCoordinates, OBJ_LIST_GENACTOR, false, nil, bhv_star_loop)
hook_behavior(id_bhvSpawnedStar, OBJ_LIST_GENACTOR, false, nil, bhv_star_loop)

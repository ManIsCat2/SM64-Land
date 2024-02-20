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
    nil,
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
    if obj_has_model_extended(o, E_MODEL_TRANSPARENT_STAR) ~= 0 then return end
    if gNetworkPlayers[0].currLevelNum == LEVEL_CCM or gNetworkPlayers[0].currLevelNum == LEVEL_JRB then
        obj_set_model_extended(o, E_MODEL_STAR_W2)
    end
    if (gNetworkPlayers[0].currLevelNum == LEVEL_CASTLE_GROUNDS or gNetworkPlayers[0].currLevelNum == LEVEL_CASTLE_COURTYARD) and worldSpecificStarModels[curWorld] ~= nil then
        obj_set_model_extended(o, worldSpecificStarModels[curWorld])
    end
end

hook_behavior(id_bhvStar, OBJ_LIST_GENACTOR, false, nil, bhv_star_loop)
hook_behavior(id_bhvCelebrationStar, OBJ_LIST_GENACTOR, false, nil, bhv_star_loop)
hook_behavior(id_bhvStarSpawnCoordinates, OBJ_LIST_GENACTOR, false, nil, bhv_star_loop)
hook_behavior(id_bhvSpawnedStar, OBJ_LIST_GENACTOR, false, nil, bhv_star_loop)
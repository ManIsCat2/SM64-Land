-- make stars do color

E_MODEL_STAR2 = smlua_model_util_get_id("star2_geo")

function bhv_star_loop(o)
    if gNetworkPlayers[0].currLevelNum == LEVEL_CCM or gNetworkPlayers[0].currLevelNum == LEVEL_JRB then
        obj_set_model_extended(o, E_MODEL_STAR2)
    end
end

hook_behavior(id_bhvStar, OBJ_LIST_GENACTOR, false, nil, bhv_star_loop)
hook_behavior(id_bhvCelebrationStar, OBJ_LIST_GENACTOR, false, nil, bhv_star_loop)
hook_behavior(id_bhvStarSpawnCoordinates, OBJ_LIST_GENACTOR, false, nil, bhv_star_loop)
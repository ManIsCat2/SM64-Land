#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"
#include "game/level_update.h"
#include "levels/scripts.h"
#include "actors/common1.h"
#include "make_const_nonconst.h"

#include "areas/1/custom.model.inc.h"
#include "areas/2/custom.model.inc.h"
#include "areas/3/custom.model.inc.h"
#include "levels/thi/header.h"
extern u8 _thi_segment_ESegmentRomStart[]; 
extern u8 _thi_segment_ESegmentRomEnd[];
const LevelScript level_thi_entry[] = {
INIT_LEVEL(),
LOAD_RAW(0x0E, _thi_segment_ESegmentRomStart, _thi_segment_ESegmentRomEnd),
LOAD_MIO0(0xA,_SkyboxCustom29858736_skybox_mio0SegmentRomStart,_SkyboxCustom29858736_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
ALLOC_LEVEL_POOL(),
MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
LOAD_MODEL_FROM_GEO(22, warp_pipe_geo),
LOAD_MODEL_FROM_GEO(23, bubbly_tree_geo),
LOAD_MODEL_FROM_GEO(24, spiky_tree_geo),
LOAD_MODEL_FROM_GEO(25, snow_tree_geo),
LOAD_MODEL_FROM_GEO(27, palm_tree_geo),
LOAD_MODEL_FROM_GEO(31, metal_door_geo),
LOAD_MODEL_FROM_GEO(32, hazy_maze_door_geo),
LOAD_MODEL_FROM_GEO(34, castle_door_0_star_geo),
LOAD_MODEL_FROM_GEO(35, castle_door_1_star_geo),
LOAD_MODEL_FROM_GEO(36, castle_door_3_stars_geo),
LOAD_MODEL_FROM_GEO(37, key_door_geo),
LOAD_MODEL_FROM_GEO(38, castle_door_geo),
    LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM,  bob_geo_000458),
// LOAD_MODEL_FROM_GEO(53,0x19000400),
// LOAD_MODEL_FROM_GEO(54,0x19000440),
// LOAD_MODEL_FROM_GEO(55,0x19000460),
// LOAD_MODEL_FROM_GEO(56,0x19000480),
// LOAD_MODEL_FROM_GEO(57,0x190004a0),
// LOAD_MODEL_FROM_GEO(58,0x190003e0),
// LOAD_MODEL_FROM_GEO(59,0x190004e0),
LOAD_MODEL_FROM_GEO(60,thi2_electric_platform_geo),
LOAD_MODEL_FROM_GEO(61,battery_powerup_geo),
LOAD_MODEL_FROM_GEO(62,thi2_spinning_platform_geo),
// LOAD_MODEL_FROM_DL(132,0x08025f08,4),
// LOAD_MODEL_FROM_DL(158,0x0302c8a0,4),
// LOAD_MODEL_FROM_DL(159,0x0302bcd0,4),
// LOAD_MODEL_FROM_DL(161,0x0301cb00,4),
// LOAD_MODEL_FROM_DL(164,0x04032a18,4),
// LOAD_MODEL_FROM_DL(201,0x080048e0,4),
// LOAD_MODEL_FROM_DL(218,0x08024bb8,4),
// LOAD_MODEL_FROM_GEO(239,0x04008090),
// LOAD_MODEL_FROM_GEO(240,0x0040ef00),
// LOAD_MODEL_FROM_GEO(241,0x00405e00),
// LOAD_MODEL_FROM_GEO(242,0x0040eb80),
// LOAD_MODEL_FROM_GEO(243,0x0040fd50),
// LOAD_MODEL_FROM_GEO(244,0x0040ebd0),
// LOAD_MODEL_FROM_GEO(245,0x003767d4),
// LOAD_MODEL_FROM_GEO(246,0x0040ed50),
// LOAD_MODEL_FROM_GEO(247,0x00412a30),
// LOAD_MODEL_FROM_GEO(248,0x00413f50),
// LOAD_MODEL_FROM_GEO(249,0x0040eac0),
// LOAD_MODEL_FROM_GEO(250,0x0040e880),
JUMP_LINK(script_func_global_1),
JUMP_LINK(local_area_thi_1_),
JUMP_LINK(local_area_thi_2_),
FREE_LEVEL_POOL(),
MARIO_POS(1,0,0,0,0),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_thi_1_[] = {
AREA(1,Geo_thi_1_0x1c9ecf0),
TERRAIN(col_thi_1_0xe07eee0),
SET_BACKGROUND_MUSIC(0,44),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_thi_1_),
JUMP_LINK(local_warps_thi_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_thi_1_[] = {
OBJECT_WITH_ACTS(0,-12796,190,12100,0,180,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(55,-12921,961,8193,0,0,0,0x0, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,-11534,959,7827,0,45,0,0x0, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,-11194,1436,5809,0,0,0,0x0, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,14275,2411,-7237,0,0,0,0x0, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,14827,2407,-6190,0,0,0,0x0, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,14281,2411,-5074,0,0,0,0x0, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(122,10206,1932,-766,0,0,0,0x10000, bhvStar,31),
OBJECT_WITH_ACTS(122,-249,3811,-10609,0,0,0,0x1000000, bhvStar,31),
OBJECT_WITH_ACTS(137,13773,2766,-9538,0,0,0,0x70000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(55,12,2418,-10025,0,90,0,0x0, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,1239,2672,-9757,0,90,0,0x0, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,563,2992,-10055,0,90,0,0x0, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(137,5517,1007,-9684,0,270,0,0x40000, bhvCloudFlower,31),
OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x17004e20, Bhv_Custom_0x1300003c,31),
OBJECT_WITH_ACTS(212,-9651,2252,154,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(0,-9956,2293,132,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-10363,2870,-1709,0,90,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-11221,1298,1689,0,67,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(212,-649,4600,434,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(212,-354,4602,284,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(212,-370,4625,-370,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(212,-654,4640,-578,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(212,-1345,4640,-119,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(212,-1269,4625,225,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(192,-11043,2276,-3981,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(192,-10380,1306,-8859,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(192,-6652,694,-9646,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(192,13667,1222,-1064,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(192,15230,1996,-2765,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(192,-10971,1863,-6679,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(192,14756,1453,-1614,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(0,12987,1706,-9630,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-10980,3227,3261,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-8121,0,-1647,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,6476,2112,-10329,25,0,-8,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,7503,2107,-9023,-25,0,-8,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-10274,1430,855,0,0,0,0x0, bhvGoombaTripletSpawner,31),
RETURN()
};
const LevelScript local_warps_thi_1_[] = {
WARP_NODE(10,9,1,0,0),
WARP_NODE(240,26,3,24,0),
WARP_NODE(241,26,3,34,0),
RETURN()
};
const LevelScript local_area_thi_2_[] = {
AREA(2,Geo_thi_2_0x1c9eed0),
TERRAIN(col_thi_2_0xe042e60),
SET_BACKGROUND_MUSIC(0,48),
TERRAIN_TYPE(4),
JUMP_LINK(local_objects_thi_2_),
JUMP_LINK(local_warps_thi_2_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_thi_2_[] = {
OBJECT_WITH_ACTS(0,0,0,269,0,180,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(0,8,108,-2231,0,180,0,0x115d0096, Bhv_Custom_0x07016ae0,31),
OBJECT_WITH_ACTS(0,595,108,-3630,0,180,0,0x115d0096, Bhv_Custom_0x07016ae0,31),
OBJECT_WITH_ACTS(0,-2518,108,-5330,0,180,0,0x115d0096, Bhv_Custom_0x07016ae0,31),
OBJECT_WITH_ACTS(0,-951,108,-4342,0,270,0,0x50110096, Bhv_Custom_0x07016ae0,31),
OBJECT_WITH_ACTS(0,6917,1093,-22714,0,0,0,0x115d0096, Bhv_Custom_0x07016ae0,31),
OBJECT_WITH_ACTS(0,9904,1093,-22659,0,0,0,0x115d0096, Bhv_Custom_0x07016ae0,31),
OBJECT_WITH_ACTS(0,8406,1093,-22657,0,180,0,0x115d0096, Bhv_Custom_0x07016ae0,31),
OBJECT_WITH_ACTS(0,21102,-2314,-23689,0,90,0,0x50110096, Bhv_Custom_0x07016ae0,31),
OBJECT_WITH_ACTS(0,24981,-1562,-24092,0,0,0,0x115d0096, Bhv_Custom_0x07016ae0,31),
OBJECT_WITH_ACTS(0,26394,-2314,-16596,0,270,0,0x5a110096, Bhv_Custom_0x07016ae0,31),
OBJECT_WITH_ACTS(0,26259,-2314,-10564,0,270,0,0x5a110096, Bhv_Custom_0x07016ae0,31),
OBJECT_WITH_ACTS(0,26549,-2223,-3486,0,0,0,0x11980164, Bhv_Custom_0x07016ae0,31),
OBJECT_WITH_ACTS(0,25831,-2223,-3511,0,180,0,0x11980164, Bhv_Custom_0x07016ae0,31),
OBJECT_WITH_ACTS(0,12176,0,-7011,0,0,0,0x0, Bhv_Custom_0x07016ac0,31),
OBJECT_WITH_ACTS(59,-1626,1521,-17216,0,0,0,0x0, Bhv_Custom_0x07016dd0,31),
OBJECT_WITH_ACTS(59,-1630,1521,-12746,0,180,0,0x0, Bhv_Custom_0x07016dd0,31),
OBJECT_WITH_ACTS(59,26276,-2107,-5938,0,0,0,0x0, Bhv_Custom_0x07016dd0,31),
OBJECT_WITH_ACTS(59,26194,-2107,-1351,0,180,0,0x0, Bhv_Custom_0x07016dd0,31),
OBJECT_WITH_ACTS(59,26268,-1784,-4827,0,0,0,0x0, Bhv_Custom_0x07016dd0,31),
OBJECT_WITH_ACTS(60,4208,854,-22571,0,0,0,0x1000000, bhvTHI2ElectricPlatform,31),
OBJECT_WITH_ACTS(60,7646,984,-22589,0,0,0,0x0, bhvTHI2ElectricPlatform,31),
OBJECT_WITH_ACTS(60,9136,984,-22589,0,0,0,0x0, bhvTHI2ElectricPlatform,31),
OBJECT_WITH_ACTS(60,29198,-1861,-18252,0,0,0,0x0, bhvTHI2ElectricPlatform,31),
OBJECT_WITH_ACTS(60,27864,-1861,-18252,0,0,0,0x3f0000, bhvTHI2ElectricPlatform,31),
OBJECT_WITH_ACTS(60,28364,-2595,-10579,0,0,0,0x0, bhvTHI2ElectricPlatform,31),
OBJECT_WITH_ACTS(61,18094,-2045,-22475,0,0,0,0x0, bhvBattreyPowerup,31),
OBJECT_WITH_ACTS(62,21460,-1996,-21914,0,0,0,0x0, bhvTHI2SpinningPlatform,31),
OBJECT_WITH_ACTS(62,23631,-1476,-21911,0,0,0,0x0, bhvTHI2SpinningPlatform,31),
OBJECT_WITH_ACTS(62,26064,-1910,-15199,0,0,0,0x0, bhvTHI2SpinningPlatform,31),
OBJECT_WITH_ACTS(62,27189,-2345,-13838,0,0,0,0x0, bhvTHI2SpinningPlatform,31),
OBJECT_WITH_ACTS(62,26161,-1808,-9433,0,0,0,0x0, bhvTHI2SpinningPlatform,31),
OBJECT_WITH_ACTS(60,26170,-2145,1540,0,0,0,0x460000, bhvTHI2ElectricPlatform,31),
OBJECT_WITH_ACTS(60,26170,-2145,3099,0,0,0,0x280000, bhvTHI2ElectricPlatform,31),
OBJECT_WITH_ACTS(60,26170,-2145,4690,0,0,0,0x280000, bhvTHI2ElectricPlatform,31),
OBJECT_WITH_ACTS(122,24458,-2055,-17496,0,0,0,0x4000000, bhvStar,31),
OBJECT_WITH_ACTS(122,26188,-1307,7206,0,0,0,0x5010000, bhvStar,31),
OBJECT_WITH_ACTS(0,-1,0,-2126,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-2553,0,-5230,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-1604,612,-9484,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,6900,1093,-22641,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,8421,1093,-22641,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,9902,1093,-22641,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,27344,-582,-24345,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,28931,-2595,-12265,0,90,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,27189,-2207,-13838,0,0,0,0x120000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,21460,-1864,-21914,0,0,0,0x120000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,26193,-2145,110,0,0,0,0x40000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,25428,-2176,-7339,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,26899,-2176,-7339,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,13195,-48,-22569,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,14329,-1519,-22533,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x18004e20, Bhv_Custom_0x1300003c,31),
OBJECT_WITH_ACTS(140,26168,-2145,-6758,0,90,0,0x0, bhvBlueCoinSwitch,31),
OBJECT_WITH_ACTS(118,26544,-2223,-5525,0,0,0,0x0, bhvHiddenBlueCoin,31),
OBJECT_WITH_ACTS(118,26525,-2223,-1622,0,0,0,0x0, bhvHiddenBlueCoin,31),
OBJECT_WITH_ACTS(118,26541,-1814,-3511,0,0,0,0x0, bhvHiddenBlueCoin,31),
OBJECT_WITH_ACTS(118,25858,-2223,-5525,0,0,0,0x0, bhvHiddenBlueCoin,31),
OBJECT_WITH_ACTS(118,25839,-2223,-1622,0,0,0,0x0, bhvHiddenBlueCoin,31),
OBJECT_WITH_ACTS(118,25855,-1814,-3511,0,0,0,0x0, bhvHiddenBlueCoin,31),
OBJECT_WITH_ACTS(188,27020,-2089,-23766,0,0,0,0x0, bhvBobomb,31),
OBJECT_WITH_ACTS(188,27297,-2089,-25098,0,0,0,0x0, bhvBobomb,31),
OBJECT_WITH_ACTS(116,-1814,1181,-21553,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-1666,1170,-21749,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-1423,1157,-21979,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-1934,1195,-21200,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-1979,1212,-20830,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-1194,1145,-22159,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-883,1132,-22320,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-564,1121,-22424,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-1980,1225,-20535,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-232,1109,-22526,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(0,27160,-2089,-24797,0,90,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(116,29316,-813,-22962,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,29414,-901,-22609,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,29466,-1016,-22180,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,29511,-1119,-21815,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,29245,-753,-23224,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(0,24983,-1562,-23500,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(239,25778,-2145,-6844,0,0,0,0x0, Bhv_Custom_0x040086a0,31),
///OBJECT_WITH_ACTS(0,60,5,37,0,0,20,5, RM_Scroll_Texture,31),
//OBJECT_WITH_ACTS(0,40,4,560,0,0,20,6, RM_Scroll_Texture,31),
//OBJECT_WITH_ACTS(0,570,5,132,0,0,20,7, RM_Scroll_Texture,31),
RETURN()
};
const LevelScript local_warps_thi_2_[] = {
WARP_NODE(10,9,2,0,0),
WARP_NODE(240,16,4,31,0),
WARP_NODE(241,16,4,21,0),
RETURN()
};

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
#include "levels/ttm/header.h"
extern u8 _ttm_segment_ESegmentRomStart[]; 
extern u8 _ttm_segment_ESegmentRomEnd[];
const LevelScript level_ttm_entry[] = {
INIT_LEVEL(),
LOAD_RAW(0x0E, _ttm_segment_ESegmentRomStart, _ttm_segment_ESegmentRomEnd),
LOAD_MIO0(0xA,_clouds_skybox_mio0SegmentRomStart,_clouds_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
LOAD_MIO0(5,_group11_mio0SegmentRomStart,_group11_mio0SegmentRomEnd),
LOAD_RAW(12,_group11_geoSegmentRomStart,_group11_geoSegmentRomEnd),
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
LOAD_MODEL_FROM_GEO(53,ttm_blue_platform_geo),
// LOAD_MODEL_FROM_GEO(54,0x19000440),
LOAD_MODEL_FROM_GEO(55,cloud_flower_geo),
LOAD_MODEL_FROM_GEO(56,ttm_swingy_thing_geo),
// LOAD_MODEL_FROM_GEO(57,0x190004a0),
// LOAD_MODEL_FROM_GEO(88,0x0500c778),
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
JUMP_LINK(script_func_global_12),
JUMP_LINK(local_area_ttm_1_),
JUMP_LINK(local_area_ttm_2_),
JUMP_LINK(local_area_ttm_3_),
FREE_LEVEL_POOL(),
MARIO_POS(1,0,0,0,0),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_ttm_1_[] = {
AREA(1,ttm_1_geo),
TERRAIN(ttm_1_collision),
SET_BACKGROUND_MUSIC(0,47),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_ttm_1_),
JUMP_LINK(local_warps_ttm_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_ttm_1_[] = {
OBJECT_WITH_ACTS(0,-955,1032,-3606,0,90,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(0,17371,3832,6822,0,0,0,0x960000, bhvPoleGrabbing,31),
OBJECT_WITH_ACTS(0,17427,4415,4192,0,0,0,0x960000, bhvPoleGrabbing,31),
OBJECT_WITH_ACTS(0,17457,4801,3306,0,0,0,0x960000, bhvPoleGrabbing,31),
OBJECT_WITH_ACTS(0,15935,5525,1500,0,0,0,0x960000, bhvPoleGrabbing,31),
OBJECT_WITH_ACTS(53,695,1437,-2255,0,90,0,0x1010000, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(215,-1934,1805,2323,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,1456,2074,5083,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,335,4220,8056,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,2977,3628,2417,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,5647,2084,3261,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-1595,2732,5398,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,3056,2679,3168,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,1579,2246,3345,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(207,1993,2252,2691,0,61,0,0x0, bhvFloorSwitchHiddenObjects,31),
OBJECT_WITH_ACTS(129,2098,2334,2423,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,2098,2534,2223,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,2098,2734,2023,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,2098,2934,1823,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,2298,3134,1823,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(0,2807,2854,5759,0,0,0,0x0, bhvBowserCourseRedCoinStar,31),
OBJECT_WITH_ACTS(122,15700,7265,11635,0,0,0,0x2010000, bhvStar,31),
OBJECT_WITH_ACTS(122,17492,5563,6796,0,0,0,0x1000000, bhvStar,31),
OBJECT_WITH_ACTS(53,-231,1848,-426,0,90,0,0x10001, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,-620,1663,-1313,0,90,0,0x2, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,3134,3339,9198,0,90,0,0x10003, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,11925,3412,12077,0,0,0,0x1000a, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,5674,3315,13227,0,0,0,0x10005, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,5791,3315,11833,0,0,0,0x6, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,7217,3315,10515,0,0,0,0x10007, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,8542,3315,11857,0,0,0,0x8, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,8842,3315,10471,0,0,0,0x10009, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,4260,3315,11831,0,0,0,0x10004, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,6992,3315,11636,0,0,0,0x5, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,11931,3412,10705,0,0,0,0xa, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,13323,3412,11227,0,0,0,0x1000b, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,14667,3412,10724,0,0,0,0x1000c, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,14671,3412,12047,0,0,0,0xc, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,15544,3412,11351,0,0,0,0x1000d, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,15904,7027,2584,0,90,0,0x10006, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,17001,7027,3486,0,90,0,0x2, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,15554,7027,3993,0,90,0,0x10006, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,14302,7027,4017,0,90,0,0xe, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,16610,7027,4864,0,90,0,0x1000c, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,15673,7027,5309,0,90,0,0xf, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,14466,7027,5373,0,90,0,0x10010, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,14612,7027,7232,0,90,0,0x2, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,13264,7027,6898,0,90,0,0x10003, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,13319,7027,8282,0,90,0,0x2, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(53,14651,7027,9051,0,90,0,0x10003, bhvTTMBluePlatform,31),
OBJECT_WITH_ACTS(0,-491,1080,-3223,0,0,0,0x14004e20, Bhv_Custom_0x1300003c,31),
OBJECT_WITH_ACTS(137,17209,3707,11127,0,0,0,0x40000, bhvCloudFlower,31),
OBJECT_WITH_ACTS(137,15544,6886,1080,0,0,0,0x40000, bhvCloudFlower,31),
OBJECT_WITH_ACTS(220,-436,2277,887,0,0,0,0x0, bhvFlyGuy,31),
OBJECT_WITH_ACTS(220,-977,2628,6317,0,0,0,0x0, bhvFlyGuy,31),
OBJECT_WITH_ACTS(220,3378,3210,6771,0,0,0,0x0, bhvFlyGuy,31),
OBJECT_WITH_ACTS(220,17326,3570,9474,0,0,0,0x0, bhvFlyGuy,31),
OBJECT_WITH_ACTS(220,15075,6840,1665,0,0,0,0x0, bhvFlyGuy,31),
OBJECT_WITH_ACTS(0,3377,3219,7303,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-1673,2391,6009,0,62,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,10562,3412,11069,0,62,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,17202,5679,1646,0,62,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(212,14291,7127,5455,0,90,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(0,-718,1957,4393,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(84,2465,2604,4895,0,90,0,0x0, bhvEnemyLakitu,31),
OBJECT_WITH_ACTS(0,-334,3462,8191,0,90,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(243,22275,1680,3912,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,22699,810,9064,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,20325,2820,-2623,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,17517,2550,-5182,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,21539,3180,16167,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,16815,2790,18684,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,12154,0,21411,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,6614,2790,21932,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,13015,810,-6899,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,717,4440,21079,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,9042,0,-9256,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,2736,0,-11151,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,-4305,0,-10693,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,-9022,0,-6314,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,-10839,0,982,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,-9026,0,9223,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,-6868,0,14597,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,-3739,4770,18450,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,1082,0,21813,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,12209,3630,-8267,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,4836,5280,-9669,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,-7071,4230,-5364,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,22912,5670,2657,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,11870,5520,20583,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,24757,6330,10274,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,18850,8190,-6104,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,-10408,4200,5500,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,-6846,7590,10348,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,17602,-390,17186,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,19007,7830,18064,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(244,142,1915,2221,0,0,0,0x0, Bhv_Custom_0x0040ebb0,31),
OBJECT_WITH_ACTS(244,-394,1914,2683,0,0,0,0x0, Bhv_Custom_0x0040ebb0,31),
OBJECT_WITH_ACTS(244,-393,1911,2007,0,0,0,0x0, Bhv_Custom_0x0040ebb0,31),
OBJECT_WITH_ACTS(244,15140,6681,1217,0,0,0,0x0, Bhv_Custom_0x0040ebb0,31),
OBJECT_WITH_ACTS(244,14767,6690,1778,0,0,0,0x0, Bhv_Custom_0x0040ebb0,31),
OBJECT_WITH_ACTS(212,17463,5375,2545,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(0,17395,5990,4249,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(212,17389,6375,3287,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(0,764,1407,-3384,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(84,2951,3584,1641,0,0,0,0x0, bhvEnemyLakitu,31),
OBJECT_WITH_ACTS(0,17183,3442,10984,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(57,-7756,3330,23179,0,90,0,0x0, Bhv_Custom_0x07036180,31),
OBJECT_WITH_ACTS(57,-8046,3330,24343,0,90,0,0x0, Bhv_Custom_0x07036180,31),
OBJECT_WITH_ACTS(57,-8308,3330,21908,0,90,0,0x0, Bhv_Custom_0x07036180,31),
OBJECT_WITH_ACTS(57,-9544,3330,23465,0,90,0,0x0, Bhv_Custom_0x07036180,31),
OBJECT_WITH_ACTS(57,-4804,3330,24550,0,90,0,0x0, Bhv_Custom_0x07036180,31),
OBJECT_WITH_ACTS(57,-4441,3330,23002,0,90,0,0x0, Bhv_Custom_0x07036180,31),
OBJECT_WITH_ACTS(57,-5727,3330,21341,0,90,0,0x0, Bhv_Custom_0x07036180,31),
OBJECT_WITH_ACTS(57,-499,3330,23713,0,90,0,0x0, Bhv_Custom_0x07036180,31),
OBJECT_WITH_ACTS(57,-11904,3330,25368,0,90,0,0x0, Bhv_Custom_0x07036180,31),
OBJECT_WITH_ACTS(57,-1241,3330,21549,0,90,0,0x0, Bhv_Custom_0x07036180,31),
OBJECT_WITH_ACTS(239,10693,3412,11583,0,90,0,0x0, Bhv_Custom_0x040086a0,31),
//start
OBJECT_WITH_ACTS(55,613,1407,-3362,0,90,0,0x0, bhvCloudFlower,31),

RETURN()
};
const LevelScript local_warps_ttm_1_[] = {
WARP_NODE(10,9,1,0,0),
WARP_NODE(240,26,3,21,0),
WARP_NODE(241,26,3,31,0),
RETURN()
};
const LevelScript local_area_ttm_2_[] = {
AREA(2,ttm_2_geo),
TERRAIN(ttm_2_collision),
SET_BACKGROUND_MUSIC(0,43),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_ttm_2_),
JUMP_LINK(local_warps_ttm_2_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_ttm_2_[] = {
OBJECT_WITH_ACTS(0,1144,4,1146,0,0,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(57,779,903,7980,0,229,0,0x28, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(57,2011,1106,10014,0,308,0,0x10000f4, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(57,1074,981,8919,0,128,0,0x10000f4, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(56,10984,3648,16667,0,67,0,0x1e0000, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(56,7437,2896,12161,0,0,0,0x40000, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(56,1111,1341,2403,0,90,0,0x40000, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(56,1111,1541,4616,0,270,0,0x40000, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(0,11376,2279,12437,0,0,0,0x3000000, bhvBowserCourseRedCoinStar,31),
OBJECT_WITH_ACTS(0,9967,16104,6521,0,0,0,0x15004e20, Bhv_Custom_0x1300003c,31),
OBJECT_WITH_ACTS(122,848,13850,3839,0,0,0,0x4010000, bhvStar,31),
OBJECT_WITH_ACTS(215,3734,2096,14840,0,0,0,0x5000000, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,7439,3027,12166,0,0,0,0x5000000, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,9917,3623,16493,0,0,0,0x5000000, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,3403,3532,16044,0,0,0,0x5000000, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,4518,2615,16490,0,0,0,0x5000000, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,10827,2868,17121,0,0,0,0x5000000, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,6825,2054,12168,0,0,0,0x5000000, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,8574,2552,13899,0,0,0,0x5000000, bhvRedCoin,31),
OBJECT_WITH_ACTS(57,1692,903,8063,0,229,0,0x28, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(56,2349,2619,11206,0,90,0,0x40000, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(56,3349,2619,11206,0,270,0,0x40000, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(56,4349,2619,11206,0,90,0,0x40000, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(56,6121,3947,15902,0,0,0,0x140000, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(57,2558,2175,14824,0,161,0,0x50, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(57,2649,2575,15420,0,14,0,0x87, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(57,2660,2975,16096,0,161,0,0x50, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(57,7101,2402,12168,0,0,0,0x14, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(137,14196,5599,6569,0,0,0,0x40000, bhvCloudFlower,31),
OBJECT_WITH_ACTS(56,11612,3172,10056,0,141,0,0x40000, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(56,12137,3372,9231,0,321,0,0x2a0000, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(56,12403,4316,8445,0,141,0,0x40000, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(56,12710,4618,7586,0,321,0,0x40000, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(56,10965,4670,6939,0,231,0,0x40000, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(56,11533,5245,5062,0,51,0,0x40000, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(56,12260,5468,5717,0,231,0,0xa0000, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(56,13183,5667,7182,0,141,0,0xa0000, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(56,16468,6522,622,0,0,0,0xa0000, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(56,17741,6667,-128,0,90,0,0xa0000, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(57,19953,5909,662,0,90,0,0x100000a, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(57,21007,5509,-392,0,180,0,0x100000a, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(57,19953,5909,-1446,0,270,0,0x100000a, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(57,19099,5509,-392,0,0,0,0x100000a, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(57,21007,6309,-392,0,180,0,0x100000a, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(57,19099,6309,-392,0,0,0,0x100000a, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(57,19953,6709,662,0,90,0,0x100000a, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(57,19953,6709,-1446,0,270,0,0x100000a, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(137,14667,11242,3611,0,0,0,0x40000, bhvCloudFlower,31),
OBJECT_WITH_ACTS(56,23054,8288,2013,0,90,0,0x0, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(57,22990,7101,4293,0,0,0,0x7f, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(57,23007,7601,5192,0,0,0,0x80, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(56,22159,9692,7274,0,0,0,0x2c0000, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(57,13516,10931,4096,0,0,0,0x80, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(57,12280,11950,4514,0,90,0,0x12, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(56,12280,12559,4054,0,90,0,0xa0080, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(56,10392,13435,4048,0,0,0,0xa0080, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(57,12280,11950,3594,0,270,0,0x12, Bhv_Custom_0x07012fd0,31),
OBJECT_WITH_ACTS(56,8892,13435,4448,20,180,0,0x80, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(56,5892,13435,4448,20,180,0,0x80, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(56,4392,13435,3648,20,0,0,0x80, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(56,7392,13435,3648,20,0,0,0x80, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(56,3292,13765,4448,0,180,0,0x140080, bhvTTMSSwingingThing,31),
OBJECT_WITH_ACTS(0,1111,495,2403,0,90,0,0x120000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,7025,1743,10796,0,89,0,0x40000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,10379,2541,14888,0,90,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,14811,5349,3986,0,90,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(246,7357,2094,16641,0,0,0,0x0, Bhv_Custom_0x0040ed84,31),
OBJECT_WITH_ACTS(246,4128,2120,13286,0,0,0,0x0, Bhv_Custom_0x0040ed84,31),
OBJECT_WITH_ACTS(246,13776,5349,4318,0,0,0,0x0, Bhv_Custom_0x0040ed84,31),
OBJECT_WITH_ACTS(247,1436,886,6713,0,0,0,0x0, Bhv_Custom_0x00407d30,31),
OBJECT_WITH_ACTS(247,742,49,1395,0,0,0,0x0, Bhv_Custom_0x00407d30,31),
OBJECT_WITH_ACTS(247,632,903,6649,0,76,0,0x0, Bhv_Custom_0x00407d30,31),
OBJECT_WITH_ACTS(247,747,1514,11357,0,0,0,0x0, Bhv_Custom_0x00407d30,31),
OBJECT_WITH_ACTS(247,1233,1486,12064,0,0,0,0x0, Bhv_Custom_0x00407d30,31),
OBJECT_WITH_ACTS(247,8638,1743,10536,0,322,0,0x0, Bhv_Custom_0x00407d30,31),
OBJECT_WITH_ACTS(247,9061,1804,10547,0,288,0,0x0, Bhv_Custom_0x00407d30,31),
OBJECT_WITH_ACTS(247,9510,1856,10560,0,67,0,0x0, Bhv_Custom_0x00407d30,31),
OBJECT_WITH_ACTS(247,9949,1905,10543,0,107,0,0x0, Bhv_Custom_0x00407d30,31),
OBJECT_WITH_ACTS(247,10432,1960,10545,0,0,0,0x0, Bhv_Custom_0x00407d30,31),
OBJECT_WITH_ACTS(247,8148,1743,10427,0,35,0,0x0, Bhv_Custom_0x00407d30,31),
OBJECT_WITH_ACTS(247,15372,5349,7246,0,0,0,0x0, Bhv_Custom_0x00407d30,31),
OBJECT_WITH_ACTS(247,15761,5349,7213,0,23,0,0x0, Bhv_Custom_0x00407d30,31),
OBJECT_WITH_ACTS(247,13931,5349,2246,0,31,0,0x0, Bhv_Custom_0x00407d30,31),
OBJECT_WITH_ACTS(0,15614,5349,1356,0,90,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,4970,2557,15606,0,90,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,8546,3331,16032,0,90,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,17748,5778,-130,0,90,0,0x120000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,23066,7407,2016,0,90,0,0x120000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,22860,8113,6536,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,845,13650,3850,0,90,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,21814,10050,6315,0,256,0,0x40000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,12280,11666,4085,0,0,0,0x120000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,8718,2152,14033,0,308,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,10012,2002,11749,0,308,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,14009,5349,4265,0,308,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,6380,2313,14314,0,308,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(247,13764,5349,2691,0,84,0,0x0, Bhv_Custom_0x00407d30,31),
OBJECT_WITH_ACTS(247,13672,5349,3122,0,138,0,0x0, Bhv_Custom_0x00407d30,31),
OBJECT_WITH_ACTS(239,13450,5349,5866,0,0,0,0x0, Bhv_Custom_0x040086a0,31),
RETURN()
};
const LevelScript local_warps_ttm_2_[] = {
WARP_NODE(10,9,2,0,0),
WARP_NODE(240,26,3,22,0),
WARP_NODE(241,26,3,32,0),
RETURN()
};

const LevelScript local_area_ttm_3_[] = {
	AREA(3, ttm_3_geo),
	TERRAIN(ttm_3_collision),
	SET_BACKGROUND_MUSIC(0, 9),
	TERRAIN_TYPE(TERRAIN_GRASS),
	JUMP_LINK(local_objects_ttm_3_),
	JUMP_LINK(local_warps_ttm_3_),
	END_AREA(),
	RETURN(),
};

const LevelScript local_objects_ttm_3_[] = {
	OBJECT_WITH_ACTS(0, -3375, 78, 2672, 0, 180, 0, 0xa0000, bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(137, -1923, 1190, -2290, 0, 0, 0, 0x40000, bhvCloudFlower, 31),
	OBJECT_WITH_ACTS(53, -2059, 5163, -460, 0, 90, 0, 0x2, bhvTTMBluePlatform, 31),
	OBJECT_WITH_ACTS(53, -1045, 5163, 689, 0, 90, 0, 0x3010002, bhvTTMBluePlatform, 31),
	OBJECT_WITH_ACTS(53, 156, 5163, -721, 0, 270, 0, 0x2, bhvTTMBluePlatform, 31),
	OBJECT_WITH_ACTS(53, 961, 5163, 432, 0, 90, 0, 0x10002, bhvTTMBluePlatform, 31),
	OBJECT_WITH_ACTS(0, -2747, 602, 111, 0, 0, 0, 0x960000, bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(22, 3364, 5441, 681, 0, 270, 0, 0x50000, bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(212, -2965, -105, 2956, 0, 0, 0, 0x0, bhv1Up, 31),
	OBJECT_WITH_ACTS(0, -2314, 1366, -1679, 0, 0, 0, 0x110000, bhvCoinFormation, 31),
	RETURN(),
};

const LevelScript local_warps_ttm_3_[] = {
	WARP_NODE(10,7,3,5,0),
	WARP_NODE(5,13,3,10,0),
	WARP_NODE(240,6,1,50,0),
	WARP_NODE(241,26,4,102,0),
	RETURN(),
};


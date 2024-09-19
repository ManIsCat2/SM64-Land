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
#include "areas/4/custom.model.inc.h"
#include "levels/bob/header.h"
extern u8 _bob_segment_ESegmentRomStart[]; 
extern u8 _bob_segment_ESegmentRomEnd[];
const LevelScript level_bob_entry[] = {
INIT_LEVEL(),
LOAD_MIO0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd),
LOAD_RAW(0x1A, _bobSegmentRomStart, _bobSegmentRomEnd),
LOAD_RAW(0x0E, _bob_segment_ESegmentRomStart, _bob_segment_ESegmentRomEnd),
LOAD_MIO0(0xA,_clouds_skybox_mio0SegmentRomStart,_clouds_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
LOAD_MIO0(5,_group11_mio0SegmentRomStart,_group11_mio0SegmentRomEnd),
LOAD_RAW(12,_group11_geoSegmentRomStart,_group11_geoSegmentRomEnd),
LOAD_MIO0(6,_group14_mio0SegmentRomStart,_group14_mio0SegmentRomEnd),
LOAD_RAW(13,_group14_geoSegmentRomStart,_group14_geoSegmentRomEnd),
ALLOC_LEVEL_POOL(),
MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE,      bubbly_tree_geo),
    LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440),
    LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM,  bob_geo_000458),
    LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS,      bob_geo_000470),
LOAD_MODEL_FROM_GEO(22, warp_pipe_geo),
LOAD_MODEL_FROM_GEO(23, bubbly_tree_geo),
LOAD_MODEL_FROM_GEO(24, spiky_tree_geo),
LOAD_MODEL_FROM_GEO(25, snow_tree_geo),
LOAD_MODEL_FROM_GEO(27, palm_tree_geo),
LOAD_MODEL_FROM_GEO(31, metal_door_geo),
LOAD_MODEL_FROM_GEO(32, hazy_maze_door_geo),
LOAD_MODEL_FROM_GEO(34, castle_door_0_star_geo),
// LOAD_MODEL_FROM_GEO(35,0x19000400),
LOAD_MODEL_FROM_GEO(36, castle_door_3_stars_geo),
LOAD_MODEL_FROM_GEO(37, key_door_geo),
LOAD_MODEL_FROM_GEO(38, castle_door_geo),
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
// LOAD_MODEL_FROM_GEO(E_MODEL_KICKABLE_ROCK,0x0040ebd0),
// LOAD_MODEL_FROM_GEO(245,0x003767d4),
// LOAD_MODEL_FROM_GEO(E_MODEL_UNCLIMBABLE_TREE,0x0040ed50),
// LOAD_MODEL_FROM_GEO(247,0x00412a30),
// LOAD_MODEL_FROM_GEO(248,0x00413f50),
// LOAD_MODEL_FROM_GEO(249,0x0040eac0),
// LOAD_MODEL_FROM_GEO(250,0x0040e880),
JUMP_LINK(script_func_global_1),
JUMP_LINK(script_func_global_12),
JUMP_LINK(script_func_global_15),
JUMP_LINK(local_area_bob_1_),
JUMP_LINK(local_area_bob_2_),
JUMP_LINK(local_area_bob_3_),
JUMP_LINK(local_area_bob_4_),
FREE_LEVEL_POOL(),
MARIO_POS(2,90,-10345,500,-21),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_bob_1_[] = {
AREA(1,Geo_bob_1_0x1351a50),
TERRAIN(col_bob_1_0xe06c460),
SET_BACKGROUND_MUSIC(0,3),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_bob_1_),
JUMP_LINK(local_warps_bob_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_bob_1_[] = {
OBJECT_WITH_ACTS(0,-1674,773,12523,0,180,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(137,4519,2066,9048,0,0,0,0x0, bhvExclamationBox,31),
OBJECT_WITH_ACTS(55,52,1469,9760,0,90,0,0x30000, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,9114,2161,9822,0,0,0,0x30000, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,9849,2306,9824,0,0,0,0x30000, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,12512,2368,9850,0,0,0,0x30000, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,11420,2309,10361,0,90,0,0x30000, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,11143,2309,9225,0,90,0,0x30000, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,16255,3501,8486,0,90,0,0x30000, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,20399,4292,8477,0,90,0,0x30000, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,139,5180,6493,0,90,0,0x30000, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,1254,5506,5948,0,90,0,0x30000, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,2428,5836,6486,0,90,0,0x30000, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,3728,1496,9757,0,90,0,0x30000, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,5631,1815,9772,0,90,0,0x30000, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,16235,7416,-1921,0,0,0,0x30001, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,16217,7438,-5025,0,0,0,0x30001, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,16223,7911,-8236,0,0,1,0x30001, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,16277,7911,-11246,0,0,0,0x30001, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(122,7358,5653,6234,0,0,0,0x0, bhvStar,31),
OBJECT_WITH_ACTS(122,16483,8306,-15470,0,0,0,0x1010000, bhvStar,31),
OBJECT_WITH_ACTS(217,12725,1437,9077,0,0,0,0x0, bhvPushableMetalBox,31),
OBJECT_WITH_ACTS(55,23822,6891,4741,0,90,0,0x30001, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(0,13445,2816,10438,0,0,0,0x2000000, bhvBowserCourseRedCoinStar,31),
OBJECT_WITH_ACTS(215,9102,2243,9081,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,9839,2474,10583,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,9853,2474,9021,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,10394,2585,9232,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,12184,2585,10355,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,12510,3154,10565,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,12517,2499,9083,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,9127,2243,10528,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(217,8802,1437,9064,0,0,0,0x0, bhvPushableMetalBox,31),
OBJECT_WITH_ACTS(0,60,1688,9795,0,90,0,0x100000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,7394,2243,9875,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,2308,1475,9816,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,16296,2568,10043,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,18217,4175,8382,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,20447,2486,9926,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,18312,2566,10449,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,18312,2566,9449,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-1623,5134,6373,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,4729,3716,8311,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,948,4677,7704,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(192,14253,2563,9853,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(0,23073,3126,10185,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(192,23595,5064,8303,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(0,17975,7455,3280,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,15005,6919,6920,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(140,15223,6919,6814,0,0,0,0x0, bhvBlueCoinSwitch,31),
OBJECT_WITH_ACTS(118,14197,6919,6138,0,0,0,0x0, bhvHiddenBlueCoin,31),
OBJECT_WITH_ACTS(118,16170,6919,6137,0,0,0,0x0, bhvHiddenBlueCoin,31),
OBJECT_WITH_ACTS(118,14175,6919,7578,0,0,0,0x0, bhvHiddenBlueCoin,31),
OBJECT_WITH_ACTS(118,16188,6919,7575,0,0,0,0x0, bhvHiddenBlueCoin,31),
OBJECT_WITH_ACTS(0,20316,7027,6804,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,24099,6097,5678,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,16235,7749,-2585,0,0,0,0x130000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,16277,8295,-8962,0,0,0,0x130000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(102,5880,3157,7200,0,0,0,0x0, bhvChainChomp,31),
OBJECT_WITH_ACTS(212,5880,3362,7200,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(129,3783,3157,6566,0,0,0,0x10000, bhvBreakableBox,31),
OBJECT_WITH_ACTS(202,15942,7665,-6580,0,0,0,0x0, bhvCheckerboardElevatorGroup,31),
OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x4e20, Bhv_Custom_0x1300003c,31),
OBJECT_WITH_ACTS(187,-1026,1296,10679,0,0,0,0x0, bhvEndBirds1,31),
OBJECT_WITH_ACTS(187,2577,1497,10651,0,0,0,0x0, bhvEndBirds1,31),
OBJECT_WITH_ACTS(187,18068,2592,9286,0,0,0,0x0, bhvEndBirds1,31),
OBJECT_WITH_ACTS(187,23715,5082,7823,0,0,0,0x0, bhvEndBirds1,31),
OBJECT_WITH_ACTS(187,-1050,5167,6556,0,0,0,0x0, bhvEndBirds1,31),
OBJECT_WITH_ACTS(187,7298,2275,10165,0,0,0,0x0, bhvEndBirds1,31),
OBJECT_WITH_ACTS(187,18613,7490,1567,0,0,0,0x0, bhvEndBirds1,31),
OBJECT_WITH_ACTS(187,27537,6685,5817,0,0,0,0x0, bhvEndBirds1,31),
OBJECT_WITH_ACTS(187,26991,6686,6290,0,0,0,0x0, bhvEndBirds1,31),
OBJECT_WITH_ACTS(E_MODEL_FLOWER,-2290,1043,11320,0,0,0,0x30000, id_bhvFlower,31),
OBJECT_WITH_ACTS(E_MODEL_FLOWER,1263,1712,9153,0,0,0,0x20000, id_bhvFlower,31),
OBJECT_WITH_ACTS(E_MODEL_FLOWER,5910,1050,10255,0,0,0,0x30000, id_bhvFlower,31),
OBJECT_WITH_ACTS(E_MODEL_FLOWER,8237,2243,9189,0,0,0,0x40000, id_bhvFlower,31),
OBJECT_WITH_ACTS(E_MODEL_FLOWER,15095,2564,9127,0,0,0,0x30000, id_bhvFlower,31),
OBJECT_WITH_ACTS(E_MODEL_FLOWER,19397,2566,8701,0,0,0,0x20000, id_bhvFlower,31),
OBJECT_WITH_ACTS(E_MODEL_FLOWER,20765,2566,8638,0,0,0,0x20000, id_bhvFlower,31),
OBJECT_WITH_ACTS(E_MODEL_FLOWER,24681,3126,9788,0,0,0,0x30000, id_bhvFlower,31),
OBJECT_WITH_ACTS(E_MODEL_FLOWER,26416,4392,6744,0,0,0,0x20000, id_bhvFlower,31),
OBJECT_WITH_ACTS(E_MODEL_FLOWER,1860,4677,6793,0,0,0,0x20000, id_bhvFlower,31),
OBJECT_WITH_ACTS(E_MODEL_FLOWER,1610,4677,7531,0,0,0,0x20000, id_bhvFlower,31),
OBJECT_WITH_ACTS(243,1778,1747,18273,0,0,0,0xfe000000, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,431,5730,-844,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,12384,4440,20357,0,0,0,0xfa000000, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,18635,2430,18556,0,0,0,0xfa000000, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,26730,4530,18595,0,0,0,0xfc000000, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,32019,2977,21000,0,0,0,0xfb000000, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,26797,6750,-6870,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,27023,6840,-18575,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,19393,7830,-27668,0,0,0,0x0, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,31501,6750,443,0,0,0,0xff00, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(243,-13326,2884,16666,0,0,0,0xfc000000, Bhv_Custom_0x0040fdb4,31),
OBJECT_WITH_ACTS(E_MODEL_KICKABLE_ROCK,-1332,773,12391,0,0,0,0x0, id_bhvKickableRock,31),
OBJECT_WITH_ACTS(E_MODEL_KICKABLE_ROCK,5030,968,10294,0,0,0,0x0, id_bhvKickableRock,31),
OBJECT_WITH_ACTS(E_MODEL_KICKABLE_ROCK,11976,1437,10350,0,0,0,0x0, id_bhvKickableRock,31),
OBJECT_WITH_ACTS(E_MODEL_KICKABLE_ROCK,17566,2566,10352,0,0,0,0x0, id_bhvKickableRock,31),
OBJECT_WITH_ACTS(E_MODEL_KICKABLE_ROCK,17532,2566,9651,0,0,0,0x0, id_bhvKickableRock,31),
OBJECT_WITH_ACTS(E_MODEL_KICKABLE_ROCK,5367,3157,6645,0,0,0,0x0, id_bhvKickableRock,31),
OBJECT_WITH_ACTS(E_MODEL_KICKABLE_ROCK,4625,3157,7434,0,0,0,0x0, id_bhvKickableRock,31),
OBJECT_WITH_ACTS(E_MODEL_KICKABLE_ROCK,-1841,1211,9288,0,0,0,0x0, id_bhvKickableRock,31),
OBJECT_WITH_ACTS(E_MODEL_KICKABLE_ROCK,26364,3572,9483,0,0,0,0x0, id_bhvKickableRock,31),
OBJECT_WITH_ACTS(E_MODEL_KICKABLE_ROCK,26676,6607,4779,0,0,0,0x0, id_bhvKickableRock,31),
OBJECT_WITH_ACTS(E_MODEL_UNCLIMBABLE_TREE,-509,1050,10524,0,0,0,0x0, id_bhvUnclimbableTree,31),
OBJECT_WITH_ACTS(E_MODEL_UNCLIMBABLE_TREE,2209,1475,9306,0,0,0,0x0, id_bhvUnclimbableTree,31),
OBJECT_WITH_ACTS(E_MODEL_UNCLIMBABLE_TREE,15397,2565,10481,0,0,0,0x0, id_bhvUnclimbableTree,31),
OBJECT_WITH_ACTS(E_MODEL_UNCLIMBABLE_TREE,24475,3126,10498,0,0,0,0x0, id_bhvUnclimbableTree,31),
OBJECT_WITH_ACTS(E_MODEL_UNCLIMBABLE_TREE,-1045,829,11458,0,0,0,0x0, id_bhvUnclimbableTree,31),
OBJECT_WITH_ACTS(E_MODEL_UNCLIMBABLE_TREE,21719,7027,6393,0,0,0,0x0, id_bhvUnclimbableTree,31),
OBJECT_WITH_ACTS(E_MODEL_UNCLIMBABLE_TREE,21712,7027,7355,0,0,0,0x0, id_bhvUnclimbableTree,31),
OBJECT_WITH_ACTS(E_MODEL_UNCLIMBABLE_TREE,19898,7455,1181,0,0,0,0x0, id_bhvUnclimbableTree,31),
OBJECT_WITH_ACTS(E_MODEL_UNCLIMBABLE_TREE,27394,6663,4845,0,0,0,0x0, id_bhvUnclimbableTree,31),
OBJECT_WITH_ACTS(E_MODEL_UNCLIMBABLE_TREE,17380,7847,-15722,0,0,0,0x0, id_bhvUnclimbableTree,31),
OBJECT_WITH_ACTS(E_MODEL_CHECKPOINT,16445,7455,971,0,0,0,0x0, id_bhvCheckpoint,31),
RETURN()
};
const LevelScript local_warps_bob_1_[] = {
WARP_NODE(10,9,1,0,0),
WARP_NODE(240,16,1,21,0),
WARP_NODE(241,16,1,31,0),
RETURN()
};
const LevelScript local_area_bob_2_[] = {
AREA(2,Geo_bob_2_0x1351c30),
TERRAIN(col_bob_2_0xe0496a0),
SET_BACKGROUND_MUSIC(0,68),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_bob_2_),
JUMP_LINK(local_warps_bob_2_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_bob_2_[] = {
OBJECT_WITH_ACTS(0,-10345,500,-21,0,90,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(122,-9006,558,-28971,0,0,0,0x5010000, bhvStar,31),
OBJECT_WITH_ACTS(0,-2522,4499,-4482,0,0,0,0x4000000, bhvBowserCourseRedCoinStar,31),
OBJECT_WITH_ACTS(215,-11032,4259,-3920,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-5516,3106,-4836,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-8444,3258,-3785,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-4403,3525,-2569,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-6494,2955,-3025,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-9384,3702,-2517,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-2562,4259,-3034,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-3710,3913,-4008,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(0,-1038,1246,-740,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-9047,-284,-19793,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(E_MODEL_CHAIN_CHOMP,-9702,3880,-4850,0,0,0,0x0, bhvStarDoor,31),
OBJECT_WITH_ACTS(E_MODEL_CHAIN_CHOMP,-9026,3501,-4002,0,0,0,0x0, bhvStarDoor,31),
OBJECT_WITH_ACTS(E_MODEL_CHAIN_CHOMP,-9542,3790,-2551,0,0,0,0x0, bhvStarDoor,31),
OBJECT_WITH_ACTS(E_MODEL_CHAIN_CHOMP,-3651,3946,-4408,0,0,0,0x0, bhvStarDoor,31),
OBJECT_WITH_ACTS(E_MODEL_CHAIN_CHOMP,-4241,3615,-3079,0,0,0,0x0, bhvStarDoor,31),
OBJECT_WITH_ACTS(0,-973,2048,-6825,0,0,0,0x20000, bhvStarDoor,31),
OBJECT_WITH_ACTS(0,-11045,2902,-2628,0,0,0,0x20000, bhvStarDoor,31),
OBJECT_WITH_ACTS(212,-1858,4285,-2043,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(E_MODEL_CHAIN_CHOMP,-9740,137,-21692,0,0,0,0x100, bhvStarDoor,31),
OBJECT_WITH_ACTS(E_MODEL_CHAIN_CHOMP,-8334,336,-24390,0,0,0,0x100, bhvStarDoor,31),
OBJECT_WITH_ACTS(E_MODEL_CHAIN_CHOMP,-9779,690,-27641,0,0,0,0x100, bhvStarDoor,31),
OBJECT_WITH_ACTS(E_MODEL_CHAIN_CHOMP,-4746,703,-5,0,0,0,0x0, bhvStarDoor,31),
OBJECT_WITH_ACTS(E_MODEL_CHAIN_CHOMP,-5765,2149,-958,0,0,0,0x0, bhvStarDoor,31),
OBJECT_WITH_ACTS(E_MODEL_CHAIN_CHOMP,-2487,1564,-1352,0,0,0,0x0, bhvStarDoor,31),
OBJECT_WITH_ACTS(E_MODEL_CHAIN_CHOMP,-8288,2502,-1409,0,0,0,0x0, bhvStarDoor,31),
OBJECT_WITH_ACTS(E_MODEL_CHAIN_CHOMP,-9729,2634,-1475,0,0,0,0x0, bhvStarDoor,31),
OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x3004e20, Bhv_Custom_0x1300003c,31),
OBJECT_WITH_ACTS(E_MODEL_UNCLIMBABLE_TREE,-2343,4259,-2636,0,0,0,0x0, id_bhvUnclimbableTree,31),
OBJECT_WITH_ACTS(E_MODEL_UNCLIMBABLE_TREE,-2282,4259,-3142,0,0,0,0x0, id_bhvUnclimbableTree,31),
OBJECT_WITH_ACTS(E_MODEL_UNCLIMBABLE_TREE,-8619,-284,-19439,0,0,0,0x0, id_bhvUnclimbableTree,31),
OBJECT_WITH_ACTS(E_MODEL_UNCLIMBABLE_TREE,-11762,2916,-685,0,0,0,0x0, id_bhvUnclimbableTree,31),
OBJECT_WITH_ACTS(E_MODEL_UNCLIMBABLE_TREE,-11509,4259,-2481,0,0,0,0x0, id_bhvUnclimbableTree,31),
OBJECT_WITH_ACTS(E_MODEL_UNCLIMBABLE_TREE,-8407,337,-28403,0,0,0,0x0, id_bhvUnclimbableTree,31),
OBJECT_WITH_ACTS(242,-1798,1224,310,0,0,0,0x0, Bhv_Custom_0x0040eb00,31),
OBJECT_WITH_ACTS(242,-310,1475,-1798,0,0,0,0x0, Bhv_Custom_0x0040eb00,31),
OBJECT_WITH_ACTS(242,-10038,500,235,0,0,0,0x0, Bhv_Custom_0x0040eb00,31),
OBJECT_WITH_ACTS(242,-10357,2644,-705,0,0,0,0x0, Bhv_Custom_0x0040eb00,31),
OBJECT_WITH_ACTS(242,-9950,2644,-702,0,0,0,0x0, Bhv_Custom_0x0040eb00,31),
OBJECT_WITH_ACTS(242,-345,1571,-2452,0,0,0,0x0, Bhv_Custom_0x0040eb00,31),
OBJECT_WITH_ACTS(242,-339,1619,-2979,0,0,0,0x0, Bhv_Custom_0x0040eb00,31),
OBJECT_WITH_ACTS(242,-9551,-491,-19315,0,0,0,0x0, Bhv_Custom_0x0040eb00,31),
OBJECT_WITH_ACTS(E_MODEL_KICKABLE_ROCK,-463,1682,-3691,0,0,0,0x0, id_bhvKickableRock,31),
OBJECT_WITH_ACTS(E_MODEL_KICKABLE_ROCK,-10554,-284,-20258,0,0,0,0x0, id_bhvKickableRock,31),
OBJECT_WITH_ACTS(E_MODEL_KICKABLE_ROCK,-9604,-284,-19379,0,0,0,0x0, id_bhvKickableRock,31),
OBJECT_WITH_ACTS(E_MODEL_KICKABLE_ROCK,-619,1224,199,0,0,0,0x0, id_bhvKickableRock,31),
OBJECT_WITH_ACTS(0,3486,1895,-5612,0,90,0,0x20000, bhvStarDoor,31),
OBJECT_WITH_ACTS(0,3841,1144,-9267,0,90,0,0x20000, bhvStarDoor,31),
OBJECT_WITH_ACTS(0,1066,1007,-11093,0,90,0,0x20000, bhvStarDoor,31),
OBJECT_WITH_ACTS(0,3059,715,-13171,0,90,0,0x20000, bhvStarDoor,31),
OBJECT_WITH_ACTS(0,-893,145,-15041,0,90,0,0x20000, bhvStarDoor,31),
OBJECT_WITH_ACTS(0,-2881,-116,-12410,0,90,0,0x20000, bhvStarDoor,31),
OBJECT_WITH_ACTS(0,-4473,-109,-14867,0,90,0,0x20000, bhvStarDoor,31),
OBJECT_WITH_ACTS(0,-6496,-150,-12450,0,90,0,0x20000, bhvStarDoor,31),
OBJECT_WITH_ACTS(212,-2831,-169,-12829,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(0,-2459,-558,-13669,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-10472,-537,-18386,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(192,-9393,-162,-24142,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(192,-8754,94,-27222,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(116,-8280,281,30,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-8080,540,30,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-7880,617,30,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-7680,640,30,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-7480,578,30,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-7280,488,30,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-4353,1857,-737,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-4553,1896,-937,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-4753,1936,-1137,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-4953,1977,-1337,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-5153,2019,-1537,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-5353,2061,-1737,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-5553,2104,-1537,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-5753,2146,-1337,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-5953,2188,-1137,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-6153,2273,-937,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-6353,2273,-737,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-6553,2313,-937,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-6753,2335,-1137,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-6953,2357,-1337,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-7153,2379,-1537,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(187,-10307,536,-330,0,0,0,0x0, bhvEndBirds1,31),
OBJECT_WITH_ACTS(187,-1315,1260,287,0,194,0,0x0, bhvEndBirds1,31),
OBJECT_WITH_ACTS(187,-1045,1260,215,0,232,0,0x0, bhvEndBirds1,31),
OBJECT_WITH_ACTS(187,-11827,4295,-4137,0,248,0,0x0, bhvEndBirds1,31),
OBJECT_WITH_ACTS(187,-11843,4295,-3628,0,56,0,0x0, bhvEndBirds1,31),
OBJECT_WITH_ACTS(187,-2066,4295,-4715,0,183,0,0x0, bhvEndBirds1,31),
OBJECT_WITH_ACTS(187,-1999,4295,-4446,0,216,0,0x0, bhvEndBirds1,31),
OBJECT_WITH_ACTS(187,-2063,4295,-3627,0,316,0,0x0, bhvEndBirds1,31),
OBJECT_WITH_ACTS(187,-289,1718,-5231,0,248,0,0x0, bhvEndBirds1,31),
RETURN()
};
const LevelScript local_warps_bob_2_[] = {
WARP_NODE(10,9,2,0,0),
WARP_NODE(240,16,1,24,0),
WARP_NODE(241,16,1,34,0),
RETURN()
};
const LevelScript local_area_bob_3_[] = {
AREA(3,Geo_bob_3_0x1351e10),
TERRAIN(col_bob_3_0xe009510),
SET_BACKGROUND_MUSIC(0,57),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_bob_3_),
JUMP_LINK(local_warps_bob_3_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_bob_3_[] = {
OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(E_MODEL_KING_GOOMBA,0,0,0,0,0,0,(3 << 24), id_bhvKingGoomba,31),
OBJECT_WITH_ACTS(192,-381,200,-2242,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-1137,200,-1915,0,0,0,0x1, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-1790,200,-1297,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-2040,200,-731,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-2305,200,106,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,200,200,-2264,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,845,200,-1941,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,1468,200,-1693,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,1855,200,-1339,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,1901,200,-962,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,2335,200,-79,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,2345,200,321,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,1937,200,1126,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,1574,200,1691,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,996,200,2041,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,102,200,2249,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-572,200,2132,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-1468,200,1696,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-1870,200,1332,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-2053,200,758,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-2064,400,1888,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-2346,400,1286,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-2537,400,767,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-2715,400,381,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-2875,400,21,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-2718,400,-401,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-1506,400,2313,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-919,400,2508,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-96,400,2752,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,452,400,2675,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,1107,400,2366,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,1985,400,1924,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,2324,400,1439,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,2540,400,974,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,2636,400,530,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,2841,400,101,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,2676,400,-350,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,2494,400,-954,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,2233,400,-1407,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,1861,400,-2017,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,1159,400,-2356,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,589,400,-2625,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,42,400,-2746,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-2471,400,-956,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-2227,400,-1608,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-2003,400,-2002,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-1571,400,-2276,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-1157,400,-2376,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-567,400,-2608,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(192,-225,400,-2762,0,0,0,0x0, Bhv_Custom_0x070023d0,31),
OBJECT_WITH_ACTS(35,-23,0,471,0,180,0,0x3010000, Bhv_Custom_0x070013e0,31),
OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x0, Bhv_Custom_0x00377ef0,31),
RETURN()
};
const LevelScript local_warps_bob_3_[] = {
WARP_NODE(10,9,3,0,0),
WARP_NODE(240,16,1,108,0),
WARP_NODE(241,16,1,109,0),
RETURN()
};

const LevelScript local_area_bob_4_[] = {
	AREA(4, bob_4_geo),
	TERRAIN(bob_4_collision),
	SET_BACKGROUND_MUSIC(0, 9),
	TERRAIN_TYPE(TERRAIN_GRASS),
	JUMP_LINK(local_objects_bob_4_),
	JUMP_LINK(local_warps_bob_4_),
	END_AREA(),
	RETURN(),
};

const LevelScript local_objects_bob_4_[] = {
	OBJECT_WITH_ACTS(0, -7454, 1380, 4551, 0, 90, 0, 0xa0000, bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(55, -2957, 1309, 3966, 0, 90, 0, 0x30001, bhvSeesawPlatform, 31),
	OBJECT_WITH_ACTS(55, -380, 1982, 3989, 0, 90, 0, 0x30001, bhvSeesawPlatform, 31),
	OBJECT_WITH_ACTS(137, 1630, 3476, 3408, 0, 0, 0, 0x0, bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(55, 13248, 3776, 3913, 0, 90, 0, 0x30001, bhvSeesawPlatform, 31),
	OBJECT_WITH_ACTS(22, 23085, 3533, 1152, 0, 0, 0, 0x50000, bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(0, 0, 0, 0, 0, 0, 0, 0x1005520, bhvCustom0x00377c40, 31),
	OBJECT_WITH_ACTS(0, 0, 0, 0, 0, 0, 0, 0x0, bhvCustom0x0041f3e0, 31),
	OBJECT_WITH_ACTS(0, 23095, 3533, 1095, 0, 0, 0, 0x0, bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, 0, 0, 0, 0, 0, 0, 0x20004e20, bhvCustom0x1300003c, 31),
	RETURN(),
};

const LevelScript local_warps_bob_4_[] = {
	WARP_NODE(10,9,4,0,0),
	WARP_NODE(5,12,3,10,0),
	WARP_NODE(240,6,1,50,0),
	WARP_NODE(241,26,4,102,0),
	RETURN(),
};


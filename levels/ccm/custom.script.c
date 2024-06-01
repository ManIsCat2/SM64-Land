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
#include "levels/ccm/header.h"
extern u8 _ccm_segment_ESegmentRomStart[]; 
extern u8 _ccm_segment_ESegmentRomEnd[];
#include "levels/bob/header.h"
const LevelScript level_ccm_entry[] = {
INIT_LEVEL(),
LOAD_MIO0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd),
LOAD_RAW(0x1A, _bobSegmentRomStart, _bobSegmentRomEnd),
LOAD_RAW(0x0E, _ccm_segment_ESegmentRomStart, _ccm_segment_ESegmentRomEnd),
LOAD_MIO0(0xA,_ssl_skybox_mio0SegmentRomStart,_ssl_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
LOAD_MIO0(5,_group5_mio0SegmentRomStart,_group5_mio0SegmentRomEnd),
LOAD_RAW(12,_group5_geoSegmentRomStart,_group5_geoSegmentRomEnd),
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
LOAD_MODEL_FROM_GEO(35, castle_door_1_star_geo),
LOAD_MODEL_FROM_GEO(36, castle_door_3_stars_geo),
LOAD_MODEL_FROM_GEO(37, key_door_geo),
LOAD_MODEL_FROM_GEO(38, castle_door_geo),
// LOAD_MODEL_FROM_GEO(53,0x19000200),
// LOAD_MODEL_FROM_GEO(56,0x19000280),
// LOAD_MODEL_FROM_GEO(64,0x19000220),
// LOAD_MODEL_FROM_GEO(65,0x19000250),
// LOAD_MODEL_FROM_GEO(86,0x05014630),
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
JUMP_LINK(script_func_global_6),
JUMP_LINK(local_area_ccm_1_),
JUMP_LINK(local_area_ccm_2_),
JUMP_LINK(local_area_ccm_3_),
FREE_LEVEL_POOL(),
MARIO_POS(1,0,0,0,0),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_ccm_1_[] = {
AREA(1,Geo_ccm_1_0x157c680),
TERRAIN(col_ccm_1_0xe037a60),
SET_BACKGROUND_MUSIC(0,12),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_ccm_1_),
JUMP_LINK(local_warps_ccm_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_ccm_1_[] = {
OBJECT_WITH_ACTS(0,-12429,860,13230,0,90,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(55,-10939,1193,12662,0,90,0,0x30000, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,-10021,1312,13164,0,90,0,0x30000, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,-6913,1413,12856,0,90,0,0x30001, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,-2882,1694,6755,0,0,0,0x30001, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,-1933,3023,-680,0,0,0,0x30000, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,-11247,921,-2191,0,90,0,0x30001, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,-13379,959,-1103,0,0,0,0x30000, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,-15739,1023,-78,0,90,0,0x30001, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(55,-16748,1013,-994,0,90,0,0x30001, bhvSeesawPlatform,31),
OBJECT_WITH_ACTS(137,-4402,3083,10549,0,0,0,0x10000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(122,-20979,1235,-998,0,0,0,0x10000, bhvStar,31),
OBJECT_WITH_ACTS(0,-9354,1453,-1498,0,0,0,0x1000000, bhvBowserCourseRedCoinStar,31),
OBJECT_WITH_ACTS(215,-9440,930,159,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-9369,930,-2876,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-3797,2460,-5904,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-1809,3208,-2703,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-4393,2884,-148,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-1855,3594,91,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-5782,1436,-2129,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-4121,2460,-2078,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(250,-4617,2460,-1848,0,11,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(250,-4134,2460,-1601,0,0,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(250,-4218,2460,-2377,0,320,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(250,-4059,2460,-2072,0,25,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x6004e20, Bhv_Custom_0x1300003c,31),
OBJECT_WITH_ACTS(120,-3105,1090,3688,0,0,0,0x0, bhvRecoveryHeart,31),
OBJECT_WITH_ACTS(0,-2873,2213,9002,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(144,-3360,2213,8971,0,90,0,0x0, Bhv_Custom_0x1300062c,31),
OBJECT_WITH_ACTS(144,-1270,1944,10225,0,0,0,0x0, Bhv_Custom_0x1300062c,31),
OBJECT_WITH_ACTS(53,-1860,2490,3614,0,0,0,0x10000, bhvKickableBoard,31),
OBJECT_WITH_ACTS(0,-9430,-600,-3567,0,0,0,0x940000, bhvPoleGrabbing,31),
OBJECT_WITH_ACTS(0,-9433,-600,669,0,0,0,0x940000, bhvPoleGrabbing,31),
OBJECT_WITH_ACTS(250,-2339,1023,1998,0,0,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(250,-11061,600,13634,0,0,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(250,-2523,2460,-1391,0,0,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(250,-8528,1459,13543,0,0,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(250,-9458,930,-790,0,0,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(122,-2955,4352,10655,0,0,0,0x2000000, bhvStar,31),
OBJECT_WITH_ACTS(244,-10401,600,13259,0,0,0,0x0, Bhv_Custom_0x0040ebb0,31),
OBJECT_WITH_ACTS(244,-3360,1023,2403,0,0,0,0x0, Bhv_Custom_0x0040ebb0,31),
OBJECT_WITH_ACTS(244,-2955,1023,1799,0,0,0,0x0, Bhv_Custom_0x0040ebb0,31),
OBJECT_WITH_ACTS(244,-4303,2460,-1134,0,0,0,0x0, Bhv_Custom_0x0040ebb0,31),
OBJECT_WITH_ACTS(212,-2138,3574,-2860,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(0,-4640,2460,-942,0,0,0,0x0, bhvPokey,31),
OBJECT_WITH_ACTS(0,-8535,930,-2198,0,0,0,0x0, bhvPokey,31),
OBJECT_WITH_ACTS(0,-10365,600,12922,0,0,0,0x0, bhvPokey,31),
//sigma
OBJECT_WITH_ACTS(/* model*/ 0, /*speed*/ 70, /*axis*/4, /*vtx count*/60, 0, /*scroll type*/ 0, /*cycle*/ 1, /*index*/ 12, RM_Scroll_Texture, 31),
//OBJECT_WITH_ACTS(0,2,5,925,0,0,20,9, RM_Scroll_Texture,31),
RETURN()
};
const LevelScript local_warps_ccm_1_[] = {
WARP_NODE(10,9,1,0,0),
WARP_NODE(240,26,1,83,0),
WARP_NODE(241,26,1,93,0),
RETURN()
};
const LevelScript local_area_ccm_2_[] = {
AREA(2,Geo_ccm_2_0x157c860),
TERRAIN(col_ccm_2_0xe01f190),
SET_BACKGROUND_MUSIC(0,75),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_ccm_2_),
JUMP_LINK(local_warps_ccm_2_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_ccm_2_[] = {
OBJECT_WITH_ACTS(0,-5673,-1744,7535,0,180,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(86,-5634,-1853,6477,0,0,0,0x0, bhvTweester,31),
OBJECT_WITH_ACTS(86,-7042,-757,5533,0,328,0,0x0, bhvTweester,31),
OBJECT_WITH_ACTS(86,-4739,-1074,-426,0,0,0,0x500000, bhvTweester,31),
OBJECT_WITH_ACTS(86,609,114,3257,0,0,0,0x3c0000, bhvTweester,31),
OBJECT_WITH_ACTS(86,-3755,1098,6679,0,0,0,0x0, bhvTweester,31),
OBJECT_WITH_ACTS(144,-5093,1094,2559,0,0,0,0x0, Bhv_Custom_0x1300062c,31),
OBJECT_WITH_ACTS(144,-4719,925,1452,0,271,0,0x0, Bhv_Custom_0x1300062c,31),
OBJECT_WITH_ACTS(144,-5033,1190,3713,0,0,0,0x0, Bhv_Custom_0x1300062c,31),
OBJECT_WITH_ACTS(245,-5610,-1522,6476,0,0,0,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(245,-5610,-1422,6476,0,0,0,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(245,-5610,-1322,6476,0,0,0,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(245,-7071,-429,5521,0,0,0,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(245,-7071,-329,5521,0,0,0,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(245,-7071,-229,5521,0,0,0,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(245,-4712,-233,-449,0,0,0,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(245,-4712,-133,-449,0,0,0,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(245,-4712,-33,-449,0,0,0,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(245,-3753,1713,6660,0,0,0,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(245,-3753,1813,6660,0,0,0,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(245,-3753,1913,6660,0,0,0,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(245,616,442,3265,0,0,0,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(245,616,542,3265,0,0,0,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(245,616,642,3265,0,0,0,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(0,-3405,831,156,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(245,-6867,232,2457,90,0,0,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(144,-6849,-669,6959,0,0,0,0x0, Bhv_Custom_0x1300062c,31),
OBJECT_WITH_ACTS(0,-4260,-625,5245,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,627,1131,2696,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(245,521,1832,1154,90,0,0,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(245,4211,544,-3017,0,0,0,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(245,4211,944,-3017,0,0,0,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(0,-6783,-669,6933,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(249,-3553,-669,4883,0,0,0,0x0, bhvTree,31),
OBJECT_WITH_ACTS(249,4211,-116,-3017,0,0,0,0x0, bhvTree,31),
OBJECT_WITH_ACTS(249,-7625,-669,-711,0,0,0,0x0, bhvTree,31),
OBJECT_WITH_ACTS(0,3530,-87,-2632,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(212,-822,1242,-3803,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(212,2449,1116,6726,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(0,16,0,2483,0,0,0,0x7004e20, Bhv_Custom_0x1300003c,31),
OBJECT_WITH_ACTS(212,263,1281,-952,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(122,4469,114,-2619,0,0,0,0x3010000, bhvStar,31),
OBJECT_WITH_ACTS(122,1416,2103,-1266,0,0,0,0x4000000, bhvStar,31),
OBJECT_WITH_ACTS(180,-6522,-625,264,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,-6522,-625,-1125,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,-7252,-625,-1126,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,-7252,-625,264,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(144,1423,1959,482,0,0,0,0x0, Bhv_Custom_0x1300062c,31),
OBJECT_WITH_ACTS(144,1409,1959,1793,0,0,0,0x0, Bhv_Custom_0x1300062c,31),
OBJECT_WITH_ACTS(87,-3903,1235,4678,0,264,0,0x0, Bhv_Custom_0x130006d0,31),
OBJECT_WITH_ACTS(87,1435,1959,-112,0,264,0,0x0, Bhv_Custom_0x130006d0,31),
OBJECT_WITH_ACTS(250,4034,-116,-2426,0,0,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(250,-6340,-669,-648,0,0,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(250,-7646,-669,-183,0,0,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(250,-5248,-669,4980,0,0,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(250,-7692,-669,6520,0,0,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(250,-7296,-669,6442,0,0,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(250,4583,-116,-3016,0,0,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(250,1378,173,3027,0,0,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(250,1219,173,3608,0,0,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(250,-3591,-669,5593,0,0,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(250,-4628,1190,7539,0,0,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(250,-3209,1190,7534,0,0,0,0x0, Bhv_Custom_0x130005f4,31),
OBJECT_WITH_ACTS(195,6896,-1591,1356,0,0,0,0x10000, bhvBobombBuddy,31),
OBJECT_WITH_ACTS(212,6655,-1683,1030,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(195,-3761,-1606,-5032,0,0,0,0x20000, bhvBobombBuddy,31),
OBJECT_WITH_ACTS(212,-3445,-1700,-4755,0,0,0,0x0, bhv1Up,31),
//OBJECT_WITH_ACTS(0,40,4,43,0,0,20,10, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,3,4,142,0,0,20,13, RM_Scroll_Texture,31),
RETURN()
};
const LevelScript local_warps_ccm_2_[] = {
WARP_NODE(10,9,2,0,0),
WARP_NODE(240,26,1,84,0),
WARP_NODE(241,26,1,94,0),
RETURN()
};
const LevelScript local_area_ccm_3_[] = {
AREA(3,Geo_ccm_3_0x157ca40),
TERRAIN(col_ccm_3_0xe012f30),
SET_BACKGROUND_MUSIC(0,22),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_ccm_3_),
JUMP_LINK(local_warps_ccm_3_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_ccm_3_[] = {
OBJECT_WITH_ACTS(0,295,1600,-335,0,0,0,0xa0000, bhvSpinAirborneWarp,31),
//OBJECT_WITH_ACTS(E_MODEL_KING_BOBOMB, 252,1600,-864,0,0,0,(5 << 24), id_bhvKingBobomb,31),
OBJECT_WITH_ACTS(E_MODEL_ANGRYSUN,-1642,2490,-2812,0,0,0,0x5000000, id_bhvAngrySun,31),
//OBJECT_WITH_ACTS(64,2345,1612,63,0,0,0,0x0,0x190009e0,31),
OBJECT_WITH_ACTS(0,439,2048,-2258,0,0,0,0x110000, bhvCoinFormation,31),
//OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x10000,0x00377ef0,31),
//OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x0,0x19000c00,31),
OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x0, bhvInitializeChangingWaterLevel,31),
RETURN()
};
const LevelScript local_warps_ccm_3_[] = {
WARP_NODE(10,9,3,0,0),
WARP_NODE(240,26,1,108,0),
WARP_NODE(241,26,1,109,0),
RETURN()
};

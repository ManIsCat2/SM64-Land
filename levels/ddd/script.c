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
#include "levels/ddd/header.h"
extern u8 _ddd_segment_ESegmentRomStart[]; 
extern u8 _ddd_segment_ESegmentRomEnd[];
const LevelScript level_ddd_entry[] = {
INIT_LEVEL(),
LOAD_RAW(0x0E, _ddd_segment_ESegmentRomStart, _ddd_segment_ESegmentRomEnd),
LOAD_MIO0(0xA,_SkyboxCustom26699168_skybox_mio0SegmentRomStart,_SkyboxCustom26699168_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
LOAD_MIO0(5,_group1_mio0SegmentRomStart,_group1_mio0SegmentRomEnd),
LOAD_RAW(12,_group1_geoSegmentRomStart,_group1_geoSegmentRomEnd),
ALLOC_LEVEL_POOL(),
MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
LOAD_MODEL_FROM_GEO(53, ddd_white_crystal_geo),
LOAD_MODEL_FROM_GEO(54, ddd_purple_appearing_path_geo),
LOAD_MODEL_FROM_GEO(55, polygon_stone_geo),
LOAD_MODEL_FROM_GEO(58, music_disc_geo),
LOAD_MODEL_FROM_GEO(59, ddd_growing_block_geo),
JUMP_LINK(script_func_global_1),
JUMP_LINK(script_func_global_2),
JUMP_LINK(local_area_ddd_1_),
JUMP_LINK(local_area_ddd_2_),
FREE_LEVEL_POOL(),
MARIO_POS(1,0,0,0,0),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_ddd_1_[] = {
AREA(1,Geo_ddd_1_0x199b6e0),
TERRAIN(col_ddd_1_0xe085d10),
//SET_BACKGROUND_MUSIC(0,17),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_ddd_1_),
JUMP_LINK(local_warps_ddd_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_ddd_1_[] = {
OBJECT_WITH_ACTS(0,169,500,-15753,0,0,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(122,-2750,2495,953,0,0,0,0x10000, bhvStar,31),
OBJECT_WITH_ACTS(53,290,1042,-11076,0,0,0,0x100, bhvDDDWhiteCrystal,31),
//start
OBJECT_WITH_ACTS(54,6,773,-8586,0,0,0,0x0, bhvDDDAppearingPath,31),

OBJECT_WITH_ACTS(54,-52,1223,-8421,0,270,0,0x0, bhvDDDAppearingPath2,31),

OBJECT_WITH_ACTS(54,3306,1223,-8425,0,270,0,0x0, bhvDDDAppearingPath3,31),

OBJECT_WITH_ACTS(54,3850,1223,-8425,90,0,90,0x0, bhvDDDAppearingPath4,31),

OBJECT_WITH_ACTS(54,4335,2620,-8425,0,270,0,0x0, bhvDDDAppearingPath5,31),

OBJECT_WITH_ACTS(54,4576,2434,-928,0,0,0,0x3030000, bhvDDDAppearingPath6,31),

OBJECT_WITH_ACTS(54,5571,2434,-928,0,0,0,0x4040000, bhvDDDAppearingPath7,31),

OBJECT_WITH_ACTS(54,-2732,2249,4562,0,180,0,0x6070000, bhvDDDAppearingPath8,31),
///end
OBJECT_WITH_ACTS(53,-1925,1543,-8161,0,0,0,0x1000100, bhvDDDWhiteCrystal2,31),
//OBJECT_WITH_ACTS(54,-2182,1196,-8474,3,90,0,0x1010000, Bhv_Custom_0x07003240,31),
OBJECT_WITH_ACTS(53,2971,1543,-8086,0,0,0,0x2000180, bhvDDDWhiteCrystal3and4and5,31),
//OBJECT_WITH_ACTS(54,3128,1292,-8439,2,90,0,0x202040e, Bhv_Custom_0x07003240,31),
OBJECT_WITH_ACTS(53,4638,2686,-4491,0,0,0,0x3000200, bhvDDDWhiteCrystal6,31),
OBJECT_WITH_ACTS(53,5472,2686,-4491,0,0,0,0x4000200, bhvDDDWhiteCrystal7,31),
/*OBJECT_WITH_ACTS(53,5073,3338,13144,0,0,0,0x5000100, Bhv_Custom_0x07003200,31),
OBJECT_WITH_ACTS(54,5088,3079,13302,2,0,0,0x5050209, Bhv_Custom_0x07003240,31),
OBJECT_WITH_ACTS(54,5088,3079,12952,40,180,0,0x5060200, Bhv_Custom_0x07003240,31),*/
OBJECT_WITH_ACTS(53,-2442,2481,7595,0,0,0,0x6000100, bhvDDDWhiteCrystal8,31),
OBJECT_WITH_ACTS(55,2852,1926,-8557,0,0,0,0x0, bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,6898,2881,-2259,0,0,0,0x0, bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,6333,2637,-598,0,0,0,0x0, bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,5102,2901,-2180,0,0,0,0x0, bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,4070,2637,-2131,0,0,0,0x0, bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,3401,2848,-317,0,0,0,0x0, bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,5034,2845,-487,0,0,0,0x0, bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,5058,3053,987,0,0,0,0x0, bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,3947,2512,1996,0,0,0,0x0, bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,6466,2499,2192,0,0,0,0x0, bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,6363,2857,786,0,0,0,0x0, bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,3116,2467,1040,0,0,0,0x0, bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,2998,3147,-2000,0,0,0,0x0, bhvPolygonStone,31),
OBJECT_WITH_ACTS(215,4018,3071,-2087,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,6302,2996,-593,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,6885,3247,-2265,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,3860,2933,1953,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,6452,2952,2244,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,3030,2838,963,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,5003,3367,1031,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,2968,3449,-1947,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(0,5035,2799,3336,0,0,0,0x1000000, bhvBowserCourseRedCoinStar,31),
//OBJECT_WITH_ACTS(220,5333,2472,3023,0,180,0,0x0, Bhv_Custom_0x07007640,31),
//OBJECT_WITH_ACTS(220,4784,2472,3023,0,180,0,0x8400000, Bhv_Custom_0x07007640,31),
//OBJECT_WITH_ACTS(0,4968,4770,357,0,0,0,0x10004e20,0x1300003c,31),
OBJECT_WITH_ACTS(0,4603,2472,-898,0,0,0,0x100000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,5079,2597,6377,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-2653,2288,10116,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-1341,756,-5873,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(212,-2014,2826,14188,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(212,4569,2142,-8159,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(0,5073,3242,13495,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,5065,2910,-6867,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,2495,3928,14911,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-45,515,-12372,0,90,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(137,4751,3163,-7877,0,0,0,0x30000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(0,5258,3572,-6295,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(55,-24783,4146,-16372,263,0,244,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,-24029,2104,-6067,212,0,260,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,-24879,4678,2795,0,0,0,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,-18460,1749,-23848,0,0,0,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,-8358,3791,-25343,0,0,0,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,5066,683,-30047,0,0,0,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,-14434,6188,-25842,195,81,350,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,-781,2814,-30164,103,0,130,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,-27233,4146,13590,0,0,0,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,-23715,4146,20184,0,0,0,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,12626,1660,-28533,109,0,130,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,20275,3347,-27371,24,0,269,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,25766,4146,-23011,0,0,0,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,29799,4590,-5642,195,0,350,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,29825,-27,989,0,0,0,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,27491,2992,7409,0,0,0,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,26479,4146,13391,81,0,86,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,23789,4146,21071,103,0,130,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,21459,5389,24963,0,0,0,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,15843,2282,29335,0,0,0,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,9092,3347,26960,0,0,0,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,1646,5477,25146,175,0,243,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,-6095,5478,25964,0,0,0,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,-11986,3880,29286,142,0,335,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(55,-20067,6010,26826,0,0,0,0x0,bhvPolygonStone,31),
OBJECT_WITH_ACTS(0,-2748,2262,958,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(212,4636,3680,-6714,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(124,4734,2943,-8037,0,180,0,0x8c0000, bhvMessagePanel,31),
//OBJECT_WITH_ACTS(239,5355,2943,-7857,0,0,0,0x0,0x040086a0,31),
OBJECT_WITH_ACTS(0,9543,-32748,7,0,0,0,0xe006820, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,618,-32748,7,0,0,0,0xe039bd0, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,1151,-32748,7,0,0,0,0xe03c270, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,1332,-32748,7,0,0,0,0xe040a60, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,4117,-32748,7,0,0,0,0xe045da0, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,789,-32748,7,0,0,0,0xe055ef0, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,1588,-32748,7,0,0,0,0xe0676a0, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,56,-32748,7,0,0,0,0xe02bc90, bhvStaticObject,31),
RETURN()
};
const LevelScript local_warps_ddd_1_[] = {
WARP_NODE(10,9,1,0,0),
WARP_NODE(240,16,3,50,0),
WARP_NODE(241,16,3,60,0),
RETURN()
};
const LevelScript local_area_ddd_2_[] = {
AREA(2,Geo_ddd_2_0x199b8c0),
TERRAIN(col_ddd_2_0xe03d610),
SET_BACKGROUND_MUSIC(0,53),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_ddd_2_),
JUMP_LINK(local_warps_ddd_2_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_ddd_2_[] = {
OBJECT_WITH_ACTS(0,5266,-916,10237,0,180,0,0xa0000, bhvSpinAirborneWarp,31),
/*OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x0,0x07007ae0,31),
OBJECT_WITH_ACTS(0,5257,-1444,8241,0,0,0,0x0,0x07007c70,31),
OBJECT_WITH_ACTS(0,5234,-1444,-1507,0,0,0,0x0,0x07007c70,31),
OBJECT_WITH_ACTS(0,5227,-1198,-3818,0,0,0,0x0,0x07007c70,31),
OBJECT_WITH_ACTS(0,-6540,1659,-3153,0,0,0,0x0,0x07007c70,31),
OBJECT_WITH_ACTS(0,-3267,1660,2817,0,0,0,0x0,0x07007c70,31),*/
OBJECT_WITH_ACTS(58,4963,-450,-10017,0,0,0,0x0,bhvMusicDisc,31),
OBJECT_WITH_ACTS(58,-6188,2130,-1432,0,0,0,0x0,bhvMusicDisc,31),
OBJECT_WITH_ACTS(58,-6547,2130,727,0,0,0,0x0, bhvMusicDisc,31),
OBJECT_WITH_ACTS(58,-5439,2130,2581,0,0,0,0x0,bhvMusicDisc,31),
OBJECT_WITH_ACTS(58,-257,1169,-11049,0,0,0,0x0, bhvMusicDisc,31),
OBJECT_WITH_ACTS(58,-2322,1169,-10411,0,0,0,0x0,bhvMusicDisc,31),
OBJECT_WITH_ACTS(122,-1402,2708,3560,0,0,0,0x4010000, bhvStar,31),
OBJECT_WITH_ACTS(122,5158,30,548,0,0,0,0x3000000, bhvStar,31),
OBJECT_WITH_ACTS(59,1500,-353,-11520,0,0,0,0x30000,bhvDDDGrowingBlock,31),
OBJECT_WITH_ACTS(59,2500,-353,-11520,0,0,0,0x20000,bhvDDDGrowingBlock,31),
OBJECT_WITH_ACTS(59,3500,-353,-11520,0,0,0,0x10000,bhvDDDGrowingBlock,31),
OBJECT_WITH_ACTS(59,4500,-353,-11520,0,0,0,0x0,bhvDDDGrowingBlock,31),
//OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x11004e20,0x1300003c,31),
OBJECT_WITH_ACTS(88,5233,-1408,2049,0,0,0,0x2800, bhvThwomp,31),
OBJECT_WITH_ACTS(88,5273,-1412,4972,0,0,0,0x2800, bhvThwomp,31),
OBJECT_WITH_ACTS(88,-6033,523,-10780,0,0,0,0xc832, bhvThwomp,31),
OBJECT_WITH_ACTS(88,-6539,1659,-3152,0,180,0,0x785a64, bhvThwomp,31),
//OBJECT_WITH_ACTS(0,-6036,533,-10771,0,0,0,0x32,0x07009e60,31),
// OG FOR STAR
//OBJECT_WITH_ACTS(58,-1292,2402,3111,0,0,0,0x0,0x07009f80,31),
OBJECT_WITH_ACTS(0,5273,-1412,4414,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,5244,-1409,2732,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,5132,-653,-6741,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-6584,2351,-7300,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,5223,-918,10230,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,5164,-348,-11505,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,1502,1134,-11518,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-254,1225,-11054,0,0,0,0x120000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-2319,1225,-10420,0,0,0,0x120000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-6188,2125,-1441,0,0,0,0x120000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-5440,2125,2572,0,0,0,0x120000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,5261,-1444,-1540,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,5224,-1198,-3838,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-6560,1659,-3126,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-3282,1659,2843,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,5247,-1444,8236,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-6037,523,-10782,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-6549,2125,731,0,0,0,0x120000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(137,5428,-355,-8480,0,0,0,0x30000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(0,5169,-664,-434,0,0,0,0x100000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-6570,2680,-4282,0,0,0,0x100000, bhvCoinFormation,31),
//OBJECT_WITH_ACTS(239,-6892,2351,-5942,0,0,0,0x0,0x040086a0,31),
OBJECT_WITH_ACTS(0,6,-24556,60,0,0,0,0xe006020, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,1331,-24556,60,0,0,0,0xe006080, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,1944,-24556,60,0,0,0,0xe00b3b0, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,2219,-24556,60,0,0,0,0xe0151a0, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,315,-24556,60,0,0,0,0xe01dc50, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,2223,-24556,60,0,0,0,0xe01f000, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,331,-24556,60,0,0,0,0xe027af0, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,315,-24556,60,0,0,0,0xe028fa0, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,997,-24556,60,0,0,0,0xe02a350, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,56,-32748,6,0,0,0,0xe02e1a0, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,1102,-32748,12,0,0,0,0xe02e520, bhvStaticObject,31),
RETURN()
};
const LevelScript local_warps_ddd_2_[] = {
WARP_NODE(10,9,2,0,0),
WARP_NODE(240,16,3,51,0),
WARP_NODE(241,16,3,61,0),
RETURN()
};

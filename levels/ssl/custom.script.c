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
#include "levels/ssl/header.h"
extern u8 _ssl_segment_ESegmentRomStart[]; 
extern u8 _ssl_segment_ESegmentRomEnd[];
const LevelScript level_ssl_entry[] = {
INIT_LEVEL(),
LOAD_RAW(0x0E, _ssl_segment_ESegmentRomStart, _ssl_segment_ESegmentRomEnd),
LOAD_MIO0(        /*seg*/ 0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd),
LOAD_MIO0(0xA,_clouds_skybox_mio0SegmentRomStart,_clouds_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
LOAD_MIO0(5,_group7_mio0SegmentRomStart,_group7_mio0SegmentRomEnd),
LOAD_RAW(12,_group7_geoSegmentRomStart,_group7_geoSegmentRomEnd),
LOAD_MIO0(6,_group17_mio0SegmentRomStart,_group17_mio0SegmentRomEnd),
LOAD_RAW(13,_group17_geoSegmentRomStart,_group17_geoSegmentRomEnd),
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
// LOAD_MODEL_FROM_GEO(54,0x190002e0),
// LOAD_MODEL_FROM_GEO(55,0x190002c0),
LOAD_MODEL_FROM_GEO(58,bowser_can_geo),
// LOAD_MODEL_FROM_GEO(59,0x19000260),
// LOAD_MODEL_FROM_GEO(60,0x19000280),
// LOAD_MODEL_FROM_GEO(64,0x19000500),
// LOAD_MODEL_FROM_GEO(65,0x19000520),
// LOAD_MODEL_FROM_GEO(66,0x19000540),
// LOAD_MODEL_FROM_GEO(67,0x19000560),
// LOAD_MODEL_FROM_GEO(68,0x19000580),
// LOAD_MODEL_FROM_GEO(84,0x19000400),
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
JUMP_LINK(script_func_global_8),
JUMP_LINK(script_func_global_18),
JUMP_LINK(local_area_ssl_1_),
JUMP_LINK(local_area_ssl_2_),
JUMP_LINK(local_area_ssl_3_),
FREE_LEVEL_POOL(),
MARIO_POS(1,0,0,0,0),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_ssl_1_[] = {
AREA(1,ssl_area_1),
TERRAIN(col_ssl_1_0xe047580),
SET_BACKGROUND_MUSIC(0,51),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_ssl_1_),
JUMP_LINK(local_warps_ssl_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_ssl_1_[] = {
OBJECT_WITH_ACTS(0,-1332,-628,1117,0,-90,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(122,90,10049,1118,0,0,0,0x10000, bhvStar,31),
OBJECT_WITH_ACTS(0,204,6058,1278,0,0,0,0x1000000, bhvBowserCourseRedCoinStar,31),
OBJECT_WITH_ACTS(215,-624,5945,1735,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-763,5945,262,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-2873,6161,1449,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-4059,6208,907,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-2467,5737,-1372,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-8009,6755,-1252,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-5889,5722,1913,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-3669,5650,-479,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(122,-4826,7870,2647,0,0,0,0x2000000, bhvStar,31),
OBJECT_WITH_ACTS(58,-2395,-628,1193,0,0,0,0x0, bhvKoopaCola,31),
OBJECT_WITH_ACTS(58,395,4215,723,0,0,0,0x0, bhvKoopaCola,31),
OBJECT_WITH_ACTS(86,-200,4533,1944,0,0,0,0x0, bhvMrBlizzard,31),
OBJECT_WITH_ACTS(86,-1200,4533,1944,0,0,0,0x0, bhvMrBlizzard,31),
OBJECT_WITH_ACTS(86,-2200,4533,1944,0,0,0,0x0, bhvMrBlizzard,31),
OBJECT_WITH_ACTS(86,-3200,4533,1944,0,0,0,0x0, bhvMrBlizzard,31),
OBJECT_WITH_ACTS(86,-4200,4533,1944,0,0,0,0x0, bhvMrBlizzard,31),
OBJECT_WITH_ACTS(86,-5200,4533,1944,0,0,0,0x0, bhvMrBlizzard,31),
OBJECT_WITH_ACTS(86,-6200,4533,1944,0,0,0,0x0, bhvMrBlizzard,31),
OBJECT_WITH_ACTS(55,800,5750,1185,0,0,0,0x0, id_bhvJelly,31),
OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x0, Bhv_Custom_0x130012f8,31),
OBJECT_WITH_ACTS(120,-1309,-558,1559,0,0,0,0x0, bhvRecoveryHeart,31),
OBJECT_WITH_ACTS(120,1233,4409,1037,0,0,0,0x0, bhvRecoveryHeart,31),
OBJECT_WITH_ACTS(120,-265,7440,1799,0,0,0,0x0, bhvRecoveryHeart,31),
OBJECT_WITH_ACTS(58,-2249,9499,1140,0,0,0,0x280000, bhvKoopaCola,31),
OBJECT_WITH_ACTS(58,-4787,9499,1209,0,0,0,0x280000, bhvKoopaCola,31),
OBJECT_WITH_ACTS(58,-3547,9499,857,0,0,0,0x280000, bhvKoopaCola,31),
OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0xb004e20, Bhv_Custom_0x1300003c,31),
OBJECT_WITH_ACTS(54,-1947,7539,2134,0,0,0,0x0, Bhv_Custom_0x1300130c,31),
OBJECT_WITH_ACTS(54,-3652,7539,2134,0,0,0,0x0, Bhv_Custom_0x1300130c,31),
OBJECT_WITH_ACTS(54,-5323,7539,2134,0,0,0,0x0, Bhv_Custom_0x1300130c,31),
OBJECT_WITH_ACTS(0,-6928,689,1343,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-5316,2311,1847,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,687,2366,606,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,1313,3080,296,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,1476,3794,539,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-3838,7370,1820,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-7712,7396,1612,0,90,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-813,9492,1145,0,90,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(129,-7593,1480,-1449,0,0,0,0x0, bhvJumpingBox,31),
OBJECT_WITH_ACTS(0,-3762,-525,-778,0,90,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(129,-6972,1494,-1503,0,0,0,0x0, bhvJumpingBox,31),
OBJECT_WITH_ACTS(212,-851,7926,832,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(212,-6095,-525,-991,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(0,-7172,4339,1209,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x0, Bhv_Custom_0x19000420,31),
OBJECT_WITH_ACTS(0,-5818,5970,922,0,0,0,0x110000, bhvCoinFormation,31),
RETURN()
};
const LevelScript local_warps_ssl_1_[] = {
WARP_NODE(10,9,1,0,0),
WARP_NODE(240,16,2,34,0),
WARP_NODE(241,16,2,44,0),
RETURN()
};
const LevelScript local_area_ssl_2_[] = {
AREA(2,Geo_ssl_2_0x18a4440),
TERRAIN(col_ssl_2_0xe05eb50),
SET_BACKGROUND_MUSIC(0,42),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_ssl_2_),
JUMP_LINK(local_warps_ssl_2_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_ssl_2_[] = {
OBJECT_WITH_ACTS(0,-1939,-64,842,0,180,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(0,-2680,-64,950,0,180,0,0x0, Bhv_Custom_0x0701ecc0,31),
OBJECT_WITH_ACTS(0,-2655,-66,-3199,0,0,0,0xf0000, Bhv_Custom_0x0701bfe8,31),
OBJECT_WITH_ACTS(0,-3463,234,-8359,0,0,0,0x50f0100, Bhv_Custom_0x0701bfe8,31),
OBJECT_WITH_ACTS(0,-5384,250,-7700,0,0,-30,0x5000228, Bhv_Custom_0x0701bfe8,31),
OBJECT_WITH_ACTS(0,-8891,300,-6372,0,0,-90,0x5080300, Bhv_Custom_0x0701bfe8,31),
OBJECT_WITH_ACTS(0,-10465,300,-5712,0,0,-90,0x5080400, Bhv_Custom_0x0701bfe8,31),
OBJECT_WITH_ACTS(0,-14311,712,-4285,10,0,-90,0xa0a0500, Bhv_Custom_0x0701bfe8,31),
OBJECT_WITH_ACTS(0,-12810,620,-1037,0,0,0,0xf030628, Bhv_Custom_0x0701bfe8,31),
OBJECT_WITH_ACTS(0,-12419,810,2020,0,0,0,0x14070700, Bhv_Custom_0x0701bfe8,31),
OBJECT_WITH_ACTS(0,-11345,2073,3261,0,0,0,0x80000800, Bhv_Custom_0x0701bfe8,31),
OBJECT_WITH_ACTS(0,-9542,2128,4680,0,0,0,0x800a0a00, Bhv_Custom_0x0701bfe8,31),
OBJECT_WITH_ACTS(0,-11556,2128,3664,0,0,0,0x320a0900, Bhv_Custom_0x0701bfe8,31),
OBJECT_WITH_ACTS(0,-8170,2278,2735,0,0,0,0xa000b1e, Bhv_Custom_0x0701bfe8,31),
OBJECT_WITH_ACTS(0,-8672,4872,-4038,0,0,0,0xa120c14, Bhv_Custom_0x0701bfe8,31),
OBJECT_WITH_ACTS(0,-8511,4872,-9648,0,0,0,0xa0a0d00, Bhv_Custom_0x0701bfe8,31),
OBJECT_WITH_ACTS(0,-5560,4872,-10554,0,0,0,0x80000e00, Bhv_Custom_0x0701bfe8,31),
OBJECT_WITH_ACTS(0,2304,5363,-10553,0,0,0,0xa300f28, Bhv_Custom_0x0701bfe8,31),
OBJECT_WITH_ACTS(0,661,5532,-3526,0,0,0,0x8032111e, Bhv_Custom_0x0701bfe8,31),
OBJECT_WITH_ACTS(0,-6492,6342,347,0,0,0,0xff321228, Bhv_Custom_0x0701bfe8,31),
OBJECT_WITH_ACTS(0,-10146,7422,379,0,0,180,0xff321300, Bhv_Custom_0x0701bfe8,31),
OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x16004e20, Bhv_Custom_0x1300003c,31),
OBJECT_WITH_ACTS(122,-5093,5697,392,0,0,0,0x5010000, bhvStar,31),
OBJECT_WITH_ACTS(0,-4610,5697,-365,0,0,0,0x4000000, bhvBowserCourseRedCoinStar,31),
OBJECT_WITH_ACTS(215,-3531,77,-3193,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-6109,413,-7066,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-12928,810,-2944,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-13168,810,132,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-9517,4872,-4336,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-7460,5022,-8104,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,956,5385,-9499,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-4017,5647,-1155,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(0,2463,5363,-7958,0,0,0,0xff00101e, Bhv_Custom_0x0701bfe8,31),
OBJECT_WITH_ACTS(212,-10063,1938,2473,0,0,0,0x40000, bhv1Up,31),
OBJECT_WITH_ACTS(0,-10063,1938,2473,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-10062,2042,5866,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(140,-4722,5497,1309,0,22,0,0x20000, bhvBlueCoinSwitch,31),
OBJECT_WITH_ACTS(118,-4853,5497,966,0,22,0,0x20000, bhvHiddenBlueCoin,31),
OBJECT_WITH_ACTS(118,-5301,5497,965,0,22,0,0x20000, bhvHiddenBlueCoin,31),
OBJECT_WITH_ACTS(118,-5649,5497,647,0,22,0,0x20000, bhvHiddenBlueCoin,31),
OBJECT_WITH_ACTS(118,-5647,5497,181,0,22,0,0x20000, bhvHiddenBlueCoin,31),
OBJECT_WITH_ACTS(118,-5310,5497,-167,0,22,0,0x20000, bhvHiddenBlueCoin,31),
OBJECT_WITH_ACTS(118,-4855,5497,-178,0,22,0,0x20000, bhvHiddenBlueCoin,31),
OBJECT_WITH_ACTS(118,-4521,5497,194,0,22,0,0x20000, bhvHiddenBlueCoin,31),
OBJECT_WITH_ACTS(118,-4518,5497,627,0,22,0,0x20000, bhvHiddenBlueCoin,31),
OBJECT_WITH_ACTS(0,-1977,-64,-324,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-2219,573,-5359,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-4154,573,-5986,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-7767,378,-6360,0,295,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-10250,378,-6361,0,293,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-11389,712,-4544,0,314,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-9717,5003,-5972,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(245,1779,5469,-6304,0,250,90,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(245,1751,5469,-4422,0,250,90,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(245,342,5603,-2285,0,250,90,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(245,-1554,5720,-799,0,215,90,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(245,-3460,6109,-203,0,203,90,0x0, Bhv_Custom_0x0040fdd0,31),
OBJECT_WITH_ACTS(101,-9567,428,-6584,0,0,0,0x0, bhvScuttlebug,31),
OBJECT_WITH_ACTS(101,-11270,428,-5903,0,0,0,0x0, bhvScuttlebug,31),
OBJECT_WITH_ACTS(206,-10175,2159,4226,0,0,0,0x0, bhvSnufit,31),
OBJECT_WITH_ACTS(206,-9558,4922,-4373,0,0,0,0x0, bhvSnufit,31),
OBJECT_WITH_ACTS(206,-4148,5697,-1177,0,0,0,0x0, bhvSnufit,31),
OBJECT_WITH_ACTS(212,-9639,5269,-7133,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(84,-2239,375,-4793,0,280,0,0x0, Bhv_Custom_0x0702ce80,31),
OBJECT_WITH_ACTS(84,-4019,366,-5938,0,91,0,0x0, Bhv_Custom_0x0702ce80,31),
OBJECT_WITH_ACTS(84,-7395,5147,-5395,0,268,0,0x0, Bhv_Custom_0x0702ce80,31),
OBJECT_WITH_ACTS(84,-9569,5152,-5925,0,88,0,0x0, Bhv_Custom_0x0702ce80,31),
OBJECT_WITH_ACTS(84,-9470,5194,-7070,0,88,0,0x0, Bhv_Custom_0x0702ce80,31),
RETURN()
};
const LevelScript local_warps_ssl_2_[] = {
WARP_NODE(10,9,2,0,0),
WARP_NODE(240,26,3,23,0),
WARP_NODE(241,26,3,33,0),
RETURN()
};
const LevelScript local_area_ssl_3_[] = {
AREA(3,Geo_ssl_3_0x18a4620),
TERRAIN(col_ssl_3_0xe058d90),
SET_BACKGROUND_MUSIC(0,58),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_ssl_3_),
JUMP_LINK(local_warps_ssl_3_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_ssl_3_[] = {
OBJECT_WITH_ACTS(0,0,360,0,0,180,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(E_MODEL_KING_BOBOMB,0,360,0,0,180,0,(3 << 24), id_bhvKingBobomb,31),
OBJECT_WITH_ACTS(64,144,480,-945,0,0,0,0x0, Bhv_Custom_0x0703dfc0,31),
OBJECT_WITH_ACTS(68,-115,2650,1217,0,0,0,0x0, Bhv_Custom_0x005cf200,31),
OBJECT_WITH_ACTS(68,-1015,2650,-912,0,0,0,0x0, Bhv_Custom_0x005cf200,31),
OBJECT_WITH_ACTS(68,1377,2650,-981,0,0,0,0x0, Bhv_Custom_0x005cf200,31),
OBJECT_WITH_ACTS(0,2737,2650,3958,0,0,0,0x20000, Bhv_Custom_0x00377ef0,31),
OBJECT_WITH_ACTS(0,0,417,0,0,0,0,0x20000, bhvCoinFormation,31),
RETURN()
};
const LevelScript local_warps_ssl_3_[] = {
WARP_NODE(10,9,3,0,0),
WARP_NODE(240,16,2,108,0),
WARP_NODE(241,16,2,109,0),
RETURN()
};
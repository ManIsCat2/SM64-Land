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
#include "levels/wdw/header.h"
extern u8 _wdw_segment_ESegmentRomStart[]; 
extern u8 _wdw_segment_ESegmentRomEnd[];
const LevelScript level_wdw_entry[] = {
INIT_LEVEL(),
LOAD_RAW(0x0E, _wdw_segment_ESegmentRomStart, _wdw_segment_ESegmentRomEnd),
LOAD_MIO0(        /*seg*/ 0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd),
LOAD_MIO0(0xA,_clouds_skybox_mio0SegmentRomStart,_clouds_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
LOAD_MIO0(5,_group10_mio0SegmentRomStart,_group10_mio0SegmentRomEnd),
LOAD_RAW(12,_group10_geoSegmentRomStart,_group10_geoSegmentRomEnd),
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
// LOAD_MODEL_FROM_GEO(53,0x19000200),
// LOAD_MODEL_FROM_GEO(54,0x19000220),
// LOAD_MODEL_FROM_GEO(55,0x19000240),
// LOAD_MODEL_FROM_GEO(56,0x19000260),
// LOAD_MODEL_FROM_GEO(57,0x19000280),
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
JUMP_LINK(script_func_global_11),
JUMP_LINK(local_area_wdw_1_),
JUMP_LINK(local_area_wdw_2_),
FREE_LEVEL_POOL(),
MARIO_POS(1,0,0,0,0),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_wdw_1_[] = {
AREA(1,Geo_wdw_1_0x1addce0),
TERRAIN(col_wdw_1_0xe04b7f0),
SET_BACKGROUND_MUSIC(0,40),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_wdw_1_),
JUMP_LINK(local_warps_wdw_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_wdw_1_[] = {
OBJECT_WITH_ACTS(0,29,0,-2269,0,0,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(53,1665,-1000,-10168,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,7441,-1000,-8897,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,13235,-1000,-3699,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,16280,-1000,-8584,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,18807,-1000,1051,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,5612,-1000,-13113,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,12303,-1000,-11107,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,-1930,-1000,-12859,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,-7330,-1000,-11795,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,-12141,-1000,-9218,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,-15010,-1000,-9203,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,-5045,-1000,-15554,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,21562,-1000,-4263,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,22250,-1000,4740,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,-14161,-1000,-1130,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,-17279,-1000,660,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,-17278,-1000,5189,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,22005,-1000,10465,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,-19232,-1000,8773,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,-20219,-1000,12747,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,-22662,-1000,10133,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,-22291,-1000,16996,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,-21291,-1000,20787,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,-18433,-1000,23199,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,21048,-1000,14580,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,19067,-1000,17563,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,22137,-1000,17198,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,16905,-1000,20458,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,13930,-1000,23080,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,10044,-1000,21736,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,5361,-1000,21753,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,156,-1000,22587,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,-6360,-1000,21713,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,-10902,-1000,21760,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,-15050,-1000,23919,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,-9034,-1000,24513,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,17089,-1000,23757,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(53,2970,-1000,23950,0,0,0,0x0, Bhv_Custom_0x07001f10,31),
OBJECT_WITH_ACTS(0,-3016,3200,-247,0,0,0,0x0, bhvBowserCourseRedCoinStar,31),
OBJECT_WITH_ACTS(122,134,325,4252,0,0,0,0x1000000, bhvStar,31),
OBJECT_WITH_ACTS(122,-6250,3475,140,0,0,0,0x2000000, bhvStar,31),
OBJECT_WITH_ACTS(122,2482,3369,12238,0,0,0,0x3010000, bhvStar,31),
OBJECT_WITH_ACTS(0,0,362,-1026,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,0,1000,2903,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,2750,2963,1500,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-6000,3250,10500,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(207,-6250,3375,3500,0,0,0,0x100000, bhvFloorSwitchHiddenObjects,31),
OBJECT_WITH_ACTS(0,-6000,1554,13750,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(E_MODEL_YOSHI,-3049,2996,3866,0,90,0,0x0, id_bhvYoshiRideable,31),
OBJECT_WITH_ACTS(129,-6250,3200,2300,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-6250,3200,2100,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-6250,3200,1900,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-6250,3200,1700,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-6250,3200,2500,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(116,-6250,3200,2300,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-6250,3200,2100,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-6250,3200,1900,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-6250,3200,1700,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-6250,3200,2500,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(54,0,500,1125,0,0,0,0x2000000, Bhv_Custom_0x07002600,31),
OBJECT_WITH_ACTS(54,2000,2000,5000,0,0,0,0x3003f, Bhv_Custom_0x07002600,31),
OBJECT_WITH_ACTS(54,4000,2250,5000,0,0,0,0x3001f, Bhv_Custom_0x07002600,31),
OBJECT_WITH_ACTS(54,5500,2500,4500,0,0,0,0x2000000, Bhv_Custom_0x07002600,31),
OBJECT_WITH_ACTS(54,-125,1750,3375,0,0,0,0x0, Bhv_Custom_0x07002600,31),
OBJECT_WITH_ACTS(54,125,1750,3375,0,0,0,0x0, Bhv_Custom_0x07002600,31),
OBJECT_WITH_ACTS(54,6250,3125,3125,0,0,0,0x0, Bhv_Custom_0x07002600,31),
OBJECT_WITH_ACTS(0,-6005,2000,12558,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(55,250,3000,250,0,0,0,0x80000, Bhv_Custom_0x07003000,31),
OBJECT_WITH_ACTS(54,250,3000,1250,0,0,0,0x10000, Bhv_Custom_0x07002600,31),
OBJECT_WITH_ACTS(55,1500,3500,-1500,0,0,0,0x1000000, Bhv_Custom_0x07003000,31),
OBJECT_WITH_ACTS(54,250,3000,-1250,0,0,0,0x200003f, Bhv_Custom_0x07002600,31),
OBJECT_WITH_ACTS(54,-250,3000,-2500,0,0,0,0x2001f, Bhv_Custom_0x07002600,31),
OBJECT_WITH_ACTS(55,-1500,3000,-2000,0,0,0,0x0, Bhv_Custom_0x07003000,31),
OBJECT_WITH_ACTS(54,-3000,3000,-2000,0,0,0,0x101001f, Bhv_Custom_0x07002600,31),
OBJECT_WITH_ACTS(215,250,3125,1250,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,250,3068,250,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,1500,3568,-1500,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,250,3125,-2500,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-1500,3068,-2000,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-3250,3125,-2000,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,2000,3500,-1500,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,250,3125,-1750,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(55,-4750,3000,5250,0,0,0,0x0, Bhv_Custom_0x07003000,31),
OBJECT_WITH_ACTS(54,-6250,3250,5000,0,0,0,0x101003f, Bhv_Custom_0x07002600,31),
OBJECT_WITH_ACTS(55,-6250,3500,6750,0,0,0,0x1080101, Bhv_Custom_0x07003000,31),
OBJECT_WITH_ACTS(55,1500,2250,12500,0,0,0,0x80000, Bhv_Custom_0x07003000,31),
OBJECT_WITH_ACTS(54,-3750,1250,15000,0,0,0,0x5003f, Bhv_Custom_0x07002600,31),
OBJECT_WITH_ACTS(54,-1250,1500,14500,0,0,0,0x3001f, Bhv_Custom_0x07002600,31),
OBJECT_WITH_ACTS(55,250,1750,14250,0,0,0,0x0, Bhv_Custom_0x07003000,31),
OBJECT_WITH_ACTS(180,-3750,1375,15000,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,-1250,1625,14500,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(54,1500,2250,14000,0,0,0,0x1010000, Bhv_Custom_0x07002600,31),
OBJECT_WITH_ACTS(180,1500,2375,14000,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0xf004e20, Bhv_Custom_0x1300003c,31),
OBJECT_WITH_ACTS(54,-5750,3750,8250,0,0,0,0x100003f, Bhv_Custom_0x07002600,31),
OBJECT_WITH_ACTS(0,-27,0,1047,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,1513,3000,1493,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,-3040,3000,5233,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(212,-6250,3568,6750,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(212,-4750,3068,5250,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(239,-3318,3000,4913,0,0,0,0x0, Bhv_Custom_0x040086a0,31),
OBJECT_WITH_ACTS(0,6,4,5151,0,0,20,3, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,512,5,2838,0,2,6,4, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,20,2,5151,0,1,1,5, RM_Scroll_Texture,31),
RETURN()
};
const LevelScript local_warps_wdw_1_[] = {
WARP_NODE(10,9,1,0,0),
WARP_NODE(240,26,2,32,0),
WARP_NODE(241,26,2,42,0),
RETURN()
};
const LevelScript local_area_wdw_2_[] = {
AREA(2,Geo_wdw_2_0x1addec0),
TERRAIN(col_wdw_2_0xe025ff0),
SET_BACKGROUND_MUSIC(0,52),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_wdw_2_),
JUMP_LINK(local_warps_wdw_2_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_wdw_2_[] = {
OBJECT_WITH_ACTS(0,-9174,750,10593,0,180,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(0,-9214,850,10130,0,0,0,0x4010000, bhvHiddenRedCoinStar,31),
OBJECT_WITH_ACTS(57,-9354,600,9314,0,180,0,0x0, Bhv_Custom_0x07007d00,31),
OBJECT_WITH_ACTS(122,11346,1444,-11856,0,0,0,0x5000000, bhvStar,31),
OBJECT_WITH_ACTS(0,-5035,974,-6003,0,90,0,0x0, bhvFlamethrower,31),
OBJECT_WITH_ACTS(0,-5657,1270,-26740,0,22,0,0x0, bhvFlamethrower,31),
OBJECT_WITH_ACTS(0,1073,2057,-22484,0,0,0,0x0, bhvFlamethrower,31),
OBJECT_WITH_ACTS(0,4531,2057,-22403,0,0,0,0x0, bhvFlamethrower,31),
OBJECT_WITH_ACTS(0,1074,2057,-20878,0,180,0,0x0, bhvFlamethrower,31),
OBJECT_WITH_ACTS(0,4558,2057,-20897,0,180,0,0x0, bhvFlamethrower,31),
OBJECT_WITH_ACTS(0,11839,1493,-21988,0,270,0,0x0, bhvFlamethrower,31),
OBJECT_WITH_ACTS(57,10050,2195,-15259,0,0,0,0x0, Bhv_Custom_0x07007d00,31),
OBJECT_WITH_ACTS(0,1517,-750,-8636,0,270,0,0x40000, bhvFlamethrower,31),
OBJECT_WITH_ACTS(0,2928,-750,-8636,0,270,0,0x40000, bhvFlamethrower,31),
OBJECT_WITH_ACTS(0,-7783,-750,10254,0,270,0,0x40000, bhvFlamethrower,31),
OBJECT_WITH_ACTS(0,2982,-750,-515,0,270,0,0x40000, bhvFlamethrower,31),
OBJECT_WITH_ACTS(215,-4062,600,-5959,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-7374,487,-20681,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,1608,1725,-21968,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,11899,1394,-17571,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,2267,1722,-8061,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,1923,176,-674,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,2097,117,9273,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-5137,1164,-26051,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(0,-9191,600,4606,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-5704,600,-2528,0,296,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-2738,600,-6334,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-7408,394,-19117,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,2790,1725,-21619,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,11793,1394,-19856,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,11423,1394,-16430,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,5086,771,-13981,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,1192,255,-2184,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,3090,117,6215,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0xd004e20, Bhv_Custom_0x1300003c,31),
OBJECT_WITH_ACTS(192,-2789,600,-3987,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(192,-6903,600,-11846,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(192,-7372,600,-10582,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(192,1660,123,853,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(192,2138,1461,-12251,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(192,10576,1394,-14072,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(192,10716,1394,-19385,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(192,7159,771,-13984,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(25,-8955,600,-3037,0,0,0,0x0, Bhv_Custom_0x07007cc0,31),
OBJECT_WITH_ACTS(25,-4270,600,-4457,0,0,0,0x0, Bhv_Custom_0x07007cc0,31),
OBJECT_WITH_ACTS(25,-4956,600,-11401,0,0,0,0x0, Bhv_Custom_0x07007cc0,31),
OBJECT_WITH_ACTS(25,-8437,600,-13752,0,0,0,0x0, Bhv_Custom_0x07007cc0,31),
OBJECT_WITH_ACTS(25,-5924,600,579,0,0,0,0x0, Bhv_Custom_0x07007cc0,31),
RETURN()
};
const LevelScript local_warps_wdw_2_[] = {
WARP_NODE(10,9,2,0,0),
WARP_NODE(240,26,2,33,0),
WARP_NODE(241,26,2,43,0),
RETURN()
};
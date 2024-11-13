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
#include "levels/hmc/header.h"
extern u8 _hmc_segment_ESegmentRomStart[]; 
extern u8 _hmc_segment_ESegmentRomEnd[];
const LevelScript level_hmc_entry[] = {
INIT_LEVEL(),
LOAD_RAW(0x0E, _hmc_segment_ESegmentRomStart, _hmc_segment_ESegmentRomEnd),
LOAD_MIO0(        /*seg*/ 0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd),
LOAD_MIO0(0xA,_clouds_skybox_mio0SegmentRomStart,_clouds_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
LOAD_MIO0(5,_group1_mio0SegmentRomStart,_group1_mio0SegmentRomEnd),
LOAD_RAW(12,_group1_geoSegmentRomStart,_group1_geoSegmentRomEnd),
LOAD_MIO0(6,_group14_mio0SegmentRomStart,_group14_mio0SegmentRomEnd),
LOAD_RAW(13,_group14_geoSegmentRomStart,_group14_geoSegmentRomEnd),
ALLOC_LEVEL_POOL(),
MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
LOAD_MODEL_FROM_GEO(22, warp_pipe_geo),
// LOAD_MODEL_FROM_GEO(53,0x19000400),
// LOAD_MODEL_FROM_GEO(54,0x19000420),
// LOAD_MODEL_FROM_GEO(55,0x19000440),
LOAD_MODEL_FROM_GEO(56,paper_plane_geo),
// LOAD_MODEL_FROM_GEO(57,0x19000480),
// LOAD_MODEL_FROM_GEO(58,0x190004a0),
LOAD_MODEL_FROM_GEO(60,lava_and_snow_platform_geo),
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
JUMP_LINK(script_func_global_2),
JUMP_LINK(script_func_global_15),
JUMP_LINK(local_area_hmc_1_),
JUMP_LINK(local_area_hmc_2_),
JUMP_LINK(local_area_hmc_3_),
FREE_LEVEL_POOL(),
MARIO_POS(1,0,0,0,0),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_hmc_1_[] = {
AREA(1,Geo_hmc_1_0x1721060),
TERRAIN(col_hmc_1_0xe0b8c30),
SET_BACKGROUND_MUSIC(0,35),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_hmc_1_),
JUMP_LINK(local_warps_hmc_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_hmc_1_[] = {
OBJECT_WITH_ACTS(0,7539,0,2584,0,270,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(122,2107,298,-64,0,0,0,(2 << 24), bhvStar,31),
OBJECT_WITH_ACTS(122,-4133,5771,-8920,0,0,0,0x1000000, bhvStar,31),
OBJECT_WITH_ACTS(89,4982,0,3225,0,0,0,0x0, bhvHeaveHo,31),
OBJECT_WITH_ACTS(89,1265,1600,5776,0,91,0,0x0, bhvHeaveHo,31),
OBJECT_WITH_ACTS(89,3669,5544,-5773,0,0,0,0x0, bhvHeaveHo,31),
OBJECT_WITH_ACTS(89,3264,5046,-6788,0,86,0,0x0, bhvHeaveHo,31),
OBJECT_WITH_ACTS(89,-1230,4051,-6274,0,294,0,0x0, bhvHeaveHo,31),
OBJECT_WITH_ACTS(89,2987,6042,-4763,0,267,0,0x0, bhvHeaveHo,31),
OBJECT_WITH_ACTS(89,1575,5544,-5768,0,232,0,0x0, bhvHeaveHo,31),
OBJECT_WITH_ACTS(89,-207,5046,-6180,0,50,0,0x0, bhvHeaveHo,31),
/*OBJECT_WITH_ACTS(53,3106,2222,8445,0,180,0,0x0, Bhv_Custom_0x13000f84,31),
OBJECT_WITH_ACTS(53,6013,3591,-8569,0,180,0,0x50000, Bhv_Custom_0x13000f84,31),
OBJECT_WITH_ACTS(53,6518,3591,-8574,0,180,0,0x90000, Bhv_Custom_0x13000f84,31),
OBJECT_WITH_ACTS(53,7058,3591,-8639,0,180,0,0xd0000, Bhv_Custom_0x13000f84,31),
OBJECT_WITH_ACTS(54,-2232,2233,7727,0,180,0,0x10000, Bhv_Custom_0x13000fb4,31),
OBJECT_WITH_ACTS(54,1300,5046,-6263,0,270,0,0x10000, Bhv_Custom_0x13000fb4,31),
OBJECT_WITH_ACTS(54,-5629,40,-3725,0,47,0,0x10000, Bhv_Custom_0x13000fb4,31),
OBJECT_WITH_ACTS(54,3296,5046,-7260,0,0,0,0x10000, Bhv_Custom_0x13000fb4,31),*/
OBJECT_WITH_ACTS(0,-6296,1245,-3669,0,0,0,0xfffe00, bhvReallyBigPole,31),
OBJECT(207,4622,964,3315,0,0,0,0, bhvFloorSwitchHiddenObjects),
OBJECT(0,3889,1447,3303,0,0,0,0x0, bhvHiddenObject),
OBJECT(0,3689,1447,3303,0,0,0,0x0, bhvHiddenObject),
OBJECT(0,3489,1447,3303,0,0,0,0x0, bhvHiddenObject),
OBJECT(0,3289,1447,3303,0,0,0,0x0, bhvHiddenObject),
OBJECT(0,3289,1447,3503,0,0,0,0x0, bhvHiddenObject),
OBJECT(0,3289,1447,3703,0,0,0,0x0, bhvHiddenObject),
OBJECT(0,3089,1447,3703,0,0,0,0x0, bhvHiddenObject),
//OBJECT_WITH_ACTS(54,1356,3301,7765,0,270,0,0x10000, Bhv_Custom_0x13000fb4,31),
OBJECT_WITH_ACTS(56,2623,5183,6210,0,42,0,0x0, bhvPaperPlane,31),
// pushable n64
OBJECT_WITH_ACTS(E_MODEL_PUSHABLE_N64_BUTTON,845,3750,6820,0,0,0,0x0, id_bhvPushableN64Button,31),
// end
//OBJECT_WITH_ACTS(0,2885,4330,5998,0,0,0,0x0, bhvSquishablePlatform,31),
//OBJECT_WITH_ACTS(0,345,3864,7552,0,0,0,0x10000, bhvSquishablePlatform,31),
/*OBJECT_WITH_ACTS(103,-1869,3553,-5587,0,0,0,0x0, Bhv_Custom_0x1300107c,31),
OBJECT_WITH_ACTS(103,-1771,3553,-5176,0,24,0,0x100, Bhv_Custom_0x1300107c,31),
OBJECT_WITH_ACTS(103,-1362,3553,-4844,0,68,0,0x200, Bhv_Custom_0x1300107c,31),
OBJECT_WITH_ACTS(103,-856,3553,-4688,0,90,0,0x300, Bhv_Custom_0x1300107c,31),
OBJECT_WITH_ACTS(103,-356,3553,-4689,0,90,0,0x400, Bhv_Custom_0x1300107c,31),
OBJECT_WITH_ACTS(103,142,3553,-4718,0,90,0,0x500, Bhv_Custom_0x1300107c,31),
OBJECT_WITH_ACTS(103,618,3553,-4784,0,119,0,0x600, Bhv_Custom_0x1300107c,31),
OBJECT_WITH_ACTS(103,863,3553,-5154,0,153,0,0x700, Bhv_Custom_0x1300107c,31),
OBJECT_WITH_ACTS(103,863,3553,-5596,0,180,0,0x800, Bhv_Custom_0x1300107c,31),
OBJECT_WITH_ACTS(103,872,3553,-6051,0,180,0,0x900, Bhv_Custom_0x1300107c,31),
OBJECT_WITH_ACTS(103,876,3553,-6454,0,180,0,0xa00, Bhv_Custom_0x1300107c,31),
OBJECT_WITH_ACTS(103,872,3553,-6838,0,180,0,0xb00, Bhv_Custom_0x1300107c,31),
OBJECT_WITH_ACTS(103,863,3553,-7284,0,180,0,0xc00, Bhv_Custom_0x1300107c,31),
OBJECT_WITH_ACTS(103,750,3553,-7651,0,214,0,0xd00, Bhv_Custom_0x1300107c,31),
OBJECT_WITH_ACTS(103,348,3553,-7789,0,260,0,0xe00, Bhv_Custom_0x1300107c,31),
OBJECT_WITH_ACTS(103,-137,3553,-7841,0,270,0,0xf00, Bhv_Custom_0x1300107c,31),
OBJECT_WITH_ACTS(103,-681,3553,-7838,0,270,0,0x1000, Bhv_Custom_0x1300107c,31),
OBJECT_WITH_ACTS(103,-1166,3553,-7838,0,270,0,0x1100, Bhv_Custom_0x1300107c,31),
OBJECT_WITH_ACTS(103,-1664,3553,-7825,0,270,0,0x1200, Bhv_Custom_0x1300107c,31),
OBJECT_WITH_ACTS(103,-2096,3553,-7825,0,270,0,0x1300, Bhv_Custom_0x1300107c,31),
OBJECT_WITH_ACTS(103,-2505,3553,-7825,0,270,0,0x1400, Bhv_Custom_0x1300107c,31),*/
OBJECT_WITH_ACTS(207,-2803,3553,-7833,0,270,0,0x1000000, bhvFloorSwitchAnimatesObject,31),
OBJECT_WITH_ACTS(129,-5036,5361,-7895,0,0,0,0x1000000, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-5036,5361,-7695,0,0,0,0x1000000, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-5036,5161,-7495,0,0,0,0x1000000, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-5036,4961,-7295,0,0,0,0x1000000, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-5036,4761,-7095,0,0,0,0x1000000, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-5036,4561,-6895,0,0,0,0x1000000, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-5036,4561,-6695,0,0,0,0x1000000, bhvHiddenObject,31),
OBJECT_WITH_ACTS(84,7679,4861,-7668,0,270,0,0x0, bhvBulletBill,31),
OBJECT_WITH_ACTS(84,7709,4861,-7059,0,270,0,0x0, bhvBulletBill,31),
OBJECT_WITH_ACTS(84,7704,4861,-6453,0,270,0,0x0, bhvBulletBill,31),
OBJECT_WITH_ACTS(84,7696,4861,-5809,0,270,0,0x0, bhvBulletBill,31),
OBJECT_WITH_ACTS(84,7696,4861,-5168,0,270,0,0x0, bhvBulletBill,31),
OBJECT_WITH_ACTS(84,7685,4861,-4575,0,270,0,0x0, bhvBulletBill,31),
OBJECT_WITH_ACTS(84,7687,4861,-3930,0,270,0,0x0, bhvBulletBill,31),
OBJECT_WITH_ACTS(84,7697,4861,-3268,0,270,0,0x0, bhvBulletBill,31),
OBJECT_WITH_ACTS(84,7677,2492,-1231,0,270,0,0x0, bhvBulletBill,31),
OBJECT_WITH_ACTS(84,6824,1968,37,0,270,0,0x0, bhvBulletBill,31),
OBJECT_WITH_ACTS(84,4742,798,584,0,180,0,0x0, bhvBulletBill,31),
OBJECT_WITH_ACTS(84,4381,798,-1884,0,0,0,0x0, bhvBulletBill,31),
OBJECT_WITH_ACTS(84,2105,798,589,0,180,0,0x0, bhvBulletBill,31),
OBJECT_WITH_ACTS(84,1839,798,-1894,0,0,0,0x0, bhvBulletBill,31),
//OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x9004e20, Bhv_Custom_0x1300003c,31),
OBJECT_WITH_ACTS(0,6362,964,3304,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-853,2233,6845,0,270,0,0x40000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-5651,729,-3726,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,1358,3941,7764,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-4184,5561,-8626,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,3568,20,-35,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,6912,6,1850,0,265,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(212,6824,2309,29,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(212,-6276,5146,-5875,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(0,-2283,3553,-6405,0,0,0,0x10000, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(129,-2610,4071,-8079,0,0,0,0x1000000, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-2410,4071,-8079,0,0,0,0x1000000, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-2210,4071,-8079,0,0,0,0x1000000, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-2010,4071,-8079,0,0,0,0x1000000, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-2810,4071,-8079,0,0,0,0x1000000, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-2610,4271,-8079,0,0,0,0x1000000, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-2610,3871,-8079,0,0,0,0x1000000, bhvHiddenObject,31),
OBJECT_WITH_ACTS(212,-7137,40,-6648,0,0,0,0x0, bhv1Up,31),
RETURN()
};
const LevelScript local_warps_hmc_1_[] = {
WARP_NODE(10,9,1,0,0),
WARP_NODE(240,16,2,32,0),
WARP_NODE(241,16,2,42,0),
RETURN()
};
const LevelScript local_area_hmc_2_[] = {
AREA(2,Geo_hmc_2_0x1721240),
TERRAIN(col_hmc_2_0xe02b340),
SET_BACKGROUND_MUSIC(0,38),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_hmc_2_),
JUMP_LINK(local_warps_hmc_2_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_hmc_2_[] = {
OBJECT_WITH_ACTS(0,0,2172,0,0,0,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(122,-5026,6650,-4537,0,0,0,0x3010000, bhvStar,31),
OBJECT_WITH_ACTS(122,5150,4620,-6126,0,0,0,0x4000000, bhvStar,31),
OBJECT_WITH_ACTS(0,-3758,1980,3584,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(0,-242,3416,9311,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(0,5440,3205,1335,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(0,4187,3792,8804,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(0,-4697,2512,5420,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(0,5955,4620,-452,0,0,0,0x5000000, bhvHiddenStar,31),
OBJECT_WITH_ACTS(60,0,2142,780,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,0,2142,1680,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,0,2142,2580,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,0,2142,3480,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-1358,2142,4608,0,270,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-2648,2142,4858,0,270,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-2648,2142,4358,0,90,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-3148,2442,4358,0,90,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-3148,2442,3858,0,270,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-4290,2664,5371,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-4026,3391,5371,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-3026,3391,6371,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-3026,3391,6871,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-3026,3391,7371,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-3526,3391,6871,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-3526,3391,6371,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-3526,3391,7371,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-4026,3391,6871,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-4026,3391,6371,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-4026,3391,7371,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-83,3591,8321,0,90,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,517,3591,8321,0,270,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,1117,3591,8321,0,270,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,1717,3591,8321,0,90,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,2317,3591,8321,0,90,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,2917,3591,8321,0,270,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,3684,4420,8117,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,4184,4420,8117,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,4184,4420,7617,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,3684,4420,7617,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,4184,4420,7117,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,3684,4420,7117,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,4184,4420,6617,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,3684,4420,6617,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,4184,4420,6117,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,3684,4420,6117,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,4184,4420,5617,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,3684,4420,5617,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,3184,4420,4117,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,2684,4420,4117,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,3184,4420,3617,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,2684,4420,3617,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,3184,4420,3117,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,2684,4420,3117,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,3184,4420,1617,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,2684,4420,1617,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,3184,4420,4617,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,2684,4420,4617,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(0,-4033,2703,4143,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-1430,3606,8443,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,2936,3820,9378,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,7053,3820,3096,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(60,6448,4000,6578,0,180,90,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,7160,4300,6578,0,180,270,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-6288,6206,5945,0,180,270,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-5293,6646,5944,0,0,90,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,5220,5946,8945,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,4720,5946,8945,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,4220,5946,8945,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,3720,5946,8945,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-4534,5582,6416,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,2720,5946,8945,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-4534,5582,5916,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-5063,6447,-3779,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-5063,6447,-3079,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-5063,6447,-2379,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-5063,6447,-1679,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-5063,6447,-979,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-5063,6447,-279,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-5063,6447,421,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-5063,6447,1121,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-5063,6447,1821,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-5063,6447,2521,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-5063,6447,3221,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,6448,4600,6578,0,180,90,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,7160,4900,6578,0,180,270,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,6448,5200,6578,0,180,90,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(120,-5777,5582,6168,0,0,0,0x0, bhvRecoveryHeart,31),
//OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x12004e14, Bhv_Custom_0x1300003c,31),
OBJECT_WITH_ACTS(212,5425,3612,-897,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(212,6079,4280,4122,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(223,3772,4420,10249,0,0,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(223,6651,4420,1959,0,0,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(223,-144,6244,10016,0,0,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(60,3184,4420,1117,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,2684,4420,1117,0,180,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,2220,5946,8945,0,180,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(0,-4460,2861,5410,-25,90,0,0x110000, bhvCoinFormation,31),
//OBJECT_WITH_ACTS(192,3661,6000,-5342,0,0,0,0x3c0000, Bhv_Custom_0x19000300,31),
//OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x0, Bhv_Custom_0x070056e0,31),
//OBJECT_WITH_ACTS(239,5758,4420,3365,0,0,0,0x0, Bhv_Custom_0x040086a0,31),
//OBJECT_WITH_ACTS(0,-10,5,22,0,0,20,6, bhvStaticObject,31),
//OBJECT_WITH_ACTS(0,-60,5,22,0,0,20,7, bhvStaticObject,31),
//OBJECT_WITH_ACTS(0,-10,5,22,0,0,20,8, bhvStaticObject,31),
RETURN()
};
const LevelScript local_warps_hmc_2_[] = {
WARP_NODE(10,9,2,0,0),
WARP_NODE(240,16,3,52,0),
WARP_NODE(241,16,3,62,0),
RETURN()
};
const LevelScript local_area_hmc_3_[] = {
AREA(3,Geo_hmc_3_0x1721420),
TERRAIN(col_hmc_3_0xe00aa90),
SET_BACKGROUND_MUSIC(0,9),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_hmc_3_),
JUMP_LINK(local_warps_hmc_3_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_hmc_3_[] = {
OBJECT_WITH_ACTS(0,-5332,3483,-4012,0,90,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(137,-3898,5099,-3648,0,0,0,0x30000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(60,-3570,5538,-4954,0,90,90,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,-4830,4606,-4006,0,0,90,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,1854,5849,-2975,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,1854,5849,-2475,0,0,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,1854,6349,-1975,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,1854,7349,-1975,0,0,180,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(60,1854,8349,-1975,0,0,0,0x0, bhvLavaAndSnowFlipBlock,31),
OBJECT_WITH_ACTS(22,-2221,8581,1690,0,90,0,0x50000, bhvWarpPipe,31),
/*OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x7004020, Bhv_Custom_0x00377c40,31),
OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x10000, Bhv_Custom_0x0041f3e0,31),
OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x20004e20, Bhv_Custom_0x1300003c,31),*/
RETURN()
};
const LevelScript local_warps_hmc_3_[] = {
WARP_NODE(10,11,3,5,0),
WARP_NODE(5,36,3,10,0),
WARP_NODE(240,6,1,50,0),
WARP_NODE(241,26,4,102,0),
RETURN()
};

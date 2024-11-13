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
#include "levels/bbh/header.h"

extern u8 _bbh_segment_ESegmentRomStart[]; 
extern u8 _bbh_segment_ESegmentRomEnd[];

const LevelScript level_bbh_entry[] = {
	INIT_LEVEL(),
	LOAD_RAW(0x0E, _bbh_segment_ESegmentRomStart, _bbh_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _SkyboxCustom23019392_skybox_mio0SegmentRomStart, _SkyboxCustom23019392_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group11_mio0SegmentRomStart, _group11_mio0SegmentRomEnd),
	LOAD_RAW(12, _group11_geoSegmentRomStart, _group11_geoSegmentRomEnd),
	LOAD_MIO0(6, _group13_mio0SegmentRomStart, _group13_mio0SegmentRomEnd),
	LOAD_RAW(13, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd),
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
// 	LOAD_MODEL_FROM_GEO(53,0x19000200),
// 	LOAD_MODEL_FROM_GEO(54,0x19000220),
// 	LOAD_MODEL_FROM_GEO(55,0x19000240),
// 	LOAD_MODEL_FROM_GEO(56,0x19000260),
// 	LOAD_MODEL_FROM_GEO(88,0x0500c778),
// 	LOAD_MODEL_FROM_GEO(137,0x19000400),
// 	LOAD_MODEL_FROM_DL(158,0x0302c8a0,4),
// 	LOAD_MODEL_FROM_DL(159,0x0302bcd0,4),
// 	LOAD_MODEL_FROM_DL(161,0x0301cb00,4),
// 	LOAD_MODEL_FROM_DL(164,0x04032a18,4),
	JUMP_LINK(script_func_global_1),
	JUMP_LINK(script_func_global_12),
	JUMP_LINK(script_func_global_14),
	JUMP_LINK(local_area_bbh_1_),
	JUMP_LINK(local_area_bbh_2_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1,0,0,0,0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
    CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
    CLEAR_LEVEL(),
    SLEEP_BEFORE_EXIT(/*frames*/ 1),
    EXIT(),
};

const LevelScript local_area_bbh_1_[] = {
	AREA(1, bbh_1_geo),
	TERRAIN(bbh_1_collision),
	SET_BACKGROUND_MUSIC(0, 36),
	TERRAIN_TYPE(TERRAIN_GRASS),
	JUMP_LINK(local_objects_bbh_1_),
	JUMP_LINK(local_warps_bbh_1_),
	END_AREA(),
	RETURN(),
};

const LevelScript local_objects_bbh_1_[] = {
	OBJECT(MODEL_NONE, -722, 1006, 6128, 0, 180, 0, (10 << 16), bhvSpinAirborneWarp),
	OBJECT(E_MODEL_EXCLAMATION_BOX, -717, 1423, -1973, 0, 0, 0, (2 << 16), id_bhvExclamationBox),
	OBJECT(E_MODEL_EXCLAMATION_BOX, -442, 1423, -11871, 0, 0, 0, (2 << 16), id_bhvExclamationBox),
	OBJECT(E_MODEL_STAR, -301, 4489, -1970, 0, 0, 0, (1 << 24), id_bhvStar),
	OBJECT(E_MODEL_STAR, -8777, 6468, -12272, 0, 0, 0, 0x00000000, id_bhvStar),
	OBJECT(MODEL_NONE, -4255, 1243, -11336, 0, 0, 0, (2 << 24), bhvBowserCourseRedCoinStar),//s
	OBJECT(E_MODEL_SPONGE, -588, 875, 3920, 0, 283, 0, 0x00000000, id_bhvSponge),
	OBJECT(E_MODEL_SPONGE, -809, 875, 3200, 0, 206, 0, 0x00000000, id_bhvSponge),
	OBJECT(E_MODEL_SPONGE, -366, 875, 2322, 0, 252, 0, 0x00000000, id_bhvSponge),
	OBJECT(E_MODEL_JELLY, -2606, 1043, -11774, 0, 0, 0, 0x00000000, id_bhvJelly),
	OBJECT(E_MODEL_SPIN_FOOD, -5056, 1228, -12679, 0, 0, 0, 0x00000000, id_bhvSpinningFood),
	OBJECT(E_MODEL_RED_COIN, -4816, 1380, -12036, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, -5972, 2547, -13074, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, -5083, 1879, -12605, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, -5390, 2401, -11889, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, -4405, 1933, -13082, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, -5573, 1349, -12824, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, -5018, 2043, -13402, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, -6000, 2547, -12198, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_1UP, -167, 2176, 2935, 0, 0, 0, 0x00000000, id_bhv1Up),
	OBJECT(E_MODEL_1UP, -4852, 3116, -9875, 0, 0, 0, 0x00000000, id_bhv1Up),
	OBJECT(MODEL_NONE, -1033, 1485, -628, 0, 0, 0, 0x00000000, id_bhvCoinFormation),
	OBJECT(MODEL_NONE, -470, 1623, 2937, 0, 90, 0, 0x00000000, id_bhvCoinFormation),
	OBJECT(MODEL_NONE, -2608, 1379, -11765, 0, 11, 0, (17 << 16), id_bhvCoinFormation),
	OBJECT(MODEL_NONE, -1398, 1485, -11764, 0, 87, 0, 0x00000000, id_bhvCoinFormation),
	OBJECT(MODEL_NONE, -1187, 1118, -8302, 0, 0, 0, (2 << 16), id_bhvCoinFormation),
	OBJECT(MODEL_NONE, -5596, 3116, -11808, 0, 298, 0, (4 << 16), id_bhvCoinFormation),
	OBJECT(E_MODEL_SKEETER, -2603, 2908, -12816, 0, 0, 0, 0x00000000, id_bhvSkeeter),
	OBJECT(E_MODEL_SKEETER, 105, 875, 3265, 0, 0, 0, 0x00000000, id_bhvSkeeter),
	OBJECT(MODEL_NONE, -1233, 1110, -11351, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -4593, 3116, -12572, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -8525, 6300, -12501, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -6161, 3186, -13139, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -3138, 2880, -13139, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(E_MODEL_BITS_WARP_PIPE, -1613, 1200, -11465, 90, 335, 0, 0x00000000, id_bhvFakeWarpPipe),
	OBJECT(MODEL_NONE, -2593, -2304, -9428, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -5045, 1750, -12802, 0, 0, 0, 0x00000000, bhvStaticObject),
	RETURN(),
};

const LevelScript local_warps_bbh_1_[] = {
	WARP_NODE(10,9,1,0,0),
	WARP_NODE(240,16,2,31,0),
	WARP_NODE(241,16,2,41,0),
	RETURN(),
};

const LevelScript local_area_bbh_2_[] = {
	AREA(2, bbh_2_geo),
	TERRAIN(bbh_2_collision),
	SET_BACKGROUND_MUSIC(0, 9),
	TERRAIN_TYPE(TERRAIN_GRASS),
	JUMP_LINK(local_objects_bbh_2_),
	JUMP_LINK(local_warps_bbh_2_),
	END_AREA(),
	RETURN(),
};

const LevelScript local_objects_bbh_2_[] = {
	OBJECT_WITH_ACTS(0, -2644, 217, -1069, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(137, -559, 2155, -1807, 0, 0, 0, 0x20000, bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(22, 422, 6662, -5, 0, 0, 0, 0x50000, bhvWarpPipe, 31),
	//OBJECT_WITH_ACTS(0, 90, 0, -1800, 0, 0, 0, 0x7009620, bhvCustom0x00377c40, 31),
	//OBJECT_WITH_ACTS(0, 0, 0, 0, 0, 0, 0, 0x10000, bhvCustom0x0041f3e0, 31),
	OBJECT_WITH_ACTS(0, -2828, 217, 346, 0, 0, 0, 0x110000, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(87, 362, 6662, -231, 0, 0, 0, 0x0, bhvWigglerHead, 31),
	//OBJECT_WITH_ACTS(0, 0, 0, 0, 0, 0, 0, 0x20004e20, bhvCustom0x1300003c, 31),
	RETURN(),
};

const LevelScript local_warps_bbh_2_[] = {
	WARP_NODE(10,12,3,5,0),
	WARP_NODE(5,11,3,10,0),
	WARP_NODE(240,6,1,50,0),
	WARP_NODE(241,26,4,102,0),
	RETURN(),
};


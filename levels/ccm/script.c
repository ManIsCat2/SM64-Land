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

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/ccm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd),
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario),
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo),
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440),
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458),
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470),
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

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(240, 26, 1, 83, 0),
	WARP_NODE(241, 26, 1, 93, 0),
	MARIO_POS(0x01, 0, 0, 2, 0),,
	OBJECT_WITH_ACTS(0, -12429, 860, 13230, 0, 90, 0, 0xa0000, bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(55, -10939, 1193, 12662, 0, 90, 0, 0x30000, bhvSeesawPlatform, 31),
	OBJECT_WITH_ACTS(55, -10021, 1312, 13164, 0, 90, 0, 0x30000, bhvSeesawPlatform, 31),
	OBJECT_WITH_ACTS(55, -6913, 1413, 12856, 0, 90, 0, 0x30001, bhvSeesawPlatform, 31),
	OBJECT_WITH_ACTS(55, -2882, 1694, 6755, 0, 0, 0, 0x30001, bhvSeesawPlatform, 31),
	OBJECT_WITH_ACTS(55, -1933, 3023, -680, 0, 0, 0, 0x30000, bhvSeesawPlatform, 31),
	OBJECT_WITH_ACTS(55, -11247, 921, -2191, 0, 90, 0, 0x30001, bhvSeesawPlatform, 31),
	OBJECT_WITH_ACTS(55, -13379, 959, -1103, 0, 0, 0, 0x30000, bhvSeesawPlatform, 31),
	OBJECT_WITH_ACTS(55, -15739, 1023, -78, 0, 90, 0, 0x30001, bhvSeesawPlatform, 31),
	OBJECT_WITH_ACTS(55, -16748, 1013, -994, 0, 90, 0, 0x30001, bhvSeesawPlatform, 31),
	OBJECT_WITH_ACTS(137, -4402, 3083, 10549, 0, 0, 0, 0x10000, bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(122, -20979, 1235, -998, 0, 0, 0, 0x10000, bhvStar, 31),
	OBJECT_WITH_ACTS(0, -9354, 1453, -1498, 0, 0, 0, 0x1000000, bhvBowserCourseRedCoinStar, 31),
	OBJECT_WITH_ACTS(215, -9440, 930, 159, 0, 0, 0, 0x0, bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -9369, 930, -2876, 0, 0, 0, 0x0, bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -3797, 2460, -5904, 0, 0, 0, 0x0, bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -1809, 3208, -2703, 0, 0, 0, 0x0, bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -4393, 2884, -148, 0, 0, 0, 0x0, bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -1855, 3594, 91, 0, 0, 0, 0x0, bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -5782, 1436, -2129, 0, 0, 0, 0x0, bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -4121, 2460, -2078, 0, 0, 0, 0x0, bhvRedCoin, 31),
	// OBJECT_WITH_ACTS(250, -4617, 2460, -1848, 0, 11, 0, 0x0, 0x130005f4, 31),
	// OBJECT_WITH_ACTS(250, -4134, 2460, -1601, 0, 0, 0, 0x0, 0x130005f4, 31),
	// OBJECT_WITH_ACTS(250, -4218, 2460, -2377, 0, 320, 0, 0x0, 0x130005f4, 31),
	// OBJECT_WITH_ACTS(250, -4059, 2460, -2072, 0, 25, 0, 0x0, 0x130005f4, 31),
	// OBJECT_WITH_ACTS(0, 0, 0, 0, 0, 0, 0, 0x6004e20, 0x1300003c, 31),
	OBJECT_WITH_ACTS(120, -3105, 1090, 3688, 0, 0, 0, 0x0, bhvRecoveryHeart, 31),
	OBJECT_WITH_ACTS(0, -2873, 2213, 9002, 0, 90, 0, 0x0, bhvCoinFormation, 31),
	// OBJECT_WITH_ACTS(144, -3360, 2213, 8971, 0, 90, 0, 0x0, 0x1300062c, 31),
	//	OBJECT_WITH_ACTS(144, -1270, 1944, 10225, 0, 0, 0, 0x0, 0x1300062c, 31),
	OBJECT_WITH_ACTS(53, -1860, 2490, 3614, 0, 0, 0, 0x10000, bhvKickableBoard, 31),
	OBJECT_WITH_ACTS(0, -9430, -600, -3567, 0, 0, 0, 0x940000, bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, -9433, -600, 669, 0, 0, 0, 0x940000, bhvPoleGrabbing, 31),
	// OBJECT_WITH_ACTS(250, -2339, 1023, 1998, 0, 0, 0, 0x0, 0x130005f4, 31),
	// OBJECT_WITH_ACTS(250, -11061, 600, 13634, 0, 0, 0, 0x0, 0x130005f4, 31),
	// OBJECT_WITH_ACTS(250, -2523, 2460, -1391, 0, 0, 0, 0x0, 0x130005f4, 31),
	// OBJECT_WITH_ACTS(250, -8528, 1459, 13543, 0, 0, 0, 0x0, 0x130005f4, 31),
	// OBJECT_WITH_ACTS(250, -9458, 930, -790, 0, 0, 0, 0x0, 0x130005f4, 31),
	OBJECT_WITH_ACTS(122, -2955, 4352, 10655, 0, 0, 0, 0x2000000, bhvStar, 31),
	// OBJECT_WITH_ACTS(244, -10401, 600, 13259, 0, 0, 0, 0x0, 0x0040ebb0, 31),
	// OBJECT_WITH_ACTS(244, -3360, 1023, 2403, 0, 0, 0, 0x0, 0x0040ebb0, 31),
	// OBJECT_WITH_ACTS(244, -2955, 1023, 1799, 0, 0, 0, 0x0, 0x0040ebb0, 31),
	// OBJECT_WITH_ACTS(244, -4303, 2460, -1134, 0, 0, 0, 0x0, 0x0040ebb0, 31),
	OBJECT_WITH_ACTS(212, -2138, 3574, -2860, 0, 0, 0, 0x0, bhv1Up, 31),
	OBJECT_WITH_ACTS(0, -4640, 2460, -942, 0, 0, 0, 0x0, bhvPokey, 31),
	OBJECT_WITH_ACTS(0, -8535, 930, -2198, 0, 0, 0, 0x0, bhvPokey, 31),
	OBJECT_WITH_ACTS(0, -10365, 600, 12922, 0, 0, 0, 0x0, bhvPokey, 31),
	// OBJECT_WITH_ACTS(0, 60, -32748, 70, 0, 0, 0, 0xe00ac10, RM_Scroll_Texture, 31),
	// OBJECT_WITH_ACTS(0, 925, -32748, 2, 0, 0, 0, 0xe024bd0, RM_Scroll_Texture, 31),
	TERRAIN(ccm_area_1_collision),
	MACRO_OBJECTS(ccm_area_1_macro_objs),
	SET_BACKGROUND_MUSIC(0,12),
	TERRAIN_TYPE(TERRAIN_GRASS),
	/* Fast64 begin persistent block [area commands] */
	/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 2, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

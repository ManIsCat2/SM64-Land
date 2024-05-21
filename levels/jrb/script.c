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
#include "levels/jrb/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd),
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario),
	JUMP_LINK(script_func_global_1),
    JUMP_LINK(script_func_global_11),

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, jrb_area_1),
	WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0, WARP_NO_CHECKPOINT),
	WARP_NODE(0xF0, 26, 1, 81, WARP_NO_CHECKPOINT),
	WARP_NODE(0xF1, 26, 1, 91, WARP_NO_CHECKPOINT),
	MARIO_POS(0x01, 0, -14044, -3931, -7371),
	OBJECT(MODEL_NONE, -14044, -3931, -7371, 0, 90, 0, 0x000A0000, bhvSpinAirborneWarp),
	OBJECT(E_MODEL_BOUNCY_PLATFORM, 12982, 5145, -1363, 0, 90, 0, (8 << 8), id_bhvBouncyPlatform),
	OBJECT(E_MODEL_BOUNCY_PLATFORM, 12982, 6435, -1500, 0, 90, 0, (40 << 16) | (4 << 8), id_bhvBouncyPlatform),
	OBJECT(E_MODEL_BOUNCY_PLATFORM, 12982, 7745, -363, 0, 90, 0, (1 << 24) | (8 << 8), id_bhvBouncyPlatform),
	OBJECT(E_MODEL_BOUNCY_PLATFORM, 12982, 9045, -1500, 0, 90, 0, (40 << 16) | (4 << 8), id_bhvBouncyPlatform),
	OBJECT(E_MODEL_BOUNCY_PLATFORM, 12982, 10145, -363, 0, 90, 0, (1 << 24) | (8 << 8), id_bhvBouncyPlatform),
	OBJECT(E_MODEL_BOUNCY_PLATFORM, 12982, 11415, -1500, 0, 90, 0, (40 << 16) | (4 << 8), id_bhvBouncyPlatform),
	OBJECT(E_MODEL_BOUNCY_PLATFORM, 12982, 5145, 197, 0, 90, 0, (8 << 8), id_bhvBouncyPlatform),
	OBJECT(E_MODEL_BOUNCY_PLATFORM, 12982, 5145, -1363, 0, 90, 0, (8 << 8), id_bhvBouncyPlatform),
	OBJECT(E_MODEL_BOUNCY_PLATFORM, 12982, 5145, -2923, 0, 90, 0, (8 << 8), id_bhvBouncyPlatform),
	OBJECT(E_MODEL_STAR, 17265, 12686, -2676, 0, 90, 0, 0x00000000, id_bhvStar),
	OBJECT(E_MODEL_STAR, 5876, 2314, 19910, 0, 90, 0, (1 << 24), id_bhvStar),
	OBJECT(E_MODEL_NONE, -1945, -120, -6874, 0, 0, 0, (2 << 24), id_bhvBowserCourseRedCoinStar),
	OBJECT(E_MODEL_RED_COIN, -4524, 1003, -8351, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, -4953, 2662, -9371, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, 1781, 1120, -6825, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, -846, 1059, -8041, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, -2705, -409, -5574, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, 383, 2051, -5244, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, -2708, -409, -7998, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, -587, -409, -6074, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_BOUNCY_PLATFORM, 1767, 4723, -2522, 0, 90, 0, (8 << 8), id_bhvBouncyPlatform),
	OBJECT(E_MODEL_BOUNCY_PLATFORM, 1767, 6850, -800, 0, 90, 0, (8 << 8), id_bhvBouncyPlatform),
	OBJECT(E_MODEL_NONE, -9156, -1493, -7452, 0, 90, 0, 0x00000000, id_bhvCoinFormation),
	OBJECT(E_MODEL_NONE, 1445, 3377, -516, 0, 0, 0, 0x00000000, id_bhvCoinFormation),
	OBJECT(E_MODEL_NONE, 1702, -1, -9288, 0, 90, 0, 0x00000000, id_bhvCoinFormation),
	OBJECT(E_MODEL_NONE, -3955, -411, -5665, 0, 0, 0, (17 << 16), id_bhvCoinFormation),
	OBJECT(E_MODEL_NONE, 398, -409, -5257, 0, 0, 0, (17 << 16), id_bhvCoinFormation),
	OBJECT(E_MODEL_NONE, 4308, 1899, 2153, 0, 90, 0, (0 << 16), id_bhvCoinFormation),
	OBJECT(E_MODEL_NONE, 15497, 12266, -2986, 0, 0, 0, (2 << 16), id_bhvCoinFormation),
	// next object, no acts, doesnt exist
	// this exists
	OBJECT_WITH_ACTS(E_MODEL_EXCLAMATION_BOX, -8366, -1181, -7919, 0, 0, 0, 0x10000, id_bhvExclamationBox, 31),
	OBJECT(E_MODEL_NONE, -7903, -368, -7469, 0, 0, 0, (0 << 16), id_bhvCoinFormation),
	// 9 BLUE COINS will be done later
	// whats 0xf7 bhv??
	OBJECT(E_MODEL_BITS_WARP_PIPE, -6111, -73, -8721, 90, 0, 0, (0 << 16), id_bhvFakeWarpPipe),
	OBJECT(E_MODEL_BITS_WARP_PIPE, -6111, -93, -5241, 270, 0, 0, (21 << 16), id_bhvFakeWarpPipe),
	TERRAIN(jrb_area_1_collision),
	MACRO_OBJECTS(jrb_area_1_macro_objs),
	SET_BACKGROUND_MUSIC(0x00, 8),
	TERRAIN_TYPE(TERRAIN_GRASS),
	/* Fast64 begin persistent block [area commands] */
	/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, jrb_area_2),
	WARP_NODE(10, 9, 2, 0, 0),
	WARP_NODE(240, 26, 1, 82, 0),
	WARP_NODE(241, 26, 1, 92, 0),
	OBJECT_WITH_ACTS(0, -15632, 250, -5138, 0, 90, 0, 0xa0000, bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(E_MODEL_ROTATING_PLATFORM_JRB, -13241, 40, -5144, 0, 0, 0, 0x10000, id_bhvRotPlatformJRB, 31),
	OBJECT_WITH_ACTS(E_MODEL_ROTATING_PLATFORM_JRB, -8065, 310, -1703, 0, 0, 0, 0x0, id_bhvRotPlatformJRB, 31),
	OBJECT_WITH_ACTS(E_MODEL_ROTATING_PLATFORM_JRB, 6195, 778, -591, 0, 0, 0, 0x10000, id_bhvRotPlatformJRB, 31),
	OBJECT_WITH_ACTS(E_MODEL_ROTATING_PLATFORM_JRB, 8895, 778, -591, 0, 0, 0, 0x10000, id_bhvRotPlatformJRB, 31),
	OBJECT_WITH_ACTS(E_MODEL_ROTATING_PLATFORM_JRB, 8895, 778, 2109, 0, 0, 0, 0x10000, id_bhvRotPlatformJRB, 31),
	OBJECT_WITH_ACTS(E_MODEL_ROTATING_PLATFORM_JRB, 11465, 1235, 7817, 0, 0, 0, 0x0, id_bhvRotPlatformJRB, 31),
	OBJECT_WITH_ACTS(E_MODEL_ROTATING_PLATFORM_JRB, 16926, 988, 8897, 0, 0, 0, 0x0, id_bhvRotPlatformJRB, 31),
	OBJECT_WITH_ACTS(E_MODEL_ROTATING_PLATFORM_JRB, 19726, 1188, 8897, 0, 0, 0, 0x0, id_bhvRotPlatformJRB, 31),
	OBJECT_WITH_ACTS(E_MODEL_ROTATING_PLATFORM_JRB, 22526, 1388, 8897, 0, 0, 0, 0x0, id_bhvRotPlatformJRB, 31),
	OBJECT_WITH_ACTS(E_MODEL_ROTATING_PLATFORM_JRB, 22526, 1588, 6097, 0, 0, 0, 0x0, id_bhvRotPlatformJRB, 31),
	OBJECT_WITH_ACTS(E_MODEL_ROTATING_PLATFORM_JRB, 22526, 1788, 1497, 0, 0, 0, 0x0, id_bhvRotPlatformJRB, 31),
	OBJECT_WITH_ACTS(122, 22513, 2576, -925, 0, 0, 0, 0x4010000, bhvStar, 31),
	OBJECT_WITH_ACTS(E_MODEL_NEW_THWOMP, -8165, 1448, -6479, 0, 0, 0, 0x0, id_bhvThwomp, 31),
	OBJECT_WITH_ACTS(E_MODEL_NEW_THWOMP, -14197, 307, -5131, 0, 270, 0, 0x0, id_bhvThwomp, 31),
	OBJECT_WITH_ACTS(E_MODEL_NEW_THWOMP, -8067, 577, -673, 0, 180, 0, 0x0, id_bhvThwomp, 31),
	OBJECT_WITH_ACTS(E_MODEL_NEW_THWOMP, 5180, 1045, -577, 0, 90, 0, 0x0, id_bhvThwomp, 31),
	OBJECT_WITH_ACTS(E_MODEL_NEW_THWOMP, 7246, 1045, -606, 0, 90, 0, 0x0, id_bhvThwomp, 31),
	OBJECT_WITH_ACTS(E_MODEL_NEW_THWOMP, 8899, 1045, -1675, 0, 0, 0, 0x0, id_bhvThwomp, 31),
	OBJECT_WITH_ACTS(E_MODEL_NEW_THWOMP, 8895, 1045, 3169, 0, 0, 0, 0x0, id_bhvThwomp, 31),
	OBJECT_WITH_ACTS(E_MODEL_NEW_THWOMP, 9477, 2020, 7811, 0, 90, 0, 0x440000, id_bhvThwomp, 31),
	OBJECT_WITH_ACTS(E_MODEL_NEW_THWOMP, 254, 1097, -2419, 0, 90, 0, 0x260000, id_bhvThwomp, 31),
	OBJECT_WITH_ACTS(E_MODEL_NEW_THWOMP, -546, 1097, -3219, 0, 90, 0, 0x260000, id_bhvThwomp, 31),
	OBJECT_WITH_ACTS(E_MODEL_NEW_THWOMP, -546, 1097, -2419, 0, 90, 0, 0x260000, id_bhvThwomp, 31),
	OBJECT_WITH_ACTS(E_MODEL_NEW_THWOMP, 254, 1097, -3219, 0, 90, 0, 0x260000, id_bhvThwomp, 31),
	OBJECT_WITH_ACTS(192, -4516, 1097, 179, 0, 0, 0, 0x0, bhvGoomba, 31),
	OBJECT_WITH_ACTS(E_MODEL_NEW_THWOMP, 21762, 1655, 8893, 0, 90, 0, 0x0, id_bhvThwomp, 31),
	OBJECT_WITH_ACTS(E_MODEL_NEW_THWOMP, 18667, 1455, 8902, 0, 90, 0, 0x0, id_bhvThwomp, 31),
	OBJECT_WITH_ACTS(E_MODEL_NEW_THWOMP, 22524, 1855, 6834, 0, 0, 0, 0x0, id_bhvThwomp, 31),
	OBJECT_WITH_ACTS(137, -5799, 851, -931, 0, 0, 0, 0x10000, bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(137, 13434, 1874, 8425, 0, 0, 0, 0x10000, bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, 13230, 1767, 8760, 0, 0, 0, 0x5000000, bhvBowserCourseRedCoinStar, 31),
	OBJECT_WITH_ACTS(215, -9091, 606, -1048, 0, 0, 0, 0x0, bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -7245, 606, -988, 0, 0, 0, 0x0, bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 1010, 1097, -2807, 0, 0, 0, 0x0, bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -8188, 2753, -6501, 0, 0, 0, 0x0, bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 11588, 1492, 9763, 0, 0, 0, 0x0, bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 10087, 2581, 7840, 0, 0, 0, 0x0, bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 12221, 1550, 5789, 0, 0, 0, 0x0, bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 11460, 1512, 7838, 0, 0, 0, 0x0, bhvRedCoin, 31),
	OBJECT_WITH_ACTS(192, 11462, 1492, 9781, 0, 0, 0, 0x0, bhvGoomba, 31),
	OBJECT_WITH_ACTS(22, -6409, 606, -3852, 90, 270, 0, 0x2, Bhv_Custom_0x1300025c, 31),
	OBJECT_WITH_ACTS(22, -9505, 250, -3852, 0, 0, 0, 0x10002, Bhv_Custom_0x1300025c, 31),
	OBJECT_WITH_ACTS(22, 8814, 711, 6320, 90, 0, 0, 0x1, Bhv_Custom_0x1300025c, 31),
	OBJECT_WITH_ACTS(22, 8814, 711, 8684, 90, 180, 0, 0x10001, Bhv_Custom_0x1300025c, 31),
	OBJECT_WITH_ACTS(0, -6295, 0, -1240, 0, 0, 0, 0x5004e20, Bhv_Custom_0x1300003c, 31),
	OBJECT_WITH_ACTS(249, -13340, 250, -7447, 0, 0, 0, 0x0, bhvTree, 31),
	OBJECT_WITH_ACTS(0, -13340, 801, -7447, 0, 0, 0, 0x0, bhvHidden1upInPoleSpawner, 31),
	OBJECT_WITH_ACTS(249, -4172, 1097, 1076, 0, 0, 0, 0x0, bhvTree, 31),
	OBJECT_WITH_ACTS(249, 3951, 1097, -2336, 0, 0, 0, 0x0, bhvTree, 31),
	OBJECT_WITH_ACTS(249, 10199, 711, 7194, 0, 0, 0, 0x0, bhvTree, 31),
	OBJECT_WITH_ACTS(249, 22698, 2246, 4245, 0, 0, 0, 0x0, bhvTree, 31),
	OBJECT_WITH_ACTS(247, -2732, 1097, -2265, 0, 0, 0, 0x0, Bhv_Custom_0x0040eb00, 31),
	OBJECT_WITH_ACTS(247, -7968, 933, -5048, 0, 0, 0, 0x0, Bhv_Custom_0x0040eb00, 31),
	OBJECT_WITH_ACTS(247, 3278, 1097, 2312, 0, 0, 0, 0x0, Bhv_Custom_0x0040eb00, 31),
	OBJECT_WITH_ACTS(247, 11560, 1492, 10005, 0, 0, 0, 0x0, Bhv_Custom_0x0040eb00, 31),
	OBJECT_WITH_ACTS(247, 12332, 713, 6990, 0, 0, 0, 0x0, Bhv_Custom_0x0040eb00, 31),
	OBJECT_WITH_ACTS(247, 22475, 2246, -583, 0, 0, 0, 0x0, Bhv_Custom_0x0040eb00, 31),
	OBJECT_WITH_ACTS(0, -10891, 250, -5119, 0, 90, 0, 0x0, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -4746, 739, -1673, 0, 0, 0, 0x20000, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -13318, 250, -7080, 0, 0, 0, 0x110000, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 11381, 921, 5343, 0, 90, 0, 0x0, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(84, -10087, 250, -4173, 0, 199, 0, 0x30000, bhvBird, 31),
	OBJECT_WITH_ACTS(84, -6466, 606, -22, 0, 34, 0, 0x40000, bhvBird, 31),
	OBJECT_WITH_ACTS(84, -3515, 1097, 1838, 0, 269, 0, 0x10000, bhvBird, 31),
	OBJECT_WITH_ACTS(84, 2385, 1097, 2300, 0, 46, 0, 0x30000, bhvBird, 31),
	OBJECT_WITH_ACTS(84, 8605, 711, 7944, 0, 236, 0, 0x30000, bhvBird, 31),
	OBJECT_WITH_ACTS(0, 12659, 713, 7803, 0, 0, 0, 0x110000, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 9951, 1160, -588, 0, 0, 0, 0x110000, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 8906, 1097, 2103, 0, 0, 0, 0x120000, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(192, -4602, 1097, -3015, 0, 0, 0, 0x0, bhvGoomba, 31),
	OBJECT_WITH_ACTS(0, 22512, 2118, 1469, 0, 0, 0, 0x120000, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(84, -8594, 1448, -5897, 0, 328, 0, 0x30000, bhvBird, 31),
	OBJECT_WITH_ACTS(84, -1870, 1097, -3142, 0, 166, 0, 0x30000, bhvBird, 31),
	OBJECT_WITH_ACTS(84, 22541, 2246, 3779, 0, 103, 0, 0x30000, bhvBird, 31),
	OBJECT_WITH_ACTS(84, 3567, 1097, -3194, 0, 163, 0, 0x10000, bhvBird, 31),
	OBJECT_WITH_ACTS(84, 22534, 1652, 8903, 0, 0, 0, 0x30000, bhvBird, 31),
	OBJECT_WITH_ACTS(0, 8891, 1106, 4786, 0, 0, 0, 0x0, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(247, -1783, 1097, 1541, 0, 0, 0, 0x0, Bhv_Custom_0x0040eb00, 31),
	OBJECT_WITH_ACTS(116, -1783, 1097, 1541, 0, 0, 0, 0x0, bhvOneCoin, 31),
	OBJECT_WITH_ACTS(247, 1905, 1097, 2907, 0, 0, 0, 0x0, Bhv_Custom_0x0040eb00, 31),
	OBJECT_WITH_ACTS(116, 1905, 1097, 2907, 0, 0, 0, 0x0, bhvOneCoin, 31),
	OBJECT_WITH_ACTS(247, 2297, 1097, 1679, 0, 0, 0, 0x0, Bhv_Custom_0x0040eb00, 31),
	OBJECT_WITH_ACTS(116, 2297, 1097, 1679, 0, 0, 0, 0x0, bhvOneCoin, 31),
	OBJECT_WITH_ACTS(247, -1948, 1097, 2651, 0, 0, 0, 0x0, Bhv_Custom_0x0040eb00, 31),
	OBJECT_WITH_ACTS(116, -1948, 1097, 2651, 0, 0, 0, 0x0, bhvOneCoin, 31),
	OBJECT_WITH_ACTS(247, 334, 1097, 2405, 0, 0, 0, 0x0, Bhv_Custom_0x0040eb00, 31),
	OBJECT_WITH_ACTS(116, 334, 1097, 2405, 0, 0, 0, 0x0, bhvOneCoin, 31),
	OBJECT_WITH_ACTS(122, -583, 2897, -3209, 0, 0, 0, 0x3000000, bhvStar, 31),
	OBJECT_WITH_ACTS(239, 15092, 1235, 8812, 0, 90, 0, 0x0, Bhv_Custom_0x040086a0, 31),
	TERRAIN(jrb_area_2_collision),
	MACRO_OBJECTS(jrb_area_2_macro_objs),
	SET_BACKGROUND_MUSIC(0x00, 78),
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

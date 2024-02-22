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
		WARP_NODE(10, 9, 2, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(240, 26, 1, 82, WARP_NO_CHECKPOINT),
		WARP_NODE(241, 26, 1, 92, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -15632, 250, -5138, 0, 90, 0, 0x000A0000, bhvSpinAirborneWarp),
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

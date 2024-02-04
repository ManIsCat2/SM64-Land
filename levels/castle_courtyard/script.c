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
#include "levels/castle_courtyard/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_courtyard_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _castle_courtyard_segment_7SegmentRomStart, _castle_courtyard_segment_7SegmentRomEnd),
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario),

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_courtyard_area_1),
	WARP_NODE(10, 16, 1, 1, WARP_NO_CHECKPOINT),
	WARP_NODE(0, 16, 2, 0, WARP_NO_CHECKPOINT),
	WARP_NODE(11, 12, 1, 10, WARP_NO_CHECKPOINT),
	WARP_NODE(12, 12, 2, 10, WARP_NO_CHECKPOINT),
	WARP_NODE(13, 5, 1, 10, WARP_NO_CHECKPOINT),
	WARP_NODE(14, 5, 2, 10, WARP_NO_CHECKPOINT),
	WARP_NODE(81, 16, 2, 0, WARP_NO_CHECKPOINT),
	WARP_NODE(82, 16, 2, 0, WARP_NO_CHECKPOINT),
	WARP_NODE(83, 16, 2, 0, WARP_NO_CHECKPOINT),
	WARP_NODE(84, 16, 2, 0, WARP_NO_CHECKPOINT),
	WARP_NODE(91, 16, 2, 0, WARP_NO_CHECKPOINT),
	WARP_NODE(92, 16, 2, 0, WARP_NO_CHECKPOINT),
	WARP_NODE(93, 16, 2, 0, WARP_NO_CHECKPOINT),
	WARP_NODE(94, 16, 2, 0, WARP_NO_CHECKPOINT),
	WARP_NODE(244, 6, 1, 50, WARP_NO_CHECKPOINT),
	WARP_NODE(245, 6, 1, 100, WARP_NO_CHECKPOINT),
	WARP_NODE(21, 12, 1, 10, WARP_NO_CHECKPOINT),
	WARP_NODE(22, 12, 2, 10, WARP_NO_CHECKPOINT),
	WARP_NODE(15, 16, 2, 10, WARP_NO_CHECKPOINT),
	WARP_NODE(1, 28, 2, 10, WARP_NO_CHECKPOINT),
	WARP_NODE(2, 5, 3, 10, WARP_NO_CHECKPOINT),
	WARP_NODE(108, 26, 1, 0, WARP_NO_CHECKPOINT),
	WARP_NODE(109, 26, 1, 0, WARP_NO_CHECKPOINT),
	WARP_NODE(240, 6, 1, 50, WARP_NO_CHECKPOINT),
	WARP_NODE(241, 26, 1, 241, WARP_NO_CHECKPOINT),
	MARIO_POS(0x01, 0, 0, 2, 0),
	OBJECT(E_MODEL_BITS_WARP_PIPE, -4029, 351, 1807, 0, 180, 0, 0x000A0000, id_bhvWarpPipe),
	OBJECT(E_MODEL_BITS_WARP_PIPE, -3153, 351, 283, 0, 0, 0, (21 << 16), id_bhvWarpPipe),
	OBJECT(E_MODEL_BITS_WARP_PIPE, -2268, 351, -2567, 0, 0, 0, (22 << 16), id_bhvWarpPipe),
	OBJECT(E_MODEL_BITS_WARP_PIPE, 1085, 590, 1284, 0, 0, 0, (13 << 16), id_bhvWarpPipe),
	OBJECT(E_MODEL_BITS_WARP_PIPE, 5189, 589, -1338, 0, 0, 0, (14 << 16), id_bhvWarpPipe),
	OBJECT(MODEL_NONE, -3150, 600, -44, 0, 0, 0, (81 << 16), bhvDeathWarp),
	OBJECT(MODEL_NONE, -3150, 600, -44, 0, 0, 0, (91 << 16), bhvDeathWarp),
	OBJECT(MODEL_NONE, -2271, 591, -2229, 0, 180, 0, (82 << 16), bhvDeathWarp),
	OBJECT(MODEL_NONE, -2271, 591, -2229, 0, 180, 0, (92 << 16), bhvDeathWarp),
	OBJECT(E_MODEL_STAR, -217, 1277, 1131, 0, 180, 0, (1 << 24), id_bhvStar),
	OBJECT(MODEL_NONE, -4424, 1980, -362, 0, 90, 0, (11 << 16), bhvSpinAirborneWarp),
	OBJECT(MODEL_NONE, 1087, 807, 823, 0, 0, 0, (83 << 16), bhvDeathWarp),
	OBJECT(MODEL_NONE, 1087, 807, 823, 0, 0, 0, (93 << 16), bhvDeathWarp),
	OBJECT(MODEL_NONE, 4878, 849, -1025, 0, 135, 0, (84 << 16), bhvDeathWarp),
	OBJECT(MODEL_NONE, 4878, 849, -1025, 0, 135, 0, (94 << 16), bhvDeathWarp),
	OBJECT(E_MODEL_BITS_WARP_PIPE, 1044, 828, -1238, 20, 0, 0, (1 << 16), id_bhvWarpPipe),
	OBJECT(E_MODEL_BOBOMB_BUDDY, 5427, 590, 2086, 0, 0, 0, (36 << 16), id_bhvBobombBuddy),
	OBJECT(MODEL_NONE, 5416, 791, 1888, 0, 0, 0, (108 << 16), bhvDeathWarp),
	OBJECT(MODEL_NONE, 5416, 791, 1888, 0, 0, 0, (109 << 16), bhvDeathWarp),
	OBJECT(MODEL_NONE, -68, 771, -697, 0, 0, 0, (241 << 16), bhvDeathWarp),
	TERRAIN(castle_courtyard_area_1_collision),
	MACRO_OBJECTS(castle_courtyard_area_1_macro_objs),
	SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
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

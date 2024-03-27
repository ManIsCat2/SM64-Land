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
#include "levels/bbh/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bbh_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario),

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bbh_area_1),
	WARP_NODE(10, 9, 1, 0, WARP_NO_CHECKPOINT),
	WARP_NODE(0xF0, 16, 2, 31, WARP_NO_CHECKPOINT),
	WARP_NODE(0xF1, 16, 2, 41, WARP_NO_CHECKPOINT),
	MARIO_POS(0x01, 0, 0, 2189, 0),
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
	OBJECT(E_MODEL_SKEETER, -1393, 875, 2722, 0, 0, 0, 0x00000000, id_bhvSkeeter),
	OBJECT(MODEL_NONE, 105, 875, 3265, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -1233, 1110, -11351, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -4593, 3116, -12572, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -8525, 6300, -12501, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -6161, 3186, -13139, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -3138, 2880, -13139, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -1613, 1200, -11465, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -2593, -2304, -9428, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -5045, 1750, -12802, 0, 0, 0, 0x00000000, bhvStaticObject),
	TERRAIN(bbh_area_1_collision),
	MACRO_OBJECTS(bbh_area_1_macro_objs),
	SET_BACKGROUND_MUSIC(0x00, 36),
	TERRAIN_TYPE(TERRAIN_GRASS),
	/* Fast64 begin persistent block [area commands] */
	/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 2189, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

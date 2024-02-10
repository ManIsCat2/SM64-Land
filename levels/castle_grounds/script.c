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
#include "levels/castle_grounds/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_grounds_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
	LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
	LOAD_MIO0(5,_group10_mio0SegmentRomStart,_group10_mio0SegmentRomEnd),
	LOAD_RAW(12,_group10_geoSegmentRomStart,_group10_geoSegmentRomEnd),
	LOAD_MIO0(6,_group13_mio0SegmentRomStart,_group13_mio0SegmentRomEnd),
	LOAD_RAW(13,_group13_geoSegmentRomStart,_group13_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario),
JUMP_LINK(script_func_global_1),
JUMP_LINK(script_func_global_11),
JUMP_LINK(script_func_global_14),
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_grounds_area_1),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 241, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(120, LEVEL_WF, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(9, LEVEL_CASTLE_GROUNDS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(109, LEVEL_CASTLE_GROUNDS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(108, LEVEL_CASTLE_GROUNDS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(51, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(18, LEVEL_BOB, 3, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(17, LEVEL_ENDING, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(16, LEVEL_BITFS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(15, LEVEL_BITFS, 2, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_CASTLE_COURTYARD, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(71, LEVEL_COTMC, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(34, LEVEL_CASTLE_GROUNDS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(33, LEVEL_CASTLE_GROUNDS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(32, LEVEL_CASTLE_GROUNDS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(31, LEVEL_CASTLE_GROUNDS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(24, LEVEL_CASTLE_GROUNDS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(23, LEVEL_CASTLE_GROUNDS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(22, LEVEL_CASTLE_GROUNDS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(21, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_WF, 2, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_WF, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BOB, 2, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(E_MODEL_BITS_WARP_PIPE, -7419, 136, -1690, 0, 0, 0, (0 << 24) | (51 << 16) | (0 << 8) | (0), id_bhvWarpPipe),
		// REAL
		OBJECT(E_MODEL_NONE, -3615, 336, -1931, 0, 0, 0, (1 << 16), bhvPipeCover),
		OBJECT(E_MODEL_NONE, -3615, 136, -1931, 0, 0, 0, (0 << 24) | (120 << 16) | (0 << 8) | (0), id_bhvWarpPipe),
		OBJECT(E_MODEL_BLOCKED_WARP_PIPE, -3615, 136, -1931, 0, 0, 0, (1 << 16), id_bhvFakeWarpPipe),
		// real end
		OBJECT(E_MODEL_NONE, 3704, 336, -2507, 0, 0, 0, 0x00000000, bhvPipeCover),
		OBJECT(E_MODEL_BLOCKED_WARP_PIPE, 3704, 136, -2507, 0, 0, 0, (0 << 24) | (13 << 16) | (0 << 8) | (0), id_bhvWarpPipe),
		OBJECT(E_MODEL_NONE, 6027, 336, -3383, 0, 0, 0, 0x00000000, bhvPipeCover),
		OBJECT(E_MODEL_BLOCKED_WARP_PIPE, 6027, 136, -3383, 0, 0, 0, (0 << 24) | (14 << 16) | (0 << 8) | (0), id_bhvWarpPipe),
		OBJECT(E_MODEL_RED_WARP_PIPE, 7364, 136, -1632, 0, 0, 0, (0 << 24) | (18 << 16) | (0 << 8) | (0), id_bhvWarpPipe),
		OBJECT(E_MODEL_8_STAR_CAGE, 7364, 136, -1632, 0, 0, 0, 0x00000000, bhv8StarCage),
		OBJECT(E_MODEL_WORLD_CANNON, -7172, 136, 1052, 0, 0, 0, 0x00000000, bhvWorldCannon),
		MARIO_POS(0x01, 0, -10827, 136, -187),
		OBJECT(0, -7430, 250, -1334, 0, -180, 0,  0x150000, bhvAirborneStarCollectWarp),
		OBJECT(0, -3622, 250, -1570, 0, -180, 0,  0x160000, bhvAirborneStarCollectWarp),
		OBJECT(0, 3702, 250, -2171, 0, -180, 0,  0x170000, bhvAirborneStarCollectWarp),
		OBJECT(0, 6040, 250, -3040, 0, -180, 0,  0x180000, bhvAirborneStarCollectWarp),
		OBJECT(0, 7375, 336, -1284, 0, 0, 0,  0x6c0000, bhvAirborneStarCollectWarp),
		OBJECT(E_MODEL_BIRDS, -7046, 136, 1698, 0, -117, 0,  0x30000, id_bhvBird),
		OBJECT(E_MODEL_BIRDS, -3198, 136, 2561, 0, -171, 0,  0x30000, id_bhvBird),
		OBJECT(E_MODEL_BIRDS, -845, 764, -1585, 0, 138, 0,  0x30000, id_bhvBird),
		OBJECT(E_MODEL_BIRDS, 4825, 243, 524, 0, -145, 0,  0x30000, id_bhvBird),
		OBJECT(E_MODEL_BIRDS, 4764, 904, -1754, 0, 0, 0,  0x30000, id_bhvBird),
		OBJECT(E_MODEL_BOBOMB_BUDDY, -7796, 136, -1609, 0, 0, 0,  0x280000, id_bhvBobombBuddy),
		OBJECT(E_MODEL_BOBOMB_BUDDY, -4018, 136, -1889, 0, 0, 0,  0x2a0000, id_bhvBobombBuddy),
		OBJECT(E_MODEL_BOBOMB_BUDDY, 7709, 136, -1016, 0, 0, 0,  0x2b0000, id_bhvBobombBuddy),
		OBJECT(E_MODEL_FISH, -12166, 0, -1763, 0, 0, 0,  0x0, id_bhvChirpChirp),
		OBJECT(E_MODEL_FISH, -9423, 0, -3568, 0, 71, 0,  0x0, id_bhvChirpChirp),
		OBJECT(E_MODEL_FISH, -3668, 0, -6228, 0, 42, 0,  0x0, id_bhvChirpChirp),
		OBJECT(E_MODEL_FISH, 645, 0, -5029, 0, -90, 0,  0x0, id_bhvChirpChirp),
		OBJECT(E_MODEL_FISH, 7514, 0, -6716, 0, 114, 0,  0x0, id_bhvChirpChirp),
		OBJECT(E_MODEL_FISH, 10987, 0, -5010, 0, 0, 0,  0x0, id_bhvChirpChirp),
		OBJECT(E_MODEL_FISH, -7707, 0, -6538, 0, 0, 0,  0x0, id_bhvChirpChirp),
		OBJECT(E_MODEL_FISH, 3922, 0, -5864, 0, 0, 0,  0x0, id_bhvChirpChirp),
		OBJECT(E_MODEL_FISH, -1051, 0, -6260, 0, 0, 0,  0x0, id_bhvChirpChirp),
		OBJECT(E_MODEL_FISH, -6469, 0, -5374, 0, 0, 0,  0x0, id_bhvChirpChirp),
		OBJECT(0, -7430, 250, -1334, 0, -180, 0,  0x1f0000, bhvDeathWarp),
		OBJECT(0, -3622, 250, -1570, 0, -180, 0,  0x200000, bhvDeathWarp),
		OBJECT(0, 3702, 250, -2171, 0, -180, 0,  0x210000, bhvDeathWarp),
		OBJECT(0, 6040, 250, -3040, 0, -180, 0,  0x220000, bhvDeathWarp),
		OBJECT(0, 7375, 336, -1284, 0, 0, 0,  0x6d0000, bhvDeathWarp),
		OBJECT(0, 578, 360, -204, 0, 0, 0,  0xf10000, bhvDeathWarp),
		OBJECT(E_MODEL_BIRDS, -5269, 196, 1618, 0, 99, 0,  0x0, id_bhvEndBirds1),
		OBJECT(E_MODEL_BIRDS, -4761, 764, -1248, 0, 7, 0,  0x0, id_bhvEndBirds1),
		OBJECT(E_MODEL_BIRDS, 4174, 300, 667, 0, -111, 0,  0x0, id_bhvEndBirds1),
		OBJECT(E_MODEL_BIRDS, 6994, 207, -2052, 0, -84, 0,  0x0, id_bhvEndBirds1),
		OBJECT(E_MODEL_BIRDS, -5834, 190, 1530, 0, 21, 0,  0x0, id_bhvEndBirds1),
		OBJECT(0, -4866, 2206, -889, 0, 38, 0,  0xb0000, bhvFlyingWarp),
		OBJECT(0, -10827, 136, -187, 0, 90, 0,  0x90000, bhvSpinAirborneWarp),
		OBJECT(0, 4710, 243, -1223, 0, 0, 0,  0x470000, bhvSpinAirborneWarp),
		OBJECT(0, 4710, 243, -1534, 0, 0, 0,  0xa470000, bhvWarp),
		OBJECT(E_MODEL_DANCING_HILL, -11918, 0, -10464, 0, -4, 0,  0x0, id_bhvDancingHill),
		OBJECT(E_MODEL_DANCING_HILL, -4300, 0, -12712, 0, 0, 0,  0x0, id_bhvDancingHill),
		OBJECT(E_MODEL_DANCING_HILL, 803, 0, -12397, 0, 0, 0,  0x0, id_bhvDancingHill),
		OBJECT(E_MODEL_DANCING_HILL, 5974, 0, -11011, 0, 0, 0,  0x0, id_bhvDancingHill),
		OBJECT(E_MODEL_DANCING_HILL, 13382, 0, -9016, 0, -27, 0,  0x0, id_bhvDancingHill),
		OBJECT(E_MODEL_DANCING_HILL, -15564, 0, -9207, 0, 14, 0,  0x0, id_bhvDancingHill),
		OBJECT(E_MODEL_DANCING_HILL, 9287, 0, -13051, 0, -14, 0,  0x0, id_bhvDancingHill),
		OBJECT(E_MODEL_DANCING_HILL, 12162, 0, -12097, 0, -12, 0,  0x0, id_bhvDancingHill),
		OBJECT(E_MODEL_DANCING_HILL, -9850, 0, -13389, 0, 0, 0,  0x10000, id_bhvDancingHill),
		OBJECT(E_MODEL_DANCING_HILL, 16934, 0, -10157, 0, -12, 0,  0x0, id_bhvDancingHill),
		OBJECT(E_MODEL_PIPE_COVER, 9170, 336, -1717, 0, 0, 0, 0x00000000, bhvPipeCover),
		OBJECT(E_MODEL_STAR, -2690, 1630, -2470, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), id_bhvStar),
		OBJECT(MODEL_NONE, -10827, 136, -187, 0, 0, 0, (0 << 24) | (9 << 16) | (0 << 8) | (0), bhvSpinAirborneWarp),
		OBJECT(E_MODEL_BLUE_WARP_PIPE, 9170, 136, -1717, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (0), id_bhvWarpPipe),
		TERRAIN(castle_grounds_area_1_collision),
		MACRO_OBJECTS(castle_grounds_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x04),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -10827, 136, -187),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

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
LOAD_MODEL_FROM_GEO(MODEL_BITS_WARP_PIPE, warp_pipe_geo)
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_grounds_area_1),
		WARP_NODE(10,9,1,0,0),
WARP_NODE(11,9,1,10,0),
WARP_NODE(14,9,2,10,0),
WARP_NODE(12,24,1,10,0),
WARP_NODE(13,24,2,10,0),
WARP_NODE(21,9,1,10,0),
WARP_NODE(22,16,1,0,0),
WARP_NODE(23,16,1,0,0),
WARP_NODE(24,16,1,0,0),
WARP_NODE(31,16,1,0,0),
WARP_NODE(32,16,1,0,0),
WARP_NODE(33,16,1,0,0),
WARP_NODE(34,16,1,0,0),
WARP_NODE(71,28,1,10,0),
WARP_NODE(1,26,1,10,0),
WARP_NODE(15,19,2,10,0),
WARP_NODE(16,19,1,10,0),
WARP_NODE(17,25,1,10,0),
WARP_NODE(18,9,3,10,0),
WARP_NODE(51,9,1,10,0),
WARP_NODE(108,16,1,0,0),
WARP_NODE(109,16,1,0,0),
WARP_NODE(9,16,1,0,0),
WARP_NODE(120,24,1,10,0),
WARP_NODE(240,6,1,50,0),
WARP_NODE(241,16,1,241,0),
	OBJECT_WITH_ACTS(0, -10827, 136, -187, 0, 90, 0, 0x90000, bhvSpinAirborneWarp, 31),
	MARIO_POS(0x01, 0,-10827, 136, -187),
	OBJECT_WITH_ACTS(MODEL_BITS_WARP_PIPE, -7419, 136, -1690, 0, 0, 0, 0x330000, bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(MODEL_BITS_WARP_PIPE, 6027, 136, -3383, 0, 0, 0, 0xe0000, bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(84, -7046, 136, 1698, 0, 243, 0, 0x30000, bhvBird, 31),
	OBJECT_WITH_ACTS(84, -3198, 136, 2561, 0, 189, 0, 0x30000, bhvBird, 31),
	OBJECT_WITH_ACTS(84, -845, 764, -1585, 0, 138, 0, 0x30000, bhvBird, 31),
	OBJECT_WITH_ACTS(84, 4825, 243, 524, 0, 215, 0, 0x30000, bhvBird, 31),
	OBJECT_WITH_ACTS(84, 4764, 904, -1754, 0, 0, 0, 0x30000, bhvBird, 31),
	OBJECT_WITH_ACTS(MODEL_BITS_WARP_PIPE, -3615, 136, -1931, 0, 0, 0, 0x780000, bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(MODEL_BITS_WARP_PIPE, 3704, 136, -2507, 0, 0, 0, 0xd0000, bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(0, -7430, 250, -1334, 0, 180, 0, 0x1f0000, bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, -3622, 250, -1570, 0, 180, 0, 0x200000, bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, 3702, 250, -2171, 0, 180, 0, 0x210000, bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, 6040, 250, -3040, 0, 180, 0, 0x220000, bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, -7430, 250, -1334, 0, 180, 0, 0x150000, bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, -3622, 250, -1570, 0, 180, 0, 0x160000, bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, 3702, 250, -2171, 0, 180, 0, 0x170000, bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, 6040, 250, -3040, 0, 180, 0, 0x180000, bhvAirborneStarCollectWarp, 31),
	//OBJECT_WITH_ACTS(240, -9749, 136, 324, 0, 0, 0, 0x20000, 0x0040ef64, 31),
	//OBJECT_WITH_ACTS(240, -5697, 136, -714, 0, 0, 0, 0x20000, 0x0040ef64, 31),
	//OBJECT_WITH_ACTS(240, -2257, 136, -837, 0, 0, 0, 0x10000, 0x0040ef64, 31),
//	OBJECT_WITH_ACTS(240, 7262, 136, -18, 0, 0, 0, 0x20000, 0x0040ef64, 31),
	OBJECT_WITH_ACTS(0, -12166, 0, -1763, 0, 0, 0, 0x0, bhvChirpChirp, 31),
	OBJECT_WITH_ACTS(0, -9423, 0, -3568, 0, 71, 0, 0x0, bhvChirpChirp, 31),
	OBJECT_WITH_ACTS(0, -3668, 0, -6228, 0, 42, 0, 0x0, bhvChirpChirp, 31),
	OBJECT_WITH_ACTS(0, 645, 0, -5029, 0, 270, 0, 0x0, bhvChirpChirp, 31),
	OBJECT_WITH_ACTS(0, 7514, 0, -6716, 0, 114, 0, 0x0, bhvChirpChirp, 31),
	OBJECT_WITH_ACTS(0, 10987, 0, -5010, 0, 0, 0, 0x0, bhvChirpChirp, 31),
	OBJECT_WITH_ACTS(0, -7707, 0, -6538, 0, 0, 0, 0x0, bhvChirpChirp, 31),
	OBJECT_WITH_ACTS(0, 3922, 0, -5864, 0, 0, 0, 0x0, bhvChirpChirp, 31),
	OBJECT_WITH_ACTS(0, -1051, 0, -6260, 0, 0, 0, 0x0, bhvChirpChirp, 31),
	OBJECT_WITH_ACTS(0, -6469, 0, -5374, 0, 0, 0, 0x0, bhvChirpChirp, 31),
	OBJECT_WITH_ACTS(187, -5269, 196, 1618, 0, 99, 0, 0x0, bhvEndBirds1, 31),
	OBJECT_WITH_ACTS(187, -4761, 764, -1248, 0, 7, 0, 0x0, bhvEndBirds1, 31),
	OBJECT_WITH_ACTS(187, 4174, 300, 667, 0, 249, 0, 0x0, bhvEndBirds1, 31),
	OBJECT_WITH_ACTS(187, 6994, 207, -2052, 0, 276, 0, 0x0, bhvEndBirds1, 31),
	OBJECT_WITH_ACTS(187, -5834, 190, 1530, 0, 21, 0, 0x0, bhvEndBirds1, 31),
	OBJECT_WITH_ACTS(E_MODEL_DANCING_HILL, -11918, 0, -10464, 0, 356, 0, 0x0, id_bhvDancingHill, 31),
	OBJECT_WITH_ACTS(E_MODEL_DANCING_HILL, -4300, 0, -12712, 0, 0, 0, 0x0, id_bhvDancingHill, 31),
	OBJECT_WITH_ACTS(E_MODEL_DANCING_HILL, 803, 0, -12397, 0, 0, 0, 0x0, id_bhvDancingHill, 31),
	OBJECT_WITH_ACTS(E_MODEL_DANCING_HILL, 5974, 0, -11011, 0, 0, 0, 0x0, id_bhvDancingHill, 31),
	OBJECT_WITH_ACTS(E_MODEL_DANCING_HILL, 13382, 0, -9016, 0, 333, 0, 0x0, id_bhvDancingHill, 31),
	OBJECT_WITH_ACTS(E_MODEL_DANCING_HILL, -15564, 0, -9207, 0, 14, 0, 0x0, id_bhvDancingHill, 31),
	OBJECT_WITH_ACTS(E_MODEL_DANCING_HILL, 9287, 0, -13051, 0, 346, 0, 0x0, id_bhvDancingHill, 31),
	OBJECT_WITH_ACTS(E_MODEL_DANCING_HILL, 12162, 0, -12097, 0, 348, 0, 0x0, id_bhvDancingHill, 31),
	OBJECT_WITH_ACTS(E_MODEL_DANCING_HILL, -9850, 0, -13389, 0, 0, 0, 0x10000, id_bhvDancingHill, 31),
	OBJECT_WITH_ACTS(E_MODEL_DANCING_HILL, 16934, 0, -10157, 0, 348, 0, 0x0, id_bhvDancingHill, 31),
	/*OBJECT_WITH_ACTS(0, -7388, 84, -1689, 0, 0, 0, 0x0, 0x130001dc, 31),
	OBJECT_WITH_ACTS(0, -3645, 136, -1901, 0, 0, 0, 0x1000000, 0x130001dc, 31),
	OBJECT_WITH_ACTS(0, 6041, 136, -3277, 0, 0, 0, 0x3000000, 0x130001dc, 31),
	OBJECT_WITH_ACTS(0, 3729, 0, -2549, 0, 0, 0, 0x2000000, 0x130001dc, 31),*/
	OBJECT_WITH_ACTS(122, -2690, 1630, -2470, 0, 0, 0, 0x0, bhvStar, 31),
	OBJECT_WITH_ACTS(0, 4710, 243, -1223, 0, 0, 0, 0x470000, bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(0, 4710, 243, -1534, 0, 0, 0, 0xa470000, bhvWarp, 31),
	OBJECT_WITH_ACTS(E_MODEL_NONE, 9170, 136, -1717, 0, 0, 0, 0x10000, id_bhvBluePipe, 31),
	OBJECT_WITH_ACTS(E_MODEL_BLUE_WARP_PIPE_COVER, 9170, 136, -1717, 0, 0, 0, 0x10000, ggbhv, 31),
	//OBJECT_WITH_ACTS(0, 9172, 136, -1376, 0, 0, 0, 0x0, 0x00403f00, 31),
	//OBJECT_WITH_ACTS(53, -7172, 136, 1052, 0, 180, 0, 0x0, 0x130006ac, 31),
	OBJECT_WITH_ACTS(E_MODEL_RED_WARP_PIPE, 7364, 136, -1632, 0, 0, 0, 0x120000, id_bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(0, -4866, 2206, -889, 0, 38, 0, 0xb0000, bhvFlyingWarp, 31),
	//cage, 8 star will unlock
	OBJECT_WITH_ACTS(E_MODEL_8_STAR_CAGE, 7364, 136, -1632, 0, 180, 0, 0x8000000, bhv8StarCage, 31),
	OBJECT_WITH_ACTS(195, -7796, 136, -1609, 0, 0, 0, 0x280000, bhvBobombBuddy, 31),
	OBJECT_WITH_ACTS(195, -4018, 136, -1889, 0, 0, 0, 0x2a0000, bhvBobombBuddy, 31),
	OBJECT_WITH_ACTS(195, 7709, 136, -1016, 0, 0, 0, 0x2b0000, bhvBobombBuddy, 31),
	OBJECT_WITH_ACTS(0, 7375, 336, -1284, 0, 0, 0, 0x6c0000, bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, 7375, 336, -1284, 0, 0, 0, 0x6d0000, bhvDeathWarp, 31),
	//OBJECT_WITH_ACTS(0, 0, 0, 0, 0, 0, 0, 0x0, 0x0703f180, 31),
	//OBJECT_WITH_ACTS(58, 9170, 336, -1717, 0, 0, 0, 0xc030000, 0x0703fdc0, 31),
	OBJECT_WITH_ACTS(0, 578, 360, -204, 0, 0, 0, 0xf10000, bhvDeathWarp, 31),
		TERRAIN(castle_grounds_area_1_collision),
		
		MACRO_OBJECTS(castle_grounds_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x04),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0,-10827, 136, -187),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

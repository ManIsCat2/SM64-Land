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
#include "areas/4/custom.model.inc.h"
#include "levels/castle_grounds/header.h"
extern u8 _castle_grounds_segment_ESegmentRomStart[];
extern u8 _castle_grounds_segment_ESegmentRomEnd[];
const LevelScript level_castle_grounds_entry[] = {
	INIT_LEVEL(),
	LOAD_RAW(0x0E, _castle_grounds_segment_ESegmentRomStart, _castle_grounds_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group10_mio0SegmentRomStart, _group10_mio0SegmentRomEnd),
	LOAD_RAW(12, _group10_geoSegmentRomStart, _group10_geoSegmentRomEnd),
	LOAD_MIO0(6, _group13_mio0SegmentRomStart, _group13_mio0SegmentRomEnd),
	LOAD_RAW(13, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
	LOAD_MODEL_FROM_GEO(MODEL_BITS_WARP_PIPE, warp_pipe_geo),
	JUMP_LINK(script_func_global_1),
	JUMP_LINK(script_func_global_11),
	JUMP_LINK(script_func_global_14),
	JUMP_LINK(local_area_castle_grounds_1_),
	JUMP_LINK(local_area_castle_grounds_2_),
	JUMP_LINK(local_area_castle_grounds_3_),
	JUMP_LINK(local_area_castle_grounds_4_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 90, -10827, 136, -187),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};
const LevelScript local_area_castle_grounds_1_[] = {
	AREA(1, Geo_castle_grounds_1_0x22b3610),
	TERRAIN(col_castle_grounds_1_0xe06df60),
	SET_BACKGROUND_MUSIC(0, 4),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_castle_grounds_1_),
	JUMP_LINK(local_warps_castle_grounds_1_),
	END_AREA(),
	RETURN()};
const LevelScript local_objects_castle_grounds_1_[] = {
	OBJECT(E_MODEL_BITS_WARP_PIPE, -7419, 136, -1690, 0, 0, 0, (0 << 24) | (51 << 16) | (0 << 8) | (0), id_bhvWarpPipe),
	// 1-2 Pipe
	OBJECT(E_MODEL_NONE, -3615, 336, -1931, 0, 0, 0, (1 << 16), bhvPipeCover),
	OBJECT(E_MODEL_NONE, -3615, 136, -1931, 0, 0, 0, (0 << 24) | (120 << 16) | (0 << 8) | (0), id_bhvWarpPipe),
	OBJECT(E_MODEL_BLOCKED_WARP_PIPE, -3615, 136, -1931, 0, 0, 0, (1 << 16), id_bhvFakeWarpPipe),
	// 1-2 Pipe End
	// 1-3 Pipe
	OBJECT(E_MODEL_NONE, 3704, 336, -2507, 0, 0, 0, (2 << 16), bhvPipeCover),
	OBJECT(E_MODEL_NONE, 3704, 136, -2507, 0, 0, 0, (0 << 24) | (13 << 16) | (0 << 8) | (0), id_bhvWarpPipe),
	OBJECT(E_MODEL_BLOCKED_WARP_PIPE, 3704, 136, -2507, 0, 0, 0, (2 << 16), id_bhvFakeWarpPipe),
	// 1-3 Pipe End
	// 1-4 Pipe
	OBJECT(E_MODEL_NONE, 6027, 336, -3383, 0, 0, 0, (3 << 16), bhvPipeCover),
	OBJECT(E_MODEL_NONE, 6027, 136, -3383, 0, 0, 0, (0 << 24) | (14 << 16) | (0 << 8) | (0), id_bhvWarpPipe),
	OBJECT(E_MODEL_BLOCKED_WARP_PIPE, 6027, 136, -3383, 0, 0, 0, (3 << 16), id_bhvFakeWarpPipe),
	// 1-4 Pipe End
	OBJECT(E_MODEL_RED_WARP_PIPE, 7364, 136, -1632, 0, 0, 0, (0 << 24) | (18 << 16) | (0 << 8) | (0), id_bhvWarpPipe),
	OBJECT(E_MODEL_8_STAR_CAGE, 7364, 136, -1632, 0, 0, 0, (1 << 16), bhv8StarCage),
	OBJECT(E_MODEL_WORLD_CANNON, -7172, 136, 1052, 0, 0, 0, 0x00000000, bhvWorldCannon),
	MARIO_POS(0x01, 0, -10827, 136, -187),
	OBJECT(0, -7430, 250, -1334, 0, -180, 0, 0x150000, bhvAirborneStarCollectWarp),
	OBJECT(0, -3622, 250, -1570, 0, -180, 0, 0x160000, bhvAirborneStarCollectWarp),
	OBJECT(0, 3702, 250, -2171, 0, -180, 0, 0x170000, bhvAirborneStarCollectWarp),
	OBJECT(0, 6040, 250, -3040, 0, -180, 0, 0x180000, bhvAirborneStarCollectWarp),
	OBJECT(0, 7375, 336, -1284, 0, 0, 0, 0x6c0000, bhvAirborneStarCollectWarp),
	OBJECT(E_MODEL_BIRDS, -7046, 136, 1698, 0, -117, 0, 0x30000, id_bhvBird),
	OBJECT(E_MODEL_BIRDS, -3198, 136, 2561, 0, -171, 0, 0x30000, id_bhvBird),
	OBJECT(E_MODEL_BIRDS, -845, 764, -1585, 0, 138, 0, 0x30000, id_bhvBird),
	OBJECT(E_MODEL_BIRDS, 4825, 243, 524, 0, -145, 0, 0x30000, id_bhvBird),
	OBJECT(E_MODEL_BIRDS, 4764, 904, -1754, 0, 0, 0, 0x30000, id_bhvBird),
	OBJECT(E_MODEL_BOBOMB_BUDDY, -7796, 136, -1609, 0, 0, 0, 0x280000, id_bhvBobombBuddy),
	OBJECT(E_MODEL_BOBOMB_BUDDY, -4018, 136, -1889, 0, 0, 0, 0x2a0000, id_bhvBobombBuddy),
	OBJECT(E_MODEL_BOBOMB_BUDDY, 7709, 136, -1016, 0, 0, 0, 0x2b0000, id_bhvBobombBuddy),
	OBJECT(E_MODEL_FISH, -12166, 0, -1763, 0, 0, 0, 0x0, id_bhvChirpChirp),
	OBJECT(E_MODEL_FISH, -9423, 0, -3568, 0, 71, 0, 0x0, id_bhvChirpChirp),
	OBJECT(E_MODEL_FISH, -3668, 0, -6228, 0, 42, 0, 0x0, id_bhvChirpChirp),
	OBJECT(E_MODEL_FISH, 645, 0, -5029, 0, -90, 0, 0x0, id_bhvChirpChirp),
	OBJECT(E_MODEL_FISH, 7514, 0, -6716, 0, 114, 0, 0x0, id_bhvChirpChirp),
	OBJECT(E_MODEL_FISH, 10987, 0, -5010, 0, 0, 0, 0x0, id_bhvChirpChirp),
	OBJECT(E_MODEL_FISH, -7707, 0, -6538, 0, 0, 0, 0x0, id_bhvChirpChirp),
	OBJECT(E_MODEL_FISH, 3922, 0, -5864, 0, 0, 0, 0x0, id_bhvChirpChirp),
	OBJECT(E_MODEL_FISH, -1051, 0, -6260, 0, 0, 0, 0x0, id_bhvChirpChirp),
	OBJECT(E_MODEL_FISH, -6469, 0, -5374, 0, 0, 0, 0x0, id_bhvChirpChirp),
	OBJECT(0, -7430, 250, -1334, 0, -180, 0, 0x1f0000, bhvDeathWarp),
	OBJECT(0, -3622, 250, -1570, 0, -180, 0, 0x200000, bhvDeathWarp),
	OBJECT(0, 3702, 250, -2171, 0, -180, 0, 0x210000, bhvDeathWarp),
	OBJECT(0, 6040, 250, -3040, 0, -180, 0, 0x220000, bhvDeathWarp),
	OBJECT(0, 7375, 336, -1284, 0, 0, 0, 0x6d0000, bhvDeathWarp),
	OBJECT(0, 578, 360, -204, 0, 0, 0, 0xf10000, bhvDeathWarp),
	OBJECT(E_MODEL_BIRDS, -5269, 196, 1618, 0, 99, 0, 0x0, id_bhvEndBirds1),
	OBJECT(E_MODEL_BIRDS, -4761, 764, -1248, 0, 7, 0, 0x0, id_bhvEndBirds1),
	OBJECT(E_MODEL_BIRDS, 4174, 300, 667, 0, -111, 0, 0x0, id_bhvEndBirds1),
	OBJECT(E_MODEL_BIRDS, 6994, 207, -2052, 0, -84, 0, 0x0, id_bhvEndBirds1),
	OBJECT(E_MODEL_BIRDS, -5834, 190, 1530, 0, 21, 0, 0x0, id_bhvEndBirds1),
	OBJECT(0, -4866, 2206, -889, 0, 38, 0, 0xb0000, bhvFlyingWarp),
	OBJECT(0, -10827, 136, -187, 0, 90, 0, 0x90000, bhvSpinAirborneWarp),
	OBJECT(0, 4710, 243, -1223, 0, 0, 0, 0x470000, bhvSpinAirborneWarp),
	OBJECT(0, 4710, 243, -1534, 0, 0, 0, 0xa470000, bhvWarp),
	OBJECT(E_MODEL_DANCING_HILL, -11918, 0, -10464, 0, -4, 0, 0x0, id_bhvDancingHill),
	OBJECT(E_MODEL_DANCING_HILL, -4300, 0, -12712, 0, 0, 0, 0x0, id_bhvDancingHill),
	OBJECT(E_MODEL_DANCING_HILL, 803, 0, -12397, 0, 0, 0, 0x0, id_bhvDancingHill),
	OBJECT(E_MODEL_DANCING_HILL, 5974, 0, -11011, 0, 0, 0, 0x0, id_bhvDancingHill),
	OBJECT(E_MODEL_DANCING_HILL, 13382, 0, -9016, 0, -27, 0, 0x0, id_bhvDancingHill),
	OBJECT(E_MODEL_DANCING_HILL, -15564, 0, -9207, 0, 14, 0, 0x0, id_bhvDancingHill),
	OBJECT(E_MODEL_DANCING_HILL, 9287, 0, -13051, 0, -14, 0, 0x0, id_bhvDancingHill),
	OBJECT(E_MODEL_DANCING_HILL, 12162, 0, -12097, 0, -12, 0, 0x0, id_bhvDancingHill),
	OBJECT(E_MODEL_DANCING_HILL, -9850, 0, -13389, 0, 0, 0, 0x10000, id_bhvDancingHill),
	OBJECT(E_MODEL_DANCING_HILL, 16934, 0, -10157, 0, -12, 0, 0x0, id_bhvDancingHill),
	OBJECT(E_MODEL_STAR, -2690, 1630, -2470, 0, 0, 0, (0 << 24) | (0 << 16) | (0 << 8) | (0), id_bhvStar),
	OBJECT(MODEL_NONE, -10827, 136, -187, 0, 0, 0, (0 << 24) | (9 << 16) | (0 << 8) | (0), bhvSpinAirborneWarp),
	// World 2 Pipe Cover
	OBJECT(E_MODEL_PIPE_COVER, 9170, 336, -1717, 0, 0, 0, (4 << 16), bhvPipeCover),
	// World 2 Pipe Cover End
	OBJECT(E_MODEL_BLUE_WARP_PIPE, 9170, 136, -1717, 0, 0, 0, (0 << 24) | (1 << 16) | (0 << 8) | (0), id_bhvWarpPipe),
	OBJECT_WITH_ACTS(/* model*/ 0, /*speed*/ 4, /*axis*/4, /*vtx count*/4, 0, /*scroll type*/ 0, /*cycle*/ 1, /*index*/ 4, RM_Scroll_Texture, 31),
	RETURN()};
const LevelScript local_warps_castle_grounds_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(11, 9, 1, 10, 0),
	WARP_NODE(14, 9, 2, 10, 0),
	WARP_NODE(12, 24, 1, 10, 0),
	WARP_NODE(13, 24, 2, 10, 0),
	WARP_NODE(21, 9, 1, 10, 0),
	WARP_NODE(22, 16, 1, 0, 0),
	WARP_NODE(23, 16, 1, 0, 0),
	WARP_NODE(24, 16, 1, 0, 0),
	WARP_NODE(31, 16, 1, 0, 0),
	WARP_NODE(32, 16, 1, 0, 0),
	WARP_NODE(33, 16, 1, 0, 0),
	WARP_NODE(34, 16, 1, 0, 0),
	WARP_NODE(71, 28, 1, 10, 0),
	WARP_NODE(1, 26, 1, 10, 0),
	WARP_NODE(15, 19, 2, 10, 0),
	WARP_NODE(16, 19, 1, 10, 0),
	WARP_NODE(17, 25, 1, 10, 0),
	WARP_NODE(18, 9, 3, 10, 0),
	WARP_NODE(51, 9, 1, 10, 0),
	WARP_NODE(108, 16, 1, 0, 0),
	WARP_NODE(109, 16, 1, 0, 0),
	WARP_NODE(9, 16, 1, 0, 0),
	WARP_NODE(120, 24, 1, 10, 0),
	WARP_NODE(240, 6, 1, 50, 0),
	WARP_NODE(241, 16, 1, 241, 0),
	RETURN()};
const LevelScript local_area_castle_grounds_2_[] = {
	AREA(2, Geo_castle_grounds_2_0x22b37f0),
	TERRAIN(col_castle_grounds_2_0xe044780),
	SET_BACKGROUND_MUSIC(0, 25),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_castle_grounds_2_),
	JUMP_LINK(local_warps_castle_grounds_2_),
	END_AREA(),
	RETURN()};
const LevelScript local_objects_castle_grounds_2_[] = {
	OBJECT_WITH_ACTS(E_MODEL_BLUE_WARP_PIPE, -2865, 0, -1466, 0, 90, 0, 0xa0000, id_bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(0, -2570, 1743, -2256, 0, 49, 0, 0xb0000, bhvFlyingWarp, 31),
	OBJECT_WITH_ACTS(122, 2695, 444, -2886, 0, 0, 0, 0x3000000, bhvStar, 31),
	OBJECT_WITH_ACTS(MODEL_BITS_WARP_PIPE, -683, 0, -3175, 0, 90, 0, 0x150000, bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(MODEL_BITS_WARP_PIPE, 1799, 0, -3427, 0, 90, 0, 0x160000, bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(MODEL_BITS_WARP_PIPE, 3421, 0, -1932, 0, 90, 0, 0x170000, bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(MODEL_BITS_WARP_PIPE, 2609, 0, -266, 0, 23, 0, 0x180000, bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(0, -2390, -276, -4914, 0, 294, 0, 0x0, bhvChirpChirp, 31),
	OBJECT_WITH_ACTS(0, -2414, -276, -5735, 0, 87, 0, 0x0, bhvChirpChirp, 31),
	OBJECT_WITH_ACTS(0, 366, -276, -5382, 0, 268, 0, 0x0, bhvChirpChirp, 31),
	OBJECT_WITH_ACTS(0, 1234, -276, -5924, 0, 78, 0, 0x0, bhvChirpChirp, 31),
	OBJECT_WITH_ACTS(0, 3466, -276, -6070, 0, 57, 0, 0x0, bhvChirpChirp, 31),
	OBJECT_WITH_ACTS(0, 4509, -276, -5576, 0, 254, 0, 0x0, bhvChirpChirp, 31),
	OBJECT_WITH_ACTS(84, -1291, 0, -2196, 0, 216, 0, 0x20000, bhvBird, 31),
	OBJECT_WITH_ACTS(84, 302, 0, -1432, 0, 314, 0, 0x20000, bhvBird, 31),
	OBJECT_WITH_ACTS(84, 2456, 0, -2260, 0, 321, 0, 0x20000, bhvBird, 31),
	OBJECT_WITH_ACTS(187, -1404, 20, -910, 0, 0, 0, 0x20000, bhvEndBirds1, 31),
	OBJECT_WITH_ACTS(187, 3170, 20, -1278, 0, 202, 0, 0x20000, bhvEndBirds1, 31),
	OBJECT_WITH_ACTS(187, 1379, 20, -2266, 0, 252, 0, 0x20000, bhvEndBirds1, 31),
	OBJECT_WITH_ACTS(53,-252,0,-618,0,180,0,0x0,bhvWorldCannon,31),
	OBJECT_WITH_ACTS(0, -668, 226, -2873, 0, 0, 0, 0x1f0000, bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, 1809, 220, -3094, 0, 0, 0, 0x210000, bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, 3055, 223, -1950, 0, 270, 0, 0x200000, bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, 2613, 211, -677, 0, 180, 0, 0x220000, bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, -668, 226, -2873, 0, 180, 0, 0x290000, bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, 1809, 220, -3094, 0, 0, 0, 0x2b0000, bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, 3055, 223, -1950, 0, 270, 0, 0x2a0000, bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, 2613, 211, -677, 0, 180, 0, 0x2c0000, bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(E_MODEL_BLUE_WARP_PIPE, 1883, 0, 666, 0, 23, 0, 0xf0000, id_bhvWarpPipe, 31),
	/*OBJECT_WITH_ACTS(0,-651,0,-3150,0,0,0,0x8000000,0x130001dc,31),
	OBJECT_WITH_ACTS(0,1774,0,-3443,0,0,0,0xa000000,0x130001dc,31),
	OBJECT_WITH_ACTS(0,3434,0,-1944,0,0,0,0x9000000,0x130001dc,31),
	OBJECT_WITH_ACTS(0,2609,0,-280,0,0,0,0xb000000,0x130001dc,31),*/
	OBJECT_WITH_ACTS(E_MODEL_RED_WARP_PIPE, 2493, 0, 634, 0, 23, 0, 0x20000, id_bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(E_MODEL_8_STAR_CAGE, 2493, 0, 634, 0, 180, 0, (3 << 16), bhv8StarCage, 31),
	OBJECT_WITH_ACTS(0, 1068, 97, 339, 0, 0, 0, 0x10000, bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(0, 1066, 97, 12, 0, 0, 0, 0xa010000, bhvWarp, 31),
	OBJECT_WITH_ACTS(0, 2497, 200, 258, 0, 0, 0, 0x6c0000, bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, 2497, 200, 258, 0, 0, 0, 0x6d0000, bhvDeathWarp, 31),
	// OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x0,0x0703f180,31),
	OBJECT_WITH_ACTS(E_MODEL_PIPE_COVER, 1883, 200, 666, 0, 23, 0, (12 << 16), bhvPipeCover, 31),
OBJECT_WITH_ACTS(/* model*/ 0, /*speed*/ 4, /*axis*/4, /*vtx count*/4, 0, /*scroll type*/ 0, /*cycle*/ 1, /*index*/ 5, RM_Scroll_Texture, 31),
	RETURN()};
const LevelScript local_warps_castle_grounds_2_[] = {
	WARP_NODE(10, 26, 1, 15, 0),
	WARP_NODE(11, 16, 2, 0, 0),
	WARP_NODE(21, 4, 1, 10, 0),
	WARP_NODE(22, 22, 1, 10, 0),
	WARP_NODE(23, 7, 1, 10, 0),
	WARP_NODE(24, 8, 1, 10, 0),
	WARP_NODE(31, 16, 2, 0, 0),
	WARP_NODE(32, 16, 2, 0, 0),
	WARP_NODE(33, 16, 2, 0, 0),
	WARP_NODE(34, 16, 2, 0, 0),
	WARP_NODE(41, 16, 2, 0, 0),
	WARP_NODE(42, 16, 2, 0, 0),
	WARP_NODE(43, 16, 2, 0, 0),
	WARP_NODE(44, 16, 2, 0, 0),
	WARP_NODE(15, 26, 2, 10, 0),
	WARP_NODE(12, 16, 1, 11, 0),
	WARP_NODE(65, 16, 2, 0, 0),
	WARP_NODE(0, 16, 2, 0, 0),
	WARP_NODE(1, 28, 3, 10, 0),
	WARP_NODE(2, 8, 3, 10, 0),
	WARP_NODE(3, 16, 2, 0, 0),
	WARP_NODE(108, 16, 2, 0, 0),
	WARP_NODE(109, 16, 2, 0, 0),
	WARP_NODE(240, 6, 1, 50, 0),
	WARP_NODE(241, 6, 1, 100, 0),
	RETURN()};
const LevelScript local_area_castle_grounds_3_[] = {
	AREA(3, Geo_castle_grounds_3_0x22b39d0),
	TERRAIN(col_castle_grounds_3_0xe05e4e0),
	SET_BACKGROUND_MUSIC(0, 76),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_castle_grounds_3_),
	JUMP_LINK(local_warps_castle_grounds_3_),
	END_AREA(),
	RETURN()};
const LevelScript local_objects_castle_grounds_3_[] = {
	OBJECT_WITH_ACTS(E_MODEL_BLUE_WARP_PIPE, -6401, -477, 1448, 0, 180, 0, 0xa0000, id_bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(0, -6571, 573, -1705, 0, 0, 0, 0xb0000, bhvFlyingWarp, 31),
	OBJECT_WITH_ACTS(MODEL_BITS_WARP_PIPE, -5990, -477, -1768, 0, 0, 0, 0x140000, bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(MODEL_BITS_WARP_PIPE, -2278, -477, -3391, 0, 0, 0, 0x150000, bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(MODEL_BITS_WARP_PIPE, 1435, 60, -3959, 0, 0, 0, 0x160000, bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(MODEL_BITS_WARP_PIPE, 3864, 139, -5321, 90, 0, 0, 0x170000, bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(122, 1538, 3027, -4929, 0, 0, 0, 0x5000000, bhvStar, 31),
	OBJECT_WITH_ACTS(0, -5988, -230, -1377, 0, 0, 0, 0x320000, bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, -2273, -230, -3021, 0, 0, 0, 0x330000, bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, 1445, 307, -3603, 0, 0, 0, 0x340000, bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, 3896, 307, -4552, 0, 0, 0, 0x350000, bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, -5988, -230, -1377, 0, 0, 0, 0x3c0000, bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, -2273, -230, -3021, 0, 0, 0, 0x3d0000, bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, 1445, 307, -3603, 0, 0, 0, 0x3e0000, bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, 3896, 307, -4552, 0, 0, 0, 0x3f0000, bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(53,-4724,-477,718,0,180,0,0x0,bhvWorldCannon,31),
	/*OBJECT_WITH_ACTS(0,-5977,-477,-1776,0,0,0,0x10000000,0x130001dc,31),
	OBJECT_WITH_ACTS(0,-2288,-477,-3376,0,0,0,0x11000000,0x130001dc,31),
	OBJECT_WITH_ACTS(0,1439,60,-3973,0,0,0,0x12000000,0x130001dc,31),
	OBJECT_WITH_ACTS(0,3880,60,-5288,0,0,0,0x13000000,0x130001dc,31),
	OBJECT_WITH_ACTS(34,4442,-65,-2363,0,0,0,0x370000, bhvWarpPipe,31),*/
	OBJECT_WITH_ACTS(E_MODEL_BLUE_WARP_PIPE, 5217, -65, -2277, 0, 180, 0, 0xf0000, id_bhvWarpPipe, 31),
	//OBJECT_WITH_ACTS(57, 4442, -65, -2363, 0, 180, 0, 0x1c040000, Bhv_Custom_0x1900273, 31),
	OBJECT_WITH_ACTS(0, 1980, 60, -1815, 0, 298, 0, 0x10000, bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(0, 2364, 60, -2004, 0, 298, 0, 0xa010000, bhvWarp, 31),
	//OBJECT_WITH_ACTS(54, 4620, 4500, -30915, 0, 0, 0, 0x0, Bhv_Custom_0x19000280, 31),
	// OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x0,0x0703cce0,31),
	OBJECT_WITH_ACTS(0, 4447, 135, -2658, 0, 180, 0, 0x6c0000, bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, 4447, 135, -2658, 0, 180, 0, 0x6d0000, bhvDeathWarp, 31),
	// OBJECT_WITH_ACTS(58,5217,135,-2277,0,180,0,0x1e050000,0x0703fdc0,31),
	OBJECT_WITH_ACTS(0, 0, 0, 0, 0, 0, 0, 0xf10000, bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, 4, -32748, 2, 0, 0, 0, 0xe015880, RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 62, -32748, 6, 0, 0, 0, 0xe0158c0, RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 41, -32748, 6, 0, 0, 0, 0xe015ca0, RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 522, -32748, 6, 0, 0, 0, 0xe021280, RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 9521, -32748, 6, 0, 0, 0, 0xe023320, RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 331, -32748, 6, 0, 0, 0, 0xe048630, RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 87, -32748, 6, 0, 0, 0, 0xe04be60, RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 21, -32748, 6, 0, 0, 0, 0xe013030, RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 2614, -32748, 6, 0, 0, 0, 0xe016f20, RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 568, -32748, 6, 0, 0, 0, 0xe049ae0, RM_Scroll_Texture, 31),
	RETURN()};
const LevelScript local_warps_castle_grounds_3_[] = {
	WARP_NODE(10, 26, 2, 15, 0),
	WARP_NODE(11, 16, 3, 0, 0),
	WARP_NODE(20, 23, 1, 10, 0),
	WARP_NODE(21, 23, 2, 10, 0),
	WARP_NODE(23, 10, 1, 10, 0),
	WARP_NODE(22, 7, 2, 10, 0),
	WARP_NODE(50, 16, 3, 0, 0),
	WARP_NODE(51, 16, 3, 0, 0),
	WARP_NODE(52, 16, 3, 0, 0),
	WARP_NODE(53, 16, 3, 0, 0),
	WARP_NODE(60, 16, 3, 0, 0),
	WARP_NODE(61, 16, 3, 0, 0),
	WARP_NODE(62, 16, 3, 0, 0),
	WARP_NODE(63, 16, 3, 0, 0),
	WARP_NODE(12, 16, 3, 0, 0),
	WARP_NODE(55, 27, 2, 10, 0),
	WARP_NODE(15, 26, 3, 10, 0),
	WARP_NODE(1, 29, 2, 10, 0),
	WARP_NODE(108, 16, 3, 0, 0),
	WARP_NODE(109, 16, 3, 0, 0),
	WARP_NODE(240, 6, 1, 50, 0),
	WARP_NODE(241, 16, 3, 241, 0),
	RETURN()};
const LevelScript local_area_castle_grounds_4_[] = {
	AREA(4, Geo_castle_grounds_4_0x22b3bb0),
	TERRAIN(col_castle_grounds_4_0xe081640),
	SET_BACKGROUND_MUSIC(0, 81),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_castle_grounds_4_),
	JUMP_LINK(local_warps_castle_grounds_4_),
	END_AREA(),
	RETURN()};
const LevelScript local_objects_castle_grounds_4_[] = {
	OBJECT_WITH_ACTS(0, -1436, 1530, 493, 0, 0, 0, 0xb0000, bhvFlyingWarp, 31),
	OBJECT_WITH_ACTS(MODEL_BITS_WARP_PIPE, -3757, 436, 1418, 0, 0, 0, 0x10000, bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(MODEL_BITS_WARP_PIPE, 372, 277, 700, 0, 0, 0, 0x20000, bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(MODEL_BITS_WARP_PIPE, 7371, 617, 592, 0, 0, 0, 0x30000, bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(MODEL_BITS_WARP_PIPE, 4435, 436, 134, 0, 0, 0, 0x40000, bhvWarpPipe, 31),
	// OBJECT_WITH_ACTS(0,3588,1546,-51,0,0,0,0x0,0x0703bfe0,31),
	// OBJECT_WITH_ACTS(0,5299,1546,-60,0,0,0,0x0,0x0703bfe0,31),
	OBJECT_WITH_ACTS(122, 3615, 1923, -323, 0, 0, 0, 0x7000000, bhvStar, 31),
	OBJECT_WITH_ACTS(0, -3760, 640, 1838, 0, 0, 0, 0x150000, bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, 374, 481, 1038, 0, 0, 0, 0x160000, bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, 7375, 934, 905, 0, 0, 0, 0x170000, bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, 4431, 617, 434, 0, 0, 0, 0x180000, bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, -3760, 640, 1838, 0, 0, 0, 0x1f0000, bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, 374, 481, 1038, 0, 0, 0, 0x200000, bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, 7375, 934, 905, 0, 0, 0, 0x210000, bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, 4431, 617, 434, 0, 0, 0, 0x220000, bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(53,2355,162,2769,0,270,0,0x0,bhvWorldCannon,31),
	OBJECT_WITH_ACTS(E_MODEL_BLUE_WARP_PIPE, -5525, 436, 2098, 0, 90, 0, 0xa0000, id_bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(E_MODEL_BLUE_WARP_PIPE, 10245, 179, 430, 0, 270, 0, 0xf0000, id_bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(E_MODEL_PIPE_COVER,10245,379,430,0,270,0,(28 << 16),bhvPipeCover,31),
	OBJECT_WITH_ACTS(0, 203, 162, 3321, 0, 77, 0, 0x50000, bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(0, -379, 162, 3034, 0, 291, 0, 0xa050000, bhvWarp, 31),
	OBJECT_WITH_ACTS(E_MODEL_RED_WARP_PIPE, 9231, 179, 287, 0, 0, 0, 0x60000, id_bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(E_MODEL_8_STAR_CAGE,9231,179,287,0,0,0,(7 << 16),bhv8StarCage,31),
	OBJECT_WITH_ACTS(0, 9234, 420, 704, 0, 0, 0, 0x6c0000, bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, 9234, 420, 704, 0, 0, 0, 0x6d0000, bhvDeathWarp, 31),
	/*OBJECT_WITH_ACTS(0,-3766,436,1461,0,0,0,0x18000000,0x130001dc,31),
	OBJECT_WITH_ACTS(0,374,277,690,0,0,0,0x19000000,0x130001dc,31),
	OBJECT_WITH_ACTS(0,4432,436,152,0,0,0,0x1a000000,0x130001dc,31),
	OBJECT_WITH_ACTS(0,7360,617,614,0,0,0,0x1b000000,0x130001dc,31),
	OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x0,0x0703cce0,31),
	OBJECT_WITH_ACTS(59,-2204,0,-2605,0,9,0,0x10000,0x0702f9e0,31),
	OBJECT_WITH_ACTS(59,-16,0,-4223,0,0,0,0x10000,0x0702f9e0,31),
	OBJECT_WITH_ACTS(59,6099,0,-3780,0,348,0,0x10000,0x0702f9e0,31),
	OBJECT_WITH_ACTS(59,8258,0,-3112,0,333,0,0x10000,0x0702f9e0,31),
	OBJECT_WITH_ACTS(59,13575,0,-4380,0,327,0,0x10000,0x0702f9e0,31),
	OBJECT_WITH_ACTS(59,-5926,0,-1734,0,14,0,0x0,0x0702f9e0,31),*/
	OBJECT_WITH_ACTS(0, 1422, 362, 1836, 0, 0, 0, 0xf10000, bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(/* model*/ 0, /*speed*/ 4, /*axis*/4, /*vtx count*/4, 0, /*scroll type*/ 0, /*cycle*/ 1, /*index*/ 10, RM_Scroll_Texture, 31),
	RETURN()};
const LevelScript local_warps_castle_grounds_4_[] = {
	WARP_NODE(10, 26, 3, 15, 0),
	WARP_NODE(0, 16, 4, 0, 0),
	WARP_NODE(1, 13, 2, 10, 0),
	WARP_NODE(2, 15, 1, 10, 0),
	WARP_NODE(3, 14, 1, 10, 0),
	WARP_NODE(4, 15, 2, 10, 0),
	WARP_NODE(21, 16, 4, 0, 0),
	WARP_NODE(22, 16, 4, 0, 0),
	WARP_NODE(23, 16, 4, 0, 0),
	WARP_NODE(24, 16, 4, 0, 0),
	WARP_NODE(31, 16, 4, 0, 0),
	WARP_NODE(32, 16, 4, 0, 0),
	WARP_NODE(33, 16, 4, 0, 0),
	WARP_NODE(34, 16, 4, 0, 0),
	WARP_NODE(12, 16, 4, 0, 0),
	WARP_NODE(11, 16, 4, 0, 0),
	WARP_NODE(15, 26, 4, 10, 0),
	WARP_NODE(5, 18, 1, 10, 0),
	WARP_NODE(6, 21, 1, 10, 0),
	WARP_NODE(108, 16, 4, 0, 0),
	WARP_NODE(109, 16, 4, 0, 0),
	WARP_NODE(240, 6, 1, 50, 0),
	WARP_NODE(241, 16, 4, 241, 0),
	RETURN()};

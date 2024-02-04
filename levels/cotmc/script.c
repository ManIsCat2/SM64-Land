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
#include "levels/cotmc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_cotmc_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _cotmc_segment_7SegmentRomStart, _cotmc_segment_7SegmentRomEnd),
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_HAUNTED_DOOR, haunted_door_geo),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_STAIRCASE_STEP, geo_bbh_0005B0),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TILTING_FLOOR_PLATFORM, geo_bbh_0005C8),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM, geo_bbh_0005E0),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM_PART, geo_bbh_0005F8),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MOVING_BOOKSHELF, geo_bbh_000610),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MESH_ELEVATOR, geo_bbh_000628),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MERRY_GO_ROUND, geo_bbh_000640),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_WOODEN_TOMB, geo_bbh_000658),
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
	JUMP_LINK(script_func_global_16),

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, cotmc_area_1),
	WARP_NODE(10, 16, 1, 71, 0),
	WARP_NODE(240, 6, 1, 50, 0),
	WARP_NODE(241, 6, 1, 100, 0),
	MARIO_POS(0x01, 0, -1638, 0, 98),
	OBJECT_WITH_ACTS(0, -1638, 0, 98, 0, 90, 0, 0xa0000, bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(E_MODEL_TOAD, -246, 130, 49, 0, 270, 0, 0x1, id_bhvToadMessage, 31),
	OBJECT_WITH_ACTS(0, -2142, 0, 62, 0, 90, 0, 0xa0a0000, bhvWarp, 31),
	// OBJECT_WITH_ACTS(0, 0, 0, 0, 0, 0, 0, 0x0, 0x0041f5a0, 31),
	TERRAIN(cotmc_area_1_collision),
	MACRO_OBJECTS(cotmc_area_1_macro_objs),
	SET_BACKGROUND_MUSIC(0x00, 59),
	TERRAIN_TYPE(TERRAIN_GRASS),
	/* Fast64 begin persistent block [area commands] */
	/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, cotmc_area_2),
	WARP_NODE(10, 26, 1, 1, 0),
	WARP_NODE(240, 6, 1, 50, 0),
	WARP_NODE(241, 6, 1, 100, 0),
	OBJECT_WITH_ACTS(E_MODEL_TOAD, -246, 130, 49, 0, 270, 0, 0x1, id_bhvToadMessage, 31),
	OBJECT_WITH_ACTS(0, -1638, 0, 98, 0, 90, 0, 0xa0000, bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(0, -2142, 0, 62, 0, 90, 0, 0xa0a0000, bhvWarp, 31),
	// OBJECT_WITH_ACTS(0, 0, 0, 0, 0, 0, 0, 0x0, 0x0041f5a0, 31),
	TERRAIN(cotmc_area_2_collision),
	MACRO_OBJECTS(cotmc_area_2_macro_objs),
	SET_BACKGROUND_MUSIC(0, 59),
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

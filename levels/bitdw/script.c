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
#include "levels/bitdw/header.h"
extern u8 _bitdw_segment_ESegmentRomStart[]; 
extern u8 _bitdw_segment_ESegmentRomEnd[];
const LevelScript level_bitdw_entry[] = {
INIT_LEVEL(),
LOAD_RAW(0x0E, _bitdw_segment_ESegmentRomStart, _bitdw_segment_ESegmentRomEnd),
LOAD_MIO0(0xA,_SkyboxCustom39715296_skybox_mio0SegmentRomStart,_SkyboxCustom39715296_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
LOAD_MIO0(5,_group1_mio0SegmentRomStart,_group1_mio0SegmentRomEnd),
LOAD_RAW(12,_group1_geoSegmentRomStart,_group1_geoSegmentRomEnd),
ALLOC_LEVEL_POOL(),
MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
JUMP_LINK(script_func_global_1),
JUMP_LINK(script_func_global_2),
JUMP_LINK(local_area_bitdw_1_),
JUMP_LINK(local_area_bitdw_2_),
FREE_LEVEL_POOL(),
MARIO_POS(1,0,0,0,0),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_bitdw_1_[] = {
AREA(1,Geo_bitdw_1_0x2605320),
TERRAIN(col_bitdw_1_0xe016af0),
SET_BACKGROUND_MUSIC(0,61),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_bitdw_1_),
JUMP_LINK(local_warps_bitdw_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_bitdw_1_[] = {
OBJECT_WITH_ACTS(0,5000,686,0,0,180,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x0, bhvPenguinRaceFinishLine,31),
OBJECT_WITH_ACTS(127,-4425,1205,0,0,90,0,0x0, Bhv_Custom_0x19000400,31),
/*OBJECT_WITH_ACTS(53,0,1067,0,0,90,0,0x1000000,0x07011bc0,31),
OBJECT_WITH_ACTS(54,2350,673,0,0,180,0,0x0,0x07011be0,31),
OBJECT_WITH_ACTS(54,2350,673,0,0,90,0,0x0,0x07011be0,31),
OBJECT_WITH_ACTS(54,2350,673,0,0,180,0,0x0,0x07011be0,31),
OBJECT_WITH_ACTS(54,2350,673,0,0,180,0,0x10000,0x07011be0,31),
OBJECT_WITH_ACTS(54,2350,673,0,0,180,0,0x10000,0x07011be0,31),
OBJECT_WITH_ACTS(54,2350,673,0,0,180,0,0x10000,0x07011be0,31),
OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x50000,0x00377ef0,31),*/
OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x0, bhvPenguinRaceFinishLine,31),
RETURN()
};
const LevelScript local_warps_bitdw_1_[] = {
WARP_NODE(10,9,1,0,0),
WARP_NODE(240,26,3,108,0),
WARP_NODE(241,26,3,109,0),
RETURN()
};
const LevelScript local_area_bitdw_2_[] = {
AREA(2,Geo_bitdw_2_0x2605500),
TERRAIN(col_bitdw_2_0xe00bf40),
SET_BACKGROUND_MUSIC(0,0),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_bitdw_2_),
JUMP_LINK(local_warps_bitdw_2_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_bitdw_2_[] = {
OBJECT_WITH_ACTS(0,-90,0,-1710,0,0,0,0xa0000, bhvSpinAirborneWarp,31),
//OBJECT_WITH_ACTS(0,0,122,0,0,180,0,0x0,0x0701e000,31),
OBJECT_WITH_ACTS(0,81,-32748,60,0,0,0,0xe008b60, bhvStaticObject,31),
RETURN()
};
const LevelScript local_warps_bitdw_2_[] = {
WARP_NODE(10,9,2,0,0),
WARP_NODE(240,16,4,108,0),
WARP_NODE(241,16,4,109,0),
RETURN()
};

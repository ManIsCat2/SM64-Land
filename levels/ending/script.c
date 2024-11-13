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
#include "levels/ending/header.h"
extern u8 _ending_segment_ESegmentRomStart[]; 
extern u8 _ending_segment_ESegmentRomEnd[];
const LevelScript level_ending_entry[] = {
INIT_LEVEL(),
LOAD_RAW(0x0E, _ending_segment_ESegmentRomStart, _ending_segment_ESegmentRomEnd),
LOAD_MIO0(0xA,_water_skybox_mio0SegmentRomStart,_water_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
LOAD_MIO0(5,_group11_mio0SegmentRomStart,_group11_mio0SegmentRomEnd),
LOAD_RAW(12,_group11_geoSegmentRomStart,_group11_geoSegmentRomEnd),
LOAD_MIO0(6,_group17_mio0SegmentRomStart,_group17_mio0SegmentRomEnd),
LOAD_RAW(13,_group17_geoSegmentRomStart,_group17_geoSegmentRomEnd),
ALLOC_LEVEL_POOL(),
MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
JUMP_LINK(script_func_global_1),
JUMP_LINK(script_func_global_12),
JUMP_LINK(script_func_global_18),
JUMP_LINK(local_area_ending_1_),
JUMP_LINK(local_area_ending_2_),
FREE_LEVEL_POOL(),
MARIO_POS(1,0,0,0,0),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_ending_1_[] = {
AREA(1,Geo_ending_1_0x20ec9d0),
TERRAIN(col_ending_1_0xe087d90),
SET_BACKGROUND_MUSIC(0,66),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_ending_1_),
JUMP_LINK(local_warps_ending_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_ending_1_[] = {
OBJECT_WITH_ACTS(0,0,-346,0,0,0,0,0xa0000, bhvSpinAirborneWarp,31),
//OBJECT_WITH_ACTS(0,1238,0,-1618,0,0,0,0x0, Bhv_Custom_0x07000000,31),
RETURN()
};
const LevelScript local_warps_ending_1_[] = {
WARP_NODE(10,9,1,0,0),
WARP_NODE(12,16,1,9,0),
WARP_NODE(240,16,1,9,0),
WARP_NODE(241,6,1,100,0),
RETURN()
};
const LevelScript local_area_ending_2_[] = {
AREA(2,Geo_ending_2_0x20ecbb0),
TERRAIN(col_ending_2_0xe005f10),
SET_BACKGROUND_MUSIC(0,82),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_ending_2_),
JUMP_LINK(local_warps_ending_2_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_ending_2_[] = {
OBJECT_WITH_ACTS(0,9834,-346,-1018,0,270,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(0,10347,-346,-1004,0,270,0,0x140a0000, bhvWarp,31),
/*OBJECT_WITH_ACTS(101,7785,-346,-1045,0,90,0,0xa00000,0x0041fb80,31),
OBJECT_WITH_ACTS(84,7353,-346,393,0,120,0,0x9f0000,0x0041fbc0,31),
OBJECT_WITH_ACTS(87,7976,-346,1874,0,160,0,0x9e0000,0x0041fc00,31),
OBJECT_WITH_ACTS(223,9323,-346,1817,0,200,0,0x9d0000,0x0041fc40,31),
OBJECT_WITH_ACTS(192,9821,-346,1053,0,240,0,0x950000,0x0041fc80,31),*/
OBJECT_WITH_ACTS(195,7293,-346,1410,0,110,0,0x940000, bhvBobombBuddy,31),
//OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x0,0x0041fce0,31),
RETURN()
};
const LevelScript local_warps_ending_2_[] = {
WARP_NODE(10,6,4,10,0),
WARP_NODE(240,6,1,50,0),
WARP_NODE(241,6,1,100,0),
RETURN()
};

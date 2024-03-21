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
#include "levels/bits/header.h"
extern u8 _bits_segment_ESegmentRomStart[]; 
extern u8 _bits_segment_ESegmentRomEnd[];
const LevelScript level_bits_entry[] = {
INIT_LEVEL(),
LOAD_RAW(0x0E, _bits_segment_ESegmentRomStart, _bits_segment_ESegmentRomEnd),
LOAD_MIO0(0xA,_water_skybox_mio0SegmentRomStart,_water_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
ALLOC_LEVEL_POOL(),
MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
JUMP_LINK(script_func_global_1),
JUMP_LINK(local_area_bits_1_),
FREE_LEVEL_POOL(),
MARIO_POS(1,0,0,0,0),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_bits_1_[] = {
AREA(1,Geo_bits_1_0x261d100),
TERRAIN(col_bits_1_0xe00caf0),
SET_BACKGROUND_MUSIC(0,74),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_bits_1_),
JUMP_LINK(local_warps_bits_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_bits_1_[] = {
OBJECT_WITH_ACTS(0,0,0,-1710,0,0,0,0xa0000, bhvSpinAirborneWarp,31),
//OBJECT_WITH_ACTS(0,0,122,0,0,180,0,0x1000000,0x0600e000,31),
//OBJECT_WITH_ACTS(61,-30,25,-1389,0,0,0,0x0,0x0701c4e0,31),
//OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x60000,0x00377ef0,31),
OBJECT_WITH_ACTS(0,77,-24556,20,0,0,0,0xe008fe0, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,92,-32748,60,0,0,0,0xe00b1d0, RM_Scroll_Texture,31),
RETURN()
};
const LevelScript local_warps_bits_1_[] = {
WARP_NODE(10,9,1,0,0),
WARP_NODE(240,16,4,108,0),
WARP_NODE(241,16,4,109,0),
RETURN()
};

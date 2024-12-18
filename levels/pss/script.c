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
#include "levels/pss/header.h"
extern u8 _pss_segment_ESegmentRomStart[]; 
extern u8 _pss_segment_ESegmentRomEnd[];
const LevelScript level_pss_entry[] = {
INIT_LEVEL(),
LOAD_RAW(0x0E, _pss_segment_ESegmentRomStart, _pss_segment_ESegmentRomEnd),
LOAD_MIO0(0xA,_SkyboxCustom32255488_skybox_mio0SegmentRomStart,_SkyboxCustom32255488_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
LOAD_MIO0(5,_group1_mio0SegmentRomStart,_group1_mio0SegmentRomEnd),
LOAD_RAW(12,_group1_geoSegmentRomStart,_group1_geoSegmentRomEnd),
LOAD_MIO0(6,_group12_mio0SegmentRomStart,_group12_mio0SegmentRomEnd),
LOAD_RAW(13,_group12_geoSegmentRomStart,_group12_geoSegmentRomEnd),
ALLOC_LEVEL_POOL(),
MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
JUMP_LINK(script_func_global_1),
JUMP_LINK(script_func_global_2),
JUMP_LINK(script_func_global_13),
JUMP_LINK(local_area_pss_1_),
JUMP_LINK(local_area_pss_2_),
FREE_LEVEL_POOL(),
MARIO_POS(1,0,0,0,0),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_pss_1_[] = {
AREA(1,Geo_pss_1_0x1ee7f40),
TERRAIN(col_pss_1_0xe0095b0),
SET_BACKGROUND_MUSIC(0,0),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_pss_1_),
JUMP_LINK(local_warps_pss_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_pss_1_[] = {
OBJECT_WITH_ACTS(0,0,0,-1646,0,0,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(E_MODEL_KING_BOBOMB,0,150,0,0,180,0,0x20000,id_bhvKingBobomb,31),
//OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x30000,0x00377ef0,31),
OBJECT_WITH_ACTS(116,-2400,200,0,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,2400,200,0,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,0,200,2400,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,0,200,-2400,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,2400,900,2400,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,2400,900,-2400,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-2400,900,-2400,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-2400,900,2400,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-2400,200,1500,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-2400,200,-1500,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,2400,200,1500,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,2400,200,-1500,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-1500,200,2400,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,1500,200,2400,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,1500,200,-2400,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-1500,200,-2400,0,0,0,0x0, bhvOneCoin,31),
RETURN()
};
const LevelScript local_warps_pss_1_[] = {
WARP_NODE(10,9,1,0,0),
WARP_NODE(240,26,2,108,0),
WARP_NODE(241,26,2,109,0),
RETURN()
};
const LevelScript local_area_pss_2_[] = {
AREA(2,Geo_pss_2_0x1ee8120),
TERRAIN(col_pss_2_0xe007120),
SET_BACKGROUND_MUSIC(0,80),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_pss_2_),
JUMP_LINK(local_warps_pss_2_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_pss_2_[] = {
OBJECT_WITH_ACTS(0,0,590,600,0,90,0,0xa0000, bhvSpinAirborneWarp,31),
/*OBJECT_WITH_ACTS(54,0,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,1000,0,-600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,2500,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,2800,0,-600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,5300,0,-600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,7500,0,-600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,11100,0,-600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,14000,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,15000,0,-600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,17700,0,-600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,20900,0,-600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,23950,0,-600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,27000,0,-600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,4500,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,7500,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,9500,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,12000,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,16500,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,18750,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,20500,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,22750,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,25750,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(23,2526,561,654,0,-90,0,0x5000000,0x0700ef30,31),
OBJECT_WITH_ACTS(54,28650,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,-23700,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,-20000,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,-18000,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,-15500,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,-13000,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,-11150,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,-8250,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,-5000,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,-3200,0,600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,-25000,0,-600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,-22000,0,-600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,-19000,0,-600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,-16500,0,-600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,-13700,0,-600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,-9500,0,-600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,-7000,0,-600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(54,-1600,0,-600,0,0,0,0xa0000,0x0700ef00,31),
OBJECT_WITH_ACTS(0,0,0,0,0,0,0,0x40000,0x00377ef0,31),*/
OBJECT_WITH_ACTS(0,120,-24556,180,0,0,0,0xe004060, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,90,-24556,180,0,0,0,0xe0047e0, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,140,-32748,60,0,0,0,0xe004d80, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,95,-32748,60,0,0,0,0xe005640, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,22,-24556,-60,0,0,0,0xe005c30, bhvStaticObject,31),
OBJECT_WITH_ACTS(0,136,-32748,60,0,0,0,0xe005d90, bhvStaticObject,31),
RETURN()
};
const LevelScript local_warps_pss_2_[] = {
WARP_NODE(10,9,2,0,0),
WARP_NODE(240,16,3,108,0),
WARP_NODE(241,16,3,109,0),
RETURN()
};

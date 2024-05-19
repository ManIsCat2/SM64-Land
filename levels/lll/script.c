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
#include "levels/lll/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_lll_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _lll_segment_7SegmentRomStart, _lll_segment_7SegmentRomEnd),
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario),

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, lll_area_1),
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(240, 16, 2, 33, 0),
	WARP_NODE(241, 16, 2, 43, 0),
	OBJECT_WITH_ACTS(0, 16751, 3349, -5754, 0, 180, 0, 0xa0000, bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(137, -12868, 4198, -5372, 0, 0, 0, 0x20000, bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(57, 14801, 3341, -2233, 0, -90, 0, 0x28000000, bhvWdwSquareFloatingPlatform, 31),
	OBJECT_WITH_ACTS(57, 1826, 3341, 460, 0, 277, 0, 0x28000000, bhvWdwSquareFloatingPlatform, 31),
	OBJECT_WITH_ACTS(57, -3823, 3341, 4162, 0, 0, 0, 0x28000000, Bhv_Custom_0x13000f58, 31),
	OBJECT_WITH_ACTS(57, -12809, 7539, 513, 0, -90, 0, 0x96010049, Bhv_Custom_0x13000f58, 31),
	OBJECT_WITH_ACTS(57, -10303, 4511, -4885, 0, -90, 0, 0x48010026, Bhv_Custom_0x13000f58, 31),
	OBJECT_WITH_ACTS(57, -10499, 4511, -177, 0, -90, 0, 0x48010026, Bhv_Custom_0x13000f58, 31),
	OBJECT_WITH_ACTS(57, 227, 4775, 3272, 0, -90, 0, 0x48010026, bhvWdwSquareFloatingPlatform, 31),
	OBJECT_WITH_ACTS(57, 2441, 3341, -1035, 0, 277, 0, 0x28000000, bhvWdwSquareFloatingPlatform, 31),
	OBJECT_WITH_ACTS(57, -2301, 7539, 3617, 0, -90, 0, 0x96010049, Bhv_Custom_0x13000f58, 31),
	OBJECT_WITH_ACTS(0, -20277, 3341, -1210, 0, 90, 0, 0x28000000, Bhv_Custom_0x0701f9c0, 31),
	OBJECT_WITH_ACTS(22, -10657, 5028, -7937, 0, 0, 0, 0x820000, bhvWaterLevelDiamond, 31),
	OBJECT_WITH_ACTS(22, 136, 8799, 8519, 0, 0, 0, 0x6e0000, bhvWaterLevelDiamond, 31),
	OBJECT_WITH_ACTS(0, 4664, 4204, -936, 0, 0, 0, 0x0, bhvInitializeChangingWaterLevel, 31),
	OBJECT_WITH_ACTS(57, 4065, 4511, 6937, 0, -90, 0, 0x96010049, Bhv_Custom_0x13000f58, 31),
	OBJECT_WITH_ACTS(57, 16435, 4511, -2314, 0, -90, 0, 0x96010026, Bhv_Custom_0x13000f58, 31),
	OBJECT_WITH_ACTS(57, -7965, 7539, 2525, 0, -90, 0, 0x96010049, Bhv_Custom_0x13000f58, 31),
	OBJECT_WITH_ACTS(0, -24634, 3341, 9093, 0, 90, 0, 0x28000000, Bhv_Custom_0x0701f9c0, 31),
	OBJECT_WITH_ACTS(122, 18030, 13816, 5811, 0, 0, 0, 0x0, bhvStar, 31),
	OBJECT_WITH_ACTS(122, -22106, 18537, 7210, 0, 0, 0, 0x1010000, bhvStar, 31),
	OBJECT_WITH_ACTS(22, -25410, 10800, 8008, 0, 0, 0, 0xff0000, bhvWaterLevelDiamond, 31),
	OBJECT_WITH_ACTS(86, 14320, 3000, -760, 0, 0, 0, 0x0, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(86, 10322, 3000, -1074, 0, 120, 0, 0x0, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(86, -1380, 3997, -1373, 0, 180, 0, 0x14020001, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(86, -2850, 3997, -1373, 0, 0, 0, 0x14020001, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(86, -4440, 3997, -1343, 0, 180, 0, 0x14020001, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(86, -5670, 3997, -1313, 0, 0, 0, 0x14020001, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(86, -7320, 3997, -1253, 0, 180, 0, 0x14020001, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(86, -9150, 3997, -1433, 0, 0, 0, 0x14020001, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(86, -4460, 10559, 2859, 0, 90, 0, 0x49010000, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(86, -6744, 10559, 1314, 0, 90, 0, 0x49010000, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(212, -10631, 3501, -7005, 0, 90, 0, 0x0, bhv1Up, 31),
	OBJECT_WITH_ACTS(86, -7263, 10559, 4471, 0, 90, 0, 0x49010000, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(86, -9528, 10559, 2963, 0, 90, 0, 0x49010000, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(86, -9173, 10559, 893, 0, 90, 0, 0x49010000, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(137, 20536, 10833, -3656, 0, 0, 0, 0x20000, bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(129, -392, 7461, 8253, 0, 0, 0, 0x10000, bhvBreakableBox, 31),
	OBJECT_WITH_ACTS(86, -15050, 10559, -1647, 0, 90, 0, 0x49010000, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(57, -23024, 7539, 1734, 0, 0, 0, 0x96010049, Bhv_Custom_0x13000f58, 31),
	OBJECT_WITH_ACTS(86, -18560, 10559, -1531, 0, 90, 0, 0x49010000, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(212, 17852, 3264, -5566, 0, 90, 0, 0x0, bhv1Up, 31),
	OBJECT_WITH_ACTS(86, -22302, 10559, -1937, 0, 90, 0, 0x49010000, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(0, -22267, 3341, -9, 0, 90, 0, 0x28000000, Bhv_Custom_0x0701f9c0, 31),
	OBJECT_WITH_ACTS(86, -24054, 10559, -606, 0, 120, 0, 0x49010000, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(86, -23155, 10559, 1035, 0, 180, 0, 0x49010000, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(129, -392, 7261, 8253, 0, 0, 0, 0x0, bhvBreakableBox, 31),
	OBJECT_WITH_ACTS(86, -24986, 10559, 2477, 0, 160, 0, 0x49010000, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(86, -23351, 10559, 3827, 0, 180, 0, 0x49010000, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(129, -392, 7261, 8453, 0, 0, 0, 0x10000, bhvBreakableBox, 31),
	OBJECT_WITH_ACTS(86, -25241, 10559, 4673, 0, 180, 0, 0x49010000, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(129, -592, 7261, 8253, 0, 0, 0, 0x0, bhvBreakableBox, 31),
	OBJECT_WITH_ACTS(86, -11862, 10559, 1422, 0, 70, 0, 0x49010000, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(0, -25404, 3341, 7079, 0, 90, 0, 0x28000000, Bhv_Custom_0x0701f9c0, 31),
	OBJECT_WITH_ACTS(0, 16771, 3349, -6541, 0, 0, 0, 0x110000, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 17197, 4071, -7444, 0, 90, 0, 0x0, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 17402, 4071, -3530, 0, 90, 0, 0x0, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 14491, 4071, -6988, 0, 305, 0, 0x0, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 14583, 4071, -4033, 0, 55, 0, 0x0, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 20734, 11409, -1507, 0, 90, 0, 0x0, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -12781, 3997, -5328, 0, 180, 0, 0x40000, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -11470, 3997, -1750, 0, 58, 0, 0x0, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 138, 8042, 7891, 0, 0, 0, 0x110000, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(245, -3436, 7162, 6758, 90, 64, 0, 0x0, Bhv_Custom_0x0040fdd0, 31),
	OBJECT_WITH_ACTS(245, -4676, 7162, 6138, 90, 49, 0, 0x0, Bhv_Custom_0x0040fdd0, 31),
	OBJECT_WITH_ACTS(245, -5455, 7162, 4937, 90, 49, 0, 0x0, Bhv_Custom_0x0040fdd0, 31),
	OBJECT_WITH_ACTS(245, -10896, 7162, -2402, 90, 0, 0, 0x0, Bhv_Custom_0x0040fdd0, 31),
	OBJECT_WITH_ACTS(245, -10131, 7162, 1249, 90, 18, 0, 0x0, Bhv_Custom_0x0040fdd0, 31),
	OBJECT_WITH_ACTS(245, -8751, 7162, 3035, 90, 45, 0, 0x0, Bhv_Custom_0x0040fdd0, 31),
	OBJECT_WITH_ACTS(245, -7374, 7162, 3913, 90, 26, 0, 0x0, Bhv_Custom_0x0040fdd0, 31),
	OBJECT_WITH_ACTS(245, 1805, 3500, 384, 90, 45, 0, 0x0, Bhv_Custom_0x0040fdd0, 31),
	OBJECT_WITH_ACTS(245, 2400, 3500, -1071, 90, 355, 0, 0x0, Bhv_Custom_0x0040fdd0, 31),
	OBJECT_WITH_ACTS(245, 6243, 3500, 1405, 90, 93, 0, 0x0, Bhv_Custom_0x0040fdd0, 31),
	OBJECT_WITH_ACTS(245, 7805, 3500, 1311, 90, 100, 0, 0x0, Bhv_Custom_0x0040fdd0, 31),
	OBJECT_WITH_ACTS(105, -12803, 3997, -6302, 0, 0, 0, 0x0, bhvSkeeter, 31),
	OBJECT_WITH_ACTS(105, -9140, 3350, 1856, 0, 0, 0, 0x0, bhvSkeeter, 31),
	OBJECT_WITH_ACTS(105, 11754, 3350, 144, 0, 127, 0, 0x0, bhvSkeeter, 31),
	OBJECT_WITH_ACTS(105, 1531, 7257, 8562, 0, 0, 0, 0x0, bhvSkeeter, 31),
	OBJECT_WITH_ACTS(245, 10075, 3500, 1123, 90, 100, 0, 0x0, Bhv_Custom_0x0040fdd0, 31),
	OBJECT_WITH_ACTS(245, 12788, 3500, -557, 90, 118, 0, 0x0, Bhv_Custom_0x0040fdd0, 31),
	OBJECT_WITH_ACTS(245, -11191, 7162, -4638, 90, 0, 0, 0x0, Bhv_Custom_0x0040fdd0, 31),
	OBJECT_WITH_ACTS(0, 118, 6744, 6071, 0, 0, 0, 0x120000, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 10161, 8100, 1823, 0, 0, 0, 0xa004e20, Bhv_Custom_0x1300003c, 31),
	OBJECT_WITH_ACTS(86, -19111, 10559, -2404, 0, 90, 0, 0x49010000, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(86, -19034, 10559, -3246, 0, 90, 0, 0x49010000, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(86, -20747, 10559, -1390, 0, 90, 0, 0x49010000, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(86, -13704, 10559, -1822, 0, 50, 0, 0x49010000, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(120, 166, 8621, 5737, 0, 63, 0, 0x49010000, bhvRecoveryHeart, 31),
	OBJECT_WITH_ACTS(86, -20977, 10559, -2737, 0, 90, 0, 0x49010000, bhvSushiShark, 31),
	OBJECT_WITH_ACTS(105, 1493, 6050, 6483, 0, 0, 0, 0x0, bhvSkeeter, 31),
	OBJECT_WITH_ACTS(105, -1365, 6054, 6064, 0, 0, 0, 0x0, bhvSkeeter, 31),
	OBJECT_WITH_ACTS(105, -1463, 7254, 8101, 0, 0, 0, 0x0, bhvSkeeter, 31),
	OBJECT_WITH_ACTS(245, 2699, 3750, -1270, 0, 0, 0, 0x0, Bhv_Custom_0x0040fdd0, 31),
	OBJECT_WITH_ACTS(245, -25435, 12138, 7986, 0, 0, 0, 0x0, Bhv_Custom_0x0040fdd0, 31),
	OBJECT_WITH_ACTS(245, -25435, 13121, 7986, 0, 0, 0, 0x0, Bhv_Custom_0x0040fdd0, 31),
	OBJECT_WITH_ACTS(245, -25435, 11271, 7986, 0, 0, 0, 0x0, Bhv_Custom_0x0040fdd0, 31),
	OBJECT_WITH_ACTS(137, 163, 8791, 5750, 0, 0, 0, 0x20000, bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, -12275, 3997, -7582, 0, 0, 0, 0x110000, bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(245, -6735, 10910, 2165, 90, 80, 0, 0x0, Bhv_Custom_0x0040fdd0, 31),
	OBJECT_WITH_ACTS(245, -17655, 10910, -2515, 90, 93, 0, 0x0, Bhv_Custom_0x0040fdd0, 31),
	OBJECT_WITH_ACTS(57, 13305, 3341, -716, 0, 305, 0, 0x28000000, bhvWdwSquareFloatingPlatform, 31),
	OBJECT_WITH_ACTS(57, 10141, 3341, 1072, 0, 277, 0, 0x28000000, bhvWdwSquareFloatingPlatform, 31),
	OBJECT_WITH_ACTS(57, 8056, 3341, 1324, 0, 0, 0, 0x26010000, Bhv_Custom_0x13000f58, 31),
	OBJECT_WITH_ACTS(57, -10559, 3341, -7030, 0, 305, 0, 0x28000000, bhvWdwSquareFloatingPlatform, 31),
	OBJECT_WITH_ACTS(120, 925, 4097, -1531, 0, 63, 0, 0x49010000, bhvRecoveryHeart, 31),
	TERRAIN(lll_area_1_collision),
	MACRO_OBJECTS(lll_area_1_macro_objs),
	SET_BACKGROUND_MUSIC(0,5),
	TERRAIN_TYPE(TERRAIN_GRASS),
	/* Fast64 begin persistent block [area commands] */
	/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 16751, 3349, -5754),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
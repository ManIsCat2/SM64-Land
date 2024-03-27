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
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd),
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario),
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458),
	LOAD_MODEL_FROM_GEO(MODEL_GOOMBA, goomba_geo),
	JUMP_LINK(script_func_global_1),
	JUMP_LINK(script_func_global_4),
	JUMP_LINK(script_func_global_15),

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
	WARP_NODE(0xF1, LEVEL_CASTLE_GROUNDS, 1, 31, WARP_NO_CHECKPOINT),
	WARP_NODE(0xF0, LEVEL_CASTLE_GROUNDS, 1, 21, WARP_NO_CHECKPOINT),
	WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
	OBJECT(MODEL_NONE, -1674, 773, 12523, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
	OBJECT(E_MODEL_1UP, 5880, 3362, 7200, 0, 0, 0, 0, id_bhv1Up),
	OBJECT(E_MODEL_BLUE_COIN_SWITCH, 15223, 6919, 6814, 0, 0, 0, 0, id_bhvBlueCoinSwitch),
	OBJECT(E_MODEL_NONE, 13445, 2816, 10438, 0, 0, 0, (2 << 24), id_bhvBowserCourseRedCoinStar),
	OBJECT(E_MODEL_BREAKABLE_BOX, 3783, 3157, 6566, 0, 0, 0, (1 << 16), id_bhvBreakableBox),
	OBJECT(E_MODEL_CHAIN_CHOMP, 5880, 3157, 7200, 0, 0, 0, 0, id_bhvChainChomp),
	OBJECT(E_MODEL_CHECKERBOARD_PLATFORM, 15942, 7665, -6580, 0, 0, 0, 0, id_bhvCheckerboardElevatorGroup),
	OBJECT(E_MODEL_NONE, 60, 1688, 9795, 0, 90, 0, (16 << 16), id_bhvCoinFormation),
	OBJECT(E_MODEL_NONE, 7394, 2243, 9875, 0, 0, 0, (2 << 16), id_bhvCoinFormation),
	OBJECT(E_MODEL_NONE, 2308, 1475, 9816, 0, 0, 0, 0, id_bhvCoinFormation),
	OBJECT(E_MODEL_NONE, 16296, 2568, 10043, 0, 90, 0, 0, id_bhvCoinFormation),
	OBJECT(E_MODEL_NONE, 18217, 4175, 8382, 0, 90, 0, 0, id_bhvCoinFormation),
	OBJECT(E_MODEL_NONE, 20447, 2486, 9926, 0, 90, 0, (2 << 16), id_bhvCoinFormation),
	OBJECT(E_MODEL_NONE, 18312, 2566, 10449, 0, 90, 0, 0, id_bhvCoinFormation),
	OBJECT(E_MODEL_NONE, 18312, 2566, 9449, 0, 90, 0, 0, id_bhvCoinFormation),
	OBJECT(E_MODEL_NONE, -1623, 5134, 6373, 0, 0, 0, (2 << 16), id_bhvCoinFormation),
	OBJECT(E_MODEL_NONE, 4729, 3716, 8311, 0, 90, 0, 0, id_bhvCoinFormation),
	OBJECT(E_MODEL_NONE, 20316, 7027, 6804, 0, 0, 0, (2 << 16), id_bhvCoinFormation),
	OBJECT(E_MODEL_NONE, 24099, 6097, 5678, 0, 0, 0, (2 << 16), id_bhvCoinFormation),
	OBJECT(E_MODEL_NONE, 16235, 7749, -2585, 0, 0, 0, (19 << 16), id_bhvCoinFormation),
	OBJECT(E_MODEL_NONE, 16277, 8295, -8962, 0, 0, 0, (19 << 16), id_bhvCoinFormation),
	OBJECT(E_MODEL_EXCLAMATION_BOX, 4519, 2066, 9048, 0, -180, 0, 0, id_bhvExclamationBox),
	OBJECT(E_MODEL_GOOMBA, 14253, 2563, 9853, 0, 0, 0, 0, id_bhvGoomba),
	OBJECT(E_MODEL_GOOMBA, 23595, 5064, 8303, 0, 0, 0, 0, id_bhvGoomba),
	OBJECT(E_MODEL_NONE, 948, 4677, 7704, 0, 0, 0, 0, id_bhvGoombaTripletSpawner),
	OBJECT(E_MODEL_NONE, 23073, 3126, 10185, 0, 0, 0, 0, id_bhvGoombaTripletSpawner),
	OBJECT(E_MODEL_NONE, 17975, 7455, 3280, 0, 0, 0, 0, id_bhvGoombaTripletSpawner),
	OBJECT(E_MODEL_NONE, 15005, 6919, 6920, 0, 0, 0, 0, id_bhvGoombaTripletSpawner),
	OBJECT(E_MODEL_BLUE_COIN, 14197, 6919, 6138, 0, 0, 0, 0, id_bhvHiddenBlueCoin),
	OBJECT(E_MODEL_BLUE_COIN, 16170, 6919, 6137, 0, 0, 0, 0, id_bhvHiddenBlueCoin),
	OBJECT(E_MODEL_BLUE_COIN, 14175, 6919, 7578, 0, 0, 0, 0, id_bhvHiddenBlueCoin),
	OBJECT(E_MODEL_BLUE_COIN, 16188, 6919, 7575, 0, 0, 0, 0, id_bhvHiddenBlueCoin),
	OBJECT(E_MODEL_METAL_BOX, 12725, 1437, 9077, 0, 0, 0, 0, id_bhvPushableMetalBox),
	OBJECT(E_MODEL_METAL_BOX, 8802, 1437, 9064, 0, 0, 0, 0, id_bhvPushableMetalBox),
	OBJECT(E_MODEL_RED_COIN, 9102, 2243, 9081, 0, 0, 0, 0, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, 9839, 2474, 10583, 0, 0, 0, 0, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, 9853, 2474, 9021, 0, 0, 0, 0, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, 10394, 2585, 9232, 0, 0, 0, 0, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, 12184, 2585, 10355, 0, 0, 0, 0, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, 12510, 3154, 10565, 0, 0, 0, 0, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, 12517, 2499, 9083, 0, 0, 0, 0, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, 9127, 2243, 10528, 0, 0, 0, 0, id_bhvRedCoin),
	OBJECT(E_MODEL_BOB_SEESAW_PLATFORM, 52, 1469, 9760, 0, 90, 0, 0x00030000, id_bhvSeesawPlatform),
	OBJECT(E_MODEL_BOB_SEESAW_PLATFORM, 9114, 2161, 9822, 0, 0, 0, 0x00030000, id_bhvSeesawPlatform),
	OBJECT(E_MODEL_BOB_SEESAW_PLATFORM, 9849, 2306, 9824, 0, 0, 0, 0x00030000, id_bhvSeesawPlatform),
	OBJECT(E_MODEL_BOB_SEESAW_PLATFORM, 12512, 2368, 9850, 0, 0, 0, 0x00030000, id_bhvSeesawPlatform),
	OBJECT(E_MODEL_BOB_SEESAW_PLATFORM, 11420, 2309, 10361, 0, 90, 0, 0x00030000, id_bhvSeesawPlatform),
	OBJECT(E_MODEL_BOB_SEESAW_PLATFORM, 11143, 2309, 9225, 0, 90, 0, 0x00030000, id_bhvSeesawPlatform),
	OBJECT(E_MODEL_BOB_SEESAW_PLATFORM, 16255, 3501, 8486, 0, 90, 0, 0x00030000, id_bhvSeesawPlatform),
	OBJECT(E_MODEL_BOB_SEESAW_PLATFORM, 20399, 4292, 8477, 0, 90, 0, 0x00030000, id_bhvSeesawPlatform),
	OBJECT(E_MODEL_BOB_SEESAW_PLATFORM, 139, 5180, 6493, 0, 90, 0, 0x00030000, id_bhvSeesawPlatform),
	OBJECT(E_MODEL_BOB_SEESAW_PLATFORM, 1254, 5506, 5948, 0, 90, 0, 0x00030000, id_bhvSeesawPlatform),
	OBJECT(E_MODEL_BOB_SEESAW_PLATFORM, 2428, 5836, 6486, 0, 90, 0, 0x00030000, id_bhvSeesawPlatform),
	OBJECT(E_MODEL_BOB_SEESAW_PLATFORM, 3728, 1496, 9757, 0, 90, 0, 0x00030000, id_bhvSeesawPlatform),
	OBJECT(E_MODEL_BOB_SEESAW_PLATFORM, 5631, 1815, 9772, 0, 90, 0, 0x00030000, id_bhvSeesawPlatform),
	OBJECT(E_MODEL_BOB_SEESAW_PLATFORM, 16235, 7416, -1921, 0, 0, 0, 0x00030000, id_bhvSeesawPlatform),
	OBJECT(E_MODEL_BOB_SEESAW_PLATFORM, 16217, 7438, -5025, 0, 0, 0, 0x00030000, id_bhvSeesawPlatform),
	OBJECT(E_MODEL_BOB_SEESAW_PLATFORM, 16223, 7911, -8236, 0, 0, 1, 0x00030000, id_bhvSeesawPlatform),
	OBJECT(E_MODEL_BOB_SEESAW_PLATFORM, 16277, 7911, -11246, 0, 0, 0, 0x00030000, id_bhvSeesawPlatform),
	OBJECT(E_MODEL_BOB_SEESAW_PLATFORM, 23822, 6891, 4741, 0, 90, 0, 0x00030000, id_bhvSeesawPlatform),
	OBJECT(E_MODEL_STAR, 7358, 5653, 6234, 0, 0, 0, 0, id_bhvStar),
	OBJECT(E_MODEL_STAR, 16483, 8306, -15470, 0, 0, 0, (1 << 24) | (1 << 16), id_bhvStar),
	TERRAIN(bob_area_1_collision),
	MACRO_OBJECTS(bob_area_1_macro_objs),
	SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
	TERRAIN_TYPE(TERRAIN_GRASS),
	/* Fast64 begin persistent block [area commands] */
	/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, bob_area_3),
	WARP_NODE(0xF1, LEVEL_CASTLE_GROUNDS, 1, 109, WARP_NO_CHECKPOINT),
	WARP_NODE(0xF0, LEVEL_CASTLE_GROUNDS, 1, 108, WARP_NO_CHECKPOINT),
	WARP_NODE(10, LEVEL_BOB, 3, 0, WARP_NO_CHECKPOINT),
	MARIO_POS(0x03, 0, 0, 0, 0),
	OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
	OBJECT(E_MODEL_KING_BOBOMB, 0, 0, 0, 0, 0, 0, (3 << 24), id_bhvKingBobomb),
	TERRAIN(bob_area_3_collision),
	MACRO_OBJECTS(bob_area_3_macro_objs),
	SET_BACKGROUND_MUSIC(0x00, 0x39),
	TERRAIN_TYPE(TERRAIN_GRASS),
	/* Fast64 begin persistent block [area commands] */
	/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, bob_area_2),
	MARIO_POS(0x03, 0, 0, 1, 0),
	OBJECT(MODEL_NONE, -10345, 500, -21, 0, 90, 0, (10 << 16), bhvSpinAirborneWarp),
	OBJECT(E_MODEL_STAR, -9006, 558, -28971, 0, 0, 0, (5 << 24), id_bhvStar),
	OBJECT(MODEL_NONE, -2522, 4499, -4482, 0, 0, 0, (4 << 24), bhvBowserCourseRedCoinStar),
	OBJECT(E_MODEL_RED_COIN, -11032, 4259, -3920, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, -5516, 3106, -4836, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, -8444, 3258, -3785, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, -4403, 3525, -2569, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, -6494, 2955, -3025, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, -9384, 3702, -2517, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, -2562, 4259, -3034, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(E_MODEL_RED_COIN, -3710, 3913, -4008, 0, 0, 0, 0x00000000, id_bhvRedCoin),
	OBJECT(MODEL_NONE, -1038, 1246, -740, 0, 2, 0, (2 << 16), bhvCoinFormation),
	OBJECT(MODEL_NONE, -9047, -284, -19793, 0, 2, 0, (2 << 16), bhvCoinFormation),
	OBJECT(MODEL_NONE, -4403, 3525, -2569, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -6494, 2955, -3025, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -9384, 3702, -2517, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -2562, 4259, -3034, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -3710, 3913, -4008, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -1038, 1246, -740, 0, 2, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -9047, -284, -19793, 0, 2, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -975, 2048, -6825, 0, 2, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -11045, 2902, -2628, 0, 2, 0, 0x00000000, bhvStaticObject),
	OBJECT(E_MODEL_1UP, -1858, 4285, -2043, 0, 0, 0, 0x00000000, id_bhv1Up),
	OBJECT(MODEL_NONE, -8288, 2502, -1409, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -9729, 2634, -1475, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -8280, 281, 30, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -8080, 540, 30, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -7880, 617, 30, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -7680, 640, 30, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -7480, 578, 30, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -7280, 488, 30, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -4353, 1857, -737, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -4553, 1896, -937, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -4753, 1936, -1137, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -4953, 1977, -1337, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -5153, 2019, -1537, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -5353, 2061, -1737, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -5553, 2104, -1537, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -5753, 2146, -1337, 0, 0, 0, 0x00000000, bhvStaticObject),
	OBJECT(MODEL_NONE, -5953, 2188, -1137, 0, 0, 0, 0x00000000, bhvStaticObject),
	TERRAIN(bob_area_2_collision),
	MACRO_OBJECTS(bob_area_2_macro_objs),
	SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
	TERRAIN_TYPE(TERRAIN_GRASS),
	/* Fast64 begin persistent block [area commands] */
	/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x03, 0, 0, 1, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

movtexqc_register('castle_grounds_1_Movtex_0', 16, 1, 0)
movtexqc_register('castle_grounds_1_Movtex_1', 16, 1, 0)
movtexqc_register('castle_grounds_1_Movtex_2', 16, 1, 0)
movtexqc_register('castle_grounds_2_Movtex_0', 16, 2, 0)
movtexqc_register('castle_grounds_2_Movtex_1', 16, 2, 0)
movtexqc_register('castle_grounds_2_Movtex_2', 16, 2, 0)
movtexqc_register('castle_grounds_3_Movtex_0', 16, 3, 0)
movtexqc_register('castle_grounds_3_Movtex_1', 16, 3, 0)
movtexqc_register('castle_grounds_3_Movtex_2', 16, 3, 0)
movtexqc_register('castle_grounds_4_Movtex_0', 16, 4, 0)
movtexqc_register('castle_grounds_4_Movtex_1', 16, 4, 0)
movtexqc_register('castle_grounds_4_Movtex_2', 16, 4, 0)
movtexqc_register('ending_1_Movtex_0', 25, 1, 0)
movtexqc_register('ending_1_Movtex_1', 25, 1, 0)
movtexqc_register('ending_1_Movtex_2', 25, 1, 0)
movtexqc_register('ending_2_Movtex_0', 25, 1, 0)
movtexqc_register('ending_2_Movtex_1', 25, 1, 0)
movtexqc_register('ending_2_Movtex_2', 25, 1, 0)

--for all hubs with water:
-- OBJECT_WITH_ACTS(/* model*/ 0, /*speed*/ 4, /*axis*/4, /*vtx count*/4, 0, /*scroll type*/ 0, /*cycle*/ 1, /*index*/ id, RM_Scroll_Texture, 31),

-- among us
add_scroll_target(4, "VB_castle_grounds_1_0xe0148a0", 0, 4)
add_scroll_target(5, "VB_castle_grounds_2_0xe019cc0", 0, 4)

add_scroll_target(6, "VB_castle_courtyard_1_0xe01d000", 0, 4)
add_scroll_target(7, "VB_castle_courtyard_1_0xe020de0", 0, 11)
add_scroll_target(7, "VB_castle_courtyard_1_0xe020e90", 0, 14)
add_scroll_target(7, "VB_castle_courtyard_1_0xe020f70", 0, 10)
add_scroll_target(7, "VB_castle_courtyard_1_0xe021010", 0, 13)
add_scroll_target(7, "VB_castle_courtyard_1_0xe0210e0", 0, 10)
add_scroll_target(8, "VB_castle_courtyard_2_0xe025bd0", 0, 4)

-- RM2C
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
-- OBJECT_WITH_ACTS(/* model*/ 0, /*speed*/ 4, /*axis*/4, /*vtx count*/size, 0, /*scroll type*/ 0, /*cycle*/ 1, /*index*/ id, RM_Scroll_Texture, 31),

add_scroll_target(563, "lll_dl_Water_Box_Mesh_mesh_layer_5_vtx_0", 0, 4)

-- among us
add_scroll_target(4, "VB_castle_grounds_1_0xe0148a0", 0, 4)
add_scroll_target(5, "VB_castle_grounds_2_0xe019cc0", 0, 4)
add_scroll_target(10, "VB_castle_grounds_4_0xe06a520", 0, 4)

add_scroll_target(6, "VB_castle_courtyard_1_0xe01d000", 0, 4)
add_scroll_target(7, "VB_castle_courtyard_1_0xe020de0", 0, 11)
add_scroll_target(7, "VB_castle_courtyard_1_0xe020e90", 0, 14)
add_scroll_target(7, "VB_castle_courtyard_1_0xe020f70", 0, 10)
add_scroll_target(7, "VB_castle_courtyard_1_0xe021010", 0, 13)
add_scroll_target(7, "VB_castle_courtyard_1_0xe0210e0", 0, 10)
add_scroll_target(8, "VB_castle_courtyard_2_0xe025bd0", 0, 4)
add_scroll_target(9, "VB_castle_courtyard_3_0xe048d20", 0, 4)

add_scroll_target(11, "VB_castle_inside_1_0xe016800", 0, 4)

add_scroll_target(12, "VB_ccm_1_0xe00ac10", 0, 15)
add_scroll_target(12, "VB_ccm_1_0xe00ad00", 0, 15)
add_scroll_target(12, "VB_ccm_1_0xe00adf0", 0, 15)
add_scroll_target(12, "VB_ccm_1_0xe00aee0", 0, 15)
add_scroll_target(13, "VB_ccm_2_0xe018b50", 0, 13)
add_scroll_target(13, "VB_ccm_2_0xe018c20", 0, 15)
add_scroll_target(13, "VB_ccm_2_0xe018d10", 0, 13)
add_scroll_target(13, "VB_ccm_2_0xe018de0", 0, 14)
add_scroll_target(13, "VB_ccm_2_0xe018ec0", 0, 9)
add_scroll_target(13, "VB_ccm_2_0xe018f50", 0, 15)
add_scroll_target(13, "VB_ccm_2_0xe019040", 0, 9)
add_scroll_target(13, "VB_ccm_2_0xe0190d0", 0, 9)
add_scroll_target(13, "VB_ccm_2_0xe019160", 0, 9)
add_scroll_target(13, "VB_ccm_2_0xe0191f0", 0, 13)
add_scroll_target(13, "VB_ccm_2_0xe0192c0", 0, 11)
add_scroll_target(13, "VB_ccm_2_0xe019370", 0, 12)

-- awesome index bro
add_scroll_target(0xe023e10, "VB_wf_1_0xe023e10", 0, 14)
add_scroll_target(0xe023e10, "VB_wf_1_0xe023ef0", 0, 12)
add_scroll_target(0xe023e10, "VB_wf_1_0xe023fb0", 0, 8)
add_scroll_target(0xe023e10, "VB_wf_1_0xe024030", 0, 13)
add_scroll_target(0xe023e10, "VB_wf_1_0xe024100", 0, 6)

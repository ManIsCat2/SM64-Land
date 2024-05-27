Lights1 kickable_rock__082_24AD8484_c_bmp_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF,0xFF,0xFF,0x28,0x28,0x28);

Gfx kickable_rock__24AD8484_c_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 kickable_rock__24AD8484_c_rgba16[] = {
	#include "actors/kickable_rock/_24AD8484_c.rgba16.inc.c"
};

Vtx kickable_rock_Rock_mesh_layer_1_vtx_cull[8] = {
	{{{-53, -53, 50}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{-53, 53, 50}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{-53, 53, -50}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{-53, -53, -50}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{53, -53, 50}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{53, 53, 50}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{53, 53, -50}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{53, -53, -50}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
};

Vtx kickable_rock_Rock_mesh_layer_1_vtx_0[20] = {
	{{{35, -20, -38}, 0, {1708, 1218}, {0x50, 0xD3, 0xA9, 0xFF}}},
	{{{47, -31, -2}, 0, {1154, 1572}, {0x6B, 0xBB, 0xFC, 0xFF}}},
	{{{-13, -53, -11}, 0, {-128, 1802}, {0xE3, 0x87, 0xE7, 0xFF}}},
	{{{53, 3, 19}, 0, {1492, 2180}, {0x77, 0x6, 0x2C, 0xFF}}},
	{{{45, 34, -4}, 0, {2120, 2452}, {0x64, 0x4E, 0xF7, 0xFF}}},
	{{{34, 20, -40}, 0, {2470, 1982}, {0x4D, 0x2D, 0xA5, 0xFF}}},
	{{{-4, 31, -47}, 0, {2722, 2814}, {0xF7, 0x45, 0x96, 0xFF}}},
	{{{-26, -3, -50}, 0, {1632, 2480}, {0xC5, 0xFA, 0x90, 0xFF}}},
	{{{-1, -34, -45}, 0, {824, 1096}, {0xFD, 0xB3, 0x9B, 0xFF}}},
	{{{-53, -3, -19}, 0, {318, 3904}, {0x89, 0xFA, 0xD4, 0xFF}}},
	{{{-45, -34, 4}, 0, {-324, 2996}, {0x9B, 0xB3, 0x9, 0xFF}}},
	{{{17, -51, 15}, 0, {362, 1852}, {0x27, 0x8C, 0x22, 0xFF}}},
	{{{4, -31, 47}, 0, {424, 2590}, {0x9, 0xBB, 0x6A, 0xFF}}},
	{{{26, 3, 50}, 0, {1062, 2716}, {0x3B, 0x6, 0x70, 0xFF}}},
	{{{1, 34, 45}, 0, {1322, 3358}, {0x3, 0x4E, 0x64, 0xFF}}},
	{{{13, 53, 11}, 0, {2028, 3254}, {0x1D, 0x79, 0x19, 0xFF}}},
	{{{-17, 51, -15}, 0, {2286, 3726}, {0xD9, 0x74, 0xDE, 0xFF}}},
	{{{-47, 31, 2}, 0, {1222, 4268}, {0x95, 0x45, 0x3, 0xFF}}},
	{{{-35, 20, 38}, 0, {788, 3804}, {0xB0, 0x2D, 0x57, 0xFF}}},
	{{{-34, -20, 40}, 0, {130, 3238}, {0xB3, 0xD3, 0x5B, 0xFF}}},
};

Gfx kickable_rock_Rock_mesh_layer_1_tri_0[] = {
	gsSPVertex(kickable_rock_Rock_mesh_layer_1_vtx_0 + 0, 20, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
	gsSP2Triangles(3, 0, 4, 0, 4, 0, 5, 0),
	gsSP2Triangles(5, 0, 6, 0, 7, 6, 0, 0),
	gsSP2Triangles(8, 7, 0, 0, 8, 0, 2, 0),
	gsSP2Triangles(2, 9, 8, 0, 10, 9, 2, 0),
	gsSP2Triangles(2, 11, 10, 0, 11, 2, 1, 0),
	gsSP2Triangles(11, 1, 12, 0, 13, 12, 1, 0),
	gsSP2Triangles(3, 13, 1, 0, 13, 3, 14, 0),
	gsSP2Triangles(15, 14, 3, 0, 4, 15, 3, 0),
	gsSP2Triangles(4, 5, 15, 0, 5, 6, 15, 0),
	gsSP2Triangles(16, 15, 6, 0, 16, 6, 9, 0),
	gsSP2Triangles(7, 9, 6, 0, 8, 9, 7, 0),
	gsSP2Triangles(17, 16, 9, 0, 17, 18, 16, 0),
	gsSP2Triangles(18, 17, 19, 0, 17, 9, 19, 0),
	gsSP2Triangles(10, 19, 9, 0, 19, 10, 12, 0),
	gsSP2Triangles(11, 12, 10, 0, 19, 12, 14, 0),
	gsSP2Triangles(13, 14, 12, 0, 18, 19, 14, 0),
	gsSP2Triangles(14, 15, 18, 0, 15, 16, 18, 0),
	gsSPEndDisplayList(),
};


Gfx mat_kickable_rock__082_24AD8484_c_bmp_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, kickable_rock__24AD8484_c_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 4095, 128),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 252),
	gsSPSetLights1(kickable_rock__082_24AD8484_c_bmp_f3d_lights),
	gsSPEndDisplayList(),
};

Gfx kickable_rock_Rock_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(kickable_rock_Rock_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_kickable_rock__082_24AD8484_c_bmp_f3d),
	gsSPDisplayList(kickable_rock_Rock_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx kickable_rock_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


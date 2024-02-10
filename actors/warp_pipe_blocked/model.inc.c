Lights1 warp_pipe_blocked_Bottom_lights = gdSPDefLights1(
	0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x28, 0x28, 0x28);

Gfx warp_pipe_blocked_warp_pipe_side_rgba16_i8_aligner[] = {gsSPEndDisplayList()};
u8 warp_pipe_blocked_warp_pipe_side_rgba16_i8[] = {
	#include "actors/warp_pipe_blocked/warp_pipe_side.rgba16.i8.inc.c"
};

Gfx warp_pipe_blocked_warp_pipe_top_rgba16_i8_aligner[] = {gsSPEndDisplayList()};
u8 warp_pipe_blocked_warp_pipe_top_rgba16_i8[] = {
	#include "actors/warp_pipe_blocked/warp_pipe_top.rgba16.i8.inc.c"
};

Vtx warp_pipe_blocked_skinned_mesh_layer_1_vtx_cull[8] = {
	{{ {-153, 0, 154}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-153, 205, 154}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-153, 205, -153}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-153, 0, -153}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {154, 0, 154}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {154, 205, 154}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {154, 205, -153}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {154, 0, -153}, 0, {-16, -16}, {0, 0, 0, 0} }},
};

Vtx warp_pipe_blocked_skinned_mesh_layer_1_vtx_0[96] = {
	{{ {0, 0, -153}, 0, {-16, 2032}, {0, 0, 0, 255} }},
	{{ {-108, 0, -108}, 0, {974, 2032}, {0, 0, 0, 255} }},
	{{ {-108, 179, -108}, 0, {974, 240}, {0, 0, 0, 255} }},
	{{ {0, 179, -153}, 0, {-16, 240}, {0, 0, 0, 255} }},
	{{ {-108, 205, -108}, 0, {974, -16}, {120, 0, 89, 255} }},
	{{ {0, 205, -153}, 0, {-16, -16}, {120, 0, 89, 255} }},
	{{ {109, 179, -108}, 0, {-16, 240}, {0, 0, 0, 255} }},
	{{ {109, 0, -108}, 0, {-16, 2032}, {0, 0, 0, 255} }},
	{{ {0, 0, -153}, 0, {974, 2032}, {0, 0, 0, 255} }},
	{{ {0, 179, -153}, 0, {974, 240}, {0, 0, 0, 255} }},
	{{ {109, 205, -108}, 0, {-16, -16}, {120, 0, 89, 255} }},
	{{ {0, 205, -153}, 0, {974, -16}, {120, 0, 89, 255} }},
	{{ {-108, 179, 109}, 0, {-16, 240}, {0, 0, 0, 255} }},
	{{ {-108, 0, 109}, 0, {-16, 2032}, {0, 0, 0, 255} }},
	{{ {0, 0, 154}, 0, {974, 2032}, {0, 0, 0, 255} }},
	{{ {0, 179, 154}, 0, {974, 240}, {1, 0, 1, 255} }},
	{{ {-108, 205, 109}, 0, {-16, -16}, {120, 0, 89, 255} }},
	{{ {0, 205, 154}, 0, {974, -16}, {117, 0, 87, 255} }},
	{{ {-108, 0, -108}, 0, {-16, 2032}, {0, 0, 0, 255} }},
	{{ {-153, 0, 0}, 0, {974, 2032}, {0, 0, 0, 255} }},
	{{ {-153, 179, 0}, 0, {974, 240}, {0, 0, 0, 255} }},
	{{ {-108, 179, -108}, 0, {-16, 240}, {0, 0, 0, 255} }},
	{{ {-153, 205, 0}, 0, {974, -16}, {120, 0, 90, 255} }},
	{{ {-108, 205, -108}, 0, {-16, -16}, {120, 0, 89, 255} }},
	{{ {-71, 179, 72}, 0, {-16, 240}, {0, 0, 0, 255} }},
	{{ {-101, 205, 0}, 0, {974, -16}, {120, 0, 89, 255} }},
	{{ {-71, 205, 72}, 0, {-16, -16}, {120, 0, 89, 255} }},
	{{ {-101, 179, 0}, 0, {974, 240}, {0, 0, 0, 255} }},
	{{ {-71, 0, 72}, 0, {-16, 2032}, {0, 0, 0, 255} }},
	{{ {-101, 0, 0}, 0, {974, 2032}, {0, 0, 0, 255} }},
	{{ {-108, 205, 109}, 0, {974, -16}, {120, 0, 89, 255} }},
	{{ {-153, 205, 0}, 0, {-16, -16}, {120, 0, 90, 255} }},
	{{ {-153, 179, 0}, 0, {-16, 240}, {0, 0, 0, 255} }},
	{{ {-108, 179, 109}, 0, {974, 240}, {0, 0, 0, 255} }},
	{{ {-153, 0, 0}, 0, {-16, 2032}, {0, 0, 0, 255} }},
	{{ {-108, 0, 109}, 0, {974, 2032}, {0, 0, 0, 255} }},
	{{ {-101, 179, 0}, 0, {-16, 240}, {0, 0, 0, 255} }},
	{{ {-71, 205, -71}, 0, {974, -16}, {120, 0, 89, 255} }},
	{{ {-101, 205, 0}, 0, {-16, -16}, {120, 0, 89, 255} }},
	{{ {-71, 179, -71}, 0, {974, 240}, {0, 0, 0, 255} }},
	{{ {-101, 0, 0}, 0, {-16, 2032}, {0, 0, 0, 255} }},
	{{ {-71, 0, -71}, 0, {974, 2032}, {0, 0, 0, 255} }},
	{{ {109, 205, 109}, 0, {974, -16}, {120, 0, 89, 255} }},
	{{ {0, 205, 154}, 0, {-16, -16}, {117, 0, 87, 255} }},
	{{ {0, 179, 154}, 0, {-16, 240}, {1, 0, 1, 255} }},
	{{ {109, 179, 109}, 0, {974, 240}, {0, 0, 0, 255} }},
	{{ {0, 0, 154}, 0, {-16, 2032}, {0, 0, 0, 255} }},
	{{ {109, 0, 109}, 0, {974, 2032}, {0, 0, 0, 255} }},
	{{ {154, 179, 0}, 0, {-16, 240}, {0, 0, 0, 255} }},
	{{ {154, 0, 0}, 0, {-16, 2032}, {0, 0, 0, 255} }},
	{{ {109, 0, -108}, 0, {974, 2032}, {0, 0, 0, 255} }},
	{{ {109, 179, -108}, 0, {974, 240}, {0, 0, 0, 255} }},
	{{ {154, 205, 0}, 0, {-16, -16}, {120, 0, 89, 255} }},
	{{ {109, 205, -108}, 0, {974, -16}, {120, 0, 89, 255} }},
	{{ {72, 179, 72}, 0, {974, 240}, {1, 0, 1, 255} }},
	{{ {102, 0, 0}, 0, {-16, 2032}, {0, 0, 0, 255} }},
	{{ {72, 0, 72}, 0, {974, 2032}, {0, 0, 0, 255} }},
	{{ {102, 179, 0}, 0, {-16, 240}, {0, 0, 0, 255} }},
	{{ {72, 205, 72}, 0, {974, -16}, {120, 0, 89, 255} }},
	{{ {102, 205, 0}, 0, {-16, -16}, {120, 0, 89, 255} }},
	{{ {109, 179, 109}, 0, {-16, 240}, {0, 0, 0, 255} }},
	{{ {109, 0, 109}, 0, {-16, 2032}, {0, 0, 0, 255} }},
	{{ {154, 0, 0}, 0, {974, 2032}, {0, 0, 0, 255} }},
	{{ {154, 179, 0}, 0, {974, 240}, {0, 0, 0, 255} }},
	{{ {109, 205, 109}, 0, {-16, -16}, {120, 0, 89, 255} }},
	{{ {154, 205, 0}, 0, {974, -16}, {120, 0, 89, 255} }},
	{{ {0, 0, 102}, 0, {974, 2032}, {0, 0, 0, 255} }},
	{{ {72, 179, 72}, 0, {-16, 240}, {1, 0, 1, 255} }},
	{{ {72, 0, 72}, 0, {-16, 2032}, {0, 0, 0, 255} }},
	{{ {0, 179, 102}, 0, {974, 240}, {0, 0, 0, 255} }},
	{{ {72, 205, 72}, 0, {-16, -16}, {120, 0, 89, 255} }},
	{{ {0, 205, 102}, 0, {974, -16}, {120, 0, 89, 255} }},
	{{ {72, 179, -71}, 0, {974, 240}, {1, 0, 1, 255} }},
	{{ {0, 0, -101}, 0, {-16, 2032}, {0, 0, 0, 255} }},
	{{ {72, 0, -71}, 0, {974, 2032}, {0, 0, 0, 255} }},
	{{ {0, 179, -101}, 0, {-16, 240}, {0, 0, 0, 255} }},
	{{ {72, 205, -71}, 0, {974, -16}, {120, 0, 90, 255} }},
	{{ {0, 205, -101}, 0, {-16, -16}, {120, 0, 89, 255} }},
	{{ {72, 205, -71}, 0, {-16, -16}, {120, 0, 90, 255} }},
	{{ {102, 179, 0}, 0, {974, 240}, {0, 0, 0, 255} }},
	{{ {102, 205, 0}, 0, {974, -16}, {120, 0, 89, 255} }},
	{{ {72, 179, -71}, 0, {-16, 240}, {1, 0, 1, 255} }},
	{{ {102, 0, 0}, 0, {974, 2032}, {0, 0, 0, 255} }},
	{{ {72, 0, -71}, 0, {-16, 2032}, {0, 0, 0, 255} }},
	{{ {-71, 179, -71}, 0, {-16, 240}, {0, 0, 0, 255} }},
	{{ {0, 205, -101}, 0, {974, -16}, {120, 0, 89, 255} }},
	{{ {-71, 205, -71}, 0, {-16, -16}, {120, 0, 89, 255} }},
	{{ {0, 179, -101}, 0, {974, 240}, {0, 0, 0, 255} }},
	{{ {-71, 0, -71}, 0, {-16, 2032}, {0, 0, 0, 255} }},
	{{ {0, 0, -101}, 0, {974, 2032}, {0, 0, 0, 255} }},
	{{ {-71, 0, 72}, 0, {974, 2032}, {0, 0, 0, 255} }},
	{{ {0, 179, 102}, 0, {-16, 240}, {0, 0, 0, 255} }},
	{{ {0, 0, 102}, 0, {-16, 2032}, {0, 0, 0, 255} }},
	{{ {-71, 179, 72}, 0, {974, 240}, {0, 0, 0, 255} }},
	{{ {0, 205, 102}, 0, {-16, -16}, {120, 0, 89, 255} }},
	{{ {-71, 205, 72}, 0, {974, -16}, {120, 0, 89, 255} }},
};

Gfx warp_pipe_blocked_skinned_mesh_layer_1_tri_0[] = {
	gsSPVertex(warp_pipe_blocked_skinned_mesh_layer_1_vtx_0 + 0, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
	gsSP2Triangles(10, 6, 9, 0, 10, 9, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 12, 15, 0, 16, 15, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 18, 20, 21, 0),
	gsSP2Triangles(21, 20, 22, 0, 21, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 27, 25, 0),
	gsSP2Triangles(28, 27, 24, 0, 28, 29, 27, 0),
	gsSPVertex(warp_pipe_blocked_skinned_mesh_layer_1_vtx_0 + 30, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 6, 9, 7, 0),
	gsSP2Triangles(10, 9, 6, 0, 10, 11, 9, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(15, 14, 16, 0, 15, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 18, 20, 21, 0),
	gsSP2Triangles(22, 18, 21, 0, 22, 21, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 27, 25, 0),
	gsSP2Triangles(28, 27, 24, 0, 28, 29, 27, 0),
	gsSPVertex(warp_pipe_blocked_skinned_mesh_layer_1_vtx_0 + 60, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 0, 3, 0, 4, 3, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 6, 9, 7, 0),
	gsSP2Triangles(9, 10, 7, 0, 9, 11, 10, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSP2Triangles(16, 15, 12, 0, 16, 17, 15, 0),
	gsSP2Triangles(18, 19, 20, 0, 18, 21, 19, 0),
	gsSP2Triangles(21, 22, 19, 0, 21, 23, 22, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 27, 25, 0),
	gsSP2Triangles(28, 27, 24, 0, 28, 29, 27, 0),
	gsSPVertex(warp_pipe_blocked_skinned_mesh_layer_1_vtx_0 + 90, 6, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(3, 4, 1, 0, 3, 5, 4, 0),
	gsSPEndDisplayList(),
};

Vtx warp_pipe_blocked_skinned_mesh_layer_1_vtx_1[16] = {
	{{ {109, 205, -108}, 0, {384, -190}, {120, 0, 89, 255} }},
	{{ {0, 205, -153}, 0, {-2, 36}, {120, 0, 89, 255} }},
	{{ {0, 205, -101}, 0, {168, 170}, {120, 0, 89, 255} }},
	{{ {-71, 205, -71}, 0, {108, 478}, {120, 0, 89, 255} }},
	{{ {-108, 205, -108}, 0, {-88, 498}, {120, 0, 89, 255} }},
	{{ {-101, 205, 0}, 0, {282, 764}, {120, 0, 89, 255} }},
	{{ {-153, 205, 0}, 0, {170, 926}, {120, 0, 90, 255} }},
	{{ {-71, 205, 72}, 0, {588, 860}, {120, 0, 89, 255} }},
	{{ {-108, 205, 109}, 0, {628, 1066}, {120, 0, 89, 255} }},
	{{ {0, 205, 102}, 0, {846, 708}, {120, 0, 89, 255} }},
	{{ {0, 205, 154}, 0, {1016, 844}, {117, 0, 87, 255} }},
	{{ {109, 205, 109}, 0, {1104, 382}, {120, 0, 89, 255} }},
	{{ {72, 205, 72}, 0, {904, 400}, {120, 0, 89, 255} }},
	{{ {154, 205, 0}, 0, {842, -46}, {120, 0, 89, 255} }},
	{{ {102, 205, 0}, 0, {730, 116}, {120, 0, 89, 255} }},
	{{ {72, 205, -71}, 0, {426, 20}, {120, 0, 90, 255} }},
};

Gfx warp_pipe_blocked_skinned_mesh_layer_1_tri_1[] = {
	gsSPVertex(warp_pipe_blocked_skinned_mesh_layer_1_vtx_1 + 0, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(1, 4, 3, 0, 4, 5, 3, 0),
	gsSP2Triangles(4, 6, 5, 0, 6, 7, 5, 0),
	gsSP2Triangles(6, 8, 7, 0, 8, 9, 7, 0),
	gsSP2Triangles(8, 10, 9, 0, 11, 9, 10, 0),
	gsSP2Triangles(11, 12, 9, 0, 13, 12, 11, 0),
	gsSP2Triangles(13, 14, 12, 0, 13, 15, 14, 0),
	gsSP2Triangles(13, 0, 15, 0, 0, 2, 15, 0),
	gsSPEndDisplayList(),
};

Vtx warp_pipe_blocked_skinned_mesh_layer_1_vtx_2[4] = {
	{{ {-101, 10, 102}, 0, {-16, -16}, {0, 127, 0, 255} }},
	{{ {102, 10, -101}, 0, {-16, -16}, {0, 127, 0, 255} }},
	{{ {-101, 10, -101}, 0, {-16, -16}, {0, 127, 0, 255} }},
	{{ {102, 10, 102}, 0, {-16, -16}, {0, 127, 0, 255} }},
};

Gfx warp_pipe_blocked_skinned_mesh_layer_1_tri_2[] = {
	gsSPVertex(warp_pipe_blocked_skinned_mesh_layer_1_vtx_2 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSPEndDisplayList(),
};


Gfx mat_warp_pipe_blocked_Side[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, TEXEL0, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0),
	gsSPGeometryMode(G_LIGHTING, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_I, G_IM_SIZ_8b_LOAD_BLOCK, 1, warp_pipe_blocked_warp_pipe_side_rgba16_i8),
	gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 512),
	gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 252),
	gsSPEndDisplayList(),
};

Gfx mat_revert_warp_pipe_blocked_Side[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx mat_warp_pipe_blocked_Top[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, TEXEL0, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0),
	gsSPGeometryMode(G_LIGHTING, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_I, G_IM_SIZ_8b_LOAD_BLOCK, 1, warp_pipe_blocked_warp_pipe_top_rgba16_i8),
	gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 511, 512),
	gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_warp_pipe_blocked_Top[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx mat_warp_pipe_blocked_Bottom[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(warp_pipe_blocked_Bottom_lights),
	gsSPEndDisplayList(),
};

Gfx warp_pipe_blocked_skinned_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(warp_pipe_blocked_skinned_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_warp_pipe_blocked_Side),
	gsSPDisplayList(warp_pipe_blocked_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_warp_pipe_blocked_Side),
	gsSPDisplayList(mat_warp_pipe_blocked_Top),
	gsSPDisplayList(warp_pipe_blocked_skinned_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_warp_pipe_blocked_Top),
	gsSPDisplayList(mat_warp_pipe_blocked_Bottom),
	gsSPDisplayList(warp_pipe_blocked_skinned_mesh_layer_1_tri_2),
	gsSPEndDisplayList(),
};

Gfx warp_pipe_blocked_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


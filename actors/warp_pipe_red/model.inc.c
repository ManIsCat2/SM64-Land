Lights1 warp_pipe_red_Side_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 warp_pipe_red_Black_lights = gdSPDefLights1(
	0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x28, 0x28, 0x28);

Lights1 warp_pipe_red_Top_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Gfx warp_pipe_red_warp_pipe_side_rgba16_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 warp_pipe_red_warp_pipe_side_rgba16_rgba16[] = {
	#include "actors/warp_pipe_red/warp_pipe_side.rgba16.inc.c"
};

Gfx warp_pipe_red_warp_pipe_top_rgba16_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 warp_pipe_red_warp_pipe_top_rgba16_rgba16[] = {
	#include "actors/warp_pipe_red/warp_pipe_top.rgba16.inc.c"
};

Vtx warp_pipe_red_000_displaylist_mesh_layer_1_vtx_0[64] = {
	{{ {-101, 0, 0}, 0, {974, 2032}, {127, 0, 0, 255} }},
	{{ {-71, 205, 72}, 0, {-16, -16}, {90, 0, 166, 255} }},
	{{ {-71, 0, 72}, 0, {-16, 2032}, {90, 0, 166, 255} }},
	{{ {-101, 205, 0}, 0, {974, -16}, {127, 0, 0, 255} }},
	{{ {-71, 0, -71}, 0, {974, 2032}, {90, 0, 90, 255} }},
	{{ {-101, 205, 0}, 0, {-16, -16}, {127, 0, 0, 255} }},
	{{ {-101, 0, 0}, 0, {-16, 2032}, {127, 0, 0, 255} }},
	{{ {-71, 205, -71}, 0, {974, -16}, {90, 0, 90, 255} }},
	{{ {72, 0, 72}, 0, {974, 2032}, {166, 0, 166, 255} }},
	{{ {72, 205, 72}, 0, {974, -16}, {166, 0, 166, 255} }},
	{{ {102, 205, 0}, 0, {-16, -16}, {129, 0, 0, 255} }},
	{{ {102, 0, 0}, 0, {-16, 2032}, {129, 0, 0, 255} }},
	{{ {0, 0, 102}, 0, {974, 2032}, {0, 0, 129, 255} }},
	{{ {72, 205, 72}, 0, {-16, -16}, {166, 0, 166, 255} }},
	{{ {72, 0, 72}, 0, {-16, 2032}, {166, 0, 166, 255} }},
	{{ {0, 205, 102}, 0, {974, -16}, {0, 0, 129, 255} }},
	{{ {-71, 0, 72}, 0, {974, 2032}, {90, 0, 166, 255} }},
	{{ {-71, 205, 72}, 0, {974, -16}, {90, 0, 166, 255} }},
	{{ {0, 205, 102}, 0, {-16, -16}, {0, 0, 129, 255} }},
	{{ {0, 0, 102}, 0, {-16, 2032}, {0, 0, 129, 255} }},
	{{ {72, 0, -71}, 0, {974, 2032}, {166, 0, 90, 255} }},
	{{ {0, 205, -101}, 0, {-16, -16}, {0, 0, 127, 255} }},
	{{ {0, 0, -101}, 0, {-16, 2032}, {0, 0, 127, 255} }},
	{{ {72, 205, -71}, 0, {974, -16}, {166, 0, 90, 255} }},
	{{ {0, 0, -101}, 0, {974, 2032}, {0, 0, 127, 255} }},
	{{ {-71, 205, -71}, 0, {-16, -16}, {90, 0, 90, 255} }},
	{{ {-71, 0, -71}, 0, {-16, 2032}, {90, 0, 90, 255} }},
	{{ {0, 205, -101}, 0, {974, -16}, {0, 0, 127, 255} }},
	{{ {102, 0, 0}, 0, {974, 2032}, {129, 0, 0, 255} }},
	{{ {72, 205, -71}, 0, {-16, -16}, {166, 0, 90, 255} }},
	{{ {72, 0, -71}, 0, {-16, 2032}, {166, 0, 90, 255} }},
	{{ {102, 205, 0}, 0, {974, -16}, {129, 0, 0, 255} }},
	{{ {154, 0, 0}, 0, {974, 2032}, {127, 0, 0, 255} }},
	{{ {154, 205, 0}, 0, {974, -16}, {127, 0, 0, 255} }},
	{{ {109, 205, 109}, 0, {-16, -16}, {90, 0, 90, 255} }},
	{{ {109, 0, 109}, 0, {-16, 2032}, {90, 0, 90, 255} }},
	{{ {109, 0, 109}, 0, {974, 2032}, {90, 0, 90, 255} }},
	{{ {109, 205, 109}, 0, {974, -16}, {90, 0, 90, 255} }},
	{{ {0, 205, 154}, 0, {-16, -16}, {0, 0, 127, 255} }},
	{{ {0, 0, 154}, 0, {-16, 2032}, {0, 0, 127, 255} }},
	{{ {0, 0, 154}, 0, {974, 2032}, {0, 0, 127, 255} }},
	{{ {0, 205, 154}, 0, {974, -16}, {0, 0, 127, 255} }},
	{{ {-108, 205, 109}, 0, {-16, -16}, {166, 0, 90, 255} }},
	{{ {-108, 0, 109}, 0, {-16, 2032}, {166, 0, 90, 255} }},
	{{ {-108, 0, -108}, 0, {974, 2032}, {166, 0, 166, 255} }},
	{{ {0, 205, -153}, 0, {-16, -16}, {0, 0, 129, 255} }},
	{{ {0, 0, -153}, 0, {-16, 2032}, {0, 0, 129, 255} }},
	{{ {-108, 205, -108}, 0, {974, -16}, {166, 0, 166, 255} }},
	{{ {0, 0, -153}, 0, {974, 2032}, {0, 0, 129, 255} }},
	{{ {0, 205, -153}, 0, {974, -16}, {0, 0, 129, 255} }},
	{{ {109, 205, -108}, 0, {-16, -16}, {90, 0, 166, 255} }},
	{{ {109, 0, -108}, 0, {-16, 2032}, {90, 0, 166, 255} }},
	{{ {-108, 0, 109}, 0, {974, 2032}, {166, 0, 90, 255} }},
	{{ {-108, 205, 109}, 0, {974, -16}, {166, 0, 90, 255} }},
	{{ {-153, 205, 0}, 0, {-16, -16}, {129, 0, 0, 255} }},
	{{ {-153, 0, 0}, 0, {-16, 2032}, {129, 0, 0, 255} }},
	{{ {-153, 0, 0}, 0, {974, 2032}, {129, 0, 0, 255} }},
	{{ {-153, 205, 0}, 0, {974, -16}, {129, 0, 0, 255} }},
	{{ {-108, 205, -108}, 0, {-16, -16}, {166, 0, 166, 255} }},
	{{ {-108, 0, -108}, 0, {-16, 2032}, {166, 0, 166, 255} }},
	{{ {109, 0, -108}, 0, {974, 2032}, {90, 0, 166, 255} }},
	{{ {109, 205, -108}, 0, {974, -16}, {90, 0, 166, 255} }},
	{{ {154, 205, 0}, 0, {-16, -16}, {127, 0, 0, 255} }},
	{{ {154, 0, 0}, 0, {-16, 2032}, {127, 0, 0, 255} }},
};

Gfx warp_pipe_red_000_displaylist_mesh_layer_1_tri_0[] = {
	gsSPVertex(warp_pipe_red_000_displaylist_mesh_layer_1_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 23, 21, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 27, 25, 0),
	gsSP2Triangles(28, 29, 30, 0, 28, 31, 29, 0),
	gsSPVertex(warp_pipe_red_000_displaylist_mesh_layer_1_vtx_0 + 32, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
	gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
	gsSPEndDisplayList(),
};

Vtx warp_pipe_red_001_displaylist_mesh_layer_1_vtx_0[4] = {
	{{ {-101, 10, 102}, 0, {-16, -16}, {0, 127, 0, 255} }},
	{{ {102, 10, 102}, 0, {-16, -16}, {0, 127, 0, 255} }},
	{{ {102, 10, -101}, 0, {-16, -16}, {0, 127, 0, 255} }},
	{{ {-101, 10, -101}, 0, {-16, -16}, {0, 127, 0, 255} }},
};

Gfx warp_pipe_red_001_displaylist_mesh_layer_1_tri_0[] = {
	gsSPVertex(warp_pipe_red_001_displaylist_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx warp_pipe_red_001_displaylist_mesh_layer_1_vtx_1[16] = {
	{{ {154, 205, 0}, 0, {842, -46}, {0, 127, 0, 255} }},
	{{ {102, 205, 0}, 0, {730, 116}, {0, 127, 0, 255} }},
	{{ {72, 205, 72}, 0, {904, 400}, {0, 127, 0, 255} }},
	{{ {72, 205, -71}, 0, {426, 20}, {0, 127, 0, 255} }},
	{{ {109, 205, -108}, 0, {384, -190}, {0, 127, 0, 255} }},
	{{ {0, 205, -101}, 0, {168, 170}, {0, 127, 0, 255} }},
	{{ {0, 205, -153}, 0, {-2, 36}, {0, 127, 0, 255} }},
	{{ {-71, 205, -71}, 0, {108, 478}, {0, 127, 0, 255} }},
	{{ {-108, 205, -108}, 0, {-88, 498}, {0, 127, 0, 255} }},
	{{ {-101, 205, 0}, 0, {282, 764}, {0, 127, 0, 255} }},
	{{ {-153, 205, 0}, 0, {170, 926}, {0, 127, 0, 255} }},
	{{ {-71, 205, 72}, 0, {588, 860}, {0, 127, 0, 255} }},
	{{ {-108, 205, 109}, 0, {628, 1066}, {0, 127, 0, 255} }},
	{{ {0, 205, 102}, 0, {846, 708}, {0, 127, 0, 255} }},
	{{ {0, 205, 154}, 0, {1016, 844}, {0, 127, 0, 255} }},
	{{ {109, 205, 109}, 0, {1104, 382}, {0, 127, 0, 255} }},
};

Gfx warp_pipe_red_001_displaylist_mesh_layer_1_tri_1[] = {
	gsSPVertex(warp_pipe_red_001_displaylist_mesh_layer_1_vtx_1 + 0, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(0, 4, 3, 0, 4, 5, 3, 0),
	gsSP2Triangles(4, 6, 5, 0, 6, 7, 5, 0),
	gsSP2Triangles(6, 8, 7, 0, 8, 9, 7, 0),
	gsSP2Triangles(8, 10, 9, 0, 10, 11, 9, 0),
	gsSP2Triangles(10, 12, 11, 0, 12, 13, 11, 0),
	gsSP2Triangles(12, 14, 13, 0, 15, 13, 14, 0),
	gsSP2Triangles(15, 2, 13, 0, 0, 2, 15, 0),
	gsSPEndDisplayList(),
};


Gfx mat_warp_pipe_red_Side[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(warp_pipe_red_Side_lights),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, warp_pipe_red_warp_pipe_side_rgba16_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 252),
	gsSPEndDisplayList(),
};

Gfx mat_warp_pipe_red_Black[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(warp_pipe_red_Black_lights),
	gsSPEndDisplayList(),
};

Gfx mat_warp_pipe_red_Top[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(warp_pipe_red_Top_lights),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, warp_pipe_red_warp_pipe_top_rgba16_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx warp_pipe_red_000_displaylist_mesh_layer_1[] = {
	gsSPDisplayList(mat_warp_pipe_red_Side),
	gsSPDisplayList(warp_pipe_red_000_displaylist_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx warp_pipe_red_001_displaylist_mesh_layer_1[] = {
	gsSPDisplayList(mat_warp_pipe_red_Black),
	gsSPDisplayList(warp_pipe_red_001_displaylist_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_warp_pipe_red_Top),
	gsSPDisplayList(warp_pipe_red_001_displaylist_mesh_layer_1_tri_1),
	gsSPEndDisplayList(),
};

Gfx warp_pipe_red_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


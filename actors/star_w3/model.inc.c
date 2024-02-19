Lights1 star_w3_Eye_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Gfx star_w3_star_surface_world_3_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 star_w3_star_surface_world_3_rgba16[] = {
	#include "actors/star_w3/star_surface_world_3.rgba16.inc.c"
};

Gfx star_w3_star_eye_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 star_w3_star_eye_rgba16[] = {
	#include "actors/star_w3/star_eye.rgba16.inc.c"
};

Vtx star_w3_000_displaylist_mesh_layer_1_vtx_0[12] = {
	{{ {0, 8, -89}, 0, {-529, -529}, {0, 3, 129, 255} }},
	{{ {190, -201, 0}, 0, {-529, -529}, {86, 162, 0, 255} }},
	{{ {0, -129, 0}, 0, {-529, -529}, {0, 129, 0, 255} }},
	{{ {146, -42, 0}, 0, {-529, -529}, {125, 233, 0, 255} }},
	{{ {257, 84, 0}, 0, {-529, -529}, {119, 44, 0, 255} }},
	{{ {96, 99, 0}, 0, {-529, -529}, {55, 114, 0, 255} }},
	{{ {0, 246, 0}, 0, {-529, -529}, {0, 127, 0, 255} }},
	{{ {-95, 99, 0}, 0, {-529, -529}, {200, 114, 0, 255} }},
	{{ {-256, 84, 0}, 0, {-529, -529}, {137, 44, 0, 255} }},
	{{ {-145, -42, 0}, 0, {-529, -529}, {131, 233, 0, 255} }},
	{{ {-189, -201, 0}, 0, {-529, -529}, {171, 162, 0, 255} }},
	{{ {0, 8, 90}, 0, {-529, -529}, {0, 3, 127, 255} }},
};

Gfx star_w3_000_displaylist_mesh_layer_1_tri_0[] = {
	gsSPVertex(star_w3_000_displaylist_mesh_layer_1_vtx_0 + 0, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 3, 0, 0, 5, 4, 0, 0),
	gsSP2Triangles(5, 0, 6, 0, 0, 7, 6, 0),
	gsSP2Triangles(0, 8, 7, 0, 0, 9, 8, 0),
	gsSP2Triangles(0, 10, 9, 0, 0, 2, 10, 0),
	gsSP2Triangles(10, 2, 11, 0, 2, 1, 11, 0),
	gsSP2Triangles(1, 3, 11, 0, 11, 3, 4, 0),
	gsSP2Triangles(11, 4, 5, 0, 6, 11, 5, 0),
	gsSP2Triangles(6, 7, 11, 0, 7, 8, 11, 0),
	gsSP2Triangles(8, 9, 11, 0, 9, 10, 11, 0),
	gsSPEndDisplayList(),
};

Vtx star_w3_001_displaylist_mesh_layer_5_vtx_0[8] = {
	{{ {0, 89, 76}, 0, {974, -16}, {0, 22, 125, 255} }},
	{{ {-66, 86, 63}, 0, {-16, -16}, {231, 21, 123, 255} }},
	{{ {-66, -29, 83}, 0, {-16, 974}, {231, 21, 123, 255} }},
	{{ {0, -27, 96}, 0, {974, 974}, {0, 22, 125, 255} }},
	{{ {67, 86, 63}, 0, {974, -16}, {25, 21, 123, 255} }},
	{{ {0, -27, 96}, 0, {-16, 974}, {0, 22, 125, 255} }},
	{{ {67, -29, 83}, 0, {974, 974}, {24, 21, 123, 255} }},
	{{ {0, 89, 76}, 0, {-16, -16}, {0, 22, 125, 255} }},
};

Gfx star_w3_001_displaylist_mesh_layer_5_tri_0[] = {
	gsSPVertex(star_w3_001_displaylist_mesh_layer_5_vtx_0 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
	gsSPEndDisplayList(),
};


Gfx mat_star_w3_Surface[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT, 0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT),
	gsSPGeometryMode(0, G_TEXTURE_GEN),
	gsSPTexture(1984, 1984, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, star_w3_star_surface_world_3_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_star_w3_Surface[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(G_TEXTURE_GEN, 0),
	gsSPEndDisplayList(),
};

Gfx mat_star_w3_Eye[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(star_w3_Eye_lights),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, star_w3_star_eye_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx star_w3_000_displaylist_mesh_layer_1[] = {
	gsSPDisplayList(mat_star_w3_Surface),
	gsSPDisplayList(star_w3_000_displaylist_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_star_w3_Surface),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

Gfx star_w3_001_displaylist_mesh_layer_5[] = {
	gsSPDisplayList(mat_star_w3_Eye),
	gsSPDisplayList(star_w3_001_displaylist_mesh_layer_5_tri_0),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


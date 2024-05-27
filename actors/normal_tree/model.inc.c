Lights1 normal_tree_Log_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF,0xFF,0xFF,0x28,0x28,0x28);

Lights1 normal_tree_Leaves_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF,0xFF,0xFF,0x28,0x28,0x28);

Lights1 normal_tree_Leaves_Edge_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF,0xFF,0xFF,0x28,0x28,0x28);

Gfx normal_tree_Tree_Log_Texture_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 normal_tree_Tree_Log_Texture_rgba16[] = {
	#include "actors/normal_tree/Tree_Log_Texture.rgba16.inc.c"
};

Gfx normal_tree_Tree_Leaves_Texture_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 normal_tree_Tree_Leaves_Texture_rgba16[] = {
	#include "actors/normal_tree/Tree_Leaves_Texture.rgba16.inc.c"
};

Gfx normal_tree_Tree_Leaves_Edge_Texture_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 normal_tree_Tree_Leaves_Edge_Texture_rgba16[] = {
	#include "actors/normal_tree/Tree_Leaves_Edge_Texture.rgba16.inc.c"
};

Vtx normal_tree_Tree_mesh_layer_1_vtx_0[10] = {
	{{{36, 0, -50}, 0, {1980, 1096}, {0x4A, 0x0, 0x99, 0xFF}}},
	{{{36, 537, -50}, 0, {1980, 1982}, {0x4A, 0x0, 0x99, 0xFF}}},
	{{{59, 537, 19}, 0, {2236, 1982}, {0x79, 0x0, 0x27, 0xFF}}},
	{{{-36, 0, -50}, 0, {1468, 1096}, {0xB6, 0x0, 0x99, 0xFF}}},
	{{{-36, 537, -50}, 0, {1468, 1982}, {0xB6, 0x0, 0x99, 0xFF}}},
	{{{-59, 0, 19}, 0, {1212, 1096}, {0x87, 0x0, 0x27, 0xFF}}},
	{{{-59, 537, 19}, 0, {1212, 1982}, {0x87, 0x0, 0x27, 0xFF}}},
	{{{0, 0, 61}, 0, {1724, 1096}, {0x0, 0x0, 0x7F, 0xFF}}},
	{{{0, 537, 61}, 0, {1724, 1982}, {0x0, 0x0, 0x7F, 0xFF}}},
	{{{59, 0, 19}, 0, {2236, 1096}, {0x79, 0x0, 0x27, 0xFF}}},
};

Gfx normal_tree_Tree_mesh_layer_1_tri_0[] = {
	gsSPVertex(normal_tree_Tree_mesh_layer_1_vtx_0 + 0, 10, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(3, 4, 1, 0, 3, 5, 4, 0),
	gsSP2Triangles(5, 6, 4, 0, 5, 7, 6, 0),
	gsSP2Triangles(7, 8, 6, 0, 7, 9, 8, 0),
	gsSP2Triangles(9, 2, 8, 0, 9, 0, 2, 0),
	gsSPEndDisplayList(),
};

Vtx normal_tree_Tree_mesh_layer_1_vtx_1[61] = {
	{{{-112, 965, -146}, 0, {-1040, 2789}, {0xD0, 0x63, 0xC0, 0xFF}}},
	{{{-182, 965, 67}, 0, {1059, 2789}, {0xB1, 0x60, 0x1C, 0xFF}}},
	{{{0, 1033, 8}, 0, {-16, 2544}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{112, 965, -146}, 0, {1008, 2789}, {0x30, 0x63, 0xC0, 0xFF}}},
	{{{182, 965, 67}, 0, {-1040, 2789}, {0x4F, 0x60, 0x1C, 0xFF}}},
	{{{0, 965, 199}, 0, {1008, 2789}, {0x0, 0x5E, 0x56, 0xFF}}},
	{{{-182, 965, 67}, 0, {-1040, 2789}, {0xB1, 0x60, 0x1C, 0xFF}}},
	{{{0, 856, 274}, 0, {1008, 2288}, {0x0, 0x51, 0x62, 0xFF}}},
	{{{-262, 856, 84}, 0, {-1040, 2288}, {0xA8, 0x57, 0x1F, 0xFF}}},
	{{{-112, 965, -146}, 0, {1008, 2789}, {0xD0, 0x63, 0xC0, 0xFF}}},
	{{{-162, 856, -224}, 0, {1008, 2288}, {0xCC, 0x5C, 0xBA, 0xFF}}},
	{{{-352, 771, 104}, 0, {-1040, 2077}, {0x8C, 0x24, 0x25, 0xFF}}},
	{{{-218, 771, -310}, 0, {1008, 2077}, {0xB9, 0x26, 0x9D, 0xFF}}},
	{{{-208, 658, -294}, 0, {1008, 1784}, {0xB5, 0xB, 0x9A, 0xFF}}},
	{{{-335, 658, 100}, 0, {-1040, 1784}, {0x88, 0xA, 0x29, 0xFF}}},
	{{{-368, 547, 107}, 0, {-1040, 1418}, {0x87, 0xF4, 0x26, 0xFF}}},
	{{{-228, 547, -326}, 0, {1008, 1418}, {0xB6, 0xF4, 0x99, 0xFF}}},
	{{{-184, 415, -257}, 0, {1008, 803}, {0xBF, 0xBD, 0xAA, 0xFF}}},
	{{{-296, 415, 91}, 0, {-1040, 803}, {0x97, 0xC2, 0x25, 0xFF}}},
	{{{0, 547, 375}, 0, {1008, 1418}, {0x0, 0xF6, 0x7F, 0xFF}}},
	{{{0, 415, 307}, 0, {1008, 803}, {0x0, 0xC6, 0x71, 0xFF}}},
	{{{296, 415, 91}, 0, {-1040, 803}, {0x69, 0xC2, 0x25, 0xFF}}},
	{{{368, 547, 107}, 0, {-1040, 1418}, {0x79, 0xF4, 0x26, 0xFF}}},
	{{{184, 415, -257}, 0, {1008, 803}, {0x41, 0xBD, 0xAA, 0xFF}}},
	{{{228, 547, -326}, 0, {1008, 1418}, {0x4A, 0xF4, 0x99, 0xFF}}},
	{{{-184, 415, -257}, 0, {-1040, 803}, {0xBF, 0xBD, 0xAA, 0xFF}}},
	{{{-228, 547, -326}, 0, {-1040, 1418}, {0xB6, 0xF4, 0x99, 0xFF}}},
	{{{208, 658, -294}, 0, {1008, 1784}, {0x4B, 0xB, 0x9A, 0xFF}}},
	{{{-208, 658, -294}, 0, {-1040, 1784}, {0xB5, 0xB, 0x9A, 0xFF}}},
	{{{218, 771, -310}, 0, {1008, 2077}, {0x47, 0x26, 0x9D, 0xFF}}},
	{{{-218, 771, -310}, 0, {-1040, 2077}, {0xB9, 0x26, 0x9D, 0xFF}}},
	{{{162, 856, -224}, 0, {1008, 2288}, {0x34, 0x5C, 0xBA, 0xFF}}},
	{{{-218, 771, -310}, 0, {-1040, 2077}, {0xB9, 0x26, 0x9D, 0xFF}}},
	{{{-162, 856, -224}, 0, {-1040, 2288}, {0xCC, 0x5C, 0xBA, 0xFF}}},
	{{{162, 856, -224}, 0, {1008, 2288}, {0x34, 0x5C, 0xBA, 0xFF}}},
	{{{112, 965, -146}, 0, {1008, 2789}, {0x30, 0x63, 0xC0, 0xFF}}},
	{{{-112, 965, -146}, 0, {-1040, 2789}, {0xD0, 0x63, 0xC0, 0xFF}}},
	{{{262, 856, 84}, 0, {-1040, 2288}, {0x58, 0x57, 0x1F, 0xFF}}},
	{{{352, 771, 104}, 0, {-1040, 2077}, {0x74, 0x24, 0x25, 0xFF}}},
	{{{0, 770, 353}, 0, {1008, 2077}, {0x0, 0x23, 0x7A, 0xFF}}},
	{{{0, 856, 274}, 0, {1008, 2288}, {0x0, 0x51, 0x62, 0xFF}}},
	{{{182, 965, 67}, 0, {-1040, 2789}, {0x4F, 0x60, 0x1C, 0xFF}}},
	{{{0, 965, 199}, 0, {1008, 2789}, {0x0, 0x5E, 0x56, 0xFF}}},
	{{{-262, 856, 84}, 0, {-1040, 2288}, {0xA8, 0x57, 0x1F, 0xFF}}},
	{{{-352, 771, 104}, 0, {-1040, 2077}, {0x8C, 0x24, 0x25, 0xFF}}},
	{{{-335, 658, 100}, 0, {-1040, 1784}, {0x88, 0xA, 0x29, 0xFF}}},
	{{{0, 658, 341}, 0, {1008, 1784}, {0x0, 0xD, 0x7E, 0xFF}}},
	{{{0, 547, 375}, 0, {1008, 1418}, {0x0, 0xF6, 0x7F, 0xFF}}},
	{{{-368, 547, 107}, 0, {-1040, 1418}, {0x87, 0xF4, 0x26, 0xFF}}},
	{{{335, 658, 100}, 0, {-1040, 1784}, {0x78, 0xA, 0x29, 0xFF}}},
	{{{368, 547, 107}, 0, {-1040, 1418}, {0x79, 0xF4, 0x26, 0xFF}}},
	{{{208, 658, -294}, 0, {1008, 1784}, {0x4B, 0xB, 0x9A, 0xFF}}},
	{{{228, 547, -326}, 0, {1008, 1418}, {0x4A, 0xF4, 0x99, 0xFF}}},
	{{{218, 771, -310}, 0, {1008, 2077}, {0x47, 0x26, 0x9D, 0xFF}}},
	{{{287, 399, 86}, 0, {-1040, 754}, {0xCE, 0x8C, 0xF0, 0xFF}}},
	{{{0, 537, 0}, 0, {-16, 285}, {0x0, 0x81, 0xFF, 0xFF}}},
	{{{178, 400, -251}, 0, {1008, 754}, {0xE2, 0x8C, 0x29, 0xFF}}},
	{{{0, 399, 295}, 0, {435, 754}, {0x0, 0x8D, 0xCA, 0xFF}}},
	{{{-287, 399, 86}, 0, {-1040, 754}, {0x32, 0x8C, 0xF0, 0xFF}}},
	{{{-178, 400, -251}, 0, {1008, 754}, {0x1E, 0x8C, 0x29, 0xFF}}},
	{{{178, 400, -251}, 0, {-1040, 754}, {0xE2, 0x8C, 0x29, 0xFF}}},
};

Gfx normal_tree_Tree_mesh_layer_1_tri_1[] = {
	gsSPVertex(normal_tree_Tree_mesh_layer_1_vtx_1 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(4, 3, 2, 0, 5, 4, 2, 0),
	gsSP2Triangles(6, 5, 2, 0, 5, 6, 7, 0),
	gsSP2Triangles(6, 8, 7, 0, 6, 9, 8, 0),
	gsSP2Triangles(9, 10, 8, 0, 8, 10, 11, 0),
	gsSP2Triangles(10, 12, 11, 0, 12, 13, 11, 0),
	gsSP2Triangles(13, 14, 11, 0, 15, 14, 13, 0),
	gsSP2Triangles(16, 15, 13, 0, 16, 17, 15, 0),
	gsSP2Triangles(17, 18, 15, 0, 15, 18, 19, 0),
	gsSP2Triangles(18, 20, 19, 0, 20, 21, 19, 0),
	gsSP2Triangles(21, 22, 19, 0, 21, 23, 22, 0),
	gsSP2Triangles(23, 24, 22, 0, 23, 25, 24, 0),
	gsSP2Triangles(25, 26, 24, 0, 24, 26, 27, 0),
	gsSP2Triangles(26, 28, 27, 0, 27, 28, 29, 0),
	gsSP2Triangles(28, 30, 29, 0, 29, 30, 31, 0),
	gsSPVertex(normal_tree_Tree_mesh_layer_1_vtx_1 + 32, 29, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
	gsSP2Triangles(1, 4, 3, 0, 5, 2, 3, 0),
	gsSP2Triangles(2, 5, 6, 0, 6, 5, 7, 0),
	gsSP2Triangles(5, 8, 7, 0, 8, 5, 9, 0),
	gsSP2Triangles(9, 5, 3, 0, 10, 8, 9, 0),
	gsSP2Triangles(7, 8, 11, 0, 12, 7, 11, 0),
	gsSP2Triangles(12, 13, 7, 0, 13, 14, 7, 0),
	gsSP2Triangles(15, 14, 13, 0, 16, 15, 13, 0),
	gsSP2Triangles(14, 15, 17, 0, 15, 18, 17, 0),
	gsSP2Triangles(17, 18, 19, 0, 18, 20, 19, 0),
	gsSP2Triangles(17, 19, 6, 0, 19, 21, 6, 0),
	gsSP2Triangles(21, 2, 6, 0, 17, 6, 7, 0),
	gsSP2Triangles(14, 17, 7, 0, 22, 23, 24, 0),
	gsSP2Triangles(25, 23, 22, 0, 26, 23, 25, 0),
	gsSP2Triangles(23, 26, 27, 0, 28, 23, 27, 0),
	gsSPEndDisplayList(),
};

Vtx normal_tree_Tree_mesh_layer_4_vtx_0[18] = {
	{{{-184, 415, -257}, 0, {1008, 803}, {0xB9, 0xDA, 0x9E, 0xFF}}},
	{{{184, 415, -257}, 0, {-1040, 803}, {0x47, 0xDA, 0x9E, 0xFF}}},
	{{{171, 342, -238}, 0, {-1040, 445}, {0x43, 0xC7, 0xA4, 0xFF}}},
	{{{-171, 342, -238}, 0, {1008, 445}, {0xBD, 0xC7, 0xA4, 0xFF}}},
	{{{139, 274, -190}, 0, {-1040, 20}, {0x3B, 0xAE, 0xB2, 0xFF}}},
	{{{-139, 274, -190}, 0, {1008, 20}, {0xC5, 0xAE, 0xB2, 0xFF}}},
	{{{-277, 342, 87}, 0, {-1040, 445}, {0x92, 0xCB, 0x24, 0xFF}}},
	{{{-226, 274, 75}, 0, {-1040, 20}, {0xA1, 0xB3, 0x22, 0xFF}}},
	{{{0, 342, 288}, 0, {1008, 445}, {0x0, 0xCE, 0x75, 0xFF}}},
	{{{0, 274, 240}, 0, {1008, 20}, {0x0, 0xB7, 0x68, 0xFF}}},
	{{{226, 274, 75}, 0, {-1040, 20}, {0x5F, 0xB3, 0x22, 0xFF}}},
	{{{277, 342, 87}, 0, {-1040, 445}, {0x6E, 0xCB, 0x24, 0xFF}}},
	{{{139, 274, -190}, 0, {1008, 20}, {0x3B, 0xAE, 0xB2, 0xFF}}},
	{{{171, 342, -238}, 0, {1008, 445}, {0x43, 0xC7, 0xA4, 0xFF}}},
	{{{296, 415, 91}, 0, {-1040, 803}, {0x75, 0xE0, 0x25, 0xFF}}},
	{{{184, 415, -257}, 0, {1008, 803}, {0x47, 0xDA, 0x9E, 0xFF}}},
	{{{0, 415, 307}, 0, {1008, 803}, {0x0, 0xE1, 0x7B, 0xFF}}},
	{{{-296, 415, 91}, 0, {-1040, 803}, {0x8B, 0xE0, 0x25, 0xFF}}},
};

Gfx normal_tree_Tree_mesh_layer_4_tri_0[] = {
	gsSPVertex(normal_tree_Tree_mesh_layer_4_vtx_0 + 0, 18, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(3, 2, 4, 0, 5, 3, 4, 0),
	gsSP2Triangles(6, 3, 5, 0, 7, 6, 5, 0),
	gsSP2Triangles(8, 6, 7, 0, 9, 8, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 11, 8, 10, 0),
	gsSP2Triangles(11, 10, 12, 0, 13, 11, 12, 0),
	gsSP2Triangles(14, 11, 13, 0, 15, 14, 13, 0),
	gsSP2Triangles(14, 16, 11, 0, 16, 8, 11, 0),
	gsSP2Triangles(8, 16, 6, 0, 16, 17, 6, 0),
	gsSP2Triangles(6, 17, 3, 0, 17, 0, 3, 0),
	gsSPEndDisplayList(),
};


Gfx mat_normal_tree_Log[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, normal_tree_Tree_Log_Texture_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(normal_tree_Log_lights),
	gsSPEndDisplayList(),
};

Gfx mat_normal_tree_Leaves[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, normal_tree_Tree_Leaves_Texture_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(normal_tree_Leaves_lights),
	gsSPEndDisplayList(),
};

Gfx mat_normal_tree_Leaves_Edge[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPGeometryMode(G_CULL_BACK, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, normal_tree_Tree_Leaves_Edge_Texture_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(normal_tree_Leaves_Edge_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_normal_tree_Leaves_Edge[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx normal_tree_Tree_mesh_layer_1[] = {
	gsSPDisplayList(mat_normal_tree_Log),
	gsSPDisplayList(normal_tree_Tree_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_normal_tree_Leaves),
	gsSPDisplayList(normal_tree_Tree_mesh_layer_1_tri_1),
	gsSPEndDisplayList(),
};

Gfx normal_tree_Tree_mesh_layer_4[] = {
	gsSPDisplayList(mat_normal_tree_Leaves_Edge),
	gsSPDisplayList(normal_tree_Tree_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_normal_tree_Leaves_Edge),
	gsSPEndDisplayList(),
};

Gfx normal_tree_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


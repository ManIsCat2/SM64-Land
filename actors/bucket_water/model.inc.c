Lights1 bucket_water_Material_0_002_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Lights1 bucket_water_Material_1_001_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Gfx bucket_water__0_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 bucket_water__0_rgba16[] = {
	#include "actors/bucket_water/_0.rgba16.inc.c"
};

Gfx bucket_water__1_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 bucket_water__1_rgba16[] = {
	#include "actors/bucket_water/_1.rgba16.inc.c"
};

Vtx bucket_water_Bone_mesh_layer_1_vtx_0[38] = {
	{{ {0, 0, -30}, 0, {951, 863}, {0, 173, 160, 255} }},
	{{ {26, 0, -15}, 0, {951, 863}, {83, 173, 208, 255} }},
	{{ {26, 0, 15}, 0, {951, 863}, {83, 173, 48, 255} }},
	{{ {0, 0, 30}, 0, {951, 863}, {0, 173, 96, 255} }},
	{{ {-26, 0, 15}, 0, {951, 863}, {173, 173, 48, 255} }},
	{{ {-26, 0, -15}, 0, {951, 863}, {173, 173, 208, 255} }},
	{{ {-22, 10, 13}, 0, {951, 863}, {77, 90, 211, 255} }},
	{{ {0, 10, 25}, 0, {951, 863}, {0, 91, 168, 255} }},
	{{ {22, 10, 13}, 0, {951, 863}, {179, 90, 211, 255} }},
	{{ {-22, 10, -13}, 0, {951, 863}, {77, 90, 46, 255} }},
	{{ {0, 10, -25}, 0, {951, 863}, {1, 91, 88, 255} }},
	{{ {22, 10, -13}, 0, {951, 863}, {179, 90, 45, 255} }},
	{{ {26, 0, -15}, 0, {884, -124}, {83, 173, 208, 255} }},
	{{ {31, 47, 18}, 0, {10, 1012}, {50, 113, 30, 255} }},
	{{ {26, 0, 15}, 0, {88, -124}, {83, 173, 48, 255} }},
	{{ {31, 47, -18}, 0, {961, 1012}, {50, 113, 226, 255} }},
	{{ {26, 0, -15}, 0, {884, -124}, {83, 173, 208, 255} }},
	{{ {0, 47, -36}, 0, {10, 1012}, {3, 113, 197, 255} }},
	{{ {31, 47, -18}, 0, {961, 1012}, {50, 113, 226, 255} }},
	{{ {0, 0, -30}, 0, {88, -124}, {0, 173, 160, 255} }},
	{{ {-26, 0, -15}, 0, {884, -124}, {173, 173, 208, 255} }},
	{{ {-31, 47, -18}, 0, {961, 1012}, {204, 113, 228, 255} }},
	{{ {-26, 0, 15}, 0, {88, -124}, {173, 173, 48, 255} }},
	{{ {-31, 47, 18}, 0, {10, 1012}, {207, 113, 31, 255} }},
	{{ {0, 0, 30}, 0, {884, -124}, {0, 173, 96, 255} }},
	{{ {0, 47, 36}, 0, {961, 1012}, {0, 113, 58, 255} }},
	{{ {26, 0, 15}, 0, {88, -124}, {83, 173, 48, 255} }},
	{{ {31, 47, 18}, 0, {10, 1012}, {50, 113, 30, 255} }},
	{{ {22, 10, 13}, 0, {150, -124}, {179, 90, 211, 255} }},
	{{ {22, 10, -13}, 0, {822, -124}, {179, 90, 45, 255} }},
	{{ {0, 10, -25}, 0, {150, -124}, {1, 91, 88, 255} }},
	{{ {-22, 10, -13}, 0, {822, -124}, {77, 90, 46, 255} }},
	{{ {-22, 10, -13}, 0, {822, -124}, {77, 90, 46, 255} }},
	{{ {-31, 47, 18}, 0, {10, 1012}, {207, 113, 31, 255} }},
	{{ {-22, 10, 13}, 0, {150, -124}, {77, 90, 211, 255} }},
	{{ {0, 47, 36}, 0, {961, 1012}, {0, 113, 58, 255} }},
	{{ {0, 10, 25}, 0, {822, -124}, {0, 91, 168, 255} }},
	{{ {22, 10, 13}, 0, {150, -124}, {179, 90, 211, 255} }},
};

Gfx bucket_water_Bone_mesh_layer_1_tri_0[] = {
	gsSPVertex(bucket_water_Bone_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(2, 3, 0, 0),
	gsSP1Triangle(3, 4, 0, 0),
	gsSP1Triangle(4, 5, 0, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 6, 8, 0),
	gsSP1Triangle(10, 9, 8, 0),
	gsSP1Triangle(8, 11, 10, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 15, 13, 0),
	gsSPVertex(bucket_water_Bone_mesh_layer_1_vtx_0 + 16, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(4, 1, 3, 0),
	gsSP1Triangle(4, 5, 1, 0),
	gsSP1Triangle(6, 5, 4, 0),
	gsSP1Triangle(6, 7, 5, 0),
	gsSP1Triangle(8, 7, 6, 0),
	gsSP1Triangle(8, 9, 7, 0),
	gsSP1Triangle(10, 9, 8, 0),
	gsSP1Triangle(10, 11, 9, 0),
	gsSP1Triangle(12, 9, 11, 0),
	gsSP1Triangle(13, 12, 11, 0),
	gsSP1Triangle(13, 11, 2, 0),
	gsSP1Triangle(13, 2, 1, 0),
	gsSP1Triangle(13, 1, 14, 0),
	gsSP1Triangle(14, 1, 5, 0),
	gsSP1Triangle(14, 5, 15, 0),
	gsSP1Triangle(15, 5, 7, 0),
	gsSPVertex(bucket_water_Bone_mesh_layer_1_vtx_0 + 32, 6, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(2, 1, 3, 0),
	gsSP1Triangle(2, 3, 4, 0),
	gsSP1Triangle(5, 4, 3, 0),
	gsSPEndDisplayList(),
};

Vtx bucket_water_Bone_mesh_layer_1_vtx_1[6] = {
	{{ {0, 36, -34}, 0, {1008, 565}, {0, 127, 0, 255} }},
	{{ {-29, 36, -17}, 0, {752, 121}, {0, 127, 0, 255} }},
	{{ {-29, 36, 17}, 0, {240, 121}, {0, 127, 0, 255} }},
	{{ {29, 36, 17}, 0, {240, 1008}, {0, 127, 0, 255} }},
	{{ {0, 36, 34}, 0, {-16, 565}, {0, 127, 0, 255} }},
	{{ {29, 36, -17}, 0, {752, 1008}, {0, 127, 0, 255} }},
};

Gfx bucket_water_Bone_mesh_layer_1_tri_1[] = {
	gsSPVertex(bucket_water_Bone_mesh_layer_1_vtx_1 + 0, 6, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(2, 3, 0, 0),
	gsSP1Triangle(2, 4, 3, 0),
	gsSP1Triangle(3, 5, 0, 0),
	gsSPEndDisplayList(),
};


Gfx mat_bucket_water_Material_0_002_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(bucket_water_Material_0_002_f3d_lights),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, bucket_water__0_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_bucket_water_Material_1_001_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(bucket_water_Material_1_001_f3d_lights),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, bucket_water__1_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx bucket_water_Bone_mesh_layer_1[] = {
	gsSPDisplayList(mat_bucket_water_Material_0_002_f3d),
	gsSPDisplayList(bucket_water_Bone_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_bucket_water_Material_1_001_f3d),
	gsSPDisplayList(bucket_water_Bone_mesh_layer_1_tri_1),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


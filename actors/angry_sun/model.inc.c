Lights1 angry_sun_Material_0_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Lights1 angry_sun_Material_1_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Gfx angry_sun__0_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 angry_sun__0_rgba16[] = {
	#include "actors/angry_sun/_0.rgba16.inc.c"
};

Gfx angry_sun__1_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 angry_sun__1_rgba16[] = {
	#include "actors/angry_sun/_1.rgba16.inc.c"
};

Vtx angry_sun_Bone_mesh_layer_4_vtx_0[9] = {
	{{ {438, 345, -16}, 0, {10, 982}, {0, 0, 127, 255} }},
	{{ {0, 688, -16}, 0, {982, 10}, {0, 0, 127, 255} }},
	{{ {0, 345, -16}, 0, {982, 982}, {0, 0, 127, 255} }},
	{{ {-438, 688, -16}, 0, {10, 10}, {0, 0, 127, 255} }},
	{{ {-438, 345, -16}, 0, {10, 982}, {0, 0, 127, 255} }},
	{{ {0, 2, -16}, 0, {982, 10}, {0, 0, 127, 255} }},
	{{ {-438, 2, -16}, 0, {10, 10}, {0, 0, 127, 255} }},
	{{ {438, 2, -16}, 0, {10, 10}, {0, 0, 127, 255} }},
	{{ {438, 688, -16}, 0, {10, 10}, {0, 0, 127, 255} }},
};

Gfx angry_sun_Bone_mesh_layer_4_tri_0[] = {
	gsSPVertex(angry_sun_Bone_mesh_layer_4_vtx_0 + 0, 9, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(2, 3, 4, 0),
	gsSP1Triangle(5, 4, 6, 0),
	gsSP1Triangle(7, 2, 5, 0),
	gsSP1Triangle(0, 8, 1, 0),
	gsSP1Triangle(2, 1, 3, 0),
	gsSP1Triangle(5, 2, 4, 0),
	gsSP1Triangle(7, 0, 2, 0),
	gsSPEndDisplayList(),
};

Vtx angry_sun_Bone_mesh_layer_4_vtx_1[4] = {
	{{ {250, 95, 0}, 0, {1008, 1008}, {0, 0, 127, 255} }},
	{{ {-250, 595, 0}, 0, {-16, -16}, {0, 0, 127, 255} }},
	{{ {-250, 95, 0}, 0, {-16, 1008}, {0, 0, 127, 255} }},
	{{ {250, 595, 0}, 0, {1008, -16}, {0, 0, 127, 255} }},
};

Gfx angry_sun_Bone_mesh_layer_4_tri_1[] = {
	gsSPVertex(angry_sun_Bone_mesh_layer_4_vtx_1 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSPEndDisplayList(),
};


Gfx mat_angry_sun_Material_0_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(angry_sun_Material_0_f3d_lights),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, angry_sun__0_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_angry_sun_Material_0_f3d[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx mat_angry_sun_Material_1_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(angry_sun_Material_1_f3d_lights),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, angry_sun__1_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_angry_sun_Material_1_f3d[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx angry_sun_Bone_mesh_layer_4[] = {
	gsSPDisplayList(mat_angry_sun_Material_0_f3d),
	gsSPDisplayList(angry_sun_Bone_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_angry_sun_Material_0_f3d),
	gsSPDisplayList(mat_angry_sun_Material_1_f3d),
	gsSPDisplayList(angry_sun_Bone_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_angry_sun_Material_1_f3d),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


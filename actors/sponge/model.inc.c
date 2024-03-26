Lights1 sponge_Material_0_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Lights1 sponge_Material_1_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Gfx sponge__0_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 sponge__0_rgba16[] = {
	#include "actors/sponge/_0.rgba16.inc.c"
};

Gfx sponge__1_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 sponge__1_rgba16[] = {
	#include "actors/sponge/_1.rgba16.inc.c"
};

Vtx sponge_Bone_mesh_layer_1_vtx_0[8] = {
	{{ {-288, -61, -214}, 0, {353, -145}, {166, 7, 167, 255} }},
	{{ {-286, -126, 213}, 0, {-383, 444}, {184, 181, 73, 255} }},
	{{ {-288, -61, 214}, 0, {-383, 376}, {166, 7, 89, 255} }},
	{{ {-286, -126, -213}, 0, {353, -76}, {184, 181, 183, 255} }},
	{{ {288, -61, -214}, 0, {1345, 556}, {90, 7, 167, 255} }},
	{{ {286, -126, -213}, 0, {1345, 625}, {72, 181, 183, 255} }},
	{{ {288, -61, 214}, 0, {608, 1077}, {90, 7, 89, 255} }},
	{{ {286, -126, 213}, 0, {608, 1146}, {72, 181, 73, 255} }},
};

Gfx sponge_Bone_mesh_layer_1_tri_0[] = {
	gsSPVertex(sponge_Bone_mesh_layer_1_vtx_0 + 0, 8, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(4, 3, 0, 0),
	gsSP1Triangle(4, 5, 3, 0),
	gsSP1Triangle(6, 5, 4, 0),
	gsSP1Triangle(6, 7, 5, 0),
	gsSP1Triangle(2, 7, 6, 0),
	gsSP1Triangle(2, 1, 7, 0),
	gsSP1Triangle(3, 7, 1, 0),
	gsSP1Triangle(3, 5, 7, 0),
	gsSPEndDisplayList(),
};

Vtx sponge_Bone_mesh_layer_1_vtx_1[25] = {
	{{ {277, 33, -205}, 0, {1651, 697}, {87, 241, 165, 255} }},
	{{ {288, -61, -214}, 0, {1700, 941}, {90, 7, 167, 255} }},
	{{ {-288, -61, -214}, 0, {228, -100}, {166, 7, 167, 255} }},
	{{ {277, 33, 205}, 0, {603, 1438}, {87, 241, 91, 255} }},
	{{ {295, 91, 218}, 0, {616, 1350}, {91, 12, 88, 255} }},
	{{ {295, 91, -218}, 0, {1734, 559}, {91, 12, 168, 255} }},
	{{ {-277, 33, -205}, 0, {231, -306}, {169, 241, 165, 255} }},
	{{ {-288, -61, 214}, 0, {-866, 673}, {166, 7, 89, 255} }},
	{{ {-277, 33, 205}, 0, {-816, 435}, {169, 241, 91, 255} }},
	{{ {288, -61, 214}, 0, {607, 1714}, {90, 7, 89, 255} }},
	{{ {-295, 91, 218}, 0, {-899, 279}, {165, 12, 88, 255} }},
	{{ {282, 116, 207}, 0, {624, 1308}, {66, 84, 69, 255} }},
	{{ {282, 116, -207}, 0, {1764, 502}, {66, 84, 187, 255} }},
	{{ {-295, 91, -218}, 0, {219, -512}, {165, 12, 168, 255} }},
	{{ {-282, 116, -207}, 0, {211, -596}, {190, 84, 187, 255} }},
	{{ {-282, 116, 207}, 0, {-929, 210}, {190, 84, 69, 255} }},
	{{ {-275, 123, 200}, 0, {-908, 189}, {218, 115, 38, 255} }},
	{{ {-282, 116, 207}, 0, {-929, 210}, {190, 84, 69, 255} }},
	{{ {282, 116, 207}, 0, {624, 1308}, {66, 84, 69, 255} }},
	{{ {275, 123, 200}, 0, {626, 1274}, {38, 115, 38, 255} }},
	{{ {282, 116, -207}, 0, {1764, 502}, {66, 84, 187, 255} }},
	{{ {275, 123, -200}, 0, {1743, 485}, {38, 115, 218, 255} }},
	{{ {-275, 123, -200}, 0, {208, -600}, {218, 115, 218, 255} }},
	{{ {-282, 116, -207}, 0, {211, -596}, {190, 84, 187, 255} }},
	{{ {-295, 91, -218}, 0, {219, -512}, {165, 12, 168, 255} }},
};

Gfx sponge_Bone_mesh_layer_1_tri_1[] = {
	gsSPVertex(sponge_Bone_mesh_layer_1_vtx_1 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 1, 0, 0),
	gsSP1Triangle(4, 3, 0, 0),
	gsSP1Triangle(4, 0, 5, 0),
	gsSP1Triangle(5, 0, 6, 0),
	gsSP1Triangle(0, 2, 6, 0),
	gsSP1Triangle(6, 2, 7, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(8, 7, 9, 0),
	gsSP1Triangle(8, 9, 3, 0),
	gsSP1Triangle(3, 9, 1, 0),
	gsSP1Triangle(4, 8, 3, 0),
	gsSP1Triangle(4, 10, 8, 0),
	gsSP1Triangle(10, 4, 11, 0),
	gsSP1Triangle(5, 11, 4, 0),
	gsSP1Triangle(5, 12, 11, 0),
	gsSP1Triangle(13, 12, 5, 0),
	gsSP1Triangle(5, 6, 13, 0),
	gsSP1Triangle(10, 13, 6, 0),
	gsSP1Triangle(10, 6, 8, 0),
	gsSP1Triangle(10, 14, 13, 0),
	gsSP1Triangle(10, 15, 14, 0),
	gsSP1Triangle(10, 11, 15, 0),
	gsSPVertex(sponge_Bone_mesh_layer_1_vtx_1 + 16, 9, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(3, 2, 4, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 5, 4, 0),
	gsSP1Triangle(6, 4, 7, 0),
	gsSP1Triangle(8, 7, 4, 0),
	gsSP1Triangle(6, 7, 1, 0),
	gsSP1Triangle(6, 1, 0, 0),
	gsSP1Triangle(6, 0, 3, 0),
	gsSP1Triangle(6, 3, 5, 0),
	gsSPEndDisplayList(),
};


Gfx mat_sponge_Material_0_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(sponge_Material_0_f3d_lights),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, sponge__0_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_sponge_Material_1_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(sponge_Material_1_f3d_lights),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, sponge__1_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx sponge_Bone_mesh_layer_1[] = {
	gsSPDisplayList(mat_sponge_Material_0_f3d),
	gsSPDisplayList(sponge_Bone_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_sponge_Material_1_f3d),
	gsSPDisplayList(sponge_Bone_mesh_layer_1_tri_1),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


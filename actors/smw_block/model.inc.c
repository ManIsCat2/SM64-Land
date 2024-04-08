Lights1 smw_block_Material_0_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Gfx smw_block__0_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 smw_block__0_rgba16[] = {
	#include "actors/smw_block/_0.rgba16.inc.c"
};

Vtx smw_block_Bone_mesh_layer_1_vtx_0[36] = {
	{{ {-125, 125, 125}, 0, {1504, -32}, {129, 0, 0, 255} }},
	{{ {-125, -125, -125}, 0, {992, 480}, {129, 0, 0, 255} }},
	{{ {-125, -125, 125}, 0, {1504, 480}, {129, 0, 0, 255} }},
	{{ {-125, 125, -125}, 0, {992, -32}, {0, 0, 129, 255} }},
	{{ {125, -125, -125}, 0, {480, 480}, {0, 0, 129, 255} }},
	{{ {-125, -125, -125}, 0, {992, 480}, {0, 0, 129, 255} }},
	{{ {125, 125, -125}, 0, {480, -32}, {127, 0, 0, 255} }},
	{{ {125, -125, 125}, 0, {-32, 480}, {127, 0, 0, 255} }},
	{{ {125, -125, -125}, 0, {480, 480}, {127, 0, 0, 255} }},
	{{ {125, 125, 125}, 0, {-32, -32}, {0, 0, 127, 255} }},
	{{ {-125, -125, 125}, 0, {-544, 480}, {0, 0, 127, 255} }},
	{{ {125, -125, 125}, 0, {-32, 480}, {0, 0, 127, 255} }},
	{{ {125, -125, -125}, 0, {480, 480}, {0, 129, 0, 255} }},
	{{ {-125, -125, 125}, 0, {-32, 992}, {0, 129, 0, 255} }},
	{{ {-125, -125, -125}, 0, {480, 992}, {0, 129, 0, 255} }},
	{{ {-125, 125, -125}, 0, {480, -544}, {0, 127, 0, 255} }},
	{{ {125, 125, 125}, 0, {-32, -32}, {0, 127, 0, 255} }},
	{{ {125, 125, -125}, 0, {480, -32}, {0, 127, 0, 255} }},
	{{ {-125, 125, 125}, 0, {1504, -32}, {129, 0, 0, 255} }},
	{{ {-125, 125, -125}, 0, {992, -32}, {129, 0, 0, 255} }},
	{{ {-125, -125, -125}, 0, {992, 480}, {129, 0, 0, 255} }},
	{{ {-125, 125, -125}, 0, {992, -32}, {0, 0, 129, 255} }},
	{{ {125, 125, -125}, 0, {480, -32}, {0, 0, 129, 255} }},
	{{ {125, -125, -125}, 0, {480, 480}, {0, 0, 129, 255} }},
	{{ {125, 125, -125}, 0, {480, -32}, {127, 0, 0, 255} }},
	{{ {125, 125, 125}, 0, {-32, -32}, {127, 0, 0, 255} }},
	{{ {125, -125, 125}, 0, {-32, 480}, {127, 0, 0, 255} }},
	{{ {125, 125, 125}, 0, {-32, -32}, {0, 0, 127, 255} }},
	{{ {-125, 125, 125}, 0, {-544, -32}, {0, 0, 127, 255} }},
	{{ {-125, -125, 125}, 0, {-544, 480}, {0, 0, 127, 255} }},
	{{ {125, -125, -125}, 0, {480, 480}, {0, 129, 0, 255} }},
	{{ {125, -125, 125}, 0, {-32, 480}, {0, 129, 0, 255} }},
	{{ {-125, -125, 125}, 0, {-32, 992}, {0, 129, 0, 255} }},
	{{ {-125, 125, -125}, 0, {480, -544}, {0, 127, 0, 255} }},
	{{ {-125, 125, 125}, 0, {-32, -544}, {0, 127, 0, 255} }},
	{{ {125, 125, 125}, 0, {-32, -32}, {0, 127, 0, 255} }},
};

Gfx smw_block_Bone_mesh_layer_1_tri_0[] = {
	gsSPVertex(smw_block_Bone_mesh_layer_1_vtx_0 + 0, 15, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSPVertex(smw_block_Bone_mesh_layer_1_vtx_0 + 15, 15, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSPVertex(smw_block_Bone_mesh_layer_1_vtx_0 + 30, 6, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSPEndDisplayList(),
};


Gfx mat_smw_block_Material_0_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(smw_block_Material_0_f3d_lights),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, smw_block__0_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 512),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0),
	gsDPSetTileSize(0, 0, 0, 60, 60),
	gsSPEndDisplayList(),
};

Gfx smw_block_Bone_mesh_layer_1[] = {
	gsSPDisplayList(mat_smw_block_Material_0_f3d),
	gsSPDisplayList(smw_block_Bone_mesh_layer_1_tri_0),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


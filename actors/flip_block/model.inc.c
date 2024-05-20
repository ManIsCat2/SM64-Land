Lights1 flip_block_Flip_Block_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Gfx flip_block_FlipBlock_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 flip_block_FlipBlock_rgba16[] = {
	#include "actors/flip_block/FlipBlock.rgba16.inc.c"
};

Vtx flip_block_smw_block_Bone_mesh_layer_1_mesh_mesh_layer_1_vtx_cull[8] = {
	{{ {-125, -125, 125}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-125, 125, 125}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-125, 125, -125}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-125, -125, -125}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {125, -125, 125}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {125, 125, 125}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {125, 125, -125}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {125, -125, -125}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx flip_block_smw_block_Bone_mesh_layer_1_mesh_mesh_layer_1_vtx_0[24] = {
	{{ {-125, 125, 125}, 0, {1520, -16}, {129, 0, 0, 255} }},
	{{ {-125, -125, -125}, 0, {1008, 496}, {129, 0, 0, 255} }},
	{{ {-125, -125, 125}, 0, {1520, 496}, {129, 0, 0, 255} }},
	{{ {-125, 125, -125}, 0, {1008, -16}, {129, 0, 0, 255} }},
	{{ {-125, 125, -125}, 0, {1008, -16}, {0, 0, 129, 255} }},
	{{ {125, -125, -125}, 0, {496, 496}, {0, 0, 129, 255} }},
	{{ {-125, -125, -125}, 0, {1008, 496}, {0, 0, 129, 255} }},
	{{ {125, 125, -125}, 0, {496, -16}, {0, 0, 129, 255} }},
	{{ {125, 125, -125}, 0, {496, -16}, {127, 0, 0, 255} }},
	{{ {125, -125, 125}, 0, {-16, 496}, {127, 0, 0, 255} }},
	{{ {125, -125, -125}, 0, {496, 496}, {127, 0, 0, 255} }},
	{{ {125, 125, 125}, 0, {-16, -16}, {127, 0, 0, 255} }},
	{{ {125, 125, 125}, 0, {-16, -16}, {0, 0, 127, 255} }},
	{{ {-125, -125, 125}, 0, {-528, 496}, {0, 0, 127, 255} }},
	{{ {125, -125, 125}, 0, {-16, 496}, {0, 0, 127, 255} }},
	{{ {-125, 125, 125}, 0, {-528, -16}, {0, 0, 127, 255} }},
	{{ {125, -125, -125}, 0, {496, 496}, {0, 129, 0, 255} }},
	{{ {-125, -125, 125}, 0, {-16, 1008}, {0, 129, 0, 255} }},
	{{ {-125, -125, -125}, 0, {496, 1008}, {0, 129, 0, 255} }},
	{{ {125, -125, 125}, 0, {-16, 496}, {0, 129, 0, 255} }},
	{{ {-125, 125, -125}, 0, {496, -528}, {0, 127, 0, 255} }},
	{{ {125, 125, 125}, 0, {-16, -16}, {0, 127, 0, 255} }},
	{{ {125, 125, -125}, 0, {496, -16}, {0, 127, 0, 255} }},
	{{ {-125, 125, 125}, 0, {-16, -528}, {0, 127, 0, 255} }},
};

Gfx flip_block_smw_block_Bone_mesh_layer_1_mesh_mesh_layer_1_tri_0[] = {
	gsSPVertex(flip_block_smw_block_Bone_mesh_layer_1_mesh_mesh_layer_1_vtx_0 + 0, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 11, 9, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 19, 17, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 23, 21, 0),
	gsSPEndDisplayList(),
};


Gfx mat_flip_block_Flip_Block[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(flip_block_Flip_Block_lights),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, flip_block_FlipBlock_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 512),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0),
	gsDPSetTileSize(0, 0, 0, 60, 60),
	gsSPEndDisplayList(),
};

Gfx flip_block_smw_block_Bone_mesh_layer_1_mesh_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(flip_block_smw_block_Bone_mesh_layer_1_mesh_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_flip_block_Flip_Block),
	gsSPDisplayList(flip_block_smw_block_Bone_mesh_layer_1_mesh_mesh_layer_1_tri_0),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


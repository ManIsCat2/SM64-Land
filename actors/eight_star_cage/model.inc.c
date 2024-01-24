Lights1 eight_star_cage_Material_0_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Lights1 eight_star_cage_Material_1_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Gfx eight_star_cage__0_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 eight_star_cage__0_rgba16[] = {
	#include "actors/eight_star_cage/_0.rgba16.inc.c"
};

Gfx eight_star_cage__1_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 eight_star_cage__1_rgba16[] = {
	#include "actors/eight_star_cage/_1.rgba16.inc.c"
};

Vtx eight_star_cage_Bone_mesh_layer_4_vtx_0[97] = {
	{{ {-400, 600, 400}, 0, {6371, -16}, {129, 0, 0, 255} }},
	{{ {-400, 300, -400}, 0, {4323, 1008}, {129, 0, 0, 255} }},
	{{ {-400, 300, 400}, 0, {6371, 1008}, {129, 0, 0, 255} }},
	{{ {-400, 600, -400}, 0, {4323, -16}, {0, 0, 129, 255} }},
	{{ {400, 300, -400}, 0, {2275, 1008}, {0, 0, 129, 255} }},
	{{ {-400, 300, -400}, 0, {4323, 1008}, {0, 0, 129, 255} }},
	{{ {400, 600, -400}, 0, {2275, -16}, {127, 0, 0, 255} }},
	{{ {400, 300, 400}, 0, {227, 1008}, {127, 0, 0, 255} }},
	{{ {400, 300, -400}, 0, {2275, 1008}, {127, 0, 0, 255} }},
	{{ {400, 600, 400}, 0, {227, -16}, {0, 0, 127, 255} }},
	{{ {-400, 300, 400}, 0, {-1821, 1008}, {0, 0, 127, 255} }},
	{{ {400, 300, 400}, 0, {227, 1008}, {0, 0, 127, 255} }},
	{{ {-400, 0, 400}, 0, {-1821, -16}, {0, 0, 127, 255} }},
	{{ {400, 0, 400}, 0, {227, -16}, {0, 0, 127, 255} }},
	{{ {400, 0, 400}, 0, {227, -16}, {127, 0, 0, 255} }},
	{{ {400, 0, -400}, 0, {2275, -16}, {127, 0, 0, 255} }},
	{{ {-400, 300, -400}, 0, {4323, 1008}, {0, 0, 129, 255} }},
	{{ {400, 0, -400}, 0, {2275, -16}, {0, 0, 129, 255} }},
	{{ {-400, 0, -400}, 0, {4323, -16}, {0, 0, 129, 255} }},
	{{ {-400, 300, 400}, 0, {6371, 1008}, {129, 0, 0, 255} }},
	{{ {-400, 0, -400}, 0, {4323, -16}, {129, 0, 0, 255} }},
	{{ {-400, 0, 400}, 0, {6371, -16}, {129, 0, 0, 255} }},
	{{ {400, 600, -400}, 0, {2275, -16}, {0, 127, 0, 255} }},
	{{ {-400, 600, -400}, 0, {227, -16}, {0, 127, 0, 255} }},
	{{ {0, 600, 0}, 0, {1251, 1008}, {0, 127, 0, 255} }},
	{{ {-400, 600, 400}, 0, {2275, -16}, {0, 127, 0, 255} }},
	{{ {400, 600, 400}, 0, {227, -16}, {0, 127, 0, 255} }},
	{{ {-400, 300, -400}, 0, {4323, 1008}, {127, 0, 0, 255} }},
	{{ {-400, 600, 400}, 0, {6371, -16}, {127, 0, 0, 255} }},
	{{ {-400, 300, 400}, 0, {6371, 1008}, {127, 0, 0, 255} }},
	{{ {400, 300, -400}, 0, {2275, 1008}, {0, 0, 127, 255} }},
	{{ {-400, 600, -400}, 0, {4323, -16}, {0, 0, 127, 255} }},
	{{ {-400, 300, -400}, 0, {4323, 1008}, {0, 0, 127, 255} }},
	{{ {400, 300, 400}, 0, {227, 1008}, {129, 0, 0, 255} }},
	{{ {400, 600, -400}, 0, {2275, -16}, {129, 0, 0, 255} }},
	{{ {400, 300, -400}, 0, {2275, 1008}, {129, 0, 0, 255} }},
	{{ {-400, 300, 400}, 0, {-1821, 1008}, {0, 0, 129, 255} }},
	{{ {400, 600, 400}, 0, {227, -16}, {0, 0, 129, 255} }},
	{{ {400, 300, 400}, 0, {227, 1008}, {0, 0, 129, 255} }},
	{{ {-400, 0, 400}, 0, {-1821, -16}, {0, 0, 129, 255} }},
	{{ {400, 0, 400}, 0, {227, -16}, {0, 0, 129, 255} }},
	{{ {400, 0, 400}, 0, {227, -16}, {129, 0, 0, 255} }},
	{{ {400, 0, -400}, 0, {2275, -16}, {129, 0, 0, 255} }},
	{{ {400, 0, -400}, 0, {2275, -16}, {0, 0, 127, 255} }},
	{{ {-400, 0, -400}, 0, {4323, -16}, {0, 0, 127, 255} }},
	{{ {-400, 0, -400}, 0, {4323, -16}, {127, 0, 0, 255} }},
	{{ {-400, 300, 400}, 0, {6371, 1008}, {127, 0, 0, 255} }},
	{{ {-400, 0, 400}, 0, {6371, -16}, {127, 0, 0, 255} }},
	{{ {400, 600, -400}, 0, {2275, -16}, {0, 129, 0, 255} }},
	{{ {0, 600, 0}, 0, {1251, 1008}, {0, 129, 0, 255} }},
	{{ {-400, 600, -400}, 0, {227, -16}, {0, 129, 0, 255} }},
	{{ {-400, 600, 400}, 0, {2275, -16}, {0, 129, 0, 255} }},
	{{ {400, 600, 400}, 0, {227, -16}, {0, 129, 0, 255} }},
	{{ {-400, 600, 400}, 0, {6371, -16}, {129, 0, 0, 255} }},
	{{ {-400, 600, -400}, 0, {4323, -16}, {129, 0, 0, 255} }},
	{{ {-400, 300, -400}, 0, {4323, 1008}, {129, 0, 0, 255} }},
	{{ {-400, 600, -400}, 0, {4323, -16}, {0, 0, 129, 255} }},
	{{ {400, 600, -400}, 0, {2275, -16}, {0, 0, 129, 255} }},
	{{ {400, 300, -400}, 0, {2275, 1008}, {0, 0, 129, 255} }},
	{{ {400, 600, -400}, 0, {2275, -16}, {127, 0, 0, 255} }},
	{{ {400, 600, 400}, 0, {227, -16}, {127, 0, 0, 255} }},
	{{ {400, 300, 400}, 0, {227, 1008}, {127, 0, 0, 255} }},
	{{ {400, 600, 400}, 0, {227, -16}, {0, 0, 127, 255} }},
	{{ {-400, 600, 400}, 0, {-1821, -16}, {0, 0, 127, 255} }},
	{{ {-400, 300, 400}, 0, {-1821, 1008}, {0, 0, 127, 255} }},
	{{ {400, 300, 400}, 0, {227, 1008}, {0, 0, 127, 255} }},
	{{ {-400, 0, 400}, 0, {-1821, -16}, {0, 0, 127, 255} }},
	{{ {400, 300, -400}, 0, {2275, 1008}, {127, 0, 0, 255} }},
	{{ {400, 0, 400}, 0, {227, -16}, {127, 0, 0, 255} }},
	{{ {-400, 300, -400}, 0, {4323, 1008}, {0, 0, 129, 255} }},
	{{ {400, 300, -400}, 0, {2275, 1008}, {0, 0, 129, 255} }},
	{{ {400, 0, -400}, 0, {2275, -16}, {0, 0, 129, 255} }},
	{{ {-400, 300, 400}, 0, {6371, 1008}, {129, 0, 0, 255} }},
	{{ {-400, 300, -400}, 0, {4323, 1008}, {129, 0, 0, 255} }},
	{{ {-400, 0, -400}, 0, {4323, -16}, {129, 0, 0, 255} }},
	{{ {-400, 300, -400}, 0, {4323, 1008}, {127, 0, 0, 255} }},
	{{ {-400, 600, -400}, 0, {4323, -16}, {127, 0, 0, 255} }},
	{{ {-400, 600, 400}, 0, {6371, -16}, {127, 0, 0, 255} }},
	{{ {400, 300, -400}, 0, {2275, 1008}, {0, 0, 127, 255} }},
	{{ {400, 600, -400}, 0, {2275, -16}, {0, 0, 127, 255} }},
	{{ {-400, 600, -400}, 0, {4323, -16}, {0, 0, 127, 255} }},
	{{ {400, 300, 400}, 0, {227, 1008}, {129, 0, 0, 255} }},
	{{ {400, 600, 400}, 0, {227, -16}, {129, 0, 0, 255} }},
	{{ {400, 600, -400}, 0, {2275, -16}, {129, 0, 0, 255} }},
	{{ {-400, 300, 400}, 0, {-1821, 1008}, {0, 0, 129, 255} }},
	{{ {-400, 600, 400}, 0, {-1821, -16}, {0, 0, 129, 255} }},
	{{ {400, 600, 400}, 0, {227, -16}, {0, 0, 129, 255} }},
	{{ {-400, 0, 400}, 0, {-1821, -16}, {0, 0, 129, 255} }},
	{{ {400, 300, 400}, 0, {227, 1008}, {0, 0, 129, 255} }},
	{{ {400, 0, 400}, 0, {227, -16}, {129, 0, 0, 255} }},
	{{ {400, 300, -400}, 0, {2275, 1008}, {129, 0, 0, 255} }},
	{{ {400, 0, -400}, 0, {2275, -16}, {0, 0, 127, 255} }},
	{{ {400, 300, -400}, 0, {2275, 1008}, {0, 0, 127, 255} }},
	{{ {-400, 300, -400}, 0, {4323, 1008}, {0, 0, 127, 255} }},
	{{ {-400, 0, -400}, 0, {4323, -16}, {127, 0, 0, 255} }},
	{{ {-400, 300, -400}, 0, {4323, 1008}, {127, 0, 0, 255} }},
	{{ {-400, 300, 400}, 0, {6371, 1008}, {127, 0, 0, 255} }},
};

Gfx eight_star_cage_Bone_mesh_layer_4_tri_0[] = {
	gsSPVertex(eight_star_cage_Bone_mesh_layer_4_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(11, 12, 13, 0),
	gsSP1Triangle(8, 14, 15, 0),
	gsSPVertex(eight_star_cage_Bone_mesh_layer_4_vtx_0 + 16, 14, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(7, 9, 8, 0),
	gsSP1Triangle(9, 10, 8, 0),
	gsSP1Triangle(10, 6, 8, 0),
	gsSP1Triangle(11, 12, 13, 0),
	gsSPVertex(eight_star_cage_Bone_mesh_layer_4_vtx_0 + 30, 15, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 8, 10, 0),
	gsSP1Triangle(11, 5, 12, 0),
	gsSP1Triangle(13, 2, 14, 0),
	gsSPVertex(eight_star_cage_Bone_mesh_layer_4_vtx_0 + 45, 14, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(5, 4, 6, 0),
	gsSP1Triangle(6, 4, 7, 0),
	gsSP1Triangle(7, 4, 3, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(11, 12, 13, 0),
	gsSPVertex(eight_star_cage_Bone_mesh_layer_4_vtx_0 + 59, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 5, 7, 0),
	gsSP1Triangle(8, 2, 9, 0),
	gsSP1Triangle(10, 11, 12, 0),
	gsSP1Triangle(13, 14, 15, 0),
	gsSPVertex(eight_star_cage_Bone_mesh_layer_4_vtx_0 + 75, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(12, 9, 13, 0),
	gsSP1Triangle(14, 6, 15, 0),
	gsSPVertex(eight_star_cage_Bone_mesh_layer_4_vtx_0 + 91, 6, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSPEndDisplayList(),
};

Vtx eight_star_cage_Bone_mesh_layer_1_vtx_0[26] = {
	{{ {-353, 544, -376}, 0, {2032, -16}, {129, 0, 0, 255} }},
	{{ {-353, 368, -424}, 0, {2032, 496}, {129, 0, 0, 255} }},
	{{ {-353, 368, -376}, 0, {2032, 496}, {129, 0, 0, 255} }},
	{{ {-353, 544, -424}, 0, {2032, -16}, {0, 0, 129, 255} }},
	{{ {353, 368, -424}, 0, {-16, 496}, {73, 183, 183, 255} }},
	{{ {-353, 368, -424}, 0, {2032, 496}, {0, 0, 129, 255} }},
	{{ {-353, 368, -376}, 0, {2032, 496}, {0, 129, 0, 255} }},
	{{ {-353, 368, -424}, 0, {2032, 496}, {0, 129, 0, 255} }},
	{{ {353, 544, -424}, 0, {-16, -16}, {0, 0, 129, 255} }},
	{{ {353, 544, -376}, 0, {-16, -16}, {0, 0, 127, 255} }},
	{{ {-353, 368, -376}, 0, {-16, 496}, {0, 0, 127, 255} }},
	{{ {353, 368, -376}, 0, {-16, 496}, {73, 183, 73, 255} }},
	{{ {353, 544, -424}, 0, {-16, -16}, {127, 0, 0, 255} }},
	{{ {353, 544, -376}, 0, {-16, -16}, {127, 0, 0, 255} }},
	{{ {-353, 544, -376}, 0, {-16, -16}, {0, 0, 127, 255} }},
	{{ {-353, 544, -424}, 0, {2032, -16}, {0, 127, 0, 255} }},
	{{ {353, 544, -376}, 0, {-16, -16}, {0, 127, 0, 255} }},
	{{ {353, 544, -424}, 0, {-16, -16}, {0, 127, 0, 255} }},
	{{ {-353, 544, -376}, 0, {2032, -16}, {129, 0, 0, 255} }},
	{{ {-353, 544, -424}, 0, {2032, -16}, {129, 0, 0, 255} }},
	{{ {-353, 368, -424}, 0, {2032, 496}, {129, 0, 0, 255} }},
	{{ {-353, 544, -376}, 0, {2032, -16}, {0, 127, 0, 255} }},
	{{ {353, 544, -424}, 0, {-16, -16}, {127, 0, 0, 255} }},
	{{ {353, 368, -376}, 0, {-16, 496}, {73, 183, 73, 255} }},
	{{ {353, 368, -424}, 0, {-16, 496}, {73, 183, 183, 255} }},
	{{ {-353, 368, -376}, 0, {2032, 496}, {0, 129, 0, 255} }},
};

Gfx eight_star_cage_Bone_mesh_layer_1_tri_0[] = {
	gsSPVertex(eight_star_cage_Bone_mesh_layer_1_vtx_0 + 0, 15, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(3, 8, 4, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(12, 13, 11, 0),
	gsSP1Triangle(9, 14, 10, 0),
	gsSPVertex(eight_star_cage_Bone_mesh_layer_1_vtx_0 + 15, 11, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(0, 6, 1, 0),
	gsSP1Triangle(7, 8, 9, 0),
	gsSP1Triangle(9, 8, 10, 0),
	gsSPEndDisplayList(),
};


Gfx mat_eight_star_cage_Material_0_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(eight_star_cage_Material_0_f3d_lights),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, eight_star_cage__0_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_eight_star_cage_Material_0_f3d[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx mat_eight_star_cage_Material_1_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(eight_star_cage_Material_1_f3d_lights),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, eight_star_cage__1_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 128),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 4, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 60),
	gsSPEndDisplayList(),
};

Gfx eight_star_cage_Bone_mesh_layer_4[] = {
	gsSPDisplayList(mat_eight_star_cage_Material_0_f3d),
	gsSPDisplayList(eight_star_cage_Bone_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_eight_star_cage_Material_0_f3d),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

Gfx eight_star_cage_Bone_mesh_layer_1[] = {
	gsSPDisplayList(mat_eight_star_cage_Material_1_f3d),
	gsSPDisplayList(eight_star_cage_Bone_mesh_layer_1_tri_0),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


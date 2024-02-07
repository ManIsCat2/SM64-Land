Lights1 eight_star_cage_Material_0_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 eight_star_cage_Material_1_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Gfx eight_star_cage__0_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 eight_star_cage__0_rgba16[] = {
	#include "actors/eight_star_cage/_0.rgba16.inc.c"
};

Gfx eight_star_cage__1_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 eight_star_cage__1_rgba16[] = {
	#include "actors/eight_star_cage/_1.rgba16.inc.c"
};

Vtx eight_star_cage_Bone_mesh_layer_4_vtx_0[23] = {
	{{ {-400, 300, 400}, 0, {6371, 1008}, {166, 0, 90, 255} }},
	{{ {-400, 0, -400}, 0, {4323, -16}, {166, 0, 166, 255} }},
	{{ {-400, 0, 400}, 0, {6371, -16}, {166, 0, 90, 255} }},
	{{ {-400, 300, -400}, 0, {4323, 1008}, {166, 0, 166, 255} }},
	{{ {-400, 600, 400}, 0, {6371, -16}, {183, 73, 73, 255} }},
	{{ {-400, 600, -400}, 0, {4323, -16}, {183, 73, 183, 255} }},
	{{ {400, 300, -400}, 0, {2275, 1008}, {90, 0, 166, 255} }},
	{{ {400, 600, -400}, 0, {2275, -16}, {73, 73, 183, 255} }},
	{{ {400, 300, 400}, 0, {227, 1008}, {90, 0, 90, 255} }},
	{{ {400, 600, 400}, 0, {227, -16}, {73, 73, 73, 255} }},
	{{ {0, 600, 0}, 0, {1251, 1008}, {0, 127, 0, 255} }},
	{{ {-400, 600, -400}, 0, {227, -16}, {183, 73, 183, 255} }},
	{{ {-400, 600, 400}, 0, {2275, -16}, {183, 73, 73, 255} }},
	{{ {-400, 300, 400}, 0, {-1821, 1008}, {166, 0, 90, 255} }},
	{{ {-400, 600, 400}, 0, {-1821, -16}, {183, 73, 73, 255} }},
	{{ {-400, 0, 400}, 0, {-1821, -16}, {166, 0, 90, 255} }},
	{{ {400, 300, 400}, 0, {227, 1008}, {90, 0, 90, 255} }},
	{{ {-400, 0, 400}, 0, {-1821, -16}, {166, 0, 90, 255} }},
	{{ {400, 0, 400}, 0, {227, -16}, {90, 0, 90, 255} }},
	{{ {400, 300, -400}, 0, {2275, 1008}, {90, 0, 166, 255} }},
	{{ {400, 0, -400}, 0, {2275, -16}, {90, 0, 166, 255} }},
	{{ {-400, 300, -400}, 0, {4323, 1008}, {166, 0, 166, 255} }},
	{{ {-400, 0, -400}, 0, {4323, -16}, {166, 0, 166, 255} }},
};

Gfx eight_star_cage_Bone_mesh_layer_4_tri_0[] = {
	gsSPVertex(eight_star_cage_Bone_mesh_layer_4_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(4, 3, 0, 0),
	gsSP1Triangle(4, 5, 3, 0),
	gsSP1Triangle(5, 6, 3, 0),
	gsSP1Triangle(5, 7, 6, 0),
	gsSP1Triangle(7, 8, 6, 0),
	gsSP1Triangle(7, 9, 8, 0),
	gsSP1Triangle(9, 7, 10, 0),
	gsSP1Triangle(7, 11, 10, 0),
	gsSP1Triangle(11, 12, 10, 0),
	gsSP1Triangle(12, 9, 10, 0),
	gsSP1Triangle(9, 13, 8, 0),
	gsSP1Triangle(9, 14, 13, 0),
	gsSP1Triangle(8, 13, 15, 0),
	gsSPVertex(eight_star_cage_Bone_mesh_layer_4_vtx_0 + 16, 7, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 0, 2, 0),
	gsSP1Triangle(3, 2, 4, 0),
	gsSP1Triangle(5, 3, 4, 0),
	gsSP1Triangle(5, 4, 6, 0),
	gsSPEndDisplayList(),
};

Vtx eight_star_cage_Bone_mesh_layer_1_vtx_0[10] = {
	{{ {353, 544, -376}, 0, {-16, -16}, {73, 73, 73, 255} }},
	{{ {-353, 544, -376}, 0, {-16, -16}, {183, 73, 73, 255} }},
	{{ {-353, 368, -376}, 0, {-16, 496}, {183, 183, 73, 255} }},
	{{ {353, 368, -376}, 0, {-16, 496}, {73, 183, 73, 255} }},
	{{ {353, 544, -424}, 0, {-16, -16}, {73, 73, 183, 255} }},
	{{ {353, 368, -424}, 0, {-16, 496}, {73, 183, 183, 255} }},
	{{ {-353, 368, -376}, 0, {2032, 496}, {183, 183, 73, 255} }},
	{{ {-353, 368, -424}, 0, {2032, 496}, {183, 183, 183, 255} }},
	{{ {-353, 544, -376}, 0, {2032, -16}, {183, 73, 73, 255} }},
	{{ {-353, 544, -424}, 0, {2032, -16}, {183, 73, 183, 255} }},
};

Gfx eight_star_cage_Bone_mesh_layer_1_tri_0[] = {
	gsSPVertex(eight_star_cage_Bone_mesh_layer_1_vtx_0 + 0, 10, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 0, 3, 0),
	gsSP1Triangle(4, 3, 5, 0),
	gsSP1Triangle(5, 3, 6, 0),
	gsSP1Triangle(5, 6, 7, 0),
	gsSP1Triangle(8, 7, 6, 0),
	gsSP1Triangle(8, 9, 7, 0),
	gsSP1Triangle(9, 8, 0, 0),
	gsSP1Triangle(9, 0, 4, 0),
	gsSP1Triangle(9, 4, 5, 0),
	gsSP1Triangle(9, 5, 7, 0),
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
	gsSPEndDisplayList(),
};

Gfx eight_star_cage_Bone_mesh_layer_1[] = {
	gsSPDisplayList(mat_eight_star_cage_Material_1_f3d),
	gsSPDisplayList(eight_star_cage_Bone_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx eight_star_cage_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


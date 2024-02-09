Lights1 pipe_cover_Material_0_003_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Gfx pipe_cover__0_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 pipe_cover__0_rgba16[] = {
	#include "actors/pipe_cover/_0.rgba16.inc.c"
};

Vtx pipe_cover_Blue_Pipe_Cover_mesh_layer_4_vtx_cull[8] = {
	{{ {-100, 0, 100}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-100, 0, 100}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-100, 0, -100}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-100, 0, -100}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {100, 0, 100}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {100, 0, 100}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {100, 0, -100}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {100, 0, -100}, 0, {-16, -16}, {0, 0, 0, 0} }},
};

Vtx pipe_cover_Blue_Pipe_Cover_mesh_layer_4_vtx_0[4] = {
	{{ {100, 0, 100}, 0, {1008, 1008}, {0, 127, 0, 255} }},
	{{ {-100, 0, -100}, 0, {-16, -16}, {0, 127, 0, 255} }},
	{{ {-100, 0, 100}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {100, 0, -100}, 0, {1008, -16}, {0, 127, 0, 255} }},
};

Gfx pipe_cover_Blue_Pipe_Cover_mesh_layer_4_tri_0[] = {
	gsSPVertex(pipe_cover_Blue_Pipe_Cover_mesh_layer_4_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSPEndDisplayList(),
};


Gfx mat_pipe_cover_Material_0_003_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPGeometryMode(G_CULL_BACK, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(pipe_cover_Material_0_003_f3d_lights),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, pipe_cover__0_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_pipe_cover_Material_0_003_f3d[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx pipe_cover_Blue_Pipe_Cover_mesh_layer_4[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(pipe_cover_Blue_Pipe_Cover_mesh_layer_4_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_pipe_cover_Material_0_003_f3d),
	gsSPDisplayList(pipe_cover_Blue_Pipe_Cover_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_pipe_cover_Material_0_003_f3d),
	gsSPEndDisplayList(),
};

Gfx pipe_cover_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


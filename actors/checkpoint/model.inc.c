Lights1 checkpoint_CheckPoint_Pole_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF,0xFF,0xFF,0x28,0x28,0x28);

Lights1 checkpoint_Flag_White_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF,0xFF,0xFF,0x28,0x28,0x28);

Lights1 checkpoint_Flag_Red_lights = gdSPDefLights1(
	0x6E, 0x0, 0x0,
	0xDE,0x0,0x0,0x28,0x28,0x28);

Lights1 checkpoint_CheckPoint_Pole_Collected_lights = gdSPDefLights1(
	0x5B, 0x5B, 0x0,
	0xB9,0xB9,0x0,0x28,0x28,0x28);

Lights1 checkpoint_Flag_Yellow_lights = gdSPDefLights1(
	0x5B, 0x5B, 0x0,
	0xB9,0xB9,0x0,0x28,0x28,0x28);

Gfx checkpoint__2C9517A7_c_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 checkpoint__2C9517A7_c_rgba16[] = {
	#include "actors/checkpoint/_2C9517A7_c.rgba16.inc.c"
};

Vtx checkpoint_Flag_Pole_mesh_layer_1_vtx_0[9] = {
	{{{-10, 23, -491}, 0, {430, 2006}, {0xD3, 0x6B, 0xCC, 0xFF}}},
	{{{-23, 10, 0}, 0, {430, 1070}, {0x8B, 0x32, 0x2, 0xFF}}},
	{{{10, 23, 0}, 0, {210, 1070}, {0x32, 0x75, 0x2, 0xFF}}},
	{{{-23, -10, -491}, 0, {210, 2006}, {0x95, 0xD3, 0xCC, 0xFF}}},
	{{{0, 0, -507}, 0, {210, 2040}, {0x0, 0x0, 0x81, 0xFF}}},
	{{{23, 10, -491}, 0, {210, 2006}, {0x6B, 0x2D, 0xCC, 0xFF}}},
	{{{23, -10, 0}, 0, {24, 1070}, {0x75, 0xCE, 0x2, 0xFF}}},
	{{{10, -23, -491}, 0, {24, 2006}, {0x2D, 0x95, 0xCC, 0xFF}}},
	{{{-10, -23, 0}, 0, {210, 1070}, {0xCE, 0x8B, 0x2, 0xFF}}},
};

Gfx checkpoint_Flag_Pole_mesh_layer_1_tri_0[] = {
	gsSPVertex(checkpoint_Flag_Pole_mesh_layer_1_vtx_0 + 0, 9, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(0, 4, 3, 0, 5, 4, 0, 0),
	gsSP2Triangles(5, 0, 2, 0, 5, 2, 6, 0),
	gsSP2Triangles(7, 5, 6, 0, 7, 6, 8, 0),
	gsSP2Triangles(3, 7, 8, 0, 3, 8, 1, 0),
	gsSP2Triangles(3, 4, 7, 0, 7, 4, 5, 0),
	gsSPEndDisplayList(),
};

Vtx checkpoint_Flag_1_mesh_layer_1_vtx_0[5] = {
	{{{92, 0, -72}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 0, -96}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 0, 0}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 0, 96}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{92, 0, 72}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx checkpoint_Flag_1_mesh_layer_1_tri_0[] = {
	gsSPVertex(checkpoint_Flag_1_mesh_layer_1_vtx_0 + 0, 5, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 3, 4, 0),
	gsSPEndDisplayList(),
};

Vtx checkpoint_Flag_1_mesh_layer_1_vtx_1[3] = {
	{{{92, 0, 72}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{92, 0, -72}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 0, 0}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx checkpoint_Flag_1_mesh_layer_1_tri_1[] = {
	gsSPVertex(checkpoint_Flag_1_mesh_layer_1_vtx_1 + 0, 3, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSPEndDisplayList(),
};

Vtx checkpoint_Flag_2_mesh_layer_1_vtx_0[4] = {
	{{{0, 0, 72}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{92, 0, 48}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{92, 0, -48}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 0, -72}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx checkpoint_Flag_2_mesh_layer_1_tri_0[] = {
	gsSPVertex(checkpoint_Flag_2_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx checkpoint_Flag_3_mesh_layer_1_vtx_0[4] = {
	{{{0, 0, 48}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{69, 0, 30}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{69, 0, -30}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 0, -48}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx checkpoint_Flag_3_mesh_layer_1_tri_0[] = {
	gsSPVertex(checkpoint_Flag_3_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx checkpoint_Flag_4_mesh_layer_1_vtx_0[4] = {
	{{{0, 0, 30}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{57, 0, 15}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{57, 0, -15}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 0, -30}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx checkpoint_Flag_4_mesh_layer_1_tri_0[] = {
	gsSPVertex(checkpoint_Flag_4_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx checkpoint_Flag_Tip_mesh_layer_1_vtx_0[3] = {
	{{{0, 0, 15}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{57, 0, 0}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 0, -15}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx checkpoint_Flag_Tip_mesh_layer_1_tri_0[] = {
	gsSPVertex(checkpoint_Flag_Tip_mesh_layer_1_vtx_0 + 0, 3, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSPEndDisplayList(),
};

Vtx checkpoint_Flag_Body_Switch_Option_Flag_Pole_mesh_layer_1_vtx_0[9] = {
	{{{-10, 23, -491}, 0, {430, 2006}, {0xD3, 0x6B, 0xCC, 0xFF}}},
	{{{-23, 10, 0}, 0, {430, 1070}, {0x8B, 0x32, 0x2, 0xFF}}},
	{{{10, 23, 0}, 0, {210, 1070}, {0x32, 0x75, 0x2, 0xFF}}},
	{{{-23, -10, -491}, 0, {210, 2006}, {0x95, 0xD3, 0xCC, 0xFF}}},
	{{{0, 0, -507}, 0, {210, 2040}, {0x0, 0x0, 0x81, 0xFF}}},
	{{{23, 10, -491}, 0, {210, 2006}, {0x6B, 0x2D, 0xCC, 0xFF}}},
	{{{23, -10, 0}, 0, {24, 1070}, {0x75, 0xCE, 0x2, 0xFF}}},
	{{{10, -23, -491}, 0, {24, 2006}, {0x2D, 0x95, 0xCC, 0xFF}}},
	{{{-10, -23, 0}, 0, {210, 1070}, {0xCE, 0x8B, 0x2, 0xFF}}},
};

Gfx checkpoint_Flag_Body_Switch_Option_Flag_Pole_mesh_layer_1_tri_0[] = {
	gsSPVertex(checkpoint_Flag_Body_Switch_Option_Flag_Pole_mesh_layer_1_vtx_0 + 0, 9, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(0, 4, 3, 0, 5, 4, 0, 0),
	gsSP2Triangles(5, 0, 2, 0, 5, 2, 6, 0),
	gsSP2Triangles(7, 5, 6, 0, 7, 6, 8, 0),
	gsSP2Triangles(3, 7, 8, 0, 3, 8, 1, 0),
	gsSP2Triangles(3, 4, 7, 0, 7, 4, 5, 0),
	gsSPEndDisplayList(),
};

Vtx checkpoint_Flag_Body_Switch_Option_Flag_1_mesh_layer_1_vtx_0[5] = {
	{{{92, 0, -72}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 0, -96}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 0, 0}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 0, 96}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{92, 0, 72}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx checkpoint_Flag_Body_Switch_Option_Flag_1_mesh_layer_1_tri_0[] = {
	gsSPVertex(checkpoint_Flag_Body_Switch_Option_Flag_1_mesh_layer_1_vtx_0 + 0, 5, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 3, 4, 0),
	gsSPEndDisplayList(),
};

Vtx checkpoint_Flag_Body_Switch_Option_Flag_1_mesh_layer_1_vtx_1[3] = {
	{{{92, 0, 72}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{92, 0, -72}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 0, 0}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx checkpoint_Flag_Body_Switch_Option_Flag_1_mesh_layer_1_tri_1[] = {
	gsSPVertex(checkpoint_Flag_Body_Switch_Option_Flag_1_mesh_layer_1_vtx_1 + 0, 3, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSPEndDisplayList(),
};

Vtx checkpoint_Flag_Body_Switch_Option_Flag_2_mesh_layer_1_vtx_0[4] = {
	{{{0, 0, 72}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{92, 0, 48}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{92, 0, -48}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 0, -72}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx checkpoint_Flag_Body_Switch_Option_Flag_2_mesh_layer_1_tri_0[] = {
	gsSPVertex(checkpoint_Flag_Body_Switch_Option_Flag_2_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx checkpoint_Flag_Body_Switch_Option_Flag_3_mesh_layer_1_vtx_0[4] = {
	{{{0, 0, 48}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{69, 0, 30}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{69, 0, -30}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 0, -48}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx checkpoint_Flag_Body_Switch_Option_Flag_3_mesh_layer_1_tri_0[] = {
	gsSPVertex(checkpoint_Flag_Body_Switch_Option_Flag_3_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx checkpoint_Flag_Body_Switch_Option_Flag_4_mesh_layer_1_vtx_0[4] = {
	{{{0, 0, 30}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{57, 0, 15}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{57, 0, -15}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 0, -30}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx checkpoint_Flag_Body_Switch_Option_Flag_4_mesh_layer_1_tri_0[] = {
	gsSPVertex(checkpoint_Flag_Body_Switch_Option_Flag_4_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx checkpoint_Flag_Body_Switch_Option_Flag_Tip_mesh_layer_1_vtx_0[3] = {
	{{{0, 0, 15}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{57, 0, 0}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 0, -15}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx checkpoint_Flag_Body_Switch_Option_Flag_Tip_mesh_layer_1_tri_0[] = {
	gsSPVertex(checkpoint_Flag_Body_Switch_Option_Flag_Tip_mesh_layer_1_vtx_0 + 0, 3, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSPEndDisplayList(),
};


Gfx mat_checkpoint_CheckPoint_Pole[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, checkpoint__2C9517A7_c_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(checkpoint_CheckPoint_Pole_lights),
	gsSPEndDisplayList(),
};

Gfx mat_checkpoint_Flag_White[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPGeometryMode(G_CULL_BACK, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(checkpoint_Flag_White_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_checkpoint_Flag_White[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx mat_checkpoint_Flag_Red[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPGeometryMode(G_CULL_BACK, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(checkpoint_Flag_Red_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_checkpoint_Flag_Red[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx mat_checkpoint_CheckPoint_Pole_Collected[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, checkpoint__2C9517A7_c_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(checkpoint_CheckPoint_Pole_Collected_lights),
	gsSPEndDisplayList(),
};

Gfx mat_checkpoint_Flag_Yellow[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPGeometryMode(G_CULL_BACK, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(checkpoint_Flag_Yellow_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_checkpoint_Flag_Yellow[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx checkpoint_Flag_Pole_mesh_layer_1[] = {
	gsSPDisplayList(mat_checkpoint_CheckPoint_Pole),
	gsSPDisplayList(checkpoint_Flag_Pole_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx checkpoint_Flag_1_mesh_layer_1[] = {
	gsSPDisplayList(mat_checkpoint_Flag_White),
	gsSPDisplayList(checkpoint_Flag_1_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_checkpoint_Flag_White),
	gsSPDisplayList(mat_checkpoint_Flag_Red),
	gsSPDisplayList(checkpoint_Flag_1_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_checkpoint_Flag_Red),
	gsSPEndDisplayList(),
};

Gfx checkpoint_Flag_2_mesh_layer_1[] = {
	gsSPDisplayList(mat_checkpoint_Flag_Red),
	gsSPDisplayList(checkpoint_Flag_2_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_checkpoint_Flag_Red),
	gsSPEndDisplayList(),
};

Gfx checkpoint_Flag_3_mesh_layer_1[] = {
	gsSPDisplayList(mat_checkpoint_Flag_Red),
	gsSPDisplayList(checkpoint_Flag_3_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_checkpoint_Flag_Red),
	gsSPEndDisplayList(),
};

Gfx checkpoint_Flag_4_mesh_layer_1[] = {
	gsSPDisplayList(mat_checkpoint_Flag_Red),
	gsSPDisplayList(checkpoint_Flag_4_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_checkpoint_Flag_Red),
	gsSPEndDisplayList(),
};

Gfx checkpoint_Flag_Tip_mesh_layer_1[] = {
	gsSPDisplayList(mat_checkpoint_Flag_Red),
	gsSPDisplayList(checkpoint_Flag_Tip_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_checkpoint_Flag_Red),
	gsSPEndDisplayList(),
};

Gfx checkpoint_Flag_Body_Switch_Option_Flag_Pole_mesh_layer_1[] = {
	gsSPDisplayList(mat_checkpoint_CheckPoint_Pole_Collected),
	gsSPDisplayList(checkpoint_Flag_Body_Switch_Option_Flag_Pole_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx checkpoint_Flag_Body_Switch_Option_Flag_1_mesh_layer_1[] = {
	gsSPDisplayList(mat_checkpoint_Flag_Yellow),
	gsSPDisplayList(checkpoint_Flag_Body_Switch_Option_Flag_1_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_checkpoint_Flag_Yellow),
	gsSPDisplayList(mat_checkpoint_Flag_Red),
	gsSPDisplayList(checkpoint_Flag_Body_Switch_Option_Flag_1_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_checkpoint_Flag_Red),
	gsSPEndDisplayList(),
};

Gfx checkpoint_Flag_Body_Switch_Option_Flag_2_mesh_layer_1[] = {
	gsSPDisplayList(mat_checkpoint_Flag_Red),
	gsSPDisplayList(checkpoint_Flag_Body_Switch_Option_Flag_2_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_checkpoint_Flag_Red),
	gsSPEndDisplayList(),
};

Gfx checkpoint_Flag_Body_Switch_Option_Flag_3_mesh_layer_1[] = {
	gsSPDisplayList(mat_checkpoint_Flag_Red),
	gsSPDisplayList(checkpoint_Flag_Body_Switch_Option_Flag_3_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_checkpoint_Flag_Red),
	gsSPEndDisplayList(),
};

Gfx checkpoint_Flag_Body_Switch_Option_Flag_4_mesh_layer_1[] = {
	gsSPDisplayList(mat_checkpoint_Flag_Red),
	gsSPDisplayList(checkpoint_Flag_Body_Switch_Option_Flag_4_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_checkpoint_Flag_Red),
	gsSPEndDisplayList(),
};

Gfx checkpoint_Flag_Body_Switch_Option_Flag_Tip_mesh_layer_1[] = {
	gsSPDisplayList(mat_checkpoint_Flag_Red),
	gsSPDisplayList(checkpoint_Flag_Body_Switch_Option_Flag_Tip_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_checkpoint_Flag_Red),
	gsSPEndDisplayList(),
};

Gfx checkpoint_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


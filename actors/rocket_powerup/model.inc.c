Lights1 rocket_powerup_Material_0_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 rocket_powerup_Material_1_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 rocket_powerup_Material_3_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 rocket_powerup_Material_2_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 rocket_powerup_Material_4_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Gfx rocket_powerup__0_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 rocket_powerup__0_rgba16[] = {
	#include "actors/rocket_powerup/_0.rgba16.inc.c"
};

Gfx rocket_powerup__1_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 rocket_powerup__1_rgba16[] = {
	#include "actors/rocket_powerup/_1.rgba16.inc.c"
};

Gfx rocket_powerup__3_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 rocket_powerup__3_rgba16[] = {
	#include "actors/rocket_powerup/_3.rgba16.inc.c"
};

Gfx rocket_powerup__2_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 rocket_powerup__2_rgba16[] = {
	#include "actors/rocket_powerup/_2.rgba16.inc.c"
};

Gfx rocket_powerup__4_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 rocket_powerup__4_rgba16[] = {
	#include "actors/rocket_powerup/_4.rgba16.inc.c"
};

Vtx rocket_powerup_Rocket_mesh_layer_1_vtx_0[43] = {
	{{ {8, 24, 20}, 0, {662, 1008}, {97, 177, 233, 255} }},
	{{ {-8, 19, 37}, 0, {330, 1008}, {160, 182, 217, 255} }},
	{{ {-8, 24, 20}, 0, {330, 1008}, {159, 177, 233, 255} }},
	{{ {8, 19, 37}, 0, {662, 1008}, {96, 182, 217, 255} }},
	{{ {-8, 5, 54}, 0, {330, 1008}, {186, 160, 45, 255} }},
	{{ {8, 5, 54}, 0, {662, 1008}, {70, 160, 45, 255} }},
	{{ {8, 49, 54}, 0, {662, -16}, {80, 38, 91, 255} }},
	{{ {8, 19, 37}, 0, {1121, 1008}, {96, 182, 217, 255} }},
	{{ {8, 66, 37}, 0, {1121, -16}, {84, 81, 51, 255} }},
	{{ {8, 24, 20}, 0, {1482, 1008}, {97, 177, 233, 255} }},
	{{ {8, 72, 20}, 0, {1482, -16}, {78, 94, 33, 255} }},
	{{ {-8, 49, 54}, 0, {330, -16}, {176, 38, 91, 255} }},
	{{ {-8, 66, 37}, 0, {330, -16}, {172, 81, 51, 255} }},
	{{ {8, 66, 37}, 0, {662, -16}, {84, 81, 51, 255} }},
	{{ {-8, 72, 20}, 0, {330, -16}, {178, 94, 33, 255} }},
	{{ {8, 72, 20}, 0, {662, -16}, {78, 94, 33, 255} }},
	{{ {-8, 19, 37}, 0, {-129, 1008}, {160, 182, 217, 255} }},
	{{ {-8, 66, 37}, 0, {-129, -16}, {172, 81, 51, 255} }},
	{{ {-8, 24, 20}, 0, {-490, 1008}, {159, 177, 233, 255} }},
	{{ {-8, 72, 20}, 0, {-490, -16}, {178, 94, 33, 255} }},
	{{ {8, 66, -37}, 0, {662, -16}, {84, 81, 205, 255} }},
	{{ {-8, 72, -20}, 0, {330, -16}, {178, 94, 223, 255} }},
	{{ {8, 72, -20}, 0, {662, -16}, {78, 94, 223, 255} }},
	{{ {-8, 66, -37}, 0, {330, -16}, {172, 81, 205, 255} }},
	{{ {8, 49, -54}, 0, {662, -16}, {80, 38, 165, 255} }},
	{{ {-8, 49, -54}, 0, {330, -16}, {176, 38, 165, 255} }},
	{{ {-8, 5, -54}, 0, {330, 1008}, {186, 160, 211, 255} }},
	{{ {8, 5, -54}, 0, {662, 1008}, {70, 160, 211, 255} }},
	{{ {8, 19, -37}, 0, {1121, 1008}, {96, 182, 39, 255} }},
	{{ {8, 66, -37}, 0, {1121, -16}, {84, 81, 205, 255} }},
	{{ {8, 24, -20}, 0, {1482, 1008}, {97, 177, 23, 255} }},
	{{ {8, 72, -20}, 0, {1482, -16}, {78, 94, 223, 255} }},
	{{ {-8, 5, -54}, 0, {330, 1008}, {186, 160, 211, 255} }},
	{{ {8, 5, -54}, 0, {662, 1008}, {70, 160, 211, 255} }},
	{{ {8, 19, -37}, 0, {662, 1008}, {96, 182, 39, 255} }},
	{{ {-8, 19, -37}, 0, {330, 1008}, {160, 182, 39, 255} }},
	{{ {8, 24, -20}, 0, {662, 1008}, {97, 177, 23, 255} }},
	{{ {-8, 24, -20}, 0, {330, 1008}, {159, 177, 23, 255} }},
	{{ {-8, 24, -20}, 0, {-490, 1008}, {159, 177, 23, 255} }},
	{{ {-8, 72, -20}, 0, {-490, -16}, {178, 94, 223, 255} }},
	{{ {-8, 66, -37}, 0, {-129, -16}, {172, 81, 205, 255} }},
	{{ {-8, 19, -37}, 0, {-129, 1008}, {160, 182, 39, 255} }},
	{{ {-8, 49, -54}, 0, {330, -16}, {176, 38, 165, 255} }},
};

Gfx rocket_powerup_Rocket_mesh_layer_1_tri_0[] = {
	gsSPVertex(rocket_powerup_Rocket_mesh_layer_1_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(3, 4, 1, 0, 3, 5, 4, 0),
	gsSP2Triangles(6, 4, 5, 0, 7, 6, 5, 0),
	gsSP2Triangles(7, 8, 6, 0, 9, 8, 7, 0),
	gsSP2Triangles(9, 10, 8, 0, 6, 11, 4, 0),
	gsSP2Triangles(12, 11, 6, 0, 12, 6, 13, 0),
	gsSP2Triangles(14, 12, 13, 0, 14, 13, 15, 0),
	gsSP2Triangles(11, 16, 4, 0, 11, 17, 16, 0),
	gsSP2Triangles(17, 18, 16, 0, 17, 19, 18, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 23, 21, 0),
	gsSP2Triangles(24, 23, 20, 0, 24, 25, 23, 0),
	gsSP2Triangles(26, 25, 24, 0, 26, 24, 27, 0),
	gsSP2Triangles(28, 27, 24, 0, 28, 24, 29, 0),
	gsSP2Triangles(30, 28, 29, 0, 30, 29, 31, 0),
	gsSPVertex(rocket_powerup_Rocket_mesh_layer_1_vtx_0 + 32, 11, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
	gsSP2Triangles(9, 8, 10, 0, 9, 10, 0, 0),
	gsSPEndDisplayList(),
};

Vtx rocket_powerup_Rocket_mesh_layer_1_vtx_1[8] = {
	{{ {0, 19, -31}, 0, {496, -16}, {0, 172, 160, 255} }},
	{{ {22, 19, -22}, 0, {858, 134}, {68, 172, 188, 255} }},
	{{ {31, 19, 0}, 0, {1008, 496}, {96, 172, 0, 255} }},
	{{ {-31, 19, 0}, 0, {-16, 496}, {160, 172, 0, 255} }},
	{{ {-22, 19, 22}, 0, {134, 858}, {188, 172, 68, 255} }},
	{{ {0, 19, 31}, 0, {496, 1008}, {0, 172, 96, 255} }},
	{{ {22, 19, 22}, 0, {858, 858}, {68, 172, 68, 255} }},
	{{ {-22, 19, -22}, 0, {134, 134}, {188, 173, 188, 255} }},
};

Gfx rocket_powerup_Rocket_mesh_layer_1_tri_1[] = {
	gsSPVertex(rocket_powerup_Rocket_mesh_layer_1_vtx_1 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(4, 3, 2, 0, 5, 4, 2, 0),
	gsSP2Triangles(2, 6, 5, 0, 3, 7, 0, 0),
	gsSPEndDisplayList(),
};

Vtx rocket_powerup_Rocket_mesh_layer_1_vtx_2[18] = {
	{{ {0, 19, -31}, 0, {-1037, 841}, {0, 172, 160, 255} }},
	{{ {0, 74, -35}, 0, {-1037, -429}, {0, 27, 132, 255} }},
	{{ {25, 74, -25}, 0, {-781, -429}, {88, 27, 168, 255} }},
	{{ {22, 19, -22}, 0, {-781, 841}, {68, 172, 188, 255} }},
	{{ {35, 74, 0}, 0, {-526, -429}, {124, 27, 0, 255} }},
	{{ {31, 19, 0}, 0, {-526, 841}, {96, 172, 0, 255} }},
	{{ {25, 74, 25}, 0, {-270, -429}, {88, 27, 88, 255} }},
	{{ {22, 19, 22}, 0, {-270, 841}, {68, 172, 68, 255} }},
	{{ {0, 74, 35}, 0, {-15, -429}, {0, 27, 124, 255} }},
	{{ {0, 19, 31}, 0, {-15, 841}, {0, 172, 96, 255} }},
	{{ {-25, 74, 25}, 0, {241, -429}, {168, 27, 88, 255} }},
	{{ {-22, 19, 22}, 0, {241, 841}, {188, 172, 68, 255} }},
	{{ {-35, 74, 0}, 0, {496, -429}, {132, 27, 0, 255} }},
	{{ {-31, 19, 0}, 0, {496, 841}, {160, 172, 0, 255} }},
	{{ {-22, 19, -22}, 0, {751, 841}, {188, 173, 188, 255} }},
	{{ {-25, 74, -25}, 0, {751, -429}, {168, 27, 168, 255} }},
	{{ {0, 74, -35}, 0, {1007, -429}, {0, 27, 132, 255} }},
	{{ {0, 19, -31}, 0, {1007, 841}, {0, 172, 160, 255} }},
};

Gfx rocket_powerup_Rocket_mesh_layer_1_tri_2[] = {
	gsSPVertex(rocket_powerup_Rocket_mesh_layer_1_vtx_2 + 0, 18, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
	gsSP2Triangles(5, 4, 6, 0, 5, 6, 7, 0),
	gsSP2Triangles(7, 6, 8, 0, 7, 8, 9, 0),
	gsSP2Triangles(9, 8, 10, 0, 9, 10, 11, 0),
	gsSP2Triangles(11, 10, 12, 0, 11, 12, 13, 0),
	gsSP2Triangles(14, 13, 12, 0, 14, 12, 15, 0),
	gsSP2Triangles(14, 15, 16, 0, 14, 16, 17, 0),
	gsSPEndDisplayList(),
};

Vtx rocket_powerup_Rocket_mesh_layer_1_vtx_3[17] = {
	{{ {15, 98, 15}, 0, {712, 712}, {74, 72, 74, 255} }},
	{{ {25, 74, 25}, 0, {858, 858}, {88, 27, 88, 255} }},
	{{ {35, 74, 0}, 0, {1008, 496}, {124, 27, 0, 255} }},
	{{ {0, 98, 21}, 0, {496, 802}, {0, 72, 105, 255} }},
	{{ {0, 123, 0}, 0, {496, 496}, {0, 127, 0, 255} }},
	{{ {21, 98, 0}, 0, {802, 496}, {105, 72, 0, 255} }},
	{{ {25, 74, -25}, 0, {858, 134}, {88, 27, 168, 255} }},
	{{ {15, 98, -15}, 0, {712, 280}, {74, 72, 182, 255} }},
	{{ {0, 98, -21}, 0, {496, 190}, {0, 72, 151, 255} }},
	{{ {0, 74, -35}, 0, {496, -16}, {0, 27, 132, 255} }},
	{{ {-15, 98, -15}, 0, {280, 280}, {182, 72, 182, 255} }},
	{{ {-25, 74, -25}, 0, {134, 134}, {168, 27, 168, 255} }},
	{{ {-35, 74, 0}, 0, {-16, 496}, {132, 27, 0, 255} }},
	{{ {-21, 98, 0}, 0, {190, 496}, {151, 72, 0, 255} }},
	{{ {-25, 74, 25}, 0, {134, 858}, {168, 27, 88, 255} }},
	{{ {-15, 98, 15}, 0, {280, 712}, {182, 72, 74, 255} }},
	{{ {0, 74, 35}, 0, {496, 1008}, {0, 27, 124, 255} }},
};

Gfx rocket_powerup_Rocket_mesh_layer_1_tri_3[] = {
	gsSPVertex(rocket_powerup_Rocket_mesh_layer_1_vtx_3 + 0, 17, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(3, 0, 4, 0, 0, 5, 4, 0),
	gsSP2Triangles(0, 2, 5, 0, 5, 2, 6, 0),
	gsSP2Triangles(5, 6, 7, 0, 8, 7, 6, 0),
	gsSP2Triangles(8, 6, 9, 0, 10, 8, 9, 0),
	gsSP2Triangles(10, 9, 11, 0, 10, 11, 12, 0),
	gsSP2Triangles(10, 12, 13, 0, 13, 12, 14, 0),
	gsSP2Triangles(13, 14, 15, 0, 3, 15, 14, 0),
	gsSP2Triangles(3, 14, 16, 0, 3, 16, 1, 0),
	gsSP2Triangles(15, 3, 4, 0, 13, 15, 4, 0),
	gsSP2Triangles(10, 13, 4, 0, 8, 10, 4, 0),
	gsSP2Triangles(7, 8, 4, 0, 5, 7, 4, 0),
	gsSPEndDisplayList(),
};

Vtx rocket_powerup_Rocket_mesh_layer_4_vtx_0[6] = {
	{{ {28, 31, -18}, 0, {955, 1008}, {122, 248, 222, 255} }},
	{{ {29, 62, -21}, 0, {1008, -16}, {122, 249, 221, 255} }},
	{{ {35, 62, 0}, 0, {496, -16}, {127, 248, 0, 255} }},
	{{ {33, 31, 0}, 0, {496, 1008}, {127, 248, 0, 255} }},
	{{ {28, 31, 18}, 0, {37, 1008}, {122, 248, 34, 255} }},
	{{ {29, 62, 21}, 0, {-16, -16}, {122, 249, 35, 255} }},
};

Gfx rocket_powerup_Rocket_mesh_layer_4_tri_0[] = {
	gsSPVertex(rocket_powerup_Rocket_mesh_layer_4_vtx_0 + 0, 6, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 3, 2, 0, 4, 2, 5, 0),
	gsSPEndDisplayList(),
};


Gfx mat_rocket_powerup_Material_0_f3d[] = {
	gsSPSetLights1(rocket_powerup_Material_0_f3d_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, rocket_powerup__0_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_rocket_powerup_Material_1_f3d[] = {
	gsSPSetLights1(rocket_powerup_Material_1_f3d_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, rocket_powerup__1_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_rocket_powerup_Material_3_f3d[] = {
	gsSPSetLights1(rocket_powerup_Material_3_f3d_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, rocket_powerup__3_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_rocket_powerup_Material_2_f3d[] = {
	gsSPSetLights1(rocket_powerup_Material_2_f3d_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, rocket_powerup__2_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_rocket_powerup_Material_4_f3d[] = {
	gsSPGeometryMode(G_CULL_BACK, 0),
	gsSPSetLights1(rocket_powerup_Material_4_f3d_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, rocket_powerup__4_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_rocket_powerup_Material_4_f3d[] = {
	gsSPGeometryMode(0, G_CULL_BACK),
	gsDPPipeSync(),
	gsSPEndDisplayList(),
};

Gfx rocket_powerup_Rocket_mesh_layer_1[] = {
	gsSPDisplayList(mat_rocket_powerup_Material_0_f3d),
	gsSPDisplayList(rocket_powerup_Rocket_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_rocket_powerup_Material_1_f3d),
	gsSPDisplayList(rocket_powerup_Rocket_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_rocket_powerup_Material_3_f3d),
	gsSPDisplayList(rocket_powerup_Rocket_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_rocket_powerup_Material_2_f3d),
	gsSPDisplayList(rocket_powerup_Rocket_mesh_layer_1_tri_3),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

Gfx rocket_powerup_Rocket_mesh_layer_4[] = {
	gsSPDisplayList(mat_rocket_powerup_Material_4_f3d),
	gsSPDisplayList(rocket_powerup_Rocket_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_rocket_powerup_Material_4_f3d),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


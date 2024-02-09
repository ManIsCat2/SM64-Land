Lights1 warp_pipe_blue_Material_0_002_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 warp_pipe_blue_Material_1_002_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Gfx warp_pipe_blue__0_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 warp_pipe_blue__0_rgba16[] = {
	#include "actors/warp_pipe_blue/_0.rgba16.inc.c"
};

Gfx warp_pipe_blue__1_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 warp_pipe_blue__1_rgba16[] = {
	#include "actors/warp_pipe_blue/_1.rgba16.inc.c"
};

Vtx warp_pipe_blue_Blue_Pipe_mesh_layer_1_vtx_cull[8] = {
	{{ {-153, 0, 154}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-153, 205, 154}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-153, 205, -153}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {-153, 0, -153}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {154, 0, 154}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {154, 205, 154}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {154, 205, -153}, 0, {-16, -16}, {0, 0, 0, 0} }},
	{{ {154, 0, -153}, 0, {-16, -16}, {0, 0, 0, 0} }},
};

Vtx warp_pipe_blue_Blue_Pipe_mesh_layer_1_vtx_0[64] = {
	{{ {-101, 0, 0}, 0, {974, 4044}, {127, 0, 0, 255} }},
	{{ {-71, 205, 72}, 0, {-16, 2032}, {54, 102, 203, 255} }},
	{{ {-71, 0, 72}, 0, {-16, 4044}, {90, 0, 166, 255} }},
	{{ {-101, 205, 0}, 0, {974, 2032}, {75, 103, 0, 255} }},
	{{ {72, 0, 72}, 0, {974, 4044}, {166, 0, 166, 255} }},
	{{ {72, 205, 72}, 0, {974, 2032}, {203, 102, 203, 255} }},
	{{ {102, 205, 0}, 0, {-16, 2032}, {181, 103, 0, 255} }},
	{{ {102, 0, 0}, 0, {-16, 4044}, {129, 0, 0, 255} }},
	{{ {0, 0, 102}, 0, {974, 4044}, {0, 0, 129, 255} }},
	{{ {0, 205, 102}, 0, {974, 2032}, {0, 103, 181, 255} }},
	{{ {72, 205, 72}, 0, {-16, 2032}, {203, 102, 203, 255} }},
	{{ {72, 0, 72}, 0, {-16, 4044}, {166, 0, 166, 255} }},
	{{ {-71, 0, 72}, 0, {974, 4044}, {90, 0, 166, 255} }},
	{{ {-71, 205, 72}, 0, {974, 2032}, {54, 102, 203, 255} }},
	{{ {0, 205, 102}, 0, {-16, 2032}, {0, 103, 181, 255} }},
	{{ {0, 0, 102}, 0, {-16, 4044}, {0, 0, 129, 255} }},
	{{ {72, 0, -71}, 0, {974, 4044}, {166, 0, 90, 255} }},
	{{ {0, 205, -101}, 0, {-16, 2032}, {0, 103, 75, 255} }},
	{{ {0, 0, -101}, 0, {-16, 4044}, {0, 0, 127, 255} }},
	{{ {72, 205, -71}, 0, {974, 2032}, {203, 102, 54, 255} }},
	{{ {-71, 0, -71}, 0, {974, 4044}, {90, 0, 90, 255} }},
	{{ {-101, 205, 0}, 0, {-16, 2032}, {75, 103, 0, 255} }},
	{{ {-101, 0, 0}, 0, {-16, 4044}, {127, 0, 0, 255} }},
	{{ {-71, 205, -71}, 0, {974, 2032}, {54, 102, 54, 255} }},
	{{ {0, 0, -101}, 0, {974, 4044}, {0, 0, 127, 255} }},
	{{ {-71, 205, -71}, 0, {-16, 2032}, {54, 102, 54, 255} }},
	{{ {-71, 0, -71}, 0, {-16, 4044}, {90, 0, 90, 255} }},
	{{ {0, 205, -101}, 0, {974, 2032}, {0, 103, 75, 255} }},
	{{ {0, 0, 154}, 0, {974, 4044}, {0, 0, 127, 255} }},
	{{ {0, 205, 154}, 0, {974, 2032}, {0, 80, 99, 255} }},
	{{ {-108, 205, 109}, 0, {-16, 2032}, {186, 80, 70, 255} }},
	{{ {-108, 0, 109}, 0, {-16, 4044}, {166, 0, 90, 255} }},
	{{ {102, 0, 0}, 0, {974, 4044}, {129, 0, 0, 255} }},
	{{ {102, 205, 0}, 0, {974, 2032}, {181, 103, 0, 255} }},
	{{ {72, 205, -71}, 0, {-16, 2032}, {203, 102, 54, 255} }},
	{{ {72, 0, -71}, 0, {-16, 4044}, {166, 0, 90, 255} }},
	{{ {154, 0, 0}, 0, {974, 4044}, {127, 0, 0, 255} }},
	{{ {154, 205, 0}, 0, {974, 2032}, {99, 80, 0, 255} }},
	{{ {109, 205, 109}, 0, {-16, 2032}, {70, 80, 70, 255} }},
	{{ {109, 0, 109}, 0, {-16, 4044}, {90, 0, 90, 255} }},
	{{ {109, 0, 109}, 0, {974, 4044}, {90, 0, 90, 255} }},
	{{ {109, 205, 109}, 0, {974, 2032}, {70, 80, 70, 255} }},
	{{ {0, 205, 154}, 0, {-16, 2032}, {0, 80, 99, 255} }},
	{{ {0, 0, 154}, 0, {-16, 4044}, {0, 0, 127, 255} }},
	{{ {-108, 0, -108}, 0, {974, 4044}, {166, 0, 166, 255} }},
	{{ {0, 205, -153}, 0, {-16, 2032}, {0, 80, 157, 255} }},
	{{ {0, 0, -153}, 0, {-16, 4044}, {0, 0, 129, 255} }},
	{{ {-108, 205, -108}, 0, {974, 2032}, {186, 80, 186, 255} }},
	{{ {-108, 0, 109}, 0, {974, 4044}, {166, 0, 90, 255} }},
	{{ {-108, 205, 109}, 0, {974, 2032}, {186, 80, 70, 255} }},
	{{ {-153, 205, 0}, 0, {-16, 2032}, {157, 80, 0, 255} }},
	{{ {-153, 0, 0}, 0, {-16, 4044}, {129, 0, 0, 255} }},
	{{ {-153, 0, 0}, 0, {974, 4044}, {129, 0, 0, 255} }},
	{{ {-108, 205, -108}, 0, {-16, 2032}, {186, 80, 186, 255} }},
	{{ {-108, 0, -108}, 0, {-16, 4044}, {166, 0, 166, 255} }},
	{{ {-153, 205, 0}, 0, {974, 2032}, {157, 80, 0, 255} }},
	{{ {0, 0, -153}, 0, {974, 4044}, {0, 0, 129, 255} }},
	{{ {0, 205, -153}, 0, {974, 2032}, {0, 80, 157, 255} }},
	{{ {109, 205, -108}, 0, {-16, 2032}, {70, 80, 186, 255} }},
	{{ {109, 0, -108}, 0, {-16, 4044}, {90, 0, 166, 255} }},
	{{ {109, 0, -108}, 0, {974, 4044}, {90, 0, 166, 255} }},
	{{ {109, 205, -108}, 0, {974, 2032}, {70, 80, 186, 255} }},
	{{ {154, 205, 0}, 0, {-16, 2032}, {99, 80, 0, 255} }},
	{{ {154, 0, 0}, 0, {-16, 4044}, {127, 0, 0, 255} }},
};

Gfx warp_pipe_blue_Blue_Pipe_mesh_layer_1_tri_0[] = {
	gsSPVertex(warp_pipe_blue_Blue_Pipe_mesh_layer_1_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 19, 17, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 23, 21, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 27, 25, 0),
	gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
	gsSPVertex(warp_pipe_blue_Blue_Pipe_mesh_layer_1_vtx_0 + 32, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 23, 21, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
	gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
	gsSPEndDisplayList(),
};

Vtx warp_pipe_blue_Blue_Pipe_mesh_layer_1_vtx_1[20] = {
	{{ {-101, 10, 102}, 0, {-16, 16}, {0, 127, 0, 255} }},
	{{ {102, 10, -101}, 0, {-16, 16}, {0, 127, 0, 255} }},
	{{ {-101, 10, -101}, 0, {-16, 16}, {0, 127, 0, 255} }},
	{{ {102, 10, 102}, 0, {-16, 16}, {0, 127, 0, 255} }},
	{{ {109, 205, -108}, 0, {384, -158}, {70, 80, 186, 255} }},
	{{ {0, 205, -153}, 0, {-2, 68}, {0, 80, 157, 255} }},
	{{ {0, 205, -101}, 0, {168, 202}, {0, 103, 75, 255} }},
	{{ {-71, 205, -71}, 0, {108, 510}, {54, 102, 54, 255} }},
	{{ {-108, 205, -108}, 0, {-88, 530}, {186, 80, 186, 255} }},
	{{ {-101, 205, 0}, 0, {282, 796}, {75, 103, 0, 255} }},
	{{ {-153, 205, 0}, 0, {170, 958}, {157, 80, 0, 255} }},
	{{ {-71, 205, 72}, 0, {588, 892}, {54, 102, 203, 255} }},
	{{ {-108, 205, 109}, 0, {628, 1098}, {186, 80, 70, 255} }},
	{{ {0, 205, 102}, 0, {846, 740}, {0, 103, 181, 255} }},
	{{ {0, 205, 154}, 0, {1016, 876}, {0, 80, 99, 255} }},
	{{ {109, 205, 109}, 0, {1104, 414}, {70, 80, 70, 255} }},
	{{ {72, 205, 72}, 0, {904, 432}, {203, 102, 203, 255} }},
	{{ {154, 205, 0}, 0, {842, -14}, {99, 80, 0, 255} }},
	{{ {102, 205, 0}, 0, {730, 148}, {181, 103, 0, 255} }},
	{{ {72, 205, -71}, 0, {426, 52}, {203, 102, 54, 255} }},
};

Gfx warp_pipe_blue_Blue_Pipe_mesh_layer_1_tri_1[] = {
	gsSPVertex(warp_pipe_blue_Blue_Pipe_mesh_layer_1_vtx_1 + 0, 20, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 5, 7, 6, 0),
	gsSP2Triangles(5, 8, 7, 0, 8, 9, 7, 0),
	gsSP2Triangles(8, 10, 9, 0, 10, 11, 9, 0),
	gsSP2Triangles(10, 12, 11, 0, 12, 13, 11, 0),
	gsSP2Triangles(12, 14, 13, 0, 15, 13, 14, 0),
	gsSP2Triangles(15, 16, 13, 0, 17, 16, 15, 0),
	gsSP2Triangles(17, 18, 16, 0, 17, 19, 18, 0),
	gsSP2Triangles(17, 4, 19, 0, 4, 6, 19, 0),
	gsSPEndDisplayList(),
};


Gfx mat_warp_pipe_blue_Material_0_002_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(warp_pipe_blue_Material_0_002_f3d_lights),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, warp_pipe_blue__0_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 252),
	gsSPEndDisplayList(),
};

Gfx mat_warp_pipe_blue_Material_1_002_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(warp_pipe_blue_Material_1_002_f3d_lights),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, warp_pipe_blue__1_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTile(7, 0, 0, 0, 0),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPSetTileSize(0, 0, 0, 0, 0),
	gsSPEndDisplayList(),
};

Gfx warp_pipe_blue_Blue_Pipe_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(warp_pipe_blue_Blue_Pipe_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_warp_pipe_blue_Material_0_002_f3d),
	gsSPDisplayList(warp_pipe_blue_Blue_Pipe_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_warp_pipe_blue_Material_1_002_f3d),
	gsSPDisplayList(warp_pipe_blue_Blue_Pipe_mesh_layer_1_tri_1),
	gsSPEndDisplayList(),
};

Gfx warp_pipe_blue_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

ALIGNED8 u8 exclamation_box_geo__texture_08014E28[] = {
#include "actors/exclamation_box/exclamation_box_geo_0x8014e28_custom.rgba16.inc.c"
};
ALIGNED8 u8 exclamation_box_geo__texture_08015628[] = {
#include "actors/exclamation_box/exclamation_box_geo_0x8015628_custom.rgba16.inc.c"
};
ALIGNED8 u8 exclamation_box_geo__texture_08013E28[] = {
#include "actors/exclamation_box/exclamation_box_geo_0x8013e28_custom.rgba16.inc.c"
};
ALIGNED8 u8 exclamation_box_geo__texture_08014628[] = {
#include "actors/exclamation_box/exclamation_box_geo_0x8014628_custom.rgba16.inc.c"
};
ALIGNED8 u8 exclamation_box_geo__texture_08012E28[] = {
#include "actors/exclamation_box/exclamation_box_geo_0x8012e28_custom.rgba16.inc.c"
};
ALIGNED8 u8 exclamation_box_geo__texture_08013628[] = {
#include "actors/exclamation_box/exclamation_box_geo_0x8013628_custom.rgba16.inc.c"
};
ALIGNED8 u8 exclamation_box_geo__texture_08016E28[] = {
#include "actors/exclamation_box/exclamation_box_geo_0x8016e28_custom.rgba16.inc.c"
};
ALIGNED8 u8 exclamation_box_geo__texture_08017628[] = {
#include "actors/exclamation_box/exclamation_box_geo_0x8017628_custom.rgba16.inc.c"
};
ALIGNED8 u8 exclamation_box_geo__texture_08017E28[] = {
#include "actors/exclamation_box/exclamation_box_geo_0x8017e28_custom.rgba16.inc.c"
};
ALIGNED8 u8 exclamation_box_geo__texture_08018628[] = {
#include "actors/exclamation_box/exclamation_box_geo_0x8018628_custom.rgba16.inc.c"
};
ALIGNED8 u8 exclamation_box_geo__texture_08015E28[] = {
#include "actors/exclamation_box/exclamation_box_geo_0x8015e28_custom.rgba16.inc.c"
};
ALIGNED8 u8 exclamation_box_geo__texture_08016628[] = {
#include "actors/exclamation_box/exclamation_box_geo_0x8016628_custom.rgba16.inc.c"
};

Vtx VB_exclamation_box_geo_0x8018e28[] = {
	{{{ -25, 1, -25 }, 0, { 992, 992 }, { 0, 0, 129, 255}}},
	{{{ -25, 52, -25 }, 0, { 992, 0 }, { 0, 0, 129, 255}}},
	{{{ 26, 52, -25 }, 0, { 0, 0 }, { 0, 0, 129, 255}}},
	{{{ -25, 1, 26 }, 0, { 0, 992 }, { 0, 0, 127, 255}}},
	{{{ 26, 1, 26 }, 0, { 992, 992 }, { 0, 0, 127, 255}}},
	{{{ 26, 52, 26 }, 0, { 992, 0 }, { 0, 0, 127, 255}}},
	{{{ -25, 52, 26 }, 0, { 0, 0 }, { 0, 0, 127, 255}}},
	{{{ 26, 52, -25 }, 0, { 992, 0 }, { 127, 0, 0, 255}}},
	{{{ 26, 1, 26 }, 0, { 0, 992 }, { 127, 0, 0, 255}}},
	{{{ 26, 1, -25 }, 0, { 992, 992 }, { 127, 0, 0, 255}}},
	{{{ 26, 52, 26 }, 0, { 0, 0 }, { 127, 0, 0, 255}}},
	{{{ -25, 1, -25 }, 0, { 0, 992 }, { 129, 0, 0, 255}}},
	{{{ -25, 1, 26 }, 0, { 992, 992 }, { 129, 0, 0, 255}}},
	{{{ -25, 52, 26 }, 0, { 992, 0 }, { 129, 0, 0, 255}}},
	{{{ -25, 52, -25 }, 0, { 0, 0 }, { 129, 0, 0, 255}}},
	{{{ 26, 1, -25 }, 0, { 0, 992 }, { 0, 0, 129, 255}}},
};

Vtx VB_exclamation_box_geo_0x8018f28[] = {
	{{{ 26, 1, -25 }, 0, { 992, 992 }, { 0, 129, 0, 255}}},
	{{{ 26, 1, 26 }, 0, { 992, 0 }, { 0, 129, 0, 255}}},
	{{{ -25, 1, 26 }, 0, { 0, 0 }, { 0, 129, 0, 255}}},
	{{{ -25, 1, -25 }, 0, { 0, 992 }, { 0, 129, 0, 255}}},
	{{{ -25, 52, -25 }, 0, { 0, 0 }, { 0, 127, 0, 255}}},
	{{{ -25, 52, 26 }, 0, { 0, 992 }, { 0, 127, 0, 255}}},
	{{{ 26, 52, 26 }, 0, { 992, 992 }, { 0, 127, 0, 255}}},
	{{{ 26, 52, -25 }, 0, { 992, 0 }, { 0, 127, 0, 255}}},
};

Light_t Light_exclamation_box_geo_0x8012e18 = {
	{ 255, 255, 255}, 0, { 255, 255, 255}, 0, { 40, 40, 40}, 0
};

Ambient_t Light_exclamation_box_geo_0x8012e10 = {
	{63, 63, 63}, 0, {63, 63, 63}, 0
};

Gfx DL_exclamation_box_geo_0x8019318[] = {
	gsDPSetTextureImage(0, 2, 1, exclamation_box_geo__texture_08014E28),
	gsSPDisplayList(DL_exclamation_box_geo_0x8019280),
	gsDPSetTextureImage(0, 2, 1, exclamation_box_geo__texture_08015628),
	gsSPBranchList(DL_exclamation_box_geo_0x80192c0),
};

Gfx DL_exclamation_box_geo_0x8019280[] = {
	gsSPDisplayList(DL_exclamation_box_geo_0x8019058),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsSPDisplayList(DL_exclamation_box_geo_0x8018fa8),
	gsDPTileSync(),
	gsDPSetTile(0, 2, 8, 0, 0, 0, 2, 6, 0, 2, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 252),
	gsSPEndDisplayList(),
};

Gfx DL_exclamation_box_geo_0x8019058[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE),
	gsSPGeometryMode(G_SHADING_SMOOTH, 0),
	gsDPSetTile(0, 2, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTile(0, 2, 8, 0, 0, 0, 2, 5, 0, 2, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx DL_exclamation_box_geo_0x8018fa8[] = {
	gsSPLight(&Light_exclamation_box_geo_0x8012e18.col, 1),
	gsSPLight(&Light_exclamation_box_geo_0x8012e10.col, 2),
	gsSPVertex(VB_exclamation_box_geo_0x8018e28, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(3, 5, 6, 0, 7, 8, 9, 0),
	gsSP2Triangles(7, 10, 8, 0, 11, 12, 13, 0),
	gsSP2Triangles(11, 13, 14, 0, 0, 2, 15, 0),
	gsSPEndDisplayList(),
};

Gfx DL_exclamation_box_geo_0x80192c0[] = {
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 2047, 256),
	gsSPDisplayList(DL_exclamation_box_geo_0x8019008),
	gsSPEndDisplayList(),
};

Gfx DL_exclamation_box_geo_0x8019008[] = {
	gsSPVertex(VB_exclamation_box_geo_0x8018f28, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
	gsSPGeometryMode(0, G_SHADING_SMOOTH),
	gsSPEndDisplayList(),
};

Gfx DL_exclamation_box_geo_0x8019338[] = {
	gsDPSetTextureImage(0, 2, 1, exclamation_box_geo__texture_08013E28),
	gsSPDisplayList(DL_exclamation_box_geo_0x8019280),
	gsDPSetTextureImage(0, 2, 1, exclamation_box_geo__texture_08014628),
	gsSPBranchList(DL_exclamation_box_geo_0x80192c0),
};

Gfx DL_exclamation_box_geo_0x8019358[] = {
	gsDPSetTextureImage(0, 2, 1, exclamation_box_geo__texture_08012E28),
	gsSPDisplayList(DL_exclamation_box_geo_0x8019280),
	gsDPSetTextureImage(0, 2, 1, exclamation_box_geo__texture_08013628),
	gsSPBranchList(DL_exclamation_box_geo_0x80192c0),
};

Gfx DL_exclamation_box_geo_0x8019378[] = {
	gsDPSetTextureImage(0, 2, 1, exclamation_box_geo__texture_08016E28),
	gsSPDisplayList(DL_exclamation_box_geo_0x8019280),
	gsDPSetTextureImage(0, 2, 1, exclamation_box_geo__texture_08017628),
	gsSPBranchList(DL_exclamation_box_geo_0x80192c0),
};

Gfx DL_exclamation_box_geo_0x8019398[] = {
	gsDPSetTextureImage(0, 2, 1, exclamation_box_geo__texture_08017E28),
	gsSPDisplayList(DL_exclamation_box_geo_0x8019280),
	gsDPSetTextureImage(0, 2, 1, exclamation_box_geo__texture_08018628),
	gsSPBranchList(DL_exclamation_box_geo_0x80192c0),
};

Gfx DL_exclamation_box_geo_0x80193b8[] = {
	gsDPSetTextureImage(0, 2, 1, exclamation_box_geo__texture_08015E28),
	gsSPDisplayList(DL_exclamation_box_geo_0x8019280),
	gsDPSetTextureImage(0, 2, 1, exclamation_box_geo__texture_08016628),
	gsSPBranchList(DL_exclamation_box_geo_0x80192c0),
};


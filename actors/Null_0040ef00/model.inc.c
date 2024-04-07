#include "model.inc.h"

ALIGNED8 u8 Null_geo_0040ef00__texture_0B000008[] = {
#include "actors/Null_0040ef00/Null_geo_0040ef00_0xb000008_custom.rgba16.inc.c"
};
ALIGNED8 u8 Null_geo_0040ef00__texture_0B000808[] = {
#include "actors/Null_0040ef00/Null_geo_0040ef00_0xb000808_custom.rgba16.inc.c"
};
ALIGNED8 u8 Null_geo_0040ef00__texture_0B001008[] = {
#include "actors/Null_0040ef00/Null_geo_0040ef00_0xb001008_custom.rgba16.inc.c"
};
ALIGNED8 u8 Null_geo_0040ef00__texture_0B001808[] = {
#include "actors/Null_0040ef00/Null_geo_0040ef00_0xb001808_custom.rgba16.inc.c"
};


Vtx VB_Null_geo_0040ef00_0x401cd20[] = {
	{{{ -16, 0, 0 }, 0, { 0, 992 }, { 255, 255, 255, 255}}},
	{{{ 16, 0, 0 }, 0, { 992, 992 }, { 255, 255, 255, 255}}},
	{{{ 16, 32, 0 }, 0, { 992, 0 }, { 255, 255, 255, 255}}},
	{{{ -16, 32, 0 }, 0, { 0, 0 }, { 255, 255, 255, 255}}},
};

Gfx DL_Null_geo_0040ef00_0x40ee00[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(0, 2, 1, Null_geo_0040ef00__texture_0B000008),
	gsSPBranchList(DL_Null_geo_0040ef00_0x401de00),
};

Gfx DL_Null_geo_0040ef00_0x401de00[] = {
	gsDPSetTile(0, 2, 0, 0, 7, 0, 2, 5, 0, 2, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(0, 2, 8, 0, 0, 0, 2, 5, 0, 2, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPVertex(VB_Null_geo_0040ef00_0x401cd20, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
	gsSPEndDisplayList(),
};

Gfx DL_Null_geo_0040ef00_0x40ee40[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(0, 2, 1, Null_geo_0040ef00__texture_0B000808),
	gsSPBranchList(DL_Null_geo_0040ef00_0x401de00),
};

Gfx DL_Null_geo_0040ef00_0x40ee80[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(0, 2, 1, Null_geo_0040ef00__texture_0B001008),
	gsSPBranchList(DL_Null_geo_0040ef00_0x401de00),
};

Gfx DL_Null_geo_0040ef00_0x40eec0[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(0, 2, 1, Null_geo_0040ef00__texture_0B001808),
	gsSPBranchList(DL_Null_geo_0040ef00_0x401de00),
};


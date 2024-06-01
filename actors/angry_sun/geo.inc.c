#include "src/game/envfx_snow.h"

const GeoLayout angry_sun_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, angry_sun_Bone_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

#include "src/game/envfx_snow.h"

const GeoLayout rotating_platform_jrb_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, rotating_platform_jrb_Bone_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

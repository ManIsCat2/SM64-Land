#include "src/game/envfx_snow.h"

const GeoLayout gravity_powerup_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, gravity_powerup_000_offset_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

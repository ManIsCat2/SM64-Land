#include "src/game/envfx_snow.h"

const GeoLayout fast_moving_wall_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, fast_moving_wall_node_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

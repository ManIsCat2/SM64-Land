#include "src/game/envfx_snow.h"

const GeoLayout bitfs_moving_pyramid_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bitfs_moving_pyramid_node_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

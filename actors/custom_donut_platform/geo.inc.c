#include "src/game/envfx_snow.h"

const GeoLayout custom_donut_platform_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, custom_donut_platform_node_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

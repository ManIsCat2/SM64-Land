#include "src/game/envfx_snow.h"

const GeoLayout ddd_purple_appearing_path_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ddd_purple_appearing_path_node_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

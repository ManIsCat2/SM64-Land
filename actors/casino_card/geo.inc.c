#include "src/game/envfx_snow.h"

const GeoLayout casino_card_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, casino_card_node_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

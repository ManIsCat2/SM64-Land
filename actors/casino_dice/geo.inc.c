#include "src/game/envfx_snow.h"

const GeoLayout casino_dice_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, casino_dice_node_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

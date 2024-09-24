#include "src/game/envfx_snow.h"

const GeoLayout octopus_boss_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, octopus_boss_node_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, octopus_boss_node_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

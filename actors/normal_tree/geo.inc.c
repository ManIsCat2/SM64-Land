#include "src/game/envfx_snow.h"

const GeoLayout normal_tree_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(0, 180, 800),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, normal_tree_Tree_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_ALPHA, normal_tree_Tree_mesh_layer_4),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, normal_tree_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, normal_tree_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

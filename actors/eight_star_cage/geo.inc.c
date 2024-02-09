#include "src/game/envfx_snow.h"

const GeoLayout eight_star_cage_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, eight_star_cage_8_Star_Cage_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, eight_star_cage_8_Star_Cage_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, eight_star_cage_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, eight_star_cage_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

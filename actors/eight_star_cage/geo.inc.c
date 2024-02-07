#include "src/game/envfx_snow.h"

const GeoLayout eight_star_cage_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, eight_star_cage_Bone_mesh_layer_4),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, eight_star_cage_Bone_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, eight_star_cage_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, eight_star_cage_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

#include "src/game/envfx_snow.h"

const GeoLayout tanooki_leaf_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, tanooki_leaf_Bone_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tanooki_leaf_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

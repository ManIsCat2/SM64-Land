#include "src/game/envfx_snow.h"

const GeoLayout yoshi_nest_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(0, 200, 70),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_FORCE, 65536),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, yoshi_nest_000_displaylist_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, yoshi_nest_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

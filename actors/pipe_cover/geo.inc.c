#include "src/game/envfx_snow.h"

const GeoLayout pipe_cover_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, pipe_cover_Blue_Pipe_Cover_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, pipe_cover_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
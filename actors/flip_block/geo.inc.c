#include "src/game/envfx_snow.h"

const GeoLayout flip_block_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, flip_block_smw_block_Bone_mesh_layer_1_mesh_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

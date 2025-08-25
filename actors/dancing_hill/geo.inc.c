#include "src/game/envfx_snow.h"

const GeoLayout dancing_hill_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 716, 0, dancing_hill_Bone_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, dancing_hill_Bone_001_skinned_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 465, 0, dancing_hill_Bone_001_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_ALPHA, dancing_hill_Bone_001_mesh_layer_4),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 213, 738, NULL),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

const GeoLayout dancing_hill2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 716, 0, dancing_hill_Bone_mesh_layer_1_2),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, dancing_hill_Bone_001_skinned_mesh_layer_1_2),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 465, 0, dancing_hill_Bone_001_mesh_layer_1_2),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_ALPHA, dancing_hill_Bone_001_mesh_layer_4),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 213, 738, NULL),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

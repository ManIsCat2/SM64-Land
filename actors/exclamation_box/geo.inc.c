
const GeoLayout exclamation_box_geo[]= {
GEO_CULLING_RADIUS(300),
GEO_OPEN_NODE(),
GEO_SHADOW(10,180,70),
GEO_OPEN_NODE(),
GEO_SWITCH_CASE(6, geo_switch_anim_state),
GEO_OPEN_NODE(),
GEO_DISPLAY_LIST(1,DL_exclamation_box_geo_0x8019318),
GEO_DISPLAY_LIST(1,DL_exclamation_box_geo_0x8019338),
GEO_DISPLAY_LIST(1,DL_exclamation_box_geo_0x8019358),
GEO_BRANCH(1,Geo_exclamation_box_geo_0xe24ef0),
GEO_CLOSE_NODE(),
GEO_CLOSE_NODE(),
GEO_CLOSE_NODE(),
GEO_END(),
};

const GeoLayout Geo_exclamation_box_geo_0xe24ef0[]= {
GEO_DISPLAY_LIST(1,DL_exclamation_box_geo_0x8019378),
GEO_DISPLAY_LIST(1,DL_exclamation_box_geo_0x8019398),
GEO_DISPLAY_LIST(1,DL_exclamation_box_geo_0x80193b8),
GEO_RETURN(),
};

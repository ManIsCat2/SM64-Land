#include "custom.model.inc.h"
const GeoLayout Geo_ddd_2_0x199b8c0[]= {
GEO_NODE_SCREEN_AREA(10,160,120,160,120),
GEO_OPEN_NODE(),
GEO_ZBUFFER(0),
GEO_OPEN_NODE(),
GEO_NODE_ORTHO(100),
GEO_OPEN_NODE(),
GEO_BACKGROUND(5, geo_skybox_main),
GEO_CLOSE_NODE(),
GEO_CLOSE_NODE(),
GEO_ZBUFFER(1),
GEO_OPEN_NODE(),
GEO_CAMERA_FRUSTUM_WITH_FUNC(45,100,42288, geo_camera_fov),
GEO_OPEN_NODE(),
GEO_CAMERA(1,0,2000,6000,3072,0,60928, geo_camera_main),
GEO_OPEN_NODE(),
GEO_DISPLAY_LIST(1,DL_ddd_2_0xe032a00),
GEO_DISPLAY_LIST(5,DL_ddd_2_0xe03c498),
GEO_RENDER_OBJ(),
GEO_ASM(0, geo_envfx_main),
GEO_ASM(20480, geo_movtex_draw_water_regions),
GEO_ASM(20481, geo_movtex_draw_water_regions),
GEO_ASM(20482, geo_movtex_draw_water_regions),
GEO_CLOSE_NODE(),
GEO_CLOSE_NODE(),
GEO_CLOSE_NODE(),
GEO_ZBUFFER(0),
GEO_OPEN_NODE(),
GEO_ASM(0, geo_cannon_circle_base),
GEO_CLOSE_NODE(),
GEO_CLOSE_NODE(),
GEO_END(),
};

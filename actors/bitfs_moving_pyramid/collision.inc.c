const Collision bitfs_moving_pyramid_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(6),
	COL_VERTEX(0, 102, 0),
	COL_VERTEX(307, 0, 307),
	COL_VERTEX(307, 0, -306),
	COL_VERTEX(-306, 0, -306),
	COL_VERTEX(0, -306, 0),
	COL_VERTEX(-306, 0, 307),
	COL_TRI_INIT(SURFACE_NOT_SLIPPERY, 8),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 5, 3),
	COL_TRI(5, 4, 1),
	COL_TRI(2, 1, 4),
	COL_TRI(3, 2, 4),
	COL_TRI(3, 5, 0),
	COL_TRI(1, 0, 5),
	COL_TRI_STOP(),
	COL_END()
};

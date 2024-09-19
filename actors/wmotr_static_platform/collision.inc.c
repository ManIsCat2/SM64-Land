const Collision wmotr_static_platform_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(16),
	COL_VERTEX(-500, 100, 500),
	COL_VERTEX(-500, -100, -500),
	COL_VERTEX(-500, -100, 500),
	COL_VERTEX(-500, 100, -500),
	COL_VERTEX(500, -100, -500),
	COL_VERTEX(500, 100, -500),
	COL_VERTEX(500, -100, 500),
	COL_VERTEX(500, 100, 500),
	COL_VERTEX(373, 100, -373),
	COL_VERTEX(373, 23, 373),
	COL_VERTEX(373, 100, 373),
	COL_VERTEX(-373, 100, -373),
	COL_VERTEX(-373, 100, 373),
	COL_VERTEX(-373, 23, -373),
	COL_VERTEX(373, 23, -373),
	COL_VERTEX(-373, 23, 373),
	COL_TRI_INIT(SURFACE_DEFAULT, 28),
	COL_TRI(0, 1, 2),
	COL_TRI(3, 4, 1),
	COL_TRI(5, 6, 4),
	COL_TRI(7, 2, 6),
	COL_TRI(4, 2, 1),
	COL_TRI(8, 9, 10),
	COL_TRI(11, 0, 12),
	COL_TRI(8, 3, 11),
	COL_TRI(10, 5, 8),
	COL_TRI(12, 7, 10),
	COL_TRI(13, 9, 14),
	COL_TRI(12, 13, 11),
	COL_TRI(10, 15, 12),
	COL_TRI(11, 14, 8),
	COL_TRI(0, 3, 1),
	COL_TRI(3, 5, 4),
	COL_TRI(5, 7, 6),
	COL_TRI(7, 0, 2),
	COL_TRI(4, 6, 2),
	COL_TRI(8, 14, 9),
	COL_TRI(11, 3, 0),
	COL_TRI(8, 5, 3),
	COL_TRI(10, 7, 5),
	COL_TRI(12, 0, 7),
	COL_TRI(13, 15, 9),
	COL_TRI(12, 15, 13),
	COL_TRI(10, 9, 15),
	COL_TRI(11, 13, 14),
	COL_TRI_STOP(),
	COL_END()
};

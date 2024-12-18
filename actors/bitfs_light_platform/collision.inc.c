const Collision bitfs_light_platform_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(16),
	COL_VERTEX(333, 103, -257),
	COL_VERTEX(-333, 103, 368),
	COL_VERTEX(333, 103, 368),
	COL_VERTEX(333, 103, 993),
	COL_VERTEX(-333, 103, 1618),
	COL_VERTEX(333, 103, 1618),
	COL_VERTEX(-333, 103, 993),
	COL_VERTEX(-333, 103, -257),
	COL_VERTEX(333, 3, -257),
	COL_VERTEX(-333, 3, -257),
	COL_VERTEX(-333, 3, 282),
	COL_VERTEX(333, 3, 1360),
	COL_VERTEX(333, 3, 821),
	COL_VERTEX(-333, 3, 1360),
	COL_VERTEX(-333, 3, 821),
	COL_VERTEX(333, 3, 282),
	COL_TRI_INIT(SURFACE_SLIPPERY, 6),
	COL_TRI(0, 1, 2),
	COL_TRI(3, 4, 5),
	COL_TRI(2, 6, 3),
	COL_TRI(0, 7, 1),
	COL_TRI(3, 6, 4),
	COL_TRI(2, 1, 6),
	COL_TRI_INIT(SURFACE_SLIPPERY, 22),
	COL_TRI(7, 8, 9),
	COL_TRI(10, 7, 9),
	COL_TRI(3, 11, 12),
	COL_TRI(11, 4, 13),
	COL_TRI(13, 12, 11),
	COL_TRI(14, 15, 12),
	COL_TRI(10, 8, 15),
	COL_TRI(0, 15, 8),
	COL_TRI(2, 12, 15),
	COL_TRI(13, 6, 14),
	COL_TRI(14, 1, 10),
	COL_TRI(7, 0, 8),
	COL_TRI(10, 1, 7),
	COL_TRI(3, 5, 11),
	COL_TRI(11, 5, 4),
	COL_TRI(13, 14, 12),
	COL_TRI(14, 10, 15),
	COL_TRI(10, 9, 8),
	COL_TRI(0, 2, 15),
	COL_TRI(2, 3, 12),
	COL_TRI(13, 4, 6),
	COL_TRI(14, 6, 1),
	COL_TRI_STOP(),
	COL_END()
};

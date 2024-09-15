const Collision fliptile_2_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(8),
	COL_VERTEX(250, -25, 250),
	COL_VERTEX(-250, -25, -250),
	COL_VERTEX(250, -25, -250),
	COL_VERTEX(-250, -25, 250),
	COL_VERTEX(-250, 25, -250),
	COL_VERTEX(250, 25, 250),
	COL_VERTEX(250, 25, -250),
	COL_VERTEX(-250, 25, 250),
	COL_TRI_INIT(SURFACE_SLIPPERY, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 3, 1),
	COL_TRI_INIT(SURFACE_BURNING, 2),
	COL_TRI(4, 5, 6),
	COL_TRI(4, 7, 5),
	COL_TRI_INIT(SURFACE_DEFAULT, 8),
	COL_TRI(4, 3, 7),
	COL_TRI(5, 2, 6),
	COL_TRI(6, 1, 4),
	COL_TRI(7, 0, 5),
	COL_TRI(4, 1, 3),
	COL_TRI(5, 0, 2),
	COL_TRI(6, 2, 1),
	COL_TRI(7, 3, 0),
	COL_TRI_STOP(),
	COL_END()
};

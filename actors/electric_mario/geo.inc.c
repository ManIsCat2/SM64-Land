#include "src/game/envfx_snow.h"

const GeoLayout electric_mario_Left_Hand_Open[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, electric_mario_Left_Hand_Open_Switch_Option_Left_Hand_Open_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_Right_Hand_Open[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, electric_mario_Right_Hand_Open_Switch_Option_Right_Hand_Open_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_HELD_OBJECT(0, 0, 0, 0, geo_switch_mario_hand_grab_pos),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_Right_Hand_Peace[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, electric_mario_Right_Hand_Peace_Switch_Option_Right_Hand_Peace_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1_jump_electric_mario_Left_Hand_Open[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, electric_mario_Left_Hand_Open_Switch_Option_Left_Hand_Open_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1_jump_electric_mario_Right_Hand_Open[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, electric_mario_Right_Hand_Open_Switch_Option_Right_Hand_Open_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_HELD_OBJECT(0, 0, 0, 0, geo_switch_mario_hand_grab_pos),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1_jump_electric_mario_Right_Hand_Peace[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, electric_mario_Right_Hand_Peace_Switch_Option_Right_Hand_Peace_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1_Capless_Switch_opt0_Eye_State_Switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_mario_Head_DL_mesh_layer_1_mat_override_Half_Closed_Eyes__SKIN__0),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_mario_Head_DL_mesh_layer_4_mat_override_Half_Closed_Eyes__SKIN__0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1_Capless_Switch_opt0_Eye_State_Switch_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_mario_Head_DL_mesh_layer_1_mat_override_Closed_Eyes__SKIN__1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_mario_Head_DL_mesh_layer_4_mat_override_Closed_Eyes__SKIN__1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1_Capless_Switch_opt0_Eye_State_Switch_opt3[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_mario_Head_DL_mesh_layer_1_mat_override_Left_Eyes__SKIN__2),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_mario_Head_DL_mesh_layer_4_mat_override_Left_Eyes__SKIN__2),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1_Capless_Switch_opt0_Eye_State_Switch_opt4[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_mario_Head_DL_mesh_layer_1_mat_override_Right_Eyes__SKIN__3),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_mario_Head_DL_mesh_layer_4_mat_override_Right_Eyes__SKIN__3),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1_Capless_Switch_opt0_Eye_State_Switch_opt5[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_mario_Head_DL_mesh_layer_1_mat_override_Up_Eyes__SKIN__4),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_mario_Head_DL_mesh_layer_4_mat_override_Up_Eyes__SKIN__4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1_Capless_Switch_opt0_Eye_State_Switch_opt6[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_mario_Head_DL_mesh_layer_1_mat_override_Down_Eyes__SKIN__5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_mario_Head_DL_mesh_layer_4_mat_override_Down_Eyes__SKIN__5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1_Capless_Switch_opt0_Eye_State_Switch_opt7[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_mario_Head_DL_mesh_layer_1_mat_override_Dead_Eyes__SKIN__6),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_mario_Head_DL_mesh_layer_4_mat_override_Dead_Eyes__SKIN__6),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, electric_mario_Butt_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_ASM(0, geo_move_mario_part_from_parent),
				GEO_ASM(0, geo_mario_tilt_torso),
				GEO_ROTATION_NODE(LAYER_FORCE, 0, 0, 0),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_TRANSPARENT, 68, 0, 0, electric_mario_Torso_mesh_layer_1),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 87, 0, 0, NULL),
						GEO_OPEN_NODE(),
							GEO_ASM(0, geo_mario_head_rotation),
							GEO_ROTATION_NODE(LAYER_FORCE, 0, 0, 0),
							GEO_OPEN_NODE(),
								GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
								GEO_OPEN_NODE(),
									GEO_NODE_START(),
									GEO_OPEN_NODE(),
										GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
										GEO_OPEN_NODE(),
											GEO_NODE_START(),
											GEO_OPEN_NODE(),
												GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_mario_Head_DL_mesh_layer_1),
												GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_mario_Head_DL_mesh_layer_4),
											GEO_CLOSE_NODE(),
											GEO_BRANCH(1, electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1_Capless_Switch_opt0_Eye_State_Switch_opt1),
											GEO_BRANCH(1, electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1_Capless_Switch_opt0_Eye_State_Switch_opt2),
											GEO_BRANCH(1, electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1_Capless_Switch_opt0_Eye_State_Switch_opt3),
											GEO_BRANCH(1, electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1_Capless_Switch_opt0_Eye_State_Switch_opt4),
											GEO_BRANCH(1, electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1_Capless_Switch_opt0_Eye_State_Switch_opt5),
											GEO_BRANCH(1, electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1_Capless_Switch_opt0_Eye_State_Switch_opt6),
											GEO_BRANCH(1, electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1_Capless_Switch_opt0_Eye_State_Switch_opt7),
										GEO_CLOSE_NODE(),
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
								GEO_TRANSLATE_ROTATE(LAYER_FORCE, 142, -51, 126, -15, 33, -133),
								GEO_OPEN_NODE(),
									GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
									GEO_ROTATION_NODE(LAYER_FORCE, 0, 0, 0),
									GEO_OPEN_NODE(),
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
								GEO_TRANSLATE_ROTATE(LAYER_FORCE, 142, -51, -126, 15, -33, -133),
								GEO_OPEN_NODE(),
									GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
									GEO_ROTATION_NODE(LAYER_FORCE, 0, 0, 0),
									GEO_OPEN_NODE(),
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 67, -10, 79, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, electric_mario_Left_Arm_Color_mesh_layer_1),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_TRANSPARENT, 65, 0, 0, electric_mario_Left_Forearm_mesh_layer_1),
								GEO_OPEN_NODE(),
									GEO_SWITCH_CASE(1, geo_switch_mario_hand),
									GEO_OPEN_NODE(),
										GEO_NODE_START(),
										GEO_OPEN_NODE(),
											GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
											GEO_OPEN_NODE(),
												GEO_ASM(1, geo_mario_hand_foot_scaler),
												GEO_SCALE(LAYER_FORCE, 65536),
												GEO_OPEN_NODE(),
													GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_mario_Left_Hand_DL_mesh_layer_1),
												GEO_CLOSE_NODE(),
											GEO_CLOSE_NODE(),
										GEO_CLOSE_NODE(),
										GEO_BRANCH(1, electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1_jump_electric_mario_Left_Hand_Open),
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 68, -10, -79, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, electric_mario_Right_Arm_Color_mesh_layer_1),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_TRANSPARENT, 65, 0, 0, electric_mario_Right_Forearm_mesh_layer_1),
								GEO_OPEN_NODE(),
									GEO_SWITCH_CASE(0, geo_switch_mario_hand),
									GEO_OPEN_NODE(),
										GEO_NODE_START(),
										GEO_OPEN_NODE(),
											GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
											GEO_OPEN_NODE(),
												GEO_ASM(0, geo_mario_hand_foot_scaler),
												GEO_SCALE(LAYER_FORCE, 65536),
												GEO_OPEN_NODE(),
													GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_mario_Right_Hand_DL_mesh_layer_1),
												GEO_CLOSE_NODE(),
												GEO_HELD_OBJECT(0, 0, 0, 0, geo_switch_mario_hand_grab_pos),
											GEO_CLOSE_NODE(),
										GEO_CLOSE_NODE(),
										GEO_BRANCH(1, electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1_jump_electric_mario_Right_Hand_Open),
										GEO_BRANCH(1, electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1_jump_electric_mario_Right_Hand_Peace),
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 13, -8, 42, NULL),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, electric_mario_Left_Thigh_Color_mesh_layer_1),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_TRANSPARENT, 89, 0, 0, electric_mario_Left_Leg_mesh_layer_1),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_TRANSPARENT, 67, 0, 0, electric_mario_Left_Shoe_mesh_layer_1),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 13, -8, -42, NULL),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, electric_mario_Right_Thigh_Color_mesh_layer_1),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_TRANSPARENT, 89, 0, 0, electric_mario_Right_Leg_mesh_layer_1),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 67, 0, 0, NULL),
							GEO_OPEN_NODE(),
								GEO_ASM(2, geo_mario_hand_foot_scaler),
								GEO_SCALE(LAYER_FORCE, 65536),
								GEO_OPEN_NODE(),
									GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_mario_Right_Shoe_DL_mesh_layer_1),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt0_Capless_Switch_opt0_Eye_State_Switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, electric_mario_Head_DL_mesh_layer_1_mat_override_Half_Closed_Eyes__SKIN__0),
		GEO_DISPLAY_LIST(LAYER_ALPHA, electric_mario_Head_DL_mesh_layer_4_mat_override_Half_Closed_Eyes__SKIN__0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt0_Capless_Switch_opt0_Eye_State_Switch_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, electric_mario_Head_DL_mesh_layer_1_mat_override_Closed_Eyes__SKIN__1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, electric_mario_Head_DL_mesh_layer_4_mat_override_Closed_Eyes__SKIN__1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt0_Capless_Switch_opt0_Eye_State_Switch_opt3[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, electric_mario_Head_DL_mesh_layer_1_mat_override_Left_Eyes__SKIN__2),
		GEO_DISPLAY_LIST(LAYER_ALPHA, electric_mario_Head_DL_mesh_layer_4_mat_override_Left_Eyes__SKIN__2),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt0_Capless_Switch_opt0_Eye_State_Switch_opt4[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, electric_mario_Head_DL_mesh_layer_1_mat_override_Right_Eyes__SKIN__3),
		GEO_DISPLAY_LIST(LAYER_ALPHA, electric_mario_Head_DL_mesh_layer_4_mat_override_Right_Eyes__SKIN__3),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt0_Capless_Switch_opt0_Eye_State_Switch_opt5[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, electric_mario_Head_DL_mesh_layer_1_mat_override_Up_Eyes__SKIN__4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, electric_mario_Head_DL_mesh_layer_4_mat_override_Up_Eyes__SKIN__4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt0_Capless_Switch_opt0_Eye_State_Switch_opt6[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, electric_mario_Head_DL_mesh_layer_1_mat_override_Down_Eyes__SKIN__5),
		GEO_DISPLAY_LIST(LAYER_ALPHA, electric_mario_Head_DL_mesh_layer_4_mat_override_Down_Eyes__SKIN__5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt0_Capless_Switch_opt0_Eye_State_Switch_opt7[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, electric_mario_Head_DL_mesh_layer_1_mat_override_Dead_Eyes__SKIN__6),
		GEO_DISPLAY_LIST(LAYER_ALPHA, electric_mario_Head_DL_mesh_layer_4_mat_override_Dead_Eyes__SKIN__6),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout electric_mario_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(99, 180, 100),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_FORCE, 16384),
			GEO_OPEN_NODE(),
				GEO_ASM(0, geo_mario_set_player_colors),
				GEO_ASM(0, geo_mirror_mario_backface_culling),
				GEO_ASM(0, geo_mirror_mario_set_alpha),
				GEO_SWITCH_CASE(0, geo_switch_mario_stand_run),
				GEO_OPEN_NODE(),
					GEO_NODE_START(),
					GEO_OPEN_NODE(),
						GEO_SWITCH_CASE(0, geo_switch_mario_cap_effect),
						GEO_OPEN_NODE(),
							GEO_NODE_START(),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
								GEO_OPEN_NODE(),
									GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, electric_mario_Butt_mesh_layer_1),
									GEO_OPEN_NODE(),
										GEO_ASM(0, geo_move_mario_part_from_parent),
										GEO_ASM(0, geo_mario_tilt_torso),
										GEO_ROTATION_NODE(LAYER_FORCE, 0, 0, 0),
										GEO_OPEN_NODE(),
											GEO_ANIMATED_PART(LAYER_OPAQUE, 68, 0, 0, electric_mario_Torso_mesh_layer_1),
											GEO_OPEN_NODE(),
												GEO_ANIMATED_PART(LAYER_OPAQUE, 87, 0, 0, NULL),
												GEO_OPEN_NODE(),
													GEO_ASM(0, geo_mario_head_rotation),
													GEO_ROTATION_NODE(LAYER_FORCE, 0, 0, 0),
													GEO_OPEN_NODE(),
														GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
														GEO_OPEN_NODE(),
															GEO_NODE_START(),
															GEO_OPEN_NODE(),
																GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
																GEO_OPEN_NODE(),
																	GEO_NODE_START(),
																	GEO_OPEN_NODE(),
																		GEO_DISPLAY_LIST(LAYER_OPAQUE, electric_mario_Head_DL_mesh_layer_1),
																		GEO_DISPLAY_LIST(LAYER_ALPHA, electric_mario_Head_DL_mesh_layer_4),
																	GEO_CLOSE_NODE(),
																	GEO_BRANCH(1, electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt0_Capless_Switch_opt0_Eye_State_Switch_opt1),
																	GEO_BRANCH(1, electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt0_Capless_Switch_opt0_Eye_State_Switch_opt2),
																	GEO_BRANCH(1, electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt0_Capless_Switch_opt0_Eye_State_Switch_opt3),
																	GEO_BRANCH(1, electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt0_Capless_Switch_opt0_Eye_State_Switch_opt4),
																	GEO_BRANCH(1, electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt0_Capless_Switch_opt0_Eye_State_Switch_opt5),
																	GEO_BRANCH(1, electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt0_Capless_Switch_opt0_Eye_State_Switch_opt6),
																	GEO_BRANCH(1, electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt0_Capless_Switch_opt0_Eye_State_Switch_opt7),
																GEO_CLOSE_NODE(),
															GEO_CLOSE_NODE(),
														GEO_CLOSE_NODE(),
														GEO_TRANSLATE_ROTATE(LAYER_FORCE, 142, -51, 126, -15, 33, -133),
														GEO_OPEN_NODE(),
															GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
															GEO_ROTATION_NODE(LAYER_FORCE, 0, 0, 0),
															GEO_OPEN_NODE(),
															GEO_CLOSE_NODE(),
														GEO_CLOSE_NODE(),
														GEO_TRANSLATE_ROTATE(LAYER_FORCE, 142, -51, -126, 15, -33, -133),
														GEO_OPEN_NODE(),
															GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
															GEO_ROTATION_NODE(LAYER_FORCE, 0, 0, 0),
															GEO_OPEN_NODE(),
															GEO_CLOSE_NODE(),
														GEO_CLOSE_NODE(),
													GEO_CLOSE_NODE(),
												GEO_CLOSE_NODE(),
												GEO_ANIMATED_PART(LAYER_OPAQUE, 67, -10, 79, NULL),
												GEO_OPEN_NODE(),
													GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, electric_mario_Left_Arm_Color_mesh_layer_1),
													GEO_OPEN_NODE(),
														GEO_ANIMATED_PART(LAYER_OPAQUE, 65, 0, 0, electric_mario_Left_Forearm_mesh_layer_1),
														GEO_OPEN_NODE(),
															GEO_SWITCH_CASE(1, geo_switch_mario_hand),
															GEO_OPEN_NODE(),
																GEO_NODE_START(),
																GEO_OPEN_NODE(),
																	GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
																	GEO_OPEN_NODE(),
																		GEO_ASM(1, geo_mario_hand_foot_scaler),
																		GEO_SCALE(LAYER_FORCE, 65536),
																		GEO_OPEN_NODE(),
																			GEO_DISPLAY_LIST(LAYER_OPAQUE, electric_mario_Left_Hand_DL_mesh_layer_1),
																		GEO_CLOSE_NODE(),
																	GEO_CLOSE_NODE(),
																GEO_CLOSE_NODE(),
																GEO_BRANCH(1, electric_mario_Left_Hand_Open),
															GEO_CLOSE_NODE(),
														GEO_CLOSE_NODE(),
													GEO_CLOSE_NODE(),
												GEO_CLOSE_NODE(),
												GEO_ANIMATED_PART(LAYER_OPAQUE, 68, -10, -79, NULL),
												GEO_OPEN_NODE(),
													GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, electric_mario_Right_Arm_Color_mesh_layer_1),
													GEO_OPEN_NODE(),
														GEO_ANIMATED_PART(LAYER_OPAQUE, 65, 0, 0, electric_mario_Right_Forearm_mesh_layer_1),
														GEO_OPEN_NODE(),
															GEO_SWITCH_CASE(0, geo_switch_mario_hand),
															GEO_OPEN_NODE(),
																GEO_NODE_START(),
																GEO_OPEN_NODE(),
																	GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
																	GEO_OPEN_NODE(),
																		GEO_ASM(0, geo_mario_hand_foot_scaler),
																		GEO_SCALE(LAYER_FORCE, 65536),
																		GEO_OPEN_NODE(),
																			GEO_DISPLAY_LIST(LAYER_OPAQUE, electric_mario_Right_Hand_DL_mesh_layer_1),
																		GEO_CLOSE_NODE(),
																		GEO_HELD_OBJECT(0, 0, 0, 0, geo_switch_mario_hand_grab_pos),
																	GEO_CLOSE_NODE(),
																GEO_CLOSE_NODE(),
																GEO_BRANCH(1, electric_mario_Right_Hand_Open),
																GEO_BRANCH(1, electric_mario_Right_Hand_Peace),
															GEO_CLOSE_NODE(),
														GEO_CLOSE_NODE(),
													GEO_CLOSE_NODE(),
												GEO_CLOSE_NODE(),
											GEO_CLOSE_NODE(),
										GEO_CLOSE_NODE(),
										GEO_ANIMATED_PART(LAYER_OPAQUE, 13, -8, 42, NULL),
										GEO_OPEN_NODE(),
											GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, electric_mario_Left_Thigh_Color_mesh_layer_1),
											GEO_OPEN_NODE(),
												GEO_ANIMATED_PART(LAYER_OPAQUE, 89, 0, 0, electric_mario_Left_Leg_mesh_layer_1),
												GEO_OPEN_NODE(),
													GEO_ANIMATED_PART(LAYER_OPAQUE, 67, 0, 0, electric_mario_Left_Shoe_mesh_layer_1),
												GEO_CLOSE_NODE(),
											GEO_CLOSE_NODE(),
										GEO_CLOSE_NODE(),
										GEO_ANIMATED_PART(LAYER_OPAQUE, 13, -8, -42, NULL),
										GEO_OPEN_NODE(),
											GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, electric_mario_Right_Thigh_Color_mesh_layer_1),
											GEO_OPEN_NODE(),
												GEO_ANIMATED_PART(LAYER_OPAQUE, 89, 0, 0, electric_mario_Right_Leg_mesh_layer_1),
												GEO_OPEN_NODE(),
													GEO_ANIMATED_PART(LAYER_OPAQUE, 67, 0, 0, NULL),
													GEO_OPEN_NODE(),
														GEO_ASM(2, geo_mario_hand_foot_scaler),
														GEO_SCALE(LAYER_FORCE, 65536),
														GEO_OPEN_NODE(),
															GEO_DISPLAY_LIST(LAYER_OPAQUE, electric_mario_Right_Shoe_DL_mesh_layer_1),
														GEO_CLOSE_NODE(),
													GEO_CLOSE_NODE(),
												GEO_CLOSE_NODE(),
											GEO_CLOSE_NODE(),
										GEO_CLOSE_NODE(),
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
							GEO_BRANCH(1, electric_mario_2_LoD_Switch_opt0_Cap_State_Switch_opt1),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_ASM(1, geo_mirror_mario_backface_culling),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

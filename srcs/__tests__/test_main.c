#include "rt.test.h"

extern t_vec3	COLOR_SAMPLES[4];

void	render_test(int argc, char **argv)
{
	t_env			e;
	t_arg_camera	arg_cam;

	(void)argc;
	init_env(&e);
	e.width /= 2;
	e.height /= 2;
	arg_cam.pos = (t_vec3){0.0, 0.0, -5.0};
	arg_cam.dir = (t_vec3){0.0, 0.0, 1.0};
	arg_cam.right = (t_vec3){1.0, 0.0, 0.0};
	set_camera(&arg_cam, &e.cam);
	set_ray_grid_props(&e);
	setup_object(argv[1], argv[3], e.ll_obj);
	e.num_objs = 1;
	if (*(argv[2]) == 'i')
		render_intersect_test(e.img_buf, &e, e.ll_obj);
	else if (*(argv[2]) == 'n')
		render_normal_test(e.img_buf, &e, e.ll_obj, argv[4]);
	else if (*(argv[2]) == 't')
		render_texture_mapping_test(
			e.img_buf, &e, e.ll_obj, argv[4], argv[5]);
	else if (*(argv[2]) == 'b')
		render_bump_mapping_test(
			e.img_buf, &e, e.ll_obj, argv[4], argv[5], argv[6]);
	render_by_sdl(&e);
	run_event_loop(&e, NULL, NULL);
}

int		main(int argc, char **argv)
{
	COLOR_SAMPLES[0] = GRAY;
	COLOR_SAMPLES[1] = BLUE;
	COLOR_SAMPLES[2] = RED;
	COLOR_SAMPLES[3] = BROWN;
	if (argc == 1)
	{
		UNITY_BEGIN();
		test_set_object();
		RUN_TEST_GROUP(translate);
		RUN_TEST_GROUP(set_distant_light);
		RUN_TEST_GROUP(set_spherical_light);
		RUN_TEST_GROUP(distant_light);
		RUN_TEST_GROUP(spherical_light);
		RUN_TEST_GROUP(set_trace_record);
		RUN_TEST_GROUP(round_n_dot_l);
		RUN_TEST_GROUP(set_texels);
		RUN_TEST_GROUP(set_camera);
		RUN_TEST_GROUP(set_ambient);
		UNITY_END();
		return (0);
	}
	if (ft_strcmp(argv[1], "scene") == 0)
		render_scene(argv[2], argc, argv);
	else if (argc >= 4)
		render_test(argc, argv);
	return (0);
}

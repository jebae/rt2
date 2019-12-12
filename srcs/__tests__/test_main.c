#include "rt.test.h"

extern t_vec3	COLOR_SAMPLES[4];

void	render_test(int argc, char **argv)
{
	t_mlxkit	mlxkit;
	t_env		e;

	init_mlxkit(&mlxkit, &e);
	e.width /= 2;
	e.height /= 2;
	setup_object(argv[1], argv[3], e.ll_obj);
	e.num_objs = 1;
	if (*(argv[2]) == 'i')
		render_intersect_test(mlxkit.img_buf, &e, e.ll_obj);
	else if (*(argv[2]) == 'n')
		render_normal_test(mlxkit.img_buf, &e, e.ll_obj, argv[4]);
	else if (*(argv[2]) == 't')
		render_texture_mapping_test(
			mlxkit.img_buf, &e, e.ll_obj, argv[4], argv[5]);
	else if (*(argv[2]) == 'b')
		render_bump_mapping_test(
			mlxkit.img_buf, &e, e.ll_obj, argv[4], argv[5], argv[6]);
	set_filter(argv[argc - 1], mlxkit.img_buf, e.width / 2, e.height / 2);
	mlx_put_image_to_window(mlxkit.p_mlx, mlxkit.p_win, mlxkit.p_img, 0, 0);
	mlx_loop(mlxkit.p_mlx);
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
		UNITY_END();
		return (0);
	}
	if (ft_strcmp(argv[1], "scene") == 0)
		render_scene(atoi(argv[2]), argc, argv);
	else if (argc >= 4)
		render_test(argc, argv);
	return (0);
}

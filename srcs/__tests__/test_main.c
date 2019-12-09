#include "rt.test.h"

static t_mlxkit		mlxkit;
static t_camera		cam;
static t_ol			ol;

extern t_vec3	COLOR_SAMPLES[4];

void	render_test(int argc, char **argv)
{
	int		res;

	(void)argc;
	init_ol(&ol);
	res = setup_object(argv[1], argv[3], &ol);
	if (res == RT_FAIL)
		return ;
	setup_scene(&mlxkit, &cam);
	if (*(argv[2]) == 'i')
		render_intersect_test(mlxkit.img_buf, &cam, &ol);
	else if (*(argv[2]) == 'n')
		render_normal_test(mlxkit.img_buf, &cam, &ol, argv[4]);
	else if (*(argv[2]) == 't')
		render_texture_mapping_test(
			mlxkit.img_buf, &cam, &ol, argv[4], argv[5]);
	else if (*(argv[2]) == 'b')
		render_bump_mapping_test(
			mlxkit.img_buf, &cam, &ol, argv[4], argv[5], argv[6]);
	set_filter(argv[argc - 1], mlxkit.img_buf, WIDTH, WIDTH);
	mlx_put_image_to_window(mlxkit.p_mlx, mlxkit.p_win, mlxkit.p_img, 0, 0);
	if (ol.texture.buffer)
		free(ol.texture.buffer);
	if (ol.bump_map.buffer)
		free(ol.bump_map.buffer);
	ft_memdel((void **)&ol.object);
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

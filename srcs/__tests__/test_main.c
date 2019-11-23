#include "rt.test.h"

static t_mlxkit		mlxkit;
static t_camera		cam;
static t_ol			ol;

void	render_test(char **argv)
{
	int		res;

	res = setup_object(argv[1], argv[3], &ol);
	if (res == RT_FAIL)
		return ;
	setup_scene(&mlxkit, &cam);
	if (*(argv[2]) == 'i')
		render_intersect_test(&mlxkit, &cam, &ol);
	else if (*(argv[2]) == 'n')
		render_normal_test(&mlxkit, &cam, &ol);
	else if (*(argv[2]) == 't')
		render_texture_mapping_test(
			&mlxkit, &cam, &ol, argv[4], argv[5]);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		UNITY_BEGIN();
		test_set_object();
		UNITY_END();
		return (0);
	}
	if (argc >= 4)
		render_test(argv);
	return (0);
}

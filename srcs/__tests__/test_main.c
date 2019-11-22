#include "rt.test.h"

static t_mlxkit		mlxkit;
static t_camera		cam;
static t_ol			ol;

void	render_test(
	const char *obj,
	const char *func,
	const char *case_num,
	const char *extra
)
{
	int		res;

	res = setup_object(obj, case_num, &ol);
	if (res == RT_FAIL)
		return ;
	setup_scene(&mlxkit, &cam);
	if (*func == 'i')
		render_intersect_test(&mlxkit, &cam, &ol);
	else if (*func == 'n')
		render_normal_test(&mlxkit, &cam, &ol);
	else if (*func == 't')
		render_texture_mapping_test(&mlxkit, &cam, &ol, extra);
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
		render_test(argv[1], argv[2], argv[3], (argc >= 5) ? argv[4] : NULL);
	return (0);
}

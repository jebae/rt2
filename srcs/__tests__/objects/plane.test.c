#include "rt.test.h"

static void	plane_case1(t_ol *ol)
{
	t_vec3		normal;
	double		d;

	ol->intersect = &v_intersect_pl;
	ol->get_normal = &normal_plane;
    ol->object = ft_memalloc(sizeof(t_plane));
    normal = (t_vec3){0.0, 1.0, 0.0};
	d = -2;

	test(
		set_plane(ol, normal, d) == RT_SUCCESS,
		"set_plane : return value"
	);
}

void		test_plane_intersect_case1(void)
{
	t_mlxkit	mlxkit;
	t_camera	cam;
	t_ol		ol;

	init_mlxkit(&mlxkit);
	cam.campos = (t_vec3){0.0, 0.0, -1.0};
	cam.camdir = (t_vec3){0.0, 0.0, 1.0};
	cam.left = (t_vec3){-1.0, 0.0, 0.0};
	cam.up = (t_vec3){0.0, 1.0, 0.0};
	cam.forw = (t_vec3){0.0, 0.0, 1.0};
	cam.focal_length = 1.0;
	cam.f_wdth = WIDTH / 384;
	cam.f_hght = WIDTH / 384;

	plane_case1(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void		test_plane_normal_case1(void)
{
	t_mlxkit	mlxkit;
	t_camera	cam;
	t_ol		ol;

	init_mlxkit(&mlxkit);
	cam.campos = (t_vec3){0.0, 5.0, -1.0};
	cam.camdir = (t_vec3){0.0, 0.0, 1.0};
	cam.left = (t_vec3){-1.0, 0.0, 0.0};
	cam.up = (t_vec3){0.0, 1.0, 0.0};
	cam.forw = (t_vec3){0.0, 0.0, 1.0};
	cam.focal_length = 1.0;
	cam.f_wdth = WIDTH / 384;
	cam.f_hght = WIDTH / 384;

	plane_case1(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}

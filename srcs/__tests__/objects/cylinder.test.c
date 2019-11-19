#include "rt.test.h"

static void	cylinder_case1(t_ol *ol)
{
	t_cyl		*cyl;
	t_arg_cyl	arg;

	ol->intersect = &v_intersect_cy;
	ol->get_normal = &normal_cylinder;
    ol->object = ft_memalloc(sizeof(t_cyl));
	cyl = (t_cyl *)ol->object;
    arg.cen = (t_vec3){0.0, -1.0, 10.0};
    arg.axis = (t_vec3){1.0, 1.0, 0.0};
	arg.radius = 1;
	set_cyl(cyl, &arg);
}

void		test_cylinder_intersect_case1(void)
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

	cylinder_case1(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void		test_cylinder_normal_case1(void)
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

	cylinder_case1(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}

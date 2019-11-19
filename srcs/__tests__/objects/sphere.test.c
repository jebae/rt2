#include "rt.test.h"

static void	sphere_case1(t_ol *ol)
{
	t_sphere	*sphere;
	t_vec3		center;
	double		radius;

    ol->intersect = &v_intersect_sp2;
    ol->get_normal = &normal_sphere;
    ol->object = ft_memalloc(sizeof(t_sphere));
	sphere = (t_sphere *)ol->object;
    center = (t_vec3){0.0, 0.0, 2.0};
    radius = 1.0;
	set_sphere(sphere, center, radius);
}

void		test_sphere_intersect_case1(void)
{
	t_mlxkit	mlxkit;
	t_camera	cam;
	t_ol		ol;

	init_mlxkit(&mlxkit);
	cam.campos = (t_vec3){0.0, 0.0, -1.0};
	cam.camdir = (t_vec3){0.0, 0.0, 1.0};
	cam.left = (t_vec3){1.0, 0.0, 0.0};
	cam.up = (t_vec3){0.0, 1.0, 0.0};
	cam.forw = (t_vec3){0.0, 0.0, 1.0};
	cam.focal_length = 1.0;
	cam.f_wdth = WIDTH / 384;
	cam.f_hght = WIDTH / 384;

	sphere_case1(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void		test_sphere_normal_case1(void)
{
	t_mlxkit	mlxkit;
	t_camera	cam;
	t_ol		ol;

	init_mlxkit(&mlxkit);
	cam.campos = (t_vec3){0.0, 0.0, -1.0};
	cam.camdir = (t_vec3){0.0, 0.0, 1.0};
	cam.left = (t_vec3){-1.0, 0.0, 0.0};
	cam.up = (t_vec3){0.0, -1.0, 0.0};
	cam.forw = (t_vec3){0.0, 0.0, 1.0};
	cam.focal_length = 1.0;
	cam.f_wdth = WIDTH / 384;
	cam.f_hght = WIDTH / 384;

	sphere_case1(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}

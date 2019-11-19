#include "rt.test.h"

static void	box_case1(t_ol *ol)
{
	t_box		*box;
	t_vec3		a;
	t_vec3		b;
	t_vec3		c;

	ol->intersect = &v_intersect_box;
	ol->get_normal = &normal_box;
    ol->object = ft_memalloc(sizeof(t_box));
	box = ol->object;
	box->vmin = (t_vec3){-1.0, 1.0, 1.0};
	box->vmax = (t_vec3){2.0, 0.5, 1.0};
	a = (t_vec3){1.0, 0.0, 1.0};
	a = v3_normalise(a);
	b = (t_vec3){0.0, 1.0, 0.0};
	b = v3_normalise(b);
	c = v3_cross(a, b);
	c = v3_normalise(c);
	ft_memcpy(&box->mat.arr[0], &a, sizeof(t_vec3));
	ft_memcpy(&box->mat.arr[1], &b, sizeof(t_vec3));
	ft_memcpy(&box->mat.arr[2], &c, sizeof(t_vec3));
}

void		test_box_intersect_case1(void)
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

	box_case1(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void		test_box_normal_case1(void)
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

	box_case1(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}

static void	box_case2(t_ol *ol)
{
	t_box		*box;
	t_vec3		a;
	t_vec3		b;
	t_vec3		c;

	ol->intersect = &v_intersect_box;
	ol->get_normal = &normal_box;
    ol->object = ft_memalloc(sizeof(t_box));
	box = ol->object;
	box->vmin = (t_vec3){-1.0, 1.0, 1.0};
	box->vmax = (t_vec3){2.0, 0.5, 1.0};
	a = (t_vec3){1.0, -0.3, 1.0};
	a = v3_normalise(a);
	b = (t_vec3){0.0, 1.0, 0.3};
	b = v3_normalise(b);
	c = v3_cross(a, b);
	c = v3_normalise(c);
	ft_memcpy(&box->mat.arr[0], &a, sizeof(t_vec3));
	ft_memcpy(&box->mat.arr[1], &b, sizeof(t_vec3));
	ft_memcpy(&box->mat.arr[2], &c, sizeof(t_vec3));
}

void		test_box_intersect_case2(void)
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

	box_case2(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void		test_box_normal_case2(void)
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

	box_case2(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}

static void	box_case3(t_ol *ol)
{
	t_box		*box;
	t_vec3		a;
	t_vec3		b;
	t_vec3		c;

	ol->intersect = &v_intersect_box;
	ol->get_normal = &normal_box;
    ol->object = ft_memalloc(sizeof(t_box));
	box = ol->object;
	box->vmin = (t_vec3){-1.0, 1.0, 5.0};
	box->vmax = (t_vec3){2.0, 2.0, 1.0};
	a = (t_vec3){1.0, 0.0, 0.0};
	a = v3_normalise(a);
	b = (t_vec3){0.0, -1.0, 0.0};
	b = v3_normalise(b);
	c = v3_cross(a, b);
	c = v3_normalise(c);
	ft_memcpy(&box->mat.arr[0], &a, sizeof(t_vec3));
	ft_memcpy(&box->mat.arr[1], &b, sizeof(t_vec3));
	ft_memcpy(&box->mat.arr[2], &c, sizeof(t_vec3));
}

void		test_box_intersect_case3(void)
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

	box_case3(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void		test_box_normal_case3(void)
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

	box_case3(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}

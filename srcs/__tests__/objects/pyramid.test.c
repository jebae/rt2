#include "rt.test.h"

static void		set_pyramid_sides(
	t_vec3 a,
	t_vec3 u,
	t_vec3 v,
	double h,
	t_pyramid *pyramid
)
{
	t_vec3			center;
	t_vec3			top;
	t_triangle		*sides;

	sides = pyramid->sides;
	center = v3_add(a, v3_scalar(v3_add(u, v), 0.5));
	top = v3_add(center, v3_scalar(v3_normalise(v3_cross(u, v)), h));

	sides[0].a = a;
	sides[0].ab = u;
	sides[0].ac = v3_sub(top, a);

	sides[1].a = v3_add(a, u);
	sides[1].ab = v;
	sides[1].ac = v3_sub(top, sides[1].a);

	sides[2].a = a;
	sides[2].ab = v;
	sides[2].ac = sides[0].ac;

	sides[3].a = v3_add(a, v);
	sides[3].ab = u;
	sides[3].ac = v3_sub(top, sides[3].a);

	for (int i=0; i < 4; i++)
	{
		sides[i].normal = v3_cross(sides[i].ab, sides[i].ac);
		sides[i].normal = v3_normalise(sides[i].normal);
	}

	pyramid->u = v3_normalise(u);
	pyramid->v = v3_normalise(v);
	pyramid->norm_u = v3_norm(u);
	pyramid->norm_v = v3_norm(v);
}

static void		pyramid_case1(t_ol *ol)
{
	t_pyramid		*pyramid;
	double			h;
	t_vec3			a;
	t_vec3			u;
	t_vec3			v;

	ol->intersect = &v_intersect_pyramid;
	ol->get_normal = &normal_pyramid;
    ol->object = ft_memalloc(sizeof(t_pyramid));
	pyramid = (t_pyramid *)ol->object;
	a = (t_vec3){-0.5, 0.5, 0.7};
	u = (t_vec3){1.0, -0.5, 1.0};
	v = (t_vec3){-1.0, 0.0, 1.0};
	h = 1.0;
	set_pyramid_sides(a, u, v, h, pyramid);
}

void			test_pyramid_intersect_case1(void)
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

	pyramid_case1(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void			test_pyramid_normal_case1(void)
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

	pyramid_case1(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}

static void		pyramid_case2(t_ol *ol)
{
	t_pyramid		*pyramid;
	double			h;
	t_vec3			a;
	t_vec3			u;
	t_vec3			v;

	ol->intersect = &v_intersect_pyramid;
	ol->get_normal = &normal_pyramid;
    ol->object = ft_memalloc(sizeof(t_pyramid));
	pyramid = (t_pyramid *)ol->object;
	a = (t_vec3){-0.5, 1.5, 0.7};
	u = (t_vec3){1.0, 0.0, 0.0};
	v = (t_vec3){0.0, -0.3, 0.5};
	h = 1.0;
	set_pyramid_sides(a, u, v, h, pyramid);
}

void			test_pyramid_intersect_case2(void)
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

	pyramid_case2(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void			test_pyramid_normal_case2(void)
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

	pyramid_case2(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}

static void		pyramid_case3(t_ol *ol)
{
	t_pyramid		*pyramid;
	double			h;
	t_vec3			a;
	t_vec3			u;
	t_vec3			v;

	ol->intersect = &v_intersect_pyramid;
	ol->get_normal = &normal_pyramid;
    ol->object = ft_memalloc(sizeof(t_pyramid));
	pyramid = (t_pyramid *)ol->object;
	a = (t_vec3){-0.5, 1.0, 1.5};
	u = (t_vec3){1.0, 0.0, 0.0};
	v = (t_vec3){0.0, -1.0, 0.0};
	h = 1.0;
	set_pyramid_sides(a, u, v, h, pyramid);
}

void			test_pyramid_intersect_case3(void)
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

	pyramid_case3(&ol);
	render_intersect_test(&mlxkit, &cam, &ol);
}

void			test_pyramid_normal_case3(void)
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

	pyramid_case3(&ol);
	render_normal_test(&mlxkit, &cam, &ol);
}

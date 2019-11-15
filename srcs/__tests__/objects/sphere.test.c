#include "rt.test.h"

void		test_sphere_intersect_case1(void)
{
	t_mlxkit	mlxkit;
	t_camera	cam;
	t_ray		ray;
	t_ol		ol;
    t_sphere    *sphere;

	init_mlxkit(&mlxkit);
	cam.campos = (t_vec3){0.0, 0.0, -1.0};
	cam.camdir = (t_vec3){0.0, 0.0, 1.0};
	cam.left = (t_vec3){-1.0, 0.0, 0.0};
	cam.up = (t_vec3){0.0, -1.0, 0.0};
	cam.forw = (t_vec3){0.0, 0.0, 1.0};
	cam.focal_length = 1.0;
	cam.f_wdth = WIDTH / 384;
	cam.f_hght = WIDTH / 384;

    ol.object = ft_memalloc(sizeof(t_sphere));
    sphere = ol.object;
    sphere->cen = (t_vec3){0.0, 0.0, 2.0};
    sphere->radius = 1.0;
    ol.intersect = &v_intersect_sp2;
	for (int i=0; i < WIDTH; i++)
	{
		for (int j=0; j < WIDTH; j++)
		{
			ray = cast_ray(j, i, cam);
			if (ol.intersect(ray, ol.object) != FAR)
				mlxkit.img_buf[j + i * WIDTH] = 0xffffff;
		}
	}
	mlx_put_image_to_window(mlxkit.p_mlx, mlxkit.p_win, mlxkit.p_img, 0, 0);
	mlx_loop(mlxkit.p_mlx);
}

void		test_sphere_normal_case1(void)
{
	t_mlxkit	mlxkit;
	t_camera	cam;
	t_ray		ray;
	t_ol		ol;
    t_sphere    *sphere;
    t_vec3      n;
    double      n_dot_l;

	init_mlxkit(&mlxkit);
	cam.campos = (t_vec3){0.0, 0.0, -1.0};
	cam.camdir = (t_vec3){0.0, 0.0, 1.0};
	cam.left = (t_vec3){-1.0, 0.0, 0.0};
	cam.up = (t_vec3){0.0, -1.0, 0.0};
	cam.forw = (t_vec3){0.0, 0.0, 1.0};
	cam.focal_length = 1.0;
	cam.f_wdth = WIDTH / 384;
	cam.f_hght = WIDTH / 384;

    ol.object = ft_memalloc(sizeof(t_sphere));
    sphere = ol.object;
    sphere->cen = (t_vec3){0.0, 0.0, 2.0};
    sphere->radius = 1.0;
    ol.intersect = &v_intersect_sp2;
    ol.get_normal = &normal_sphere;
	for (int i=0; i < WIDTH; i++)
	{
		for (int j=0; j < WIDTH; j++)
		{
			ray = cast_ray(j, i, cam);
			if ((ray.t = ol.intersect(ray, ol.object)) == FAR)
				continue ;
			n = ol.get_normal(ray, ol.object);
			n_dot_l = v_scal(v_mult(ray.dir, -1.0), n);
			mlxkit.img_buf[j + i * WIDTH] = 0x0000ff * MAX(0.0, n_dot_l);
		}
	}
	mlx_put_image_to_window(mlxkit.p_mlx, mlxkit.p_win, mlxkit.p_img, 0, 0);
	mlx_loop(mlxkit.p_mlx);
}

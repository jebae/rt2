#include "rt.test.h"

// void		test_rectangle_intersect_case1(void)
// {
// 	t_mlxkit	mlxkit;
// 	t_camera	cam;
// 	t_ray		ray;
// 	t_ol		ol;

// 	init_mlxkit(&mlxkit);
// 	cam.campos = (t_vec3){0.0, 0.0, -1.0};
// 	cam.camdir = (t_vec3){0.0, 0.0, 1.0};
// 	cam.left = (t_vec3){-1.0, 0.0, 0.0};
// 	cam.up = (t_vec3){0.0, -1.0, 0.0};
// 	cam.forw = (t_vec3){0.0, 0.0, 1.0};
// 	cam.focal_length = 1.0;
// 	cam.f_wdth = WIDTH / 384;
// 	cam.f_hght = WIDTH / 384;

// 	ol.rectangle.p = (t_vec3){-1.0, 1.0, 1.0};
// 	ol.rectangle.a = (t_vec3){1.0, 0.0, 0.0};
// 	ol.rectangle.b = (t_vec3){0.0, 0.0, 1.0};
// 	ol.rectangle.norm_a = 2.0;
// 	ol.rectangle.norm_b = 2.0;
// 	ol.nor = v_cross(ol.rectangle.a, ol.rectangle.b);
// 	ol.nor = v_normalise(ol.nor);
// 	ol.d = -v_scal(ol.rectangle.p, ol.nor);

// 	for (int i=0; i < WIDTH; i++)
// 	{
// 		for (int j=0; j < WIDTH; j++)
// 		{
// 			ray = cast_ray(j, i, cam);
// 			if (v_intersect_rectangle(ray, &ol) != FAR)
// 				mlxkit.img_buf[j + i * WIDTH] = 0xffffff;
// 		}
// 	}
// 	mlx_put_image_to_window(mlxkit.p_mlx, mlxkit.p_win, mlxkit.p_img, 0, 0);
// 	mlx_loop(mlxkit.p_mlx);
// }

// void		test_rectangle_normal_case1(void)
// {
// 	t_mlxkit	mlxkit;
// 	t_camera	cam;
// 	t_ray		ray;
// 	t_ol		ol;
// 	t_vec3		n;
// 	double		n_dot_l;

// 	init_mlxkit(&mlxkit);
// 	cam.campos = (t_vec3){0.0, 0.0, -1.0};
// 	cam.camdir = (t_vec3){0.0, 0.0, 1.0};
// 	cam.left = (t_vec3){-1.0, 0.0, 0.0};
// 	cam.up = (t_vec3){0.0, -1.0, 0.0};
// 	cam.forw = (t_vec3){0.0, 0.0, 1.0};
// 	cam.focal_length = 1.0;
// 	cam.f_wdth = WIDTH / 384;
// 	cam.f_hght = WIDTH / 384;

// 	ol.rectangle.p = (t_vec3){-1.0, 1.0, 1.0};
// 	ol.rectangle.a = (t_vec3){1.0, 0.0, 0.0};
// 	ol.rectangle.b = (t_vec3){0.0, 0.0, 1.0};
// 	ol.rectangle.norm_a = 2.0;
// 	ol.rectangle.norm_b = 2.0;
// 	ol.nor = v_cross(ol.rectangle.a, ol.rectangle.b);
// 	ol.nor = v_normalise(ol.nor);
// 	ol.d = -v_scal(ol.rectangle.p, ol.nor);

// 	for (int i=0; i < WIDTH; i++)
// 	{
// 		for (int j=0; j < WIDTH; j++)
// 		{
// 			ray = cast_ray(j, i, cam);
// 			if (v_intersect_rectangle(ray, &ol) == FAR)
// 				continue ;
// 			n = normal_plane(ray, &ol);
// 			n_dot_l = v_scal(v_mult(ray.dir, -1.0), n);
// 			mlxkit.img_buf[j + i * WIDTH] = 0x0000ff * MAX(0.0, n_dot_l);
// 		}
// 	}
// 	mlx_put_image_to_window(mlxkit.p_mlx, mlxkit.p_win, mlxkit.p_img, 0, 0);
// 	mlx_loop(mlxkit.p_mlx);
// }

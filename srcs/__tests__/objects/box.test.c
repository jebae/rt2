#include "rt.test.h"

// void		test_box_intersect_case1(void)
// {
// 	t_mlxkit	mlxkit;
// 	t_camera	cam;
// 	t_ray		ray;
// 	t_ol		ol;
// 	t_vec3		a;
// 	t_vec3		b;
// 	t_vec3		c;

// 	init_mlxkit(&mlxkit);
// 	cam.campos = (t_vec3){0.0, 0.0, -1.0};
// 	cam.camdir = (t_vec3){0.0, 0.0, 1.0};
// 	cam.left = (t_vec3){-1.0, 0.0, 0.0};
// 	cam.up = (t_vec3){0.0, -1.0, 0.0};
// 	cam.forw = (t_vec3){0.0, 0.0, 1.0};
// 	cam.focal_length = 1.0;
// 	cam.f_wdth = WIDTH / 384;
// 	cam.f_hght = WIDTH / 384;

// 	ol.box.vmin = (t_vec3){-1.0, 1.0, 1.0};
// 	ol.box.vmax = (t_vec3){3.0, 1.0, 1.0};
// 	a = (t_vec3){1.0, 0.0, 1.0};
// 	a = v_normalise(a);
// 	b = (t_vec3){0.0, 1.0, 0.0};
// 	b = v_normalise(b);
// 	c = v_cross(a, b);
// 	c = v_normalise(c);
// 	ft_memcpy(&ol.box.mat.arr[0], &a, sizeof(t_vec3));
// 	ft_memcpy(&ol.box.mat.arr[1], &b, sizeof(t_vec3));
// 	ft_memcpy(&ol.box.mat.arr[2], &c, sizeof(t_vec3));
// 	for (int i=0; i < WIDTH; i++)
// 	{
// 		for (int j=0; j < WIDTH; j++)
// 		{
// 			ray = cast_ray(j, i, cam);
// 			if (v_intersect_box(ray, &ol) != FAR)
// 				mlxkit.img_buf[j + i * WIDTH] = 0xffffff;
// 		}
// 	}
// 	mlx_put_image_to_window(mlxkit.p_mlx, mlxkit.p_win, mlxkit.p_img, 0, 0);
// 	mlx_loop(mlxkit.p_mlx);
// }

#include "rt.test.h"

void			setup_scene(t_mlxkit *mlxkit, t_camera *cam)
{
	init_mlxkit(mlxkit);
	cam->campos = (t_vec3){0.0, 0.0, -1.0};
	cam->camdir = (t_vec3){0.0, 0.0, 1.0};
	cam->left = (t_vec3){1.0, 0.0, 0.0};
	cam->up = (t_vec3){0.0, 1.0, 0.0};
	cam->forw = (t_vec3){0.0, 0.0, 1.0};
	cam->focal_length = 1.0;
	cam->f_wdth = WIDTH / 384;
	cam->f_hght = WIDTH / 384;
}

void			render_intersect_test(
	t_mlxkit *mlxkit,
	t_camera *cam,
	t_ol *ol
)
{
	t_ray		ray;

	for (int i=0; i < WIDTH; i++)
	{
		for (int j=0; j < WIDTH; j++)
		{
			ray = cast_ray(j, i, *cam);
			if (ol->intersect(ray, ol->object) != FAR)
				mlxkit->img_buf[j + i * WIDTH] = 0xffffff;
		}
	}
	mlx_put_image_to_window(mlxkit->p_mlx, mlxkit->p_win, mlxkit->p_img, 0, 0);
	ft_memdel((void **)&ol->object);
	mlx_loop(mlxkit->p_mlx);
}

void			render_normal_test(
	t_mlxkit *mlxkit,
	t_camera *cam,
	t_ol *ol
)
{
	t_ray		ray;
	t_vec3		n;
	double		n_dot_l;

	for (int i=0; i < WIDTH; i++)
	{
		for (int j=0; j < WIDTH; j++)
		{
			ray = cast_ray(j, i, *cam);
			if ((ray.t = ol->intersect(ray, ol->object)) == FAR)
				continue ;
			n = ol->get_normal(ray, ol->object);
			n_dot_l = v3_dotpdt(v3_scalar(ray.dir, -1.0), n);
			mlxkit->img_buf[j + i * WIDTH] = 0x0000ff * MAX(0.0, n_dot_l);
		}
	}
	mlx_put_image_to_window(mlxkit->p_mlx, mlxkit->p_win, mlxkit->p_img, 0, 0);
	ft_memdel((void **)&ol->object);
	mlx_loop(mlxkit->p_mlx);
}

void			render_texture_mapping_test(
	t_mlxkit *mlxkit,
	t_camera *cam,
	t_ol *ol,
	const char *texture_file_name,
	const char *repeat
)
{
	double			n_dot_l;
	t_ray			ray;
	t_vec2			uv;
	t_vec3			n;
	t_vec3			point;
	t_texture		*texture;

	texture = &ol->texture;
	set_texture(texture_file_name, repeat, texture);
	for (int i=0; i < WIDTH; i++)
	{
		for (int j=0; j < WIDTH; j++)
		{
			ray = cast_ray(j, i, *cam);
			if ((ray.t = ol->intersect(ray, ol->object)) == FAR)
				continue ;
			n = ol->get_normal(ray, ol->object);
			n_dot_l = v3_dotpdt(v3_scalar(ray.dir, -1.0), n);
			point = find_point_from_ray(ray);

			uv = ol->uv_mapping(point, &ol->axis_mat, texture, ol->object);
			mlxkit->img_buf[j + i * WIDTH] = get_texture_pixel_color(&uv, texture, n_dot_l);
		}
	}
	mlx_put_image_to_window(mlxkit->p_mlx, mlxkit->p_win, mlxkit->p_img, 0, 0);
	free(ol->texture.pixels);
	ft_memdel((void **)&ol->object);
	mlx_loop(mlxkit->p_mlx);
}

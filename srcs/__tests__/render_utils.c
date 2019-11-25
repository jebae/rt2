#include "rt.test.h"

extern t_col	COLOR_SAMPLES[4];

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

static t_col*	select_color(const char *str)
{
	if (strcmp(str, "gray") == 0)
		return (COLOR_SAMPLES);
	else if (strcmp(str, "blue") == 0)
		return (COLOR_SAMPLES + 1);
	else if (strcmp(str, "red") == 0)
		return (COLOR_SAMPLES + 2);
	else if (strcmp(str, "brown") == 0)
		return (COLOR_SAMPLES + 3);
	return (COLOR_SAMPLES);
}

static unsigned int	rgb_to_uint32(t_col *rgb, double n_dot_l)
{
	unsigned int	color;

	n_dot_l = (n_dot_l < 0.0) ? 0.0 : n_dot_l;
	color = rgb->r * n_dot_l;
	color <<= 8;
	color += rgb->g * n_dot_l;
	color <<= 8;
	color += rgb->b * n_dot_l;
	return (color);
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
	t_ol *ol,
	const char *color
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
			mlxkit->img_buf[j + i * WIDTH] = rgb_to_uint32(
				select_color(color), n_dot_l);
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
	const char *filename,
	const char *repeat
)
{
	double			n_dot_l;
	t_ray			ray;
	t_vec2			uv;
	t_vec3			n;
	t_vec3			point;
	t_texels		*texture;
	t_col			texel_color;

	texture = &ol->texture;
	set_texels(filename, repeat, texture);
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
			texel_color = get_texel_color(&uv, texture);
			mlxkit->img_buf[j + i * WIDTH] = rgb_to_uint32(&texel_color, n_dot_l);
		}
	}
	mlx_put_image_to_window(mlxkit->p_mlx, mlxkit->p_win, mlxkit->p_img, 0, 0);
	free(ol->texture.buffer);
	ft_memdel((void **)&ol->object);
	mlx_loop(mlxkit->p_mlx);
}

void			render_bump_mapping_test(
	t_mlxkit *mlxkit,
	t_camera *cam,
	t_ol *ol,
	const char *filename,
	const char *repeat,
	const char *color
)
{
	double			n_dot_l;
	t_ray			ray;
	t_vec2			uv;
	t_vec3			n;
	t_vec3			point;
	t_texels		*bump_map;

	bump_map = &ol->texture;
	set_texels(filename, repeat, bump_map);
	for (int i=0; i < WIDTH; i++)
	{
		for (int j=0; j < WIDTH; j++)
		{
			ray = cast_ray(j, i, *cam);
			if ((ray.t = ol->intersect(ray, ol->object)) == FAR)
				continue ;
			point = find_point_from_ray(ray);
			n = ol->get_normal(ray, ol->object);
			uv = ol->uv_mapping(point, &ol->axis_mat, bump_map, ol->object);
			n = get_bumped_normal(&uv, bump_map, &n, &ol->axis_mat);
			n_dot_l = v3_dotpdt(v3_scalar(ray.dir, -1.0), n);
			mlxkit->img_buf[j + i * WIDTH] = rgb_to_uint32(
				select_color(color), n_dot_l);
		}
	}
	mlx_put_image_to_window(mlxkit->p_mlx, mlxkit->p_win, mlxkit->p_img, 0, 0);
	free(ol->bump_map.buffer);
	ft_memdel((void **)&ol->object);
	mlx_loop(mlxkit->p_mlx);
}

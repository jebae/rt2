#include "rt.test.h"

extern t_vec3	COLOR_SAMPLES[4];

void			setup_scene(
	t_mlxkit *mlxkit,
	t_camera *cam,
	int width,
	int height
)
{
	init_mlxkit(mlxkit);
	cam->campos = (t_vec3){0.0, 0.0, -1.0};
	cam->camdir = (t_vec3){0.0, 0.0, 1.0};
	cam->left = (t_vec3){1.0, 0.0, 0.0};
	cam->up = (t_vec3){0.0, 1.0, 0.0};
	cam->forw = (t_vec3){0.0, 0.0, 1.0};
	cam->focal_length = 1.0;
	cam->f_wdth = width / 384;
	cam->f_hght = height / 384;
}

static t_vec3*	select_color(const char *str)
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

static unsigned int	simple_shade(t_vec3 *rgb, double n_dot_l)
{
	unsigned int	color;

	n_dot_l = (n_dot_l < 0.0) ? 0.0 : n_dot_l;
	color = rgb->x * n_dot_l;
	color <<= 8;
	color += rgb->y * n_dot_l;
	color <<= 8;
	color += rgb->z * n_dot_l;
	return (color);
}

void			render_intersect_test(
	unsigned int *img_buf,
	t_env *e,
	t_ol *ol
)
{
	t_ray		ray;

	for (int i=0; i < WIDTH; i++)
	{
		for (int j=0; j < HEIGHT; j++)
		{
			ray = cast_ray(j, i, e);
			if (ol->intersect(ray, ol->object) != FAR)
				img_buf[j + i * WIDTH] = 0xffffff;
		}
	}
}

void			render_normal_test(
	unsigned int *img_buf,
	t_env *e,
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
			ray = cast_ray(j, i, e);
			if ((ray.t = ol->intersect(ray, ol->object)) == FAR)
			{
				img_buf[j + i * WIDTH] = 0x00000000;
				continue ;
			}
			n = ol->get_normal(ray, ol->object);
			n_dot_l = v3_dotpdt(v3_scalar(ray.dir, -1.0), n);
			img_buf[j + i * WIDTH] = simple_shade(
				select_color(color), n_dot_l);
		}
	}
}

void			render_texture_mapping_test(
	unsigned int *img_buf,
	t_env *e,
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
	t_vec3			texel_color;

	texture = &ol->texture;
	set_texels(filename, repeat, texture);
	for (int i=0; i < WIDTH; i++)
	{
		for (int j=0; j < WIDTH; j++)
		{
			ray = cast_ray(j, i, e);
			if ((ray.t = ol->intersect(ray, ol->object)) == FAR)
			{
				img_buf[j + i * WIDTH] = 0x00000000;
				continue ;
			}
			n = ol->get_normal(ray, ol->object);
			n_dot_l = v3_dotpdt(v3_scalar(ray.dir, -1.0), n);
			point = find_point_from_ray(ray);

			uv = ol->uv_mapping(point, &ol->axis_mat, texture, ol->object);
			texel_color = get_texel_color(&uv, texture);
			img_buf[j + i * WIDTH] = simple_shade(&texel_color, n_dot_l);
		}
	}
}

void			render_bump_mapping_test(
	unsigned int *img_buf,
	t_env *e,
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

	bump_map = &ol->bump_map;
	set_texels(filename, repeat, bump_map);
	for (int i=0; i < WIDTH; i++)
	{
		for (int j=0; j < WIDTH; j++)
		{
			ray = cast_ray(j, i, e);
			if ((ray.t = ol->intersect(ray, ol->object)) == FAR)
			{
				img_buf[j + i * WIDTH] = 0x00000000;
				continue ;
			}
			point = find_point_from_ray(ray);
			n = ol->get_normal(ray, ol->object);
			uv = ol->uv_mapping(point, &ol->axis_mat, bump_map, ol->object);
			n = get_bumped_normal(&uv, bump_map, &n, &ol->axis_mat);
			n_dot_l = v3_dotpdt(v3_scalar(ray.dir, -1.0), n);
			img_buf[j + i * WIDTH] = simple_shade(
				select_color(color), n_dot_l);
		}
	}
}

void			render_scene(int scene_num, int argc, char **argv)
{
	t_mlxkit	mlxkit;
	t_env		e;

	init_scene(&e);
	setup_scene(&mlxkit, &e.cam, e.width, e.height);
	for (int i=3; i < argc; i++)
	{
		if (strcmp(argv[i], "cel") == 0)
			e.mask |= RT_ENV_MASK_CEL_SHADING;
	}
	e.w.mp = mlxkit.p_mlx;
	e.w.wp = mlxkit.p_win;
	e.w.ip = mlxkit.p_img;
	//e.img_buf = mlx_get_data_addr(e.w.ip, &e.w.bpp, &e.w.sl, &e.w.end);
	e.img_buf = (char *)mlxkit.img_buf;
	switch (scene_num)
	{
		case 1:
			set_scene1(&e);
			break ;
		default:
			break ;
	}
	if (e.mask & RT_ENV_MASK_CEL_SHADING)
		cel_shading(&e);
	else
		multi_thread(&e);
	anti_aliasing((unsigned int *)e.img_buf, (unsigned int *)e.data, e.width / 2, e.height / 2);
	for (int i=3; i < argc; i++)
		set_filter(argv[i], (unsigned int *)e.img_buf, e.width / 2, e.height / 2);
	mlx_put_image_to_window(e.w.mp, e.w.wp, e.w.ip, 0, 0);
	clear_scene(&e);
	mlx_loop(e.w.mp);
}

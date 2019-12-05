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

static unsigned int	simple_shade(t_col *rgb, double n_dot_l)
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
	unsigned int *img_buf,
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
				img_buf[j + i * WIDTH] = 0xffffff;
		}
	}
}

void			render_normal_test(
	unsigned int *img_buf,
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

	bump_map = &ol->bump_map;
	set_texels(filename, repeat, bump_map);
	for (int i=0; i < WIDTH; i++)
	{
		for (int j=0; j < WIDTH; j++)
		{
			ray = cast_ray(j, i, *cam);
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

void			render_motion_blur_test(
	unsigned int *img_buf,
	t_camera *cam,
	t_ol *ol,
	const char *color
)
{
	t_ray			ray;
	t_vec3			n;
	double			n_dot_l;

	for (int i=0; i < WIDTH; i++)
	{
		for (int j=0; j < WIDTH; j++)
		{
			ray = cast_ray(j, i, *cam);
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
	motion_blur(ol, 1, WIDTH, WIDTH, img_buf, cam, color);
}

void			render_scene(int scene_num)
{
	t_mlxkit	mlxkit;
	t_env		e;

	setup_scene(&mlxkit, &e.cam)
	e.w.mp = mlxkit.p_mlx;
	e.w.wp = mlxkit.p_win;
	e.w.ip = mlxkit.p_img;
	e.data = mlxkit.img_buf;
	switch (scene_num)
	{
		case 1:
			set_scene1(&e);
			break ;
		default:
			break ;
	}
	multi_thread(e);
	mlx_put_image_to_window(e->w.mp, e->w.wp, e->w.ip, 0, 0);
	mlx_loop(e.w.mp);
}

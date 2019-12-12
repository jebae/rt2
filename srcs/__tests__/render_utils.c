#include "rt.test.h"

extern t_vec3	COLOR_SAMPLES[4];

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

	for (int i=0; i < e->height; i++)
	{
		for (int j=0; j < e->width; j++)
		{
			ray = cast_ray(j, i, e);
			if (ol->intersect(ray, ol->object) != FAR)
				img_buf[j + i * e->width] = 0xffffff;
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

	for (int i=0; i < e->height; i++)
	{
		for (int j=0; j < e->width; j++)
		{
			ray = cast_ray(j, i, e);
			if ((ray.t = ol->intersect(ray, ol->object)) == FAR)
			{
				img_buf[j + i * e->width] = 0x00000000;
				continue ;
			}
			n = ol->get_normal(ray, ol->object);
			n_dot_l = v3_dotpdt(v3_scalar(ray.dir, -1.0), n);
			img_buf[j + i * e->width] = simple_shade(
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
	for (int i=0; i < e->height; i++)
	{
		for (int j=0; j < e->width; j++)
		{
			ray = cast_ray(j, i, e);
			if ((ray.t = ol->intersect(ray, ol->object)) == FAR)
			{
				img_buf[j + i * e->width] = 0x00000000;
				continue ;
			}
			n = ol->get_normal(ray, ol->object);
			n_dot_l = v3_dotpdt(v3_scalar(ray.dir, -1.0), n);
			point = find_point_from_ray(ray);

			uv = ol->uv_mapping(point, &ol->axis_mat, texture, ol->object);
			texel_color = get_texel_color(&uv, texture);
			img_buf[j + i * e->width] = simple_shade(&texel_color, n_dot_l);
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
	for (int i=0; i < e->height; i++)
	{
		for (int j=0; j < e->width; j++)
		{
			ray = cast_ray(j, i, e);
			if ((ray.t = ol->intersect(ray, ol->object)) == FAR)
			{
				img_buf[j + i * e->width] = 0x00000000;
				continue ;
			}
			point = find_point_from_ray(ray);
			n = ol->get_normal(ray, ol->object);
			uv = ol->uv_mapping(point, &ol->axis_mat, bump_map, ol->object);
			n = get_bumped_normal(&uv, bump_map, &n, &ol->axis_mat);
			n_dot_l = v3_dotpdt(v3_scalar(ray.dir, -1.0), n);
			img_buf[j + i * e->width] = simple_shade(
				select_color(color), n_dot_l);
		}
	}
}

void			render_scene(char *title, int argc, char **argv)
{
	t_mlxkit	mlxkit;
	t_env		e;

	init_mlxkit(&mlxkit, &e);
	for (int i=3; i < argc; i++)
	{
		if (strcmp(argv[i], "cel") == 0)
			e.mask |= RT_ENV_MASK_CEL_SHADING;
		if (strcmp(argv[i], "sephia") == 0)
			e.mask |= RT_ENV_MASK_SEPHIA;
		if (strcmp(argv[i], "negative") == 0)
			e.mask |= RT_ENV_MASK_NEGATIVE;
		if (strcmp(argv[i], "gray") == 0)
			e.mask |= RT_ENV_MASK_GRAY_SCALE;
		if (strcmp(argv[i], "blur") == 0)
			e.mask |= RT_ENV_MASK_GAUSSIAN_BLUR;
	}
	e.w.mp = mlxkit.p_mlx;
	e.w.wp = mlxkit.p_win;
	e.w.ip = mlxkit.p_img;
	if (strcmp(title, "1") == 0)
		set_scene_1(&e);
	else if (strcmp(title, "sphere") == 0)
		set_scene_sphere(&e);
	else if (strcmp(title, "box") == 0)
		set_scene_box(&e);
	render(&e);
	mlx_loop(e.w.mp);
}

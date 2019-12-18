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
	set_texels(filename, atoi(repeat), texture);
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
	set_texels(filename, atoi(repeat), bump_map);
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
	t_env			e;
	t_arg_camera	arg_cam;

	if (init_env(&e) == RT_FAIL)
		printf("Fail init_env\n");
	arg_cam.pos = (t_vec3){0.0, 0.0, -5.0};
	arg_cam.dir = (t_vec3){0.0, 0.0, 1.0};
	arg_cam.right = (t_vec3){1.0, 0.0, 0.0};
	set_camera(&arg_cam, &e.cam);
	set_ray_grid_props(&e);
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
	if (strcmp(title, "1") == 0)
		set_scene_1(&e);
	else if (strcmp(title, "sphere") == 0)
		set_scene_sphere(&e);
	else if (strcmp(title, "box") == 0)
		set_scene_box(&e);
	else if (strcmp(title, "rect") == 0)
		set_scene_rectangle(&e);
	else if (strcmp(title, "cone") == 0)
		set_scene_cone(&e);
	else if (strcmp(title, "cyl") == 0)
		set_scene_cylinder(&e);
	else if (strcmp(title, "plane") == 0)
		set_scene_plane(&e);
	else if (strcmp(title, "pyramid") == 0)
		set_scene_pyramid(&e);
	else if (strcmp(title, "ring") == 0)
		set_scene_ring(&e);
	else if (strcmp(title, "tri") == 0)
		set_scene_triangle(&e);
	else if (strcmp(title, "para") == 0)
		set_scene_paraboloid(&e);
	else if (strcmp(title, "ellip") == 0)
		set_scene_ellipsoid(&e);
	if (render(&e) == RT_FAIL)
		printf("Fail render\n");
	run_event_loop(&e, NULL, NULL);
}

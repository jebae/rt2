#include "rt.test.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

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

t_col			get_rgb(unsigned int value)
{
	t_col	rgb;

	rgb.r = value & 0x000000ff;
	value >>= 8;
	rgb.g = value & 0x000000ff;
	value >>= 8;
	rgb.b = value & 0x000000ff;
	return (rgb);
}

unsigned int	get_uint32_color(t_col *rgb)
{
	unsigned int	color;

	color = 0;
	color += rgb->r;
	color <<= 8;
	color += rgb->g;
	color <<= 8;
	color += rgb->b;
	return (color);
}

void			render_texture_mapping_test(
	t_mlxkit *mlxkit,
	t_camera *cam,
	t_ol *ol,
	const char *texture_file_name
)
{
	int				index;
	t_ray			ray;
	t_vec3			n;
	double			n_dot_l;
	int				img_coord[2];
	t_col			rgb;
	t_vec2			uv;
	t_vec3			point;
	t_texture		*texture;

	ol->texture.pixels = (unsigned int *)stbi_load(
		texture_file_name, &ol->texture.width, &ol->texture.height,
		NULL, STBI_rgb_alpha);
	texture = &ol->texture;
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
			uv = ol->uv_mapping(point, &ol->axis_mat, ol->object);

			img_coord[0] = uv.x * (texture->width - 1);
			img_coord[1] = uv.y * (texture->height - 1);

			index = img_coord[0] + img_coord[1] * texture->width;
			if (index < 0 || index >= texture->width * texture->height)
				continue ;
			rgb = get_rgb(texture->pixels[img_coord[0] + img_coord[1] * texture->width]);
			rgb.r *= MAX(0.0, n_dot_l);
			rgb.g *= MAX(0.0, n_dot_l);
			rgb.b *= MAX(0.0, n_dot_l);
			mlxkit->img_buf[j + i * WIDTH] = get_uint32_color(&rgb);
		}
	}
	mlx_put_image_to_window(mlxkit->p_mlx, mlxkit->p_win, mlxkit->p_img, 0, 0);
	free(ol->texture.pixels);
	ft_memdel((void **)&ol->object);
	mlx_loop(mlxkit->p_mlx);
}

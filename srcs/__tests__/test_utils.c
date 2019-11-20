#include "rt.test.h"
# define STB_IMAGE_IMPLEMENTATION
# include "stb_image.h"

int			mlxkit_key_press(int keycode, void *param)
{
	t_mlxkit *mlxkit = (t_mlxkit *)param;

    if (keycode == KEY_ESC)
	{
		mlx_destroy_image(mlxkit->p_mlx, mlxkit->p_img);
		mlx_destroy_window(mlxkit->p_mlx, mlxkit->p_win);
        exit(0);
	}
    return (0);
}

void		init_mlxkit(t_mlxkit *mlxkit)
{
	int		bpp;
	int		endian;
	int		width;

	bpp = MLX_BPP;
	endian = MLX_ENDIAN;
	width = WIDTH;
	mlxkit->p_mlx = mlx_init();
	mlxkit->p_win = mlx_new_window(mlxkit->p_mlx, width, width, "RT");
	mlxkit->p_img = mlx_new_image(mlxkit->p_mlx, width, width);
	mlxkit->img_buf = (unsigned int *)mlx_get_data_addr(mlxkit->p_img, &bpp, &width, &endian);
	mlx_key_hook(mlxkit->p_win, &mlxkit_key_press, mlxkit);
}

void		render_intersect_test(
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

void		render_normal_test(
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

void		test(int res, const char *msg)
{
	if (!res)
	{
		printf(KRED "[FAILED] " KNRM);
		printf("%s\n", msg);
	}
}

void		render_img()
{
	t_mlxkit		mlxkit;
	unsigned int	*pixels;
	unsigned int	value;
	unsigned int	rgb;
	int				width;
	int				height;

	init_mlxkit(&mlxkit);
	pixels = (unsigned int *)stbi_load("./contents/Brick_image_texture.jpg", &width, &height,
		NULL, STBI_rgb_alpha);
	for (int i=0; i < WIDTH; i++)
	{
		for (int j=0; j < WIDTH; j++)
		{
			rgb = 0;
			value = pixels[i * width + j];
			rgb |= value & 0x000000ff;
			rgb <<= 8;
			value >>= 8;
			rgb |= value & 0x000000ff;
			rgb <<= 8;
			value >>= 8;
			rgb |= value & 0x000000ff;
			mlxkit.img_buf[j + i * WIDTH] = rgb;
		}
	}
	mlx_put_image_to_window(mlxkit.p_mlx, mlxkit.p_win, mlxkit.p_img, 0, 0);
	mlx_loop(mlxkit.p_mlx);
}

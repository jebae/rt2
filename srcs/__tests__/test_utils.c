#include "rt.test.h"

void		clear_mlxkit(t_mlxkit *mlxkit)
{
	mlx_destroy_image(mlxkit->p_mlx, mlxkit->p_img);
	mlx_destroy_window(mlxkit->p_mlx, mlxkit->p_win);
	exit(0);
}

int			mlxkit_key_press(int keycode, void *param)
{
	t_mlxkit *mlxkit = (t_mlxkit *)param;

    if (keycode == KEY_ESC)
		clear_mlxkit(mlxkit);
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
	mlxkit->p_win = mlx_new_window(mlxkit->p_mlx, width, HEIGHT, "RT");
	mlxkit->p_img = mlx_new_image(mlxkit->p_mlx, width, HEIGHT);
	mlxkit->img_buf = (unsigned int *)mlx_get_data_addr(mlxkit->p_img, &bpp, &width, &endian);
	mlx_key_hook(mlxkit->p_win, &mlxkit_key_press, mlxkit);
}

#include "rt.test.h"

void			init_mlxkit(t_mlxkit *mlxkit)
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
	mlxkit->img_buf = (int *)mlx_get_data_addr(mlxkit->p_img, &bpp, &width, &endian);
}

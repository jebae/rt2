#include "rt.test.h"

void		clear_mlxkit(t_mlxkit *mlxkit)
{
	mlx_destroy_image(mlxkit->p_mlx, mlxkit->p_img);
	mlx_destroy_window(mlxkit->p_mlx, mlxkit->p_win);
	clear_scene(mlxkit->e);
	exit(0);
}

static void	rotate_obj(t_env *e, double theta)
{
	t_vec4		q[2];
	t_ol		*obj;

	q[0] = rotate_q(&e->cam.camdir, theta);
	q[1] = inverse_q(&q[0]);
	obj = e->ll_obj;
	obj->rotate(q, &obj->axis_mat, obj->object);
	render(e);
}

int			mlxkit_key_press(int keycode, void *param)
{
	t_mlxkit *mlxkit = (t_mlxkit *)param;

    if (keycode == KEY_ESC)
		clear_mlxkit(mlxkit);
	else if (keycode == KEY_COMMA)
		rotate_obj(mlxkit->e, DEGREE_1 * 10.0);
	else if (keycode == KEY_POINT)
		rotate_obj(mlxkit->e, -DEGREE_1 * 10.0);
    return (0);
}

void		init_mlxkit(t_mlxkit *mlxkit, t_env *e)
{
	int		bpp;
	int		endian;
	int		width;
	int		height;

	setup_scene(e);
	mlxkit->e = e;
	bpp = MLX_BPP;
	endian = MLX_ENDIAN;
	width = e->width / 2;
	height = e->height / 2;
	mlxkit->p_mlx = mlx_init();
	mlxkit->p_win = mlx_new_window(mlxkit->p_mlx, width, height, "RT");
	mlxkit->p_img = mlx_new_image(mlxkit->p_mlx, width, height);
	mlxkit->img_buf = (unsigned int *)mlx_get_data_addr(mlxkit->p_img, &bpp, &width, &endian);
	mlx_key_hook(mlxkit->p_win, &mlxkit_key_press, mlxkit);
	e->img_buf = (char *)mlxkit->img_buf;
}

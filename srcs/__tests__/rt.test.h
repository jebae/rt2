#ifndef RT_TEST_H
# define RT_TEST_H

# include "../minilibx_macos/mlx.h"
# include "raycast.h"
# include <stdio.h>

# define MLX_BPP                32
# define MLX_ENDIAN             0
# define KEY_ESC				53
# define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct	s_mlxkit
{
	void		*p_win;
	void		*p_mlx;
	void		*p_img;
	int			*img_buf;
}				t_mlxkit;

void			init_mlxkit(t_mlxkit *mlxkit);

/*
** object test
*/
void			test_rectangle_intersect_case1(void);
void			test_rectangle_normal_case1(void);

#endif

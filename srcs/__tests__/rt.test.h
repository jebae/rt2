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

void			render_intersect_test(
	t_mlxkit *mlxkit,
	t_camera *cam,
	t_ol *ol
);

void			render_normal_test(
	t_mlxkit *mlxkit,
	t_camera *cam,
	t_ol *ol
);

/*
** object test
*/
void			test_sphere_intersect_case1(void);
void			test_sphere_normal_case1(void);

void			test_cylinder_intersect_case1(void);
void			test_cylinder_normal_case1(void);

void			test_cone_intersect_case1(void);
void			test_cone_normal_case1(void);

void			test_rectangle_intersect_case1(void);
void			test_rectangle_intersect_case2(void);
void			test_rectangle_normal_case1(void);
void			test_rectangle_normal_case2(void);

void			test_box_intersect_case1(void);
void			test_box_intersect_case2(void);
void			test_box_intersect_case3(void);
void			test_box_normal_case1(void);
void			test_box_normal_case2(void);
void			test_box_normal_case3(void);

void			test_plane_intersect_case1();
void			test_plane_normal_case1();

void			test_triangle_intersect_case1(void);
void			test_triangle_intersect_case2(void);
void			test_triangle_normal_case1(void);
void			test_triangle_normal_case2(void);

#endif

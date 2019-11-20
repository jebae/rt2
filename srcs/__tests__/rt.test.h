#ifndef RT_TEST_H
# define RT_TEST_H

# include "../minilibx_macos/mlx.h"
# include "raycast.h"
# include <stdio.h>

# define KRED					"\x1B[31m"
# define KGRN					"\x1B[32m"
# define KYEL					"\x1B[33m"
# define KNRM					"\x1B[0m"

# define MLX_BPP                32
# define MLX_ENDIAN             0
# define KEY_ESC				53
# define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct	s_mlxkit
{
	void			*p_win;
	void			*p_mlx;
	void			*p_img;
	unsigned int	*img_buf;
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

void			test(int res, const char *msg);

void			render_img();

/*
** object intersect normal test
** (render test)
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

void			test_pyramid_intersect_case1(void);
void			test_pyramid_intersect_case2(void);
void			test_pyramid_intersect_case3(void);
void			test_pyramid_normal_case1(void);
void			test_pyramid_normal_case2(void);
void			test_pyramid_normal_case3(void);

void			test_ring_intersect_case1(void);
void			test_ring_intersect_case2(void);
void			test_ring_intersect_case3(void);
void			test_ring_normal_case1(void);
void			test_ring_normal_case2(void);
void			test_ring_normal_case3(void);

/*
** set_object test
*/
void			test_set_sphere_case1(void);
void			test_set_sphere_case2(void);

void			test_set_cone_case1(void);
void			test_set_cone_case2(void);
void			test_set_cone_case3(void);
void			test_set_cone_case4(void);
void			test_set_cone_case5(void);

void			test_set_cyl_case1(void);
void			test_set_cyl_case2(void);
void			test_set_cyl_case3(void);

void			test_set_plane_case1(void);
void			test_set_plane_case2(void);

void			test_set_rectangle_case1(void);
void			test_set_rectangle_case2(void);
void			test_set_rectangle_case3(void);
void			test_set_rectangle_case4(void);

void			test_set_box_case1(void);
void			test_set_box_case2(void);
void			test_set_box_case3(void);
void			test_set_box_case4(void);

void			test_set_triangle_case1(void);
void			test_set_triangle_case2(void);
void			test_set_triangle_case3(void);
void			test_set_triangle_case4(void);

void			test_set_pyramid_case1(void);
void			test_set_pyramid_case2(void);
void			test_set_pyramid_case3(void);
void			test_set_pyramid_case4(void);
void			test_set_pyramid_case5(void);

void			test_set_ring_case1(void);
void			test_set_ring_case2(void);
void			test_set_ring_case3(void);
void			test_set_ring_case4(void);
void			test_set_ring_case5(void);

#endif

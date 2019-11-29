#ifndef RT_TEST_H
# define RT_TEST_H

# include "../minilibx_macos/mlx.h"
# include "raycast.h"
# include "unity.h"
# include "unity_fixture.h"
# include <float.h>
# include <stdio.h>

# define KRED					"\x1B[31m"
# define KGRN					"\x1B[32m"
# define KYEL					"\x1B[33m"
# define KNRM					"\x1B[0m"

# define MLX_BPP                32
# define MLX_ENDIAN             0
# define KEY_ESC				53
# define MAX(a, b) (((a) > (b)) ? (a) : (b))
# define GRAY					(t_col){0xa0, 0xa0, 0xa0}
# define BLUE					(t_col){0x11, 0x5d, 0xa8}
# define RED					(t_col){0xf2, 0x00, 0x3c}
# define BROWN					(t_col){0x65, 0x32, 0x21}

t_col			COLOR_SAMPLES[4];

typedef struct	s_mlxkit
{
	void			*p_win;
	void			*p_mlx;
	void			*p_img;
	unsigned int	*img_buf;
}				t_mlxkit;

/*
** test utils
*/
void			init_mlxkit(t_mlxkit *mlxkit);
void			clear_mlxkit(t_mlxkit *mlxkit);

/*
** render utils
*/
void			setup_scene(t_mlxkit *mlxkit, t_camera *cam);
void			render_intersect_test(
	unsigned int *img_buf,
	t_camera *cam,
	t_ol *ol
);
void			render_normal_test(
	unsigned int *img_buf,
	t_camera *cam,
	t_ol *ol,
	const char *color
);
void			render_texture_mapping_test(
	unsigned int *img_buf,
	t_camera *cam,
	t_ol *ol,
	const char *texture_file_name,
	const char *repeat
);
void			render_bump_mapping_test(
	unsigned int *img_buf,
	t_camera *cam,
	t_ol *ol,
	const char *filename,
	const char *repeat,
	const char *color
);
void			render_motion_blur_test(
	unsigned int *img_buf,
	t_camera *cam,
	t_ol *ol,
	const char *color
);

/*
** texture utils
*/
void			set_texels(
	const char *filename,
	const char *repeat,
	t_texels *texture
);

/*
** filter utils
*/
void			set_filter(
	const char *filter,
	unsigned int *buffer,
	int width,
	int height
);

/*
** setup object
*/
int				setup_object(
	const char *obj,
	const char *case_num,
	t_ol *ol
);
int				setup_box(const char *cast_num,t_ol *ol);
int				setup_cone(const char *cast_num, t_ol *ol);
int				setup_cylinder(const char *cast_num, t_ol *ol);
int				setup_plane(const char *cast_num, t_ol *ol);
int				setup_pyramid(const char *cast_num, t_ol *ol);
int				setup_rectangle(const char *cast_num, t_ol *ol);
int				setup_ring(const char *cast_num, t_ol *ol);
int				setup_sphere(const char *cast_num, t_ol *ol);
int				setup_triangle(const char *cast_num, t_ol *ol);

/*
** set_object
*/
void			test_set_object(void);

/*
** buffer
*/
void			test_for_each_pixel(void);

#endif

#ifndef RT_TEST_H
# define RT_TEST_H

# include "raycast.h"
# include "unity.h"
# include "unity_fixture.h"
# include <float.h>
# include <stdio.h>
# include <stdlib.h>

# define KRED					"\x1B[31m"
# define KGRN					"\x1B[32m"
# define KYEL					"\x1B[33m"
# define KNRM					"\x1B[0m"

# define MLX_BPP                32
# define MLX_ENDIAN             0
# define KEY_ESC				53
# define KEY_COMMA				43
# define KEY_POINT				47
# define MAX(a, b) (((a) > (b)) ? (a) : (b))
# define GRAY					(t_vec3){0xa0, 0xa0, 0xa0}
# define BLUE					(t_vec3){0x11, 0x5d, 0xa8}
# define RED					(t_vec3){0xf2, 0x00, 0x3c}
# define BROWN					(t_vec3){0x65, 0x32, 0x21}

t_vec3			COLOR_SAMPLES[4];

/*
** render utils
*/
void			render_intersect_test(
	unsigned int *img_buf,
	t_env *e,
	t_ol *ol
);
void			render_normal_test(
	unsigned int *img_buf,
	t_env *e,
	t_ol *ol,
	const char *color
);
void			render_texture_mapping_test(
	unsigned int *img_buf,
	t_env *e,
	t_ol *ol,
	const char *texture_file_name,
	const char *repeat
);
void			render_bump_mapping_test(
	unsigned int *img_buf,
	t_env *e,
	t_ol *ol,
	const char *filename,
	const char *repeat,
	const char *color
);
void			render_scene(char *title, int argc, char **argv);

/*
** scene
*/
void			set_scene_1(t_env *e);
void			set_scene_sphere(t_env *e);
void			set_scene_box(t_env *e);
void			set_scene_rectangle(t_env *e);
void			set_scene_cone(t_env *e);
void			set_scene_cylinder(t_env *e);
void			set_scene_plane(t_env *e);
void			set_scene_pyramid(t_env *e);
void			set_scene_ring(t_env *e);
void			set_scene_triangle(t_env *e);

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

#endif

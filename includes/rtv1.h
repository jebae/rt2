/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:13:39 by mhernand          #+#    #+#             */
/*   Updated: 2019/11/18 16:33:55 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../libvector/libvector.h"
# include "rtv1_parser.h"
# include <math.h>
# include <complex.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <assert.h>
# define WIDTH		800
# define HEIGHT 	800
# define FAR		2000000.0
# define ESC		53
# define CONE		0
# define CYLINDER	1
# define PLANE		2
# define SPHERE		3
# define RECTANGLE	5

typedef struct		s_mat3
{
	double			arr[3][3];
}					t_mat3;

typedef struct		s_ray
{
	t_vec3			ori;
	t_vec3			dir;
	double			t;
}					t_ray;

typedef struct		s_col
{
	int				r;
	int				g;
	int				b;
}					t_col;

typedef struct		s_shader
{
	t_col			diff;
	t_col			spec;
}					t_shader;

typedef struct		s_camera
{
	t_vec3			campos;
	t_vec3			camdir;
	t_vec3			*tra;
	t_vec3			*rot;
	t_vec3			left;
	t_vec3			up;
	t_vec3			forw;
	double			focal_length;
	double			f_wdth;
	double			f_hght;
}					t_camera;

typedef struct		s_amb
{
	t_col			col;
	int				specpower;
}					t_amb;

typedef struct		s_ll
{
	size_t			content_size;
	t_vec3			pos;
	t_vec3			its;
	t_vec3			tra;
	t_vec3			rot;
	struct s_ll		*next;
}					t_ll;

typedef struct		s_ol
{
	void			*object;
	int				specpower;
	int				specvalue;
	t_vec3			dif;
	double			(*intersect)(t_ray ray, void *object);
	t_vec3			(*get_normal)(t_ray ray, void *object);
	struct s_ol		*next;
	// int				status;	
	// t_vec3			rot_x;
	// t_vec3			rot_y;
	// t_vec3			rot_z;
	// t_vec3			translation;
}					t_ol;

typedef struct 		s_sphere
{
	t_vec3			cen;
	double			radius;
}					t_sphere;

typedef struct		s_cone
{
	t_vec3			cen;
	t_vec3			axis;
	double			angle;
}					t_cone;

typedef struct		s_cyl
{
	t_vec3			cen;
	t_vec3			axis;
	double			radius;
}					t_cyl;

typedef struct		s_plane
{
	t_vec3			normal;
	double			d;
}					t_plane;

typedef struct		s_rectangle
{
	t_vec3			p;
	t_vec3			a;
	t_vec3			b;
	t_vec3			normal;
	double			norm_a;
	double			norm_b;
	double			d;
}					t_rectangle;

typedef struct		s_box
{
	t_vec3			vmin;
	t_vec3			vmax;
	t_mat3			mat;
}					t_box;

typedef struct		s_triangle
{
	t_vec3			a;
	t_vec3			ab;
	t_vec3			ac;
	t_vec3			normal;
}					t_triangle;

typedef struct		s_pyramid
{
	t_triangle		sides[4];
	t_vec3			u;
	t_vec3			v;
	double			norm_u;
	double			norm_v;
}					t_pyramid;

typedef struct		s_mlx
{
	void			*mp;
	void			*wp;
	void			*ip;
	int				bpp;
	int				end;
	int				sl;
}					t_mlx;

typedef struct		s_creecam
{
	t_vec4			v1;
	t_vec4			v2;
	t_vec4			v3;
}					t_creecam;

typedef struct		s_env
{
	int	thread;
	char			*data;
	int				k[300];
	int				s_count;
	int				cs;
	int				x;
	int				y;
	t_parser		p;
	t_mlx			w;
	t_amb			amb;
	t_camera		cam;
	t_ll			*ll_lit;
	t_ol			*ll_obj;
	t_ll			*tp_l;
	t_ol			*tp_o;
	double			r;
	t_creecam		cc;
	int				y_min;
	int				y_max;
	void			**image;
}					t_env;

void				setup_rtv1(t_env *e);
int					parser(t_env *e, t_parser *p, int fd);
void				start_rtv1(t_env *e);
int					touch(t_env *e);
int					key_press(int key, t_env *e);
int					key_release(int key, t_env *e);
int					quit(t_env *e);
void				draw_sphere(t_env *e);
int					two_tabs_specs(t_env *e, t_parser *p, t_ll **l_head);
int					twotab_verifications(t_env *e, t_parser *p, t_ol **o_head);
int					verifyobjecttags_closings(t_env *e, t_parser *p,
						char *split);
int					verifyargs_one(t_env *e, t_parser *p, t_ll **l_head,
						t_ol **o_head);
int					verifyargs_three(t_env *e, t_parser *p, t_ll **l_head,
						t_ol **o_head);
int					shapevocab_checker(t_env *e, t_parser *p);
int					shapevocab_checker_partwo(t_env *e, t_parser *p);
int					error(t_env *e, t_parser *p, int i);
int					verify_numbers_one(t_env *e, t_parser *p, t_ll *l_head,
						t_ol *o_head);
int					verify_numbers_three(t_env *e, t_parser *p, t_ll *l_head,
						t_ol *o_head);
int					add_link_light(t_env *e, t_ll **head);
int					add_link_obj(t_env *e, t_ol **head);
int					storing_three(t_env *e, t_parser *p, t_ll *l_tmp,
						t_ol *o_tmp);
int					storing_three_3(t_env *e, t_parser *p, t_ll *l_tmp,
						t_ol *o_tmp);
void				store_lit_tra(t_parser *p, t_ll *l_tmp);
void				store_translate(t_parser *p, t_ll *l_tmp, t_ol *o_tmp);
int					main(int argc, char **argv);

#endif

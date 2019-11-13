/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:13:39 by mhernand          #+#    #+#             */
/*   Updated: 2019/10/09 11:50:23 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
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

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef struct		s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

typedef struct		s_ray
{
	t_point			ori;
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
	t_point			campos;
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
	t_point			pos;
	t_point			its;
	t_vec3			tra;
	t_vec3			rot;
	struct s_ll		*next;
}					t_ll;

typedef struct		s_ol
{
	size_t			content_size;
	int				status;
	int				d;
	double			angle;
	int				radius;
	int				s_pow;
	int				s_val;
	int				cur_shape;
	int				specpower;
	int				specvalue;
	int				ref;
	t_point			dif;
	t_vec3			dir;
	t_point			cen;
	t_vec3			nor;
	t_vec3			rot;
	t_vec3			rot_x;
	t_vec3			rot_y;
	t_vec3			rot_z;
	t_vec3			tra;
	t_vec3			pla_po;
	struct s_ol		*next;
}					t_ol;

typedef struct		s_mlx
{
	void			*mp;
	void			*wp;
	void			*ip;
	int				bpp;
	int				end;
	int				sl;
}					t_mlx;

typedef struct		s_vec4
{
	int				x;
	int				y;
	int				z;
	int				w;
}					t_vec4;

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

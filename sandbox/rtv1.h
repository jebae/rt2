/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:13:39 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/19 18:58:11 by sabonifa         ###   ########.fr       */
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
# include <stdio.h> // remove

# define WIDTH		800
# define HEIGHT 	800
# define FAR		2000000.0

# define ESC		53

# define CONE		0
# define CYLINDER	1
# define PLANE		2
# define SPHERE		3

typedef struct  	s_point
{
	double      	x;
	double    	  	y;
	double      	z;
}              		t_point;

typedef struct		s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

typedef struct	s_ray
{
	t_point     ori;
	t_vec3    dir;
	double      t;
}				t_ray;

typedef struct		s_col
{
	int				x;
	int				y;
	int				z;
}					t_col; // color amb

typedef struct		s_camera // struct for camera data
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

typedef struct		s_amb // struct for amb data
{
	t_col			col;
	int				specpower;
}					t_amb;

typedef struct		s_ll  // linked list for storing LIGHT data
{
	size_t			content_size;
	t_point			pos;
	t_point			its;
	t_vec3			tra;
	t_vec3			rot;
	struct s_ll		*next;
}					t_ll;

typedef struct		s_ol  // linked list for storing OBJECT data
{
	size_t			content_size;
	int				status; // 0 == basic , 1 == extra
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
	char			*data;
	int				str_count;
	int				k[300];
	int				s_count;
	int				cs;
	t_parser		p; // THE PARSER STRUCTURE !
	t_mlx			w; // mlx images, window, etc.
	t_amb			amb; // store amb
	t_camera		cam; // store cam
	t_ll			*ll_lit; // linked list
	t_ol			*ll_obj; // linked list

	t_creecam		cc;
}					t_env;

void				setup_rtv1(t_env *e);
int					parser(t_env *e, int fd);
void				start_rtv1(t_env *e);
int					touch(t_env *e);
int					key_press(int key, t_env *e);
int					key_release(int key, t_env *e);
int					quit(t_env *e);
void				draw_sphere(t_env *e);

//functions for parser
void				set_vocab(t_env *e);
int					two_tabs_specs(t_env *e, t_ll **l_head);
int					open_close(int *check_me);
int					extract_status(t_env *e);
int					two_angle_brackets(t_env *e);
int					twotab_verifications(t_env *e, t_ol **o_head);
void				count_shapes(t_env *e, char *split);
int					verifyobjecttags_closings(t_env *e, char *split);
int					globals(t_env *e, char *gnl_line);
int					verifyargs_one(t_env *e, t_ll **l_head, t_ol **o_head);
int					verifyanglebrackets_one(t_env *e);
int					verifyvocab_one(t_env *e);
int					verifyargs_three(t_env *e, t_ll **l_head, t_ol **o_head);
int					verifyanglebrackets_three(t_env *e);
int					verifyvocab_three(t_env *e);
int					shapevocab_checker(t_env *e);
int					shapevocab_checker_partwo(t_env *e);
int					verify_spec_atb(t_env *e);
int					verify_spec_atb_partwo(t_env *e);
int					verify_tag_to_argument(t_env *e, char *string, int args);
int					error(t_env *e, int i);
void				reset_spec_atb(t_env *e);
void				lineless_errors_three(t_env *e, int i);
void				lineless_errors_eight(t_env *e, int i);
int					verify_numbers_one(t_env *e, t_ll *l_head, t_ol *o_head);
int					verify_values(t_env *e);
int					verify_numbers_three(t_env *e, t_ll *l_head, t_ol *o_head);
void				reset_shape_atb(t_env *e);
void				reset_shape_atb_two(t_env *e);
int					checkforopenobjecttags(t_env *e);
int					add_link_light(t_env *e, t_ll **head);
int					add_link_obj(t_env *e, t_ol **head);

int					main(int argc, char **argv);

/////////////////////////SANDBOX TO BE BETTER INCLUDED //////////////////////////

t_mlx   init(t_mlx *p);
int     sand(t_env *e);
int     sand2(t_env *e, t_ol *ol, t_ll *ll);
int		raycast(t_env *e, t_ol *ol, t_ll *ll);
int     color(t_point p, t_ol *ol, t_ll *ll);
/*
 * ** Vector operations
 */

t_point     create_pt(double x, double y, double z);
t_vec3    create_v(t_point ori, t_point dest);
t_vec3    v_add(t_vec3 u, t_vec3 v, char c);
t_vec3    v_mult(t_vec3 u, double k);
double      v_scal(t_vec3 u, t_vec3 v);
double      v_norm(t_vec3 u);
t_vec3    v_cross(t_vec3 u, t_vec3 v);
t_vec3    v_normalise(t_vec3 u);

/*
 * ** Intersection functions
 */

double  v_intersect_sp(t_vec3 ray, t_ol *ol, t_env *e);
double  v_intersect_pl(t_vec3 ray, t_ol *ol, t_env *e);

double  v_intersect_cy(t_vec3 ray, t_ol *ol, t_env *e);
double  v_intersect_co(t_ray ray, t_ol *ol, t_env *e);
double  v_intersect_sp2(t_ray ray, t_ol *ol, t_env *e);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:06:07 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/10 12:06:09 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_PARSER_H
# define RTV1_PARSER_H
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <math.h>
# include <complex.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <assert.h>

typedef struct		s_ret
{
	int				tag;
	int				glo;
	int				gnl;
}					t_ret;

typedef struct		s_spec
{
	int				cam;
	int				amb;
	int				light;
	int				cam_cl;
	int				amb_cl;
}					t_spec;

typedef struct		s_parseobj
{
	int				sphere;
	int				plane;
	int				cone;
	int				cyn;
}					t_parseobj;

typedef struct		s_pla_atb
{
	int				normal;
	int				d;
	int				diffusion;
	int				reflection;
	int				specpower;
	int				specvalue;
	int				rotate;
	int				translate;
}					t_pla_atb;

typedef struct		s_cyn_atb
{
	int				radius;
	int				center;
	int				direction;
	int				diffusion;
	int				reflection;
	int				specpower;
	int				specvalue;
	int				angle;
	int				rotate;
	int				translate;
}					t_cyn_atb;

typedef struct		s_cone_atb
{
	int				radius;
	int				center;
	int				direction;
	int				diffusion;
	int				reflection;
	int				specpower;
	int				specvalue;
	int				angle;
	int				rotate;
	int				translate;
}					t_cone_atb;

typedef struct		s_sphere_atb
{
	int				radius;
	int				center;
	int				diffusion;
	int				reflection;
	int				specpower;
	int				specvalue;
	int				rotate;
	int				translate;
}					t_sphere_atb;

typedef struct		s_cam_atb
{
	int				position;
	int				direction;
	int				rotation;
	int				translation;
}					t_cam_atb;

typedef struct		s_amb_atb
{
	int				power;
	int				color;
}					t_amb_atb;

typedef struct		s_lig_atb
{
	int				position;
	int				intensity;
	int				rotate;
	int				translate;
}					t_lig_atb;

typedef struct		s_shape_count
{
	int				spheres;
	int				cones;
	int				cylinders;
	int				planes;
}					t_shape_count;

typedef struct		s_parser
{
	char			**split;
	char			*strone;
	char			*strtwo;
	char			*s_tmp;
	int				gnl_i;
	char			*gnl_line;
	char			*tmp;
	char			*t;
	char			*vocab_one[4];
	char			*vocab_two[16];
	int				skips;
	int				scene;
	int				specs;
	int				spec_order;
	int				skip;
	int				objects;
	int				voc_i;
	int				voc_check;
	int				status;
	int				set_one;
	int				set_two;
	int				i;
	int				j;
	int				k;
	int				str_count;
	int				close_obj_i;
	int				good_obj_brack;
	int				bad_obj_brack;
	int				e1;
	int				e2;
	int				l;
	int				v;
	int				v1;
	int				v2;
	int				v3;
	int				comma;
	int				ret_p;
	t_parseobj		p_obj;
	t_spec			p_spec;
	t_ret			ret;
	t_shape_count	count;
	t_pla_atb		p_atb;
	t_cyn_atb		y_atb;
	t_cone_atb		c_atb;
	t_sphere_atb	s_atb;
	t_lig_atb		l_atb;
	t_amb_atb		a_atb;
	t_cam_atb		ca_atb;
}					t_parser;

void				set_vocab(t_parser *p);
int					open_close(int *check_me);
int					extract_status(t_parser *p);
int					two_angle_brackets(t_parser *p);
void				count_shapes(t_parser *p, char *split);
int					globals(t_parser *p, char *gnl_line);
int					verifyanglebrackets_one(t_parser *p);
int					verifyvocab_one(t_parser *p);
int					verifyanglebrackets_three(t_parser *p);
int					verifyvocab_three(t_parser *p);
int					verify_spec_atb(t_parser *p);
int					verify_spec_atb_partwo(t_parser *p);
int					verify_tag_to_argument(t_parser *p, char *string, int args);
void				reset_spec_atb(t_parser *p);
void				lineless_errors_three(t_parser *p, int i);
void				lineless_errors_eight(t_parser *p, int i);
int					verify_values(t_parser *p);
void				reset_shape_atb(t_parser *p);
void				reset_shape_atb_two(t_parser *p);
int					checkforopenobjecttags(t_parser *p);
int					last_checks(t_parser *p);
int					verify_values(t_parser *p);
int					verify_values_diff(t_parser *p);

#endif

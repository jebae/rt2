/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:13:39 by mhernand          #+#    #+#             */
/*   Updated: 2019/12/06 19:18:30 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../libvector/libvector.h"
# include <math.h>
# include <complex.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <assert.h>
# define WIDTH		1000
# define HEIGHT 	1000
# define FAR		2000000.0
# define ESC		53
# define CONE		0
# define CYLINDER	1
# define PLANE		2
# define SPHERE		3
# define RECTANGLE	5
# define RT_SUCCESS			0
# define RT_FAIL			1
# define RT_APPROX_0			1e-6
//# define RT_BIAS			1e-3
# define RT_MAX_THREAD		50
# define RT_FRAME_PER_SEC	64
# define RT_TRUE			1
# define RT_FALSE			0

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

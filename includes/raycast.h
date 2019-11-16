/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:25:49 by sabonifa          #+#    #+#             */
/*   Updated: 2019/11/16 16:58:50 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include "rtv1.h"
# include "rtv1_parser.h"
#include <stdio.h>

t_mlx		init(t_mlx *p);
int			raycast(t_env *e);
t_ray		cast_ray(int x, int y, t_camera cam);
int			color(t_vec3 p, t_ol *ol, t_ll *ll);
void    multi_thread(t_env *e);

/*
** Vector operations
*/
t_vec3		create_pt(double x, double y, double z);
t_vec3		v3_frompoints(t_vec3 ori, t_vec3 dest);
t_vec3		v_add(t_vec3 u, t_vec3 v, char c);
t_vec3		v_mult(t_vec3 u, double k);
double		v_scal(t_vec3 u, t_vec3 v);
double		v_norm(t_vec3 u);
t_vec3		v_cross(t_vec3 u, t_vec3 v);
t_vec3		v_normalise(t_vec3 u);

/*
** Matrix operations
*/
t_vec3		m_mult(t_mat3 m, t_vec3 v);

/*
** Intersection functions
*/
double		v_intersect_sp(t_vec3 ray, t_ol *ol);
double		v_intersect_pl(t_ray ray, void *object);
double		v_intersect_cy(t_ray ray, void *object);
double		v_intersect_co(t_ray ray, void *object);
double		v_intersect_sp2(t_ray ray, void *object);
double		v_intersect_rectangle(t_ray ray, void *object);
double		v_intersect_box(t_ray ray, void *object);
double		intersection(t_ray ray, t_ol *ol);
double		find_closest_intersection(double a, double b, double c);
t_vec3		find_point_from_ray(t_ray ray);

/*
** Coloring functions
*/
t_shader	compute_color(t_ray ray, t_ol *ol, t_ll *ll, t_env *e);
void		color_pixel(int x, int y, t_shader sh, t_env *e);
t_shader	init_shader(void);
t_shader	shader_add(t_shader sh1, t_shader sh2);
int			specular(t_ray ray, t_vec3 p, t_ol *ol, t_ll *ll);
t_col		color_add(t_col c1, t_col c2);

/*
** Normal related functions
*/
t_vec3		normal_sphere(t_ray ray, void *object);
t_vec3		normal_cylinder(t_ray ray, void *object);
t_vec3		normal_cone(t_ray ray, void *object);
t_vec3	    normal_plane(t_ray ray, void *object);
t_vec3		normal_rectangle(t_ray ray, void *object);
t_vec3		normal_box(t_ray ray, void *object);
t_vec3		get_normal(t_ray ray, t_ol *ol);

/*
** Object manipulation functions
*/
t_vec3		translation(t_vec3 pos, t_vec3 trans);
t_vec3		rotation(t_vec3 axis, t_vec3 rotx, t_vec3 roty, t_vec3 rotz);
int			is_vector_empty(t_vec3 vec);
int			is_matrix_empty(t_vec3 x, t_vec3 y, t_vec3 z);
t_ol		*apply_extra(t_ol *ll_obj);
float		m3_det(t_vec3 x, t_vec3 y, t_vec3 z);
#endif

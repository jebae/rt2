/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:25:49 by sabonifa          #+#    #+#             */
/*   Updated: 2019/10/01 16:48:22 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// /!/ This header still have the rtv1.h that is inside the directory
//     Need to modify the one that is in /includes to have everything in it and then change path 

//#include "libft.h"
#ifndef RAYCAST_H
# define RAYCAST_H
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "rtv1.h"
# include "rtv1_parser.h"

# define X0 -WIDTH / 2
# define Y0 -WIDTH / 2
# define	RAYON 70

t_mlx   init(t_mlx *p);
int     sand(t_env *e);
int     sand2(t_env *e, t_ol *ol, t_ll *ll);
int     raycast(t_env *e, t_ol *ol, t_ll *ll);
int     color(t_point p, t_ol *ol, t_ll *ll);

/*
** Vector operations
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
** Intersection functions
*/

double  v_intersect_sp(t_vec3 ray, t_ol *ol);
double  v_intersect_pl(t_ray ray, t_ol *ol);

double  v_intersect_cy(t_ray ray, t_ol *ol);
double  v_intersect_co(t_ray ray, t_ol *ol);
double  v_intersect_sp2(t_ray ray, t_ol *ol);
double  intersection(t_ray ray, t_ol *ol);
t_point		find_point_from_ray(t_ray ray);

/*
** Coloring functions
*/

t_shader        compute_color(t_ray ray,t_ol *ol, t_ll *ll, t_env *e);
void    color_pixel(int x, int y, t_shader sh, t_env *e); //to be changed for using img
t_shader        init_shader(void);
t_shader        shader_add(t_shader sh1, t_shader sh2);
int     specular(t_ray ray, t_point p, t_ol *ol, t_ll *ll);
t_col       color_add(t_col c1, t_col c2);

/*
** Normal related functions
*/

t_vec3      normal_sphere(t_ray ray, t_ol * ol);
t_vec3      normal_cylinder(t_ray ray, t_ol *ol);
t_vec3      normal_cone(t_ray ray, t_ol *ol);
t_vec3      get_normal(t_ray ray, t_ol *ol);

#endif

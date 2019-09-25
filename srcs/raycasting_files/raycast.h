/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanbox.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:25:49 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/20 10:35:15 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// /!/ This header still have the rtv1.h that is inside the directory
//     Need to modify the one that is in /includes to have everything in it and then change path 



//#include "libft.h"
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "rtv1.h"

#define X0 -WIDTH / 2
#define Y0 -WIDTH / 2
#define	RAYON 70

t_mlx   init(t_mlx *p);
int     sand(t_env *e);
int     sand2(t_env *e, t_ol *ol, t_ll *ll);
int     raycast(t_env *e, t_ol *ol, t_ll *ll);
int     color(t_point p, t_ol *ol, t_ll *ll);
/*
 *  * ** Vector operations
 *   */

t_point     create_pt(double x, double y, double z);
t_vec3    create_v(t_point ori, t_point dest);
t_vec3    v_add(t_vec3 u, t_vec3 v, char c);
t_vec3    v_mult(t_vec3 u, double k);
double      v_scal(t_vec3 u, t_vec3 v);
double      v_norm(t_vec3 u);
t_vec3    v_cross(t_vec3 u, t_vec3 v);
t_vec3    v_normalise(t_vec3 u);

/*
 *  * ** Intersection functions
 *   */

double  v_intersect_sp(t_vec3 ray, t_ol *ol, t_env *e);
double  v_intersect_pl(t_vec3 ray, t_ol *ol, t_env *e);

double  v_intersect_cy(t_vec3 ray, t_ol *ol, t_env *e);
double  v_intersect_co(t_ray ray, t_ol *ol, t_env *e);
double  v_intersect_sp2(t_ray ray, t_ol *ol, t_env *e);
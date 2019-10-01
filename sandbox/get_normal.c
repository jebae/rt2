/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 12:27:52 by sabonifa          #+#    #+#             */
/*   Updated: 2019/10/01 14:57:10 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sandbox.h"

t_vec3      normal_sphere(t_ray ray, t_ol * ol)
{
	t_vec3  normal;
	t_point point;

	point.x = ray.dir.x * ray.t;
	point.y = ray.dir.y * ray.t;
	point.z = ray.dir.z * ray.t;
	normal = create_v(ol->cen, point);
//	normal = create_v(point, ol->cen);
	normal = v_normalise(normal);
	return (normal);
}

t_vec3      normal_cylinder(t_ray ray, t_ol *ol)
{
	t_vec3	V = v_normalise(ol->dir);
	t_vec3	D = ray.dir;
	t_point	C = ol->cen;
	t_point O = ray.ori;
	t_vec3	X = create_v(C, O);
	t_vec3	N;
	double	k = tan(ol->angle / 2);
	double	m;

	// m = D|V*t + X|V   
	m = ray.t * v_scal(D, V) + v_scal(X, V);
	N.x = ray.dir.x * ray.t - C.x - m * V.x;
	N.y = ray.dir.y * ray.t - C.y - m * V.y;
	N.z = ray.dir.z * ray.t - C.z - m * V.z;

	N = v_normalise(N);
	return (N);
}

t_vec3      normal_cone(t_ray ray, t_ol *ol)
{
	t_vec3	V = v_normalise(ol->dir);
	t_vec3	D = ray.dir;
	t_point	C = ol->cen;
	t_point O = ray.ori;
	t_vec3	X = create_v(C, O);
	t_vec3	N;
	double	k = tan(ol->angle / 2);
	double	m;

	// m = D|V*t + X|V   
	m = ray.t * v_scal(D, V) + v_scal(X, V);
	N.x = ray.dir.x * ray.t - C.x - (1 + k * k) * m * V.x;
	N.y = ray.dir.y * ray.t - C.y - (1 + k * k) * m * V.y;
	N.z = ray.dir.z * ray.t - C.z - (1 + k * k) * m * V.z;

	N = v_normalise(N);
	return (N);
}


t_vec3      get_normal(t_ray ray, t_ol *ol)
{
	t_vec3 normal;
	if (ol->cur_shape == 1)
		normal = normal_sphere(ray, ol);
	if (ol->cur_shape == 2)
		normal = normal_cone(ray, ol);
	if (ol->cur_shape == 3)
		normal = normal_cylinder(ray, ol);
	return (normal);
}

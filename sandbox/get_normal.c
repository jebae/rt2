/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 12:27:52 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/26 12:37:09 by sabonifa         ###   ########.fr       */
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
	//normal = create_v(ol->cen, point);
	normal = create_v(point, ol->cen);
	normal = v_normalise(normal);
	return (normal);
}

t_vec3      normal_cylinder(t_ray ray, t_ol *ol)
{
	t_vec3  normal;
	t_vec3  oc;
	double  m;

	oc = create_v(ray.ori, ol->cen);
	oc = v_normalise(oc);
	m = ray.t * v_scal(v_normalise(ray.dir), v_normalise(ol->dir)) +
		v_scal(oc, v_normalise(ol->dir));
	//P - C - V* m
	normal.x = ray.dir.x * ray.t - ol->cen.x - ol->dir.x * m;
	normal.y = ray.dir.y * ray.t - ol->cen.y - ol->dir.y * m;
	normal.z = ray.dir.z * ray.t - ol->cen.z - ol->dir.z * m;
	normal = v_normalise(normal);
	return (normal);
}

t_vec3      normal_cone(t_ray ray, t_ol *ol)
{
	t_vec3  normal;
	t_vec3  oc;
	double  m;
	double k;

	k = tan(ol->angle / 2);
	oc = create_v(ray.ori, ol->cen);
	oc = v_normalise(oc);
	m = ray.t * v_scal(ray.dir, ol->dir) + v_scal(oc, ol->dir);
	//P - C - V* m
	normal.x = ray.dir.x * ray.t - ol->cen.x - ol->dir.x * m * (1 + k * k);
	normal.y = ray.dir.y * ray.t - ol->cen.y - ol->dir.y * m * (1 + k * k);
	normal.z = ray.dir.z * ray.t - ol->cen.z - ol->dir.z * m * (1 + k * k);
	normal = v_normalise(normal);
	return (normal);
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

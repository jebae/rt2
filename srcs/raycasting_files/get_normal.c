/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 12:27:52 by sabonifa          #+#    #+#             */
/*   Updated: 2019/11/12 14:04:03 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

t_vec3	normal_sphere(t_ray ray, t_ol *ol)
{
	t_vec3	normal;
	t_vec3	point;

	point = find_point_from_ray(ray);
	normal = v3_frompoints(ol->cen, point); //to change
	normal = v3_normalise(normal);
	return (normal);
}

t_vec3	normal_cylinder(t_ray ray, t_ol *ol)
{
	t_vec3	v;
	t_vec3	n;
	double	m;

	ol->dir = v3_normalise(ol->dir);
	v = v3_frompoints(ol->cen, ray.ori); //to change
	m = ray.t * v3_dotpdt(ray.dir, ol->dir) + v3_dotpdt(v, ol->dir);
	n.x = ray.ori.x + ray.dir.x * ray.t - ol->cen.x - m * ol->dir.x;
	n.y = ray.ori.y + ray.dir.y * ray.t - ol->cen.y - m * ol->dir.y;
	n.z = ray.ori.z + ray.dir.z * ray.t - ol->cen.z - m * ol->dir.z;
	n = v3_normalise(n);
	return (n);
}

t_vec3	normal_cone(t_ray ray, t_ol *ol)
{
	t_vec3	p;
	t_vec3	v;
	t_vec3	n;
	double	k;
	double	m;

	p = find_point_from_ray(ray);
	v = v3_frompoints(ol->cen, ray.ori); //to change
	ol->dir = v3_normalise(ol->dir);
	k = tan(((ol->angle * M_PI) / 180) / 2);
	m = ray.t * v3_dotpdt(ray.dir, ol->dir) + v3_dotpdt(v, ol->dir);
	n.x = p.x - ol->cen.x - (1 + k * k) * m * ol->dir.x;
	n.y = p.y - (1 + k * k) * m * ol->dir.y;
	n.z = p.z - ol->cen.z - (1 + k * k) * m * ol->dir.z;
	n = v3_normalise(n);
	return (n);
}

t_vec3	normal_plane(t_ray ray, t_ol *ol)
{
	t_vec3	normal;

	if (v3_dotpdt(ray.dir, v3_normalise(ol->nor)) <= 0)
		normal = v3_scalar(ol->nor, 1);
	else 
		normal = v3_scalar(ol->nor, -1);
	return (v3_normalise(normal));
}

t_vec3	get_normal(t_ray ray, t_ol *ol)
{
	t_vec3	normal;

	if (ol->cur_shape == 1)
		normal = normal_sphere(ray, ol);
	if (ol->cur_shape == 2)
		normal = normal_cone(ray, ol);
	if (ol->cur_shape == 3)
		normal = normal_cylinder(ray, ol);
	if (ol->cur_shape == 4)
		normal = normal_plane(ray, ol);
	return (normal);
}

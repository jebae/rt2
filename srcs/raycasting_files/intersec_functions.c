/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:08:14 by sabonifa          #+#    #+#             */
/*   Updated: 2019/10/01 17:22:51 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

double	v_intersect_sp2(t_ray ray, t_ol *ol)
{
	t_vec3	v;
	double	a;
	double	b;
	double	c;

	v = create_v(ol->cen, ray.ori);
	a = v_scal(ray.dir, ray.dir);
	b = 2 * v_scal(ray.dir, v);
	c = v_scal(v, v) - ol->radius * ol->radius;
	return (find_closest_intersection(a, b, c));
}

t_point	find_point_on_plane(t_ol *ol)
{
	t_point	c;
	t_vec3	normal;

	normal = v_normalise(ol->nor);
	c.x = ol->nor.x * (double)ol->d / v_scal(ol->nor, ol->nor);
	c.y = ol->nor.y * (double)ol->d / v_scal(ol->nor, ol->nor);
	c.z = ol->nor.z * (double)ol->d / v_scal(ol->nor, ol->nor);
	return (c);
}

double	v_intersect_pl(t_ray ray, t_ol *ol)
{
	t_point	c;
	t_vec3	v;
	t_vec3	norm;
	double	t;

	norm = v_normalise(ol->nor);
	c = find_point_on_plane(ol);
	v = create_v(c, ray.ori);
	if (v_scal(ray.dir, norm) == 0)
		return (FAR);
	t = -v_scal(v, norm) / v_scal(ray.dir, norm);
	if (t <= 0)
		return (FAR);
	return (t);
}

double	v_intersect_co(t_ray ray, t_ol *ol)
{
	t_vec3	v;
	double	k;
	double	a;
	double	c;
	double	b;

	v = create_v(ol->cen, ray.ori);
	k = tan(((ol->angle * M_PI) / 180) / 2);
	ol->dir = v_normalise(ol->dir);
	a = v_scal(ray.dir, ray.dir) - (1 + k * k)\
		* v_scal(ray.dir, ol->dir) * v_scal(ray.dir, ol->dir);
	b = 2 * (v_scal(ray.dir, v) - (1 + k * k)\
		* (v_scal(ray.dir, ol->dir) * v_scal(v, ol->dir)));
	c = v_scal(v, v) - (1 + k * k)\
		* v_scal(v, ol->dir) * v_scal(v, ol->dir);
	return (find_closest_intersection(a, b, c));
}

double	v_intersect_cy(t_ray ray, t_ol *ol)
{
	t_vec3	v;
	double	a;
	double	b;
	double	c;

	v = create_v(ol->cen, ray.ori);
	ol->dir = v_normalise(ol->dir);
	a = v_scal(ray.dir, ray.dir)\
		- v_scal(ray.dir, ol->dir) * v_scal(ray.dir, ol->dir);
	b = 2 * (v_scal(ray.dir, v)\
		- v_scal(ray.dir, ol->dir) * v_scal(v, ol->dir));
	c = v_scal(v, v) - v_scal(v, ol->dir) * v_scal(v, ol->dir)\
		- ol->radius * ol->radius;
	return (find_closest_intersection(a, b, c));
}

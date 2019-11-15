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

	v = v3_frompoints(ol->cen, ray.ori); //to change
	a = v3_dotpdt(ray.dir, ray.dir);
	b = 2 * v3_dotpdt(ray.dir, v);
	c = v3_dotpdt(v, v) - ol->radius * ol->radius;
	return (find_closest_intersection(a, b, c));
}

t_vec3	find_point_on_plane(t_ol *ol)
{
	t_vec3	c;
	t_vec3	normal;

	normal = v3_normalise(ol->nor);
	c.x = ol->nor.x * (double)ol->d / v3_dotpdt(ol->nor, ol->nor);
	c.y = ol->nor.y * (double)ol->d / v3_dotpdt(ol->nor, ol->nor);
	c.z = ol->nor.z * (double)ol->d / v3_dotpdt(ol->nor, ol->nor);
	return (c);
}

double	v_intersect_pl(t_ray ray, t_ol *ol)
{
	t_vec3	c;
	t_vec3	v;
	t_vec3	norm;
	double	t;

	norm = v3_normalise(ol->nor);
	c = find_point_on_plane(ol);
	v = v3_frompoints(c, ray.ori); //to change
	if (v3_dotpdt(ray.dir, norm) == 0)
		return (FAR);
	t = -v3_dotpdt(v, norm) / v3_dotpdt(ray.dir, norm);
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

	v = v3_frompoints(ol->cen, ray.ori); //to change
	k = tan(((ol->angle * M_PI) / 180) / 2);
	ol->dir = v3_normalise(ol->dir);
	a = v3_dotpdt(ray.dir, ray.dir) - (1 + k * k)\
		* v3_dotpdt(ray.dir, ol->dir) * v3_dotpdt(ray.dir, ol->dir);
	b = 2 * (v3_dotpdt(ray.dir, v) - (1 + k * k)\
		* (v3_dotpdt(ray.dir, ol->dir) * v3_dotpdt(v, ol->dir)));
	c = v3_dotpdt(v, v) - (1 + k * k)\
		* v3_dotpdt(v, ol->dir) * v3_dotpdt(v, ol->dir);
	return (find_closest_intersection(a, b, c));
}

double	find_closest_intersection1(double a, double b, double c)
{
	double	delta;
	double	t1;
	double	t2;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (FAR);
	else
	{
		t1 = (-b + sqrt(delta)) / (2 * a);
		t2 = (-b - sqrt(delta)) / (2 * a);
		return (t1);
	}
}

double	find_closest_intersection2(double a, double b, double c)
{
	double	delta;
	double	t1;
	double	t2;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (FAR);
	else
	{
		t1 = (-b + sqrt(delta)) / (2 * a);
		t2 = (-b - sqrt(delta)) / (2 * a);
		return (t2);
	}
}


double	v_intersect_cy(t_ray ray, t_ol *ol)
{
	t_vec3	v;
	double	a;
	double	b;
	double	c;

	int MAX  = 5;


	v = v3_frompoints(ol->cen, ray.ori); //to change
	ol->dir = v3_normalise(ol->dir);
	a = v3_dotpdt(ray.dir, ray.dir)\
		- v3_dotpdt(ray.dir, ol->dir) * v3_dotpdt(ray.dir, ol->dir);
	b = 2 * (v3_dotpdt(ray.dir, v)\
		- v3_dotpdt(ray.dir, ol->dir) * v3_dotpdt(v, ol->dir));
	c = v3_dotpdt(v, v) - v3_dotpdt(v, ol->dir) * v3_dotpdt(v, ol->dir)\
		- ol->radius * ol->radius;
	
	double t1;
	double t2;
	t1 = (find_closest_intersection1(a, b, c));
	t2 = (find_closest_intersection2(a, b, c));


	//m = D|V*t + X|V
	double m1 = v3_dotpdt(ray.dir, ol->dir) * t1 + v3_dotpdt(v, ol->dir);
	double m2 = v3_dotpdt(ray.dir, ol->dir) * t2 + v3_dotpdt(v, ol->dir);
	if (m1 > MAX || m1 < -MAX)
		t1 = FAR;
	if (m2 > MAX || m2 < -MAX)
		t2 = FAR;
	if (t1 <= 0 && t2 <= 0)
		return (FAR);
	t1 = t1 > 0 ? t1 : t2;
	t1 = t2 < t1 && t2 > 0 ? t2 : t1;
	
	return (t1);
}


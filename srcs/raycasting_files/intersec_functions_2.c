/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec_functions_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:44:27 by mhernand          #+#    #+#             */
/*   Updated: 2019/11/14 17:55:27 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

double	find_closest_intersection(double a, double b, double c)
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
		if (t1 <= 0 && t2 <= 0)
			return (0);
		t1 = t1 > 0 ? t1 : t2;
		t1 = t2 < t1 && t2 > 0 ? t2 : t1;
	}
	return (t1);
}

double	v_intersect_rectangle(t_ray ray, t_ol *ol)
{
	double			length;
	double			t;
	t_vec3			pp;
	t_rectangle		*rect;

	rect = &ol->rectangle;
	t = v_intersect_pl(ray, ol);
	if (t == FAR)
		return (FAR);
	pp = v_add(*((t_vec3 *)&ray.ori), v_mult(ray.dir, t), '+');
	pp = v_add(pp, rect->p, '-');
	length = v_scal(pp, rect->a);
	if (length < 0.0 || length > rect->norm_a)
		return (FAR);
	length = v_scal(pp, rect->b);
	if (length < 0.0 || length > rect->norm_b)
		return (FAR);
	return (t);
}

static double	box_get_t(t_ray *ray, t_box *box)
{
	double	tmin[3];
	double	tmax[3];

	tmin[0] = 
}

double			v_intersect_box(t_ray ray, t_ol *ol)
{
	double		t;
	t_box		*box;

	box = &ol->box;
	ray.ori = v_add(ray.ori, box->vmin, '-');
	ray.ori = m_mult(box->mat, ray.ori);
	ray.dir = m_mult(box->mat, ray.dir);
}

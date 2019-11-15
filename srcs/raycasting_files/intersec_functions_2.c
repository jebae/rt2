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

static void		swap_double(double *a, double *b)
{
	double		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static double	box_get_t(t_ray *ray, t_box *box)
{
	int			i;
	double		tmin[4];
	double		tmax[4];

	tmin[0] = -FAR;
	tmax[0] = FAR;
	i = 0;
	while (i < 3)
	{

		tmin[i + 1] = -((double *)&ray->ori)[i] / ((double *)&ray->dir)[i];
		tmax[i + 1] = (((double *)&box->vmax)[i] - ((double *)&ray->ori)[i])
			/ ((double *)&ray->dir)[i];
		if (tmin[i + 1] > tmax[i + 1])
			swap_double(&(tmin[i + 1]), &(tmax[i + 1]));
		if (tmin[0] > tmax[i + 1] || tmax[0] < tmin[i + 1])
			return (FAR);
		if (tmin[0] < tmin[i + 1])
			tmin[0] = tmin[i + 1];
		if (tmax[0] > tmax[i + 1])
			tmax[0] = tmax[i + 1];
		i++;
	}
	if (tmin[0] >= 0)
		return (tmin[0]);
	else if (tmin[0] < 0 && tmax[0] >= 0)
		return (tmax[0]);
	return (FAR);
}

double			v_intersect_box(t_ray ray, t_ol *ol)
{
	t_box		*box;

	box = &ol->box;
	ray.ori = v_add(ray.ori, box->vmin, '-');
	ray.ori = m_mult(box->mat, ray.ori);
	ray.dir = m_mult(box->mat, ray.dir);
	return (box_get_t(&ray, box));
}

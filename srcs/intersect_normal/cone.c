/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:51:39 by jebae             #+#    #+#             */
/*   Updated: 2019/12/19 23:41:44 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double	get_t(t_ray ray, t_cone *cone, t_vec3 v, double k)
{
	double	a;
	double	b;
	double	c;
	double	cp_dot_v;

	a = v3_dotpdt(ray.dir, ray.dir) - (1 + k * k)\
		* v3_dotpdt(ray.dir, cone->axis) * v3_dotpdt(ray.dir, cone->axis);
	b = 2 * (v3_dotpdt(ray.dir, v) - (1 + k * k)\
		* (v3_dotpdt(ray.dir, cone->axis) * v3_dotpdt(v, cone->axis)));
	c = v3_dotpdt(v, v) - (1 + k * k)\
		* v3_dotpdt(v, cone->axis) * v3_dotpdt(v, cone->axis);
	ray.t = find_closest_intersection(a, b, c);
	if (ray.t == FAR)
		return (FAR);
	cp_dot_v = v3_dotpdt(
		v3_sub(find_point_from_ray(ray), cone->cen), cone->axis);
	if (cp_dot_v >= 0.0 && cp_dot_v < cone->lower_height)
		return (ray.t);
	else if (cp_dot_v < 0.0 && cp_dot_v > -cone->upper_height)
		return (ray.t);
	return (FAR);
}

double			v_intersect_co(t_ray ray, void *object)
{
	t_vec3	v;
	double	k;
	t_cone	*cone;

	cone = object;
	v = v3_frompoints(cone->cen, ray.ori);
	k = tan(((cone->angle * M_PI) / 180) / 2);
	return (get_t(ray, cone, v, k));
}

t_vec3			normal_cone(t_ray ray, void *object)
{
	t_vec3	p;
	t_vec3	n;
	double	k;
	double	m;
	t_cone	*cone;

	cone = object;
	p = find_point_from_ray(ray);
	k = tan(((cone->angle * M_PI) / 180) / 2);
	m = ray.t * v3_dotpdt(ray.dir, cone->axis) +
		v3_dotpdt(v3_frompoints(cone->cen, ray.ori), cone->axis);
	n.x = p.x - cone->cen.x - (1 + k * k) * m * cone->axis.x;
	n.y = p.y - cone->cen.y - (1 + k * k) * m * cone->axis.y;
	n.z = p.z - cone->cen.z - (1 + k * k) * m * cone->axis.z;
	return (v3_normalise(n));
}

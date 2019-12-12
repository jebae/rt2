/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 12:27:52 by sabonifa          #+#    #+#             */
/*   Updated: 2019/11/15 16:54:55 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3	normal_sphere(t_ray ray, void *object)
{
	t_sphere	*sphere;
	t_vec3	normal;
	t_vec3	point;

	sphere = object;
	point = find_point_from_ray(ray);
	normal = v3_frompoints(sphere->cen, point); //to change
	normal = v3_normalise(normal);
	return (normal);
}

t_vec3	normal_cylinder(t_ray ray, void *object)
{
	t_vec3	v;
	t_vec3	n;
	double	m;
	t_cyl	*cyl;

	cyl = object;
	// cyl->axis = v3_normalise(cyl->axis); to be done by parser
	v = v3_frompoints(cyl->cen, ray.ori);
	m = ray.t * v3_dotpdt(ray.dir, cyl->axis) + v3_dotpdt(v, cyl->axis);
	n.x = ray.ori.x + ray.dir.x * ray.t - cyl->cen.x - m * cyl->axis.x;
	n.y = ray.ori.y + ray.dir.y * ray.t - cyl->cen.y - m * cyl->axis.y;
	n.z = ray.ori.z + ray.dir.z * ray.t - cyl->cen.z - m * cyl->axis.z;
	n = v3_normalise(n);
	return (n);
}

t_vec3	normal_cone(t_ray ray, void *object)
{
	t_vec3	p;
	t_vec3	v;
	t_vec3	n;
	double	k;
	double	m;
	t_cone	*cone;

	cone = object;
	p = find_point_from_ray(ray);
	v = v3_frompoints(cone->cen, ray.ori); //to change
	cone->axis = v3_normalise(cone->axis);
	k = tan(((cone->angle * M_PI) / 180) / 2);
	m = ray.t * v3_dotpdt(ray.dir, cone->axis) + v3_dotpdt(v, cone->axis);
	n.x = p.x - cone->cen.x - (1 + k * k) * m * cone->axis.x;
	n.y = p.y - cone->cen.y - (1 + k * k) * m * cone->axis.y;
	n.z = p.z - cone->cen.z - (1 + k * k) * m * cone->axis.z;
	n = v3_normalise(n);
	return (n);
}

t_vec3	normal_plane(t_ray ray, void *object)
{
	t_plane	*plane;
	t_vec3	normal;

	plane = object;
	if (v3_dotpdt(ray.dir, v3_normalise(plane->normal)) <= 0)
		normal = v3_scalar(plane->normal, 1);
	else 
		normal = v3_scalar(plane->normal, -1);
	return (v3_normalise(normal));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:08:14 by sabonifa          #+#    #+#             */
/*   Updated: 2019/12/17 21:42:33 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	v_intersect_sp2(t_ray ray, void *object)
{
	t_sphere	*sphere;
	t_vec3	v;
	double	a;
	double	b;
	double	c;

	sphere = (t_sphere *)object;
	v = v3_frompoints(sphere->cen, ray.ori);
	a = v3_dotpdt(ray.dir, ray.dir);
	b = 2 * v3_dotpdt(ray.dir, v);
	c = v3_dotpdt(v, v) - sphere->radius * sphere->radius;
	return (find_closest_intersection(a, b, c));
}

t_vec3	find_point_on_plane(t_plane *plane)
{
	t_vec3	c;
	t_vec3	normal;

	normal = v3_normalise(plane->normal);
	c.x = plane->normal.x * (double)plane->d / v3_norm2(plane->normal);
	c.y = plane->normal.y * (double)plane->d / v3_norm2(plane->normal);
	c.z = plane->normal.z * (double)plane->d / v3_norm2(plane->normal);
	return (c);
}

double	v_intersect_pl(t_ray ray, void *object)
{
	t_vec3	c;
	t_vec3	v;
	t_vec3	norm;
	double	t;
	t_plane	*plane;

	plane = object;
	norm = v3_normalise(plane->normal);
	c = find_point_on_plane(plane);
	v = v3_frompoints(c, ray.ori);
	if (v3_dotpdt(ray.dir, norm) == 0)
		return (FAR);
	t = -v3_dotpdt(v, norm) / v3_dotpdt(ray.dir, norm);
	if (t <= 0)
		return (FAR);
	return (t);
}

double	v_intersect_co(t_ray ray, void *object)
{
	t_vec3	v;
	double	k;
	double	a;
	double	c;
	double	b;
	t_cone	*cone;

	cone = object;
	v = v3_frompoints(cone->cen, ray.ori);
	k = tan(((cone->angle * M_PI) / 180) / 2);
	a = v3_dotpdt(ray.dir, ray.dir) - (1 + k * k)\
		* v3_dotpdt(ray.dir, cone->axis) * v3_dotpdt(ray.dir, cone->axis);
	b = 2 * (v3_dotpdt(ray.dir, v) - (1 + k * k)\
		* (v3_dotpdt(ray.dir, cone->axis) * v3_dotpdt(v, cone->axis)));
	c = v3_dotpdt(v, v) - (1 + k * k)\
		* v3_dotpdt(v, cone->axis) * v3_dotpdt(v, cone->axis);
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


double	v_intersect_cy(t_ray ray, void *object)
{
	t_vec3	v;
	double	a;
	double	b;
	double	c;
	t_cyl	*cyl;

	cyl = object;
	v = v3_frompoints(cyl->cen, ray.ori); //to change
	cyl->axis = v3_normalise(cyl->axis);
	a = v3_dotpdt(ray.dir, ray.dir)\
		- v3_dotpdt(ray.dir, cyl->axis) * v3_dotpdt(ray.dir, cyl->axis);
	b = 2 * (v3_dotpdt(ray.dir, v)\
		- v3_dotpdt(ray.dir, cyl->axis) * v3_dotpdt(v, cyl->axis));
	c = v3_dotpdt(v, v) - v3_dotpdt(v, cyl->axis) * v3_dotpdt(v, cyl->axis)\
		- cyl->radius * cyl->radius;
	
	double t1;
	double t2;
	t1 = (find_closest_intersection1(a, b, c));
	t2 = (find_closest_intersection2(a, b, c));


	//m = D|V*t + X|V
	double m1 = v3_dotpdt(ray.dir, cyl->axis) * t1 + v3_dotpdt(v, cyl->axis);
	double m2 = v3_dotpdt(ray.dir, cyl->axis) * t2 + v3_dotpdt(v, cyl->axis);
	if (m1 > cyl->height || m1 < 0)
		t1 = FAR;
	if (m2 > cyl->height || m2 < 0)
		t2 = FAR;
	if (t1 <= 0 && t2 <= 0)
		return (FAR);
	t1 = t1 > 0 ? t1 : t2;
	t1 = t2 < t1 && t2 > 0 ? t2 : t1;
	return (t1);
}

double	v_intersect_paraboloid(t_ray ray, void *object)  // PARABOLOID
{
	t_vec3	v;
	double	k;
	double	a;
	double	c;
	double	b;
	t_paraboloid *para;

	para = object;
	v = v3_frompoints(para->cen, ray.ori);
	k = para->k;
	para->dir = v3_normalise(para->dir);
	a = v3_dotpdt(ray.dir, ray.dir) - \
		v3_dotpdt(ray.dir, para->dir) * v3_dotpdt(ray.dir, para->dir);
	b = 2 * (v3_dotpdt(ray.dir, v) - \
		v3_dotpdt(ray.dir, para->dir) * (v3_dotpdt(v, para->dir) + 2*k));
	c = v3_dotpdt(v, v) - 1\
		* v3_dotpdt(v, para->dir) * (v3_dotpdt(v, para->dir) + 4 * k);
	return (find_closest_intersection(a, b, c));
}

double	v_intersect_ellipsoid(t_ray ray, void *object)  //ELLIPSOID
{
	t_vec3	v;
	double	k;
	double	a;
	double	c;
	double	b;
	t_ellipsoid *ell;

//	  A1  = 2*k*(D|V)
//    A2  = r^2 + 2*k*(X|V) - k
//    a   = 4*r^2*D|D - A1^2
//    b/2 = 4*r^2*D|X - A1*A2
//    c   = 4*r^2*X|X - A2^2             X = v

	ell = object;
	v = v3_frompoints(ell->cen, ray.ori);
	k = ell->d;
	ell->dir = v3_normalise(ell->dir);

double A1 = 2 * k * v3_dotpdt(ray.dir, ell->dir);
double A2 = ell->sum * ell->sum + 2 * k * v3_dotpdt(v, ell->dir) - k;

	a = 4 * ell->sum * ell->sum * v3_dotpdt(ray.dir, ray.dir) - A1 * A1;
	b = 2 * (4 * ell->sum * ell->sum * v3_dotpdt(ray.dir, v) - A1 * A2);
	c = 4 * ell->sum * ell->sum * v3_dotpdt(v, v) - A2 * A2;
// printf("A1: %f, A2: %f,  a: %f, b:%f\n", A1, A2, a, b);

	return (find_closest_intersection(a, b, c));
}

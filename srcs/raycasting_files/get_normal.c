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

t_vec3	normal_paraboloid(t_ray ray, void *object) // PARABOLOID
{
	t_vec3	p;
	t_vec3	v;
	t_vec3	n;
	double	k;
	double	m;
	t_paraboloid *para;

//m=(P-C)|V
// N = nrm( P-C-V*(m+k) )

	para = object;
	p = find_point_from_ray(ray);
	v = v3_frompoints(para->cen, ray.ori); //to change
	para->dir = v3_normalise(para->dir);
	k = para->k;
	m = v3_dotpdt(v3_frompoints(para->cen, p), para->dir);
			// m = ray.t * v3_dotpdt(ray.dir, ol->dir) + v3_dotpdt(v, ol->dir);
	// v = v3_scalar(v, m + k);
	// n = v3_frompoints(ol->cen, p);
	// n = v3_frompoints(p, v);
	n.x = p.x - para->cen.x - para->dir.x * (m + k);
	n.y = p.y - para->cen.y - para->dir.y * (m + k);
	n.z = p.z - para->cen.z - para->dir.z * (m + k);
	n = v3_normalise(n);
	// printf("n : < %f, %f, %f>", n.x, n.y, n.z);
	return (n);
}

t_vec3	normal_ellipsoid(t_ray ray, void *object) // ELLIPSOID
{
// 	Cmid = C + V*k/2
//    R = P - Cmid
//    N = nrm( R - V*(1-b^2/a^2)*(R|V) )
t_ellipsoid *ell;

ell = object;
double k = ell->k;
// double r = ol->radius;
t_vec3 C = para->cen;
t_vec3 V = v3_normalise(para->dir);
// t_vec3 X = v3_frompoints(C, ray.ori);

// double A1 = 2 * k * v3_dotpdt(ray.dir, V);
// double A2 = r * r + 2 * k * v3_dotpdt(X, V) - k;
// double	a = 4 * r * r * v3_dotpdt(ray.dir, ray.dir) - A1 * A1;
// double	b = 2 * (4 * r * r * v3_dotpdt(ray.dir, X) - A1 * A2);

t_vec3 Cmid = v3_add(C, v3_scalar(V, k /2));
t_vec3 P = find_point_from_ray(ray);
// t_vec3 R = v3_sub(P, Cmid);
// t_vec3 n = v3_normalise( v3_sub( R, v3_scalar( V, (1-(81/36)) * v3_dotpdt(R,V))));
t_vec3 n = v3_normalise(v3_frompoints(Cmid, P));
// printf("R : <%f %f %f>      V : <%f %f %f>\n", R.x, R.y, R.z, V.x, V.y, V.z);
// printf("A1: %f, A2: %f,  a: %f, b:%f\n", A1, A2, a, b);
// n = v3_normalise(v3_frompoints(Cmid, P));
	return (n);
}
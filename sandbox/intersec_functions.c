/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:08:14 by sabonifa          #+#    #+#             */
/*   Updated: 2019/10/01 14:47:12 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sandbox.h"

double	v_intersect_sp2(t_ray ray, t_ol *ol, t_env *e)
{
	t_point	C = ol->cen;
	t_point	O = ray.ori;
	t_vec3	D = ray.dir;
	t_vec3	X = create_v(C, O);

	double 	a;
	double	b;
	double	c;
	double	r = ol->radius;
	double delta;
	double	t = FAR;
	double	t2;

	/*
	 * a   = D|D
	 *    b/2 = D|X
	 *       c   = X|X - r*r
	 */

	a = v_scal(D, D);
	b = 2 * v_scal(D, X);
	c = v_scal(X, X) - r * r;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (FAR);
	else
	{
		t = (-b + sqrt(delta)) / (2 * a);
		t2 = (-b - sqrt(delta)) / (2 * a);
		if (t <= 0 && t2 <= 0)
			          return (0);
			t = t > 0 ? t : t2;
		t = t2 < t && t2 > 0 ? t2 : t;
	}
	return (t);
}

double	v_intersect_pl(t_vec3 ray, t_ol *ol, t_env *e)
{
	// D is the dir of the ray --> ray 
	// don't know what 't' is
	// o is ray origin --> cam pos;
	// t = -X | V / D | V
	double		t = 0; 
	t_vec3	tmp;
	t_point		plane_point;
	t_vec3	diff;

	// hello = create new vector that is the difference betweent camera position and point in the plane 
	plane_point.x = (double)ol->d / ol->nor.x;
	plane_point.y = 0;
	plane_point.z = 0;

	diff = create_v((t_point)e->cam.campos, plane_point);
	tmp.x = ol->nor.x;
	tmp.y = ol->nor.y;
	tmp.z = ol->nor.z;
	t = v_scal(diff, tmp) / v_scal(ray, tmp);

	if (t < 0)
		return (0); //return val to be modified to send the closest valid solution
	else
		return (1);
	return (0);
}

double	v_intersect_co(t_ray ray, t_ol *ol, t_env *e)
{
	t_point C = ol->cen;
	t_point O = ray.ori;
	t_vec3	V = v_normalise(ol->dir);
	t_vec3	D = v_normalise(ray.dir);
	t_vec3	X = create_v(C, O);
	double	k = tan(ol->angle / 2);
	double	t = ray.t;

	double	a;
	double	c;
	double	b;
	double 	delta;
	double	t1;
	double	t2;

	/*
	 * a   = D|D - (1+k*k)*(D|V)^2
	 *    b/2 = D|X - (1+k*k)*(D|V)*(X|V)
	 *       c   = X|X - (1+k*k)*(X|V)^2
	 */

	a = v_scal(D,D) - (1 + k * k) * v_scal(D, V) * v_scal(D,V);
	b = 2 * (v_scal(D, X) - (1 + k * k) * (v_scal(D, V) * v_scal(X, V)));
	c = v_scal(X, X) - (1 + k * k) * v_scal(X, V) * v_scal(X, V);

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (FAR);
	else
	{
		t1 = (-b + sqrt(delta)) / (2 * a);
		t2 = (-b - sqrt(delta)) / (2 * a);
		if (t <= 0 && t2 <= 0)
			return (0);
		t1 = t1 > 0 ? t1 : t2;
		t1 = t2 < t1 && t2 > 0 ? t2 : t1;
	}
	return (t1);
}

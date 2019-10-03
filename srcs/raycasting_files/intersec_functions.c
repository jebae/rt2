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

t_point	find_point_on_plane(t_ol *ol)
{
	t_point	C;

	C.x = ol->nor.x * ol->d / v_scal(ol->nor, ol->nor);
	C.y = ol->nor.y * ol->d / v_scal(ol->nor, ol->nor);
	C.z = ol->nor.z * ol->d / v_scal(ol->nor, ol->nor);
	
	return (C);
}

double	v_intersect_pl(t_ray ray, t_ol *ol)
{
	t_point	O = ray.ori;
	t_point	C;
	t_vec3	X;
	t_vec3	V = v_normalise(ol->nor);
	t_vec3	D = ray.dir;
	double	t;

	C = find_point_on_plane(ol);
	X = create_v(C, O);
	X = v_normalise(X);
//	printf("%f %f %f\n", O.x, O.y, O.z);
	if (v_scal(D, V) == 0)
		return (FAR);
	t = -v_scal(X, V) / v_scal(D, V);
	if (t < 0)
		return (FAR);
	return (t);
}

double	v_intersect_co(t_ray ray, t_ol *ol)
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

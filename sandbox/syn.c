/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:19:01 by mhernand          #+#    #+#             */
/*   Updated: 2019/10/01 16:18:03 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sandbox.h"


double  v_intersect_cy(t_ray ray, t_ol *ol, t_env *e)
{
	t_point	O = ray.ori;
	t_point	C = ol->cen;
	t_vec3	X = create_v(C, O);
	t_vec3	D = ray.dir;
	t_vec3	V = v_normalise(ol->dir);

	double	r = ol->radius;
	double	a;
	double	b;
	double	c;
	double delta;
	double	t;
	double	t2;

	a = v_scal(D, D) - v_scal(D, V) *v_scal(D, V);
	b = 2* (v_scal(D, X) - v_scal(D, V) * v_scal(X, V));
	c = v_scal(X, X) - v_scal(X, V) * v_scal(X, V) - r * r;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:19:01 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/24 18:38:18 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sandbox.h"

double  v_intersect_cy(t_ray ray, t_ol *ol, t_env *e)
{
	(void)e;
	double      t = 0;
	double      t_2 = 0;
	double      a = 0;
	double      b = 0;
	double      c = 0;
	double      det = 0;
	t_vec3    co;
	t_vec3    nor_dir = v_normalise(ol->dir);

	// V is a unit length vector that determines cylinder's axis

	//    a   = D|D - (D|V)^2
	//    b/2 = D|X - (D|V)*(X|V)
	//    c   = X|X - (X|V)^2 - r*r

	co = create_v(e->cam.campos, ol->cen);

	a = v_scal(ray.dir, ray.dir) - (v_scal(ray.dir, nor_dir) * v_scal(ray.dir, nor_dir));

	b = v_scal(ray.dir, co) - v_scal(ray.dir, nor_dir) * v_scal(co, nor_dir);
	b *= 2;

	c = v_scal(co, co) - (v_scal(co, nor_dir) * v_scal(co, nor_dir)) - ol->radius * ol->radius;

	det = b * b - 4 * a * c;
	double epsilon = 0.00000001;

	// delta < 0 means no intersections
	if (det < epsilon)
		return (FAR);

	// nearest intersection
	t = -(-b + sqrt (det))/ (2 *a);
	t_2 = -(-b - sqrt (det))/ (2 *a);

	// t<0 means the intersection is behind the ray origin
	// which we don't want
	if (t <= epsilon && t_2 <= epsilon)
		return (FAR);
	else
	{
		t = t < epsilon ? t_2 : t;
		t = t < t_2 ? t : t_2;
		return (t);
	}
	// if (t < 0)
	// return (0); //return val to be modified to send the closest valid solution
	return (FAR);
}

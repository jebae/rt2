/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:19:01 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/19 11:43:00 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sandbox.h"

double  v_intersect_cy(t_vector ray, t_ol *ol, t_env *e)
{
	(void)e;
	double      t = 0;
	double      t_2 = 0;
	double      a = 0;
	double      b = 0;
	double      c = 0;
	double      det = 0;
	t_vector    tmp_dir = {ol->dir.x, ol->dir.y, ol->dir.z};
	t_vector    co;
	t_point     tmp_ray = {ray.x, ray.y, ray.z};
	t_point     tmp_po_cen = {ol->cen.x, ol->cen.y, ol->cen.z};
	t_vector    nor_dir; nor_dir.y = ol->dir.y; nor_dir.z = ol->dir.z; nor_dir.x = ol->dir.x;
	nor_dir = v_normalise(nor_dir);
	t_vector    nor_ray = v_normalise(ray);

	// V is a unit length vector that determines cylinder's axis

	//    a   = D|D - (D|V)^2
	//    b/2 = D|X - (D|V)*(X|V)
	//    c   = X|X - (X|V)^2 - r*r

	co = create_v(e->cam.campos, tmp_po_cen);

	a = v_scal(ray, ray) - (v_scal(ray, tmp_dir) * v_scal(ray, tmp_dir));

	b = v_scal(ray, co) - v_scal(ray, tmp_dir) * v_scal(co, tmp_dir);
	b /= 2;

	c = v_scal(co, co) - (v_scal(co, tmp_dir) * v_scal(co, tmp_dir)) - (cos(ol->radius) * cos(ol->radius));

	det = b * b - a * c;
	double epsilon = 0.00000001;

	// delta < 0 means no intersections
	if (det < epsilon)
		return (0);

	// nearest intersection
	t = (-b - sqrt (det))/a;

	// t<0 means the intersection is behind the ray origin
	// which we don't want
	if (t <= epsilon)
		return (0);
	else
		return (1);
	// if (t < 0)
		// return (0); //return val to be modified to send the closest valid solution
	return (0);
}

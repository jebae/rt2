/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:35:27 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/19 19:28:03 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

#define ITY 5



int     color(t_point p, t_ol *ol, t_ll *ll)
{
	t_vec3 p_l = create_v(p, ll->pos);
	double  d2 = v_norm(p_l);
	t_vec3 n = create_v(ol->cen, p);  //normal vector to sphere on intersection
	n = v_normalise(n);
	double res = v_scal(p_l, n) / d2; //how much light hit the point
	if (res >= -0.009)
		return (255);
	res = ( res) * 255; //max light: alpha = 0
	int c = res;
	return (res);
}


/* Algo
* Find the point of intersection = t * ray
* trouver le vecteur vers la light
*  notyet - send a shadow ray trough all objects to see if it intersects
* trouver la normale du plan
* faire intensite * N . L
*/

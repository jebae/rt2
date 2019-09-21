/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:35:27 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/21 18:44:54 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sandbox.h"

#define ITY 5



int     color(t_point p, t_ol *ol, t_ll *ll)
{
	t_vec3 p_l = create_v(p, ll->pos);
	p_l = v_normalise(p_l);
	double  d2 = v_norm(p_l);
	t_vec3 n = create_v(ol->cen, p);  //normal vector to sphere on intersection
	n = v_normalise(n);
	double res = -v_scal(p_l, n); //how much light hit the point
//	printf("%f\n", res);
	if (res < -0.0)
		return (0xFF);
	res = (1 - res) * (0xFF); //max light: alpha = 0
	int c = res;
	return (c);
}


int		specular(t_ray ray, t_point p, t_ol *ol, t_ll *ll)
{
	t_vec3	V;
	t_vec3 L;
	t_vec3 N;  //normal vector to sphere on intersection
	double NL;
	double S;
	t_vec3 R;
	
	V = v_mult(ray.dir, -1);
	V = v_normalise(ray.dir);
	L = create_v(ll->pos, p);
	L = v_normalise(L);
	N = create_v(ol->cen, p);  //normal vector to sphere on intersection
	N = v_normalise(N);
	NL = v_scal(N, L);
	R = v_mult(N, 2 * NL);
	R = v_add(R, L, '-');
	S = v_scal(V, R);
	S = S < 0 ? 0 : S;
	S = pow(S, 1000);

	return ((1-S) * 0xFF);
}


/* Algo
* Find the point of intersection = t * ray
* trouver le vecteur vers la light
*  notyet - send a shadow ray trough all objects to see if it intersects
* trouver la normale du plan
* faire intensite * N . L
*/

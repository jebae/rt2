/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:08:14 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/14 16:38:33 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sandbox.h"

double	v_intersect_sp(t_vector ray, t_ol *ol, t_env *e)
{
	t_vector c_s; //vector camera->sphere center

	c_s = create_v(e->cam.campos, ol->cen );
	double a;
	double b;
	double c;
	double delta;
	a = 1.0;
	b = 2 * (v_scal(ray, c_s));
	c = v_scal(c_s, c_s) - ol->radius * ol->radius;
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (0); //return val to be modified to send the closest valid solution
	else
		return (1);	
}

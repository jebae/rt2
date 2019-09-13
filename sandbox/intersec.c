/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:08:14 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/12 19:07:50 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sandbox.h"

int	v_intersecit(t_vector ray)
{
	t_vector v; //vector camera->sphere center

	v = vector(point(cx,cy,cz), point(sx, sy, sz));
	double a = 1.0;
	double b = 2 * (v_scal(ray, v));
	double c = v_scal(v, v) - RAYON * RAYON;
	double delta = b * b - 4 * a * c;
	if (delta < 0)
		return (0);
	else
		return (1);
	
}

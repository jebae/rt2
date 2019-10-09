/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:47:38 by mhernand          #+#    #+#             */
/*   Updated: 2019/10/09 10:48:34 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

double		v_scal(t_vec3 u, t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

double		v_norm(t_vec3 u)
{
	return (sqrt(v_scal(u, u)));
}

t_vec3		v_normalise(t_vec3 u)
{
	return (v_mult(u, 1 / v_norm(u)));
}

t_vec3		v_cross(t_vec3 u, t_vec3 v)
{
	t_vec3	w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = u.z * v.x - u.x * v.z;
	w.z = u.x * v.y - u.y * v.x;
	return (w);
}

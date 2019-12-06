/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:01:39 by mhernand          #+#    #+#             */
/*   Updated: 2019/11/12 14:05:06 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

t_vec3		translation(t_vec3 pos, t_vec3 trans)
{
	t_vec3	new;

	new.x = pos.x + trans.x;
	new.y = pos.y + trans.y;
	new.z = pos.z + trans.z;
	return (new);
}

t_vec3		rotation(t_vec3 axis, t_vec3 rotx, t_vec3 roty, t_vec3 rotz)
{
	t_vec3	new;

	rotx = v_mult(rotx, 0.01);
	roty = v_mult(roty, 0.01);
	rotz = v_mult(rotz, 0.01);
	new.x = rotx.x * axis.x + roty.x * axis.y + rotz.x * axis.z;
	new.y = rotx.y * axis.x + roty.y * axis.y + rotz.y * axis.z;
	new.z = rotx.z * axis.x + roty.z * axis.y + rotz.z * axis.z;
	return (new);
}

int			is_vector_empty(t_vec3 vec)
{
	if (vec.x == 0 && vec.y == 0 && vec.z == 0)
		return (1);
	return (0);
}

int			is_matrix_empty(t_vec3 x, t_vec3 y, t_vec3 z)
{
	if (is_vector_empty(x) && is_vector_empty(y) && is_vector_empty(z))
		return (1);
	return (0);
}

// t_ol		*apply_extra(t_ol *ll_obj)
// {
// 	t_ol	*start;

// 	start = ll_obj;
// 	while (ll_obj)
// 	{
// 		if (!(is_vector_empty(ll_obj->tra)))
// 			ll_obj->cen = translation(ll_obj->cen, ll_obj->tra);
// 		if (!is_matrix_empty(ll_obj->rot_x, ll_obj->rot_y, ll_obj->rot_z))
// 		{
// 			if (m3_det(ll_obj->rot_x, ll_obj->rot_y, ll_obj->rot_z) < 0.9\
// 				&& m3_det(ll_obj->rot_x, ll_obj->rot_y, ll_obj->rot_z) > 1.1)
// 			{
// 				ft_putendl("A rotation matrix has poor arguments\
// 						, it has been ignored");
// 			}
// 			else
// 			{
// 				ll_obj->dir = rotation(ll_obj->dir, ll_obj->rot_x,\
// 				ll_obj->rot_y, ll_obj->rot_z);
// 			}
// 		}
// 		ll_obj = ll_obj->next;
// 	}
// 	return (start);
// }

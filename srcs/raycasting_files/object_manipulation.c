/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:01:39 by mhernand          #+#    #+#             */
/*   Updated: 2019/11/06 12:03:01 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

t_point		translation(t_point pos, t_vec3 trans)
{
	t_point	new;

	new.x = pos.x + trans.x;
	new.y = pos.y + trans.y;
	new.z = pos.z + trans.z;
	return (new);
}

t_vec3		rotation(t_vec3 axis, t_vec3 rotx, t_vec3 roty, t_vec3 rotz)
{
	t_vec3	new;

	new.x = rotx.x * axis.x + roty.x * axis.y + rotz.x * axis.z;
	new.x = rotx.y * axis.x + roty.y * axis.y + rotz.y * axis.z;
	new.x = rotx.z * axis.x + roty.z * axis.y + rotz.z * axis.z;
	return (new);
}

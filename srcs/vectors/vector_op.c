/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorcast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:13:30 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/19 16:16:32 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

t_point		create_pt(double x, double y, double z)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

t_vec3		create_v(t_point ori, t_point dest)
{
	t_vec3	u;

	u.x = dest.x - ori.x;
	u.y = dest.y - ori.y;
	u.z = dest.z - ori.z;
	return (u);
}

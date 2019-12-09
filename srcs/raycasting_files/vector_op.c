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

#include "rt.h"

t_vec3		create_pt(double x, double y, double z)
{
	t_vec3	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

t_vec3		create_v(t_vec3 ori, t_vec3 dest)
{
	t_vec3	u;

	u.x = dest.x - ori.x;
	u.y = dest.y - ori.y;
	u.z = dest.z - ori.z;
	return (u);
}

t_vec3		v_add(t_vec3 u, t_vec3 v, char c)
{
	t_vec3	w;
	int		s;

	s = 0;
	if (c == '+')
		s = 1;
	else if (c == '-')
		s = -1;
	w.x = u.x + s * v.x;
	w.y = u.y + s * v.y;
	w.z = u.z + s * v.z;
	return (w);
}

t_vec3		v_mult(t_vec3 u, double k)
{
	t_vec3	w;

	w.x = k * u.x;
	w.y = k * u.y;
	w.z = k * u.z;
	return (w);
}

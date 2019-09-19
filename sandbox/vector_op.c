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

#include "sandbox.h"

t_point		create_pt(double x, double y, double z)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

t_vec3	create_v(t_point ori, t_point dest)
{
	t_vec3	u;

	u.x = dest.x - ori.x;
	u.y = dest.y - ori.y;
	u.z = dest.z - ori.z;
	return (u);
}

t_vec3	v_add(t_vec3 u, t_vec3 v, char c)
{
	t_vec3	w;
	int			s;

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

t_vec3	v_mult(t_vec3 u, double k)
{
	t_vec3	w;

	w.x = k * u.x;
	w.y = k * u.y;
	w.z = k * u.z;
	return (w);
}

double			v_scal(t_vec3 u, t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

double			v_norm(t_vec3 u)
{
	return (sqrt(v_scal(u, u)));
}

t_vec3		v_normalise(t_vec3 u)
{
	return (v_mult(u, 1 / v_norm(u)));
}

t_vec3	v_cross(t_vec3 u, t_vec3 v)
{
	t_vec3	w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = u.z * v.x - u.x * v.z;
	w.z = u.x * v.y - u.y * v.x;
	return (w);
}

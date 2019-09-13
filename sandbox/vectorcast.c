/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorcast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:13:30 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/12 18:00:54 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sandbox.h"

t_point		point(double x, double y, double z)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

t_vector	vector(t_point o, t_point p)
{
	t_vector	u;

	u.x = o.x - p.x;
	u.y = o.y - p.y;
	u.z = o.z - p.z;
	return (u);
}

t_vector	v_add(t_vector u, t_vector v, char c)
{
	t_vector	w;
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

t_vector	v_mult(t_vector u, double k)
{
	t_vector	w;

	w.x = k * u.x;
	w.y = k * u.y;
	w.z = k * u.z;
	return (w);
}

double			v_scal(t_vector u, t_vector v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

double			v_norm(t_vector u)
{
	return (sqrt(v_scal(u, u)));
}

t_vector		v_normalise(t_vector u)
{
	return (v_mult(u, 1 / v_norm(u)));
}

t_vector		v_unit(t_vector u)
{
	return (v_mult(u, 1 / v_norm(u)));
}

t_vector	v_cross(t_vector u, t_vector v)
{
	t_vector	w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = u.z * v.x - u.x * v.z;
	w.z = u.x * v.y - u.y * v.x;
	return (w);
}

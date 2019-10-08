/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 12:32:44 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/26 13:15:23 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

t_col		color_add(t_col c1, t_col c2)
{
	t_col	c;

	c.r = (c1.r + c2.r);
	c.g = (c1.g + c2.g);
	c.b = (c1.b + c2.b);
	c.r = c.r > 0xFF ? 0xFF : c.r;
	c.g = c.g > 0xFF ? 0xFF : c.g;
	c.b = c.b > 0xFF ? 0xFF : c.b;
	return (c);
}

t_shader	init_shader(void)
{
	t_shader	shader;

	shader.diff.r = 0;
	shader.diff.g = 0;
	shader.diff.b = 0;
	shader.spec.r = 0;
	shader.spec.g = 0;
	shader.spec.b = 0;
	return (shader);
}

t_shader	shader_add(t_shader sh1, t_shader sh2)
{
	t_shader	s;

	s.diff = color_add(sh1.diff, sh2.diff);
	s.spec = color_add(sh1.spec, sh2.spec);
	return (s);
}

void		color_pixel(int x, int y, t_shader sh, t_env *e)
{
	t_col	c;

	c = sh.diff;
	c = color_add(sh.diff, sh.spec);
	c = color_add(c, e->amb.col);
	e->data[0 + x * (e->w.bpp / 8) + y * e->w.sl] = c.b;
	e->data[1 + x * (e->w.bpp / 8) + y * e->w.sl] = c.g;
	e->data[2 + x * (e->w.bpp / 8) + y * e->w.sl] = c.r;
	e->data[3 + x * (e->w.bpp / 8) + y * e->w.sl] = 0;
}

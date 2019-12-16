/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 02:59:06 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/16 22:26:24 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_objects(t_parse *p)
{
	t_str	*s;

	s = &p->str;
	if (p->index > 20)
	{
		ft_putendl("too many objects!");
		return ;
	}
	if ((ft_strcmp(s->word, "sphere") == 0))
	{
		p->flag |= 1UL << 4;
		p->index++;
	}
	if (p->flag & 1UL << 4)
		parse_sphere(p);
	if ((ft_strcmp(s->word, "cone") == 0))
	{
		p->flag |= 1UL << 5;
		p->index++;
	}
	if (p->flag & 1UL << 5)
		parse_cone(p);
	if ((ft_strcmp(s->word, "cylinder") == 0))
	{
		p->flag |= 1UL << 6;
		p->index++;
	}
	if (p->flag & 1UL << 6)
		parse_cylinder(p);
	if ((ft_strcmp(s->word, "plane") == 0))
	{
		p->flag |= 1UL << 7;
		p->index++;
	}
	if (p->flag & 1UL << 7)
		parse_plane(p);
	if ((ft_strcmp(s->word, "rectangle") == 0))
	{
		p->flag |= 1UL << 8;
		p->index++;
	}
	if (p->flag & 1UL << 8)
		parse_rectangle(p);
	if ((ft_strcmp(s->word, "box") == 0))
	{
		p->flag |= 1UL << 9;
		p->index++;
	}
	if (p->flag & 1UL << 9)
		parse_box(p);
	if ((ft_strcmp(s->word, "triangle") == 0))
	{
		p->flag |= 1UL << 10;
		p->index++;
	}
	if (p->flag & 1UL << 10)
		parse_triangle(p);
	if ((ft_strcmp(s->word, "pyramid") == 0))
	{
		p->flag |= 1UL << 11;
		p->index++;
	}
	if (p->flag & 1UL << 11)
		parse_pyramid(p);
	if ((ft_strcmp(s->word, "ring") == 0))
	{
		p->flag |= 1UL << 12;
		p->index++;
	}
	if (p->flag & 1UL << 12)
		parse_ring(p);
}

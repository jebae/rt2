/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 02:59:06 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/05 20:10:06 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_ring(t_parse *p)
{
	t_ol			*ob;
	t_arg_ring	r;
	t_str			*s;
	int				i;

	ob = p->ob;
	s = &p->str;
	i = p->index;
	ob[i].object = ft_mem(&p->mem, sizeof(t_ring));
	puts("Ring here");
	while (*s->buf != '\0' && ft_strcmp(s->line, "</ring>") != 0)
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		if ((ft_strcmp(s->word, "center")) == 0)
			handle_3vec_number(s, &r.center);
		if ((ft_strcmp(s->word, "normal")) == 0)
			handle_3vec_number(s, &r.normal);
		if ((ft_strcmp(s->word, "r_one")) == 0)
			handle_float_number(s, &r.r1);
		if ((ft_strcmp(s->word, "r_two")) == 0)
			handle_float_number(s, &r.r2);
		s->buf++;
	}
	puts("Ring done");
	// error message would be printed inside set_object
	//if (set_ring(&ob[i], &r) == RT_FAIL)
	// handle when fail
	p->flag &= ~(1UL << 12);
}

void	parse_pyramid(t_parse *p)
{
	t_ol		*ob;
	t_arg_pyramid	py;
	t_str		*s;
	int		i;

	ob = p->ob;
	s = &p->str;
	i = p->index;
	ob[i].object = ft_mem(&p->mem, sizeof(t_pyramid));
	puts("Pyramid here");
	while (*s->buf != '\0' && ft_strcmp(s->line, "</pyramid>") != 0)
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		if ((ft_strcmp(s->word, "a")) == 0)
			handle_3vec_number(s, &py.a);
		if ((ft_strcmp(s->word, "u")) == 0)
			handle_3vec_number(s, &py.u);
		if ((ft_strcmp(s->word, "v")) == 0)
			handle_3vec_number(s, &py.v);
		if ((ft_strcmp(s->word, "height")) == 0)
			handle_float_number(s, &py.height);
		s->buf++;
	}
	puts("Pyramid done");
	// error message would be printed inside set_object
	//if (set_pyramid(&ob[i], &py) == RT_FAIL)
	// handle when fail
	p->flag &= ~(1UL << 11);
}

void	parse_triangle(t_parse *p)
{
	t_ol		*ob;
	t_arg_triangle	t;
	t_str		*s;
	int		i;

	ob = p->ob;
	s = &p->str;
	i = p->index;
	ob[i].object = ft_mem(&p->mem, sizeof(t_triangle));
	puts("Triangle here");
	while (*s->buf != '\0' && ft_strcmp(s->line, "</triangle>") != 0)
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		if ((ft_strcmp(s->word, "a")) == 0)
			handle_3vec_number(s, &t.a);
		if ((ft_strcmp(s->word, "ab")) == 0)
			handle_3vec_number(s, &t.ab);
		if ((ft_strcmp(s->word, "ac")) == 0)
			handle_3vec_number(s, &t.ac);
		s->buf++;
	}
	puts("Triangle done");
	// error message would be printed inside set_object
	//if (set_triangle(&ob[i], &t) == RT_FAIL)
	// handle when fail
	p->flag &= ~(1UL << 10);
}

void	parse_box(t_parse *p)
{
	t_ol		*ob;
	t_arg_box	b;
	t_str		*s;
	int		i;

	ob = p->ob;
	s = &p->str;
	i = p->index;
	ob[i].object = ft_mem(&p->mem, sizeof(t_box));
	puts("Box here");
	while (*s->buf != '\0' && ft_strcmp(s->line, "</box>") != 0)
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		if ((ft_strcmp(s->word, "vmin")) == 0)
			handle_3vec_number(s, &b.vmin);
		if ((ft_strcmp(s->word, "a")) == 0)
			handle_3vec_number(s, &b.a);
		if ((ft_strcmp(s->word, "b")) == 0)
			handle_3vec_number(s, &b.b);
		if ((ft_strcmp(s->word, "norm_c")) == 0)
			handle_float_number(s, &b.norm_c);
		s->buf++;
	}
	puts("Box done");
	// error message would be printed inside set_object
	//if (set_box(&ob[i], &b) == RT_FAIL)
	// handle when fail
	p->flag &= ~(1UL << 9);
}

void	parse_rectangle(t_parse *p)
{
	t_ol		*ob;
	t_arg_rectangle r;
	t_str		*s;
	int		i;

	ob = p->ob;
	s = &p->str;
	i = p->index;
	ob[i].object = ft_mem(&p->mem, sizeof(t_rectangle));
	puts("Rectangle here");
	while (*s->buf != '\0' && ft_strcmp(s->line, "</rectangle>") != 0)
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		if ((ft_strcmp(s->word, "p")) == 0)
			handle_3vec_number(s, &r.p);
		if ((ft_strcmp(s->word, "a")) == 0)
			handle_3vec_number(s, &r.a);
		if ((ft_strcmp(s->word, "b")) == 0)
			handle_3vec_number(s, &r.b);
		s->buf++;
	}
	puts("Rectangle done");
	// error message would be printed inside set_object
	//if (set_rectangle(&ob[i], &r) == RT_FAIL)
	// handle when fail
	p->flag &= ~(1UL << 8);
}

void	parse_plane(t_parse *p)
{
	t_ol		*ob;
	t_arg_plane	pl;
	t_str		*s;
	int		i;

	ob = p->ob;
	s = &p->str;
	i = p->index;
	ob[i].object = ft_mem(&p->mem, sizeof(t_plane));	
	puts("Plane here");
	while (*s->buf != '\0' && ft_strcmp(s->line, "</plane>") != 0)
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		if ((ft_strcmp(s->word, "normal")) == 0)
			handle_3vec_number(s, &pl.normal);
		if ((ft_strcmp(s->word, "d")) == 0)
			handle_float_number(s, &pl.d);
		s->buf++;
	}
	puts("Plane Done");
	// error message would be printed inside set_object
	//if (set_plane(&ob[i], &pl) == RT_FAIL)
	// handle when fail
	p->flag &= ~(1UL << 7);
}

void	parse_cylinder(t_parse *p)
{
	t_ol		*ob;
	t_arg_cyl		c;
	t_str		*s;
	int		i;

	ob = p->ob;
	s = &p->str;
	i = p->index;
	ob[i].object = ft_mem(&p->mem, sizeof(t_cyl));
	puts("Cylinder here");
	while (*s->buf != '\0' && ft_strcmp(s->line, "</cylinder>") != 0)
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		if ((ft_strcmp(s->word, "center")) == 0)
			handle_3vec_number(s, &c.cen);
		if ((ft_strcmp(s->word, "axis")) == 0)
			handle_3vec_number(s, &c.axis);
		if ((ft_strcmp(s->word, "radius")) == 0)
			handle_float_number(s, &c.radius);
		if ((ft_strcmp(s->word, "height")) == 0)
			handle_float_number(s, &c.height);
		s->buf++;
	}
	puts("Cylinder done");
	// error message would be printed inside set_object
	//if (set_cyl(&ob[i], &c) == RT_FAIL)
	// handle when fail
	p->flag &= ~(1UL << 6);
}

void	parse_cone(t_parse *p)
{
	t_ol		*ob;
	t_arg_cone	c;
	t_str		*s;
	int		i;

	ob = p->ob;
	s = &p->str;
	i = p->index;
	ob[i].object = ft_mem(&p->mem, sizeof(t_cone));
	puts("Cone here");
	while (*s->buf != '\0' && ft_strcmp(s->line, "</cone>") != 0)
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		if ((ft_strcmp(s->word, "center")) == 0)
			handle_3vec_number(s, &c.cen);
		if ((ft_strcmp(s->word, "axis")) == 0)
			handle_3vec_number(s, &c.axis);
		if ((ft_strcmp(s->word, "angle")) == 0)
			handle_float_number(s, &c.angle);
		if ((ft_strcmp(s->word, "upper_height")) == 0)
			handle_float_number(s, &c.upper_height);
		if ((ft_strcmp(s->word, "lower_height")) == 0)
			handle_float_number(s, &c.lower_height);
		s->buf++;
	}
	puts("cone done");
	// error message would be printed inside set_object
	//if (set_cone(&ob[i], &c) == RT_FAIL)
	// handle when fail
	p->flag &= ~(1UL << 5);
}

void	parse_sphere(t_parse *p)
{
	t_ol		*ob;
	t_arg_sphere	sp;
	t_str		*s;
	int		i;

	ob = p->ob;
	s = &p->str;
	i = p->index;
	ob[i].object = ft_mem(&p->mem, sizeof(t_sphere));
	puts("Sphere is here");
	while (*s->buf != '\0' && ft_strcmp(s->line, "</sphere>") != 0)
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		if ((ft_strcmp(s->word, "center")) == 0)
			handle_3vec_number(s, &sp.cen);
		if ((ft_strcmp(s->word, "radius")) == 0)
			handle_float_number(s, &sp.radius);
		s->buf++;
	}
	p->flag &= ~(1UL << 4);
	// error message would be printed inside set_object
	//if (set_sphere(&ob[i], &sp) == RT_FAIL)
	// handle when fail
	puts("sphere done");
}

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

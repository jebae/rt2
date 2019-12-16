/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:20:54 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/16 22:21:21 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_cylinder(t_parse *p)
{
	t_ol		*ob;
	t_arg_cyl		c;
	t_str		*s;
	int		i;
	int tex_mode;

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
		if ((ft_strcmp(s->word, "optional")) == 0)
			handle_optional_vaules(p);
		if ((ft_strcmp(s->word, "tex_mode")) == 0)
			tex_mode = handle_int_number(s, tex_mode);
		if (tex_mode == 1)
		{
			tex_mode = 0;
			ft_putendl("texture mode detected");
		}
		//set texture
		if (tex_mode == 2)
		{
			tex_mode = 0;
			ft_putendl("bump mapping detected");
		}
		//set bump mapping
		s->buf++;
	}
	puts("Cylinder done");
	// error message would be printed inside set_object
	//if (set_cyl(&ob[i], &c) == RT_FAIL)
	// handle when fail
	p->flag &= ~(1UL << 6);
}

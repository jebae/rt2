/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:20:54 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 13:12:51 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_arg(t_str *s, t_arg_cyl *arg)
{
	if ((ft_strcmp(s->word, "center")) == 0)
		handle_3vec_number(s, &arg->cen);
	if ((ft_strcmp(s->word, "axis")) == 0)
		handle_3vec_number(s, &arg->axis);
	if ((ft_strcmp(s->word, "radius")) == 0)
		handle_float_number(s, &arg->radius);
	if ((ft_strcmp(s->word, "height")) == 0)
		handle_float_number(s, &arg->height);
}

void			parse_cylinder(t_parse *p)
{
	int				tex_mode;
	t_arg_cyl		arg;
	t_ol			*ob;
	t_str			*s;

	ob = &p->ob[p->index];
	s = &p->str;
	ob->object = ft_mem(&p->mem, sizeof(t_cyl));
	ft_bzero(&arg, sizeof(t_arg_cyl));
	puts("Cylinder here");
	while (*s->buf != '\0' && ft_strcmp(s->line, "</cylinder>") != 0)
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		parse_arg(s, &arg);
		if ((ft_strcmp(s->word, "optional")) == 0)
			handle_optional_vaules(p);
		if ((ft_strcmp(s->word, "tex_mode")) == 0)
			tex_mode = handle_int_number(s, tex_mode);
		if (tex_mode == 1)
		{
			tex_mode = 0;
			ft_putendl("texture mode detected");
		}
		if (tex_mode == 2)
		{
			tex_mode = 0;
			ft_putendl("bump mapping detected");
		}
		s->buf++;
	}
	puts("Cylinder done");
	if (set_cyl(ob, &arg) == RT_FAIL)
		p->mask |= RT_ENV_MASK_PARSE_FAIL;
	p->flag &= ~(1UL << 6);
}

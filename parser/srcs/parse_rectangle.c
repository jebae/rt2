/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:22:50 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/17 22:34:51 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_rectangle(t_parse *p)
{
	t_ol		*ob;
	t_arg_rectangle r;
	t_str		*s;
	int		i;
	int tex_mode;

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
		if ((ft_strcmp(s->word, "optional")) == 0)
			handle_optional_vaules(p);
		if ((ft_strcmp(s->word, "tex_mode")) == 0)
			tex_mode = handle_int_number(s, tex_mode);
		if (tex_mode == 1)
		{
			ft_putendl("texture mode detected");
			tex_mode = 0;
		}
		//set texture
		if (tex_mode == 2)
		{
			ft_putendl("bump mapping detected");
			tex_mode = 0;
		}
		//set bump mapping
		s->buf++;
	}
	puts("Rectangle done");
	if (set_rectangle(&ob[i], &r) == RT_FAIL)
		p->mask |= RT_ENV_MASK_PARSE_FAIL;
	p->flag &= ~(1UL << 8);
}

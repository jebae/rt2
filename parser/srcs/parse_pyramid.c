/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pyramid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:25:21 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/17 22:33:59 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
		if ((ft_strcmp(s->word, "optional")) == 0)
			handle_optional_vaules(p);
		s->buf++;
	}
	puts("Pyramid done");
	if (set_pyramid(&ob[i], &py) == RT_FAIL)
		p->ret |= RT_PARSE_RET_FAIL;
	p->flag &= ~(1UL << 11);
}

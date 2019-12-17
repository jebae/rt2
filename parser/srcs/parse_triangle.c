/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:24:32 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/17 22:35:32 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
		if ((ft_strcmp(s->word, "optional")) == 0)
			handle_optional_vaules(p);
		s->buf++;
	}
	puts("Triangle done");
	if (set_triangle(&ob[i], &t) == RT_FAIL)
		p->ret |= RT_PARSE_RET_FAIL;
	p->flag &= ~(1UL << 10);
}

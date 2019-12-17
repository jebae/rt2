/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:23:46 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/17 22:22:28 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
		if ((ft_strcmp(s->word, "optional")) == 0)
			handle_optional_vaules(p);
		s->buf++;
	}
	puts("Box done");
	if (set_box(&ob[i], &b) == RT_FAIL)
		p->ret |= RT_PARSE_RET_FAIL;
	p->flag &= ~(1UL << 9);
}

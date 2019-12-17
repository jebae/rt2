/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:26:05 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/17 22:35:12 by jebae            ###   ########.fr       */
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
		if ((ft_strcmp(s->word, "optional")) == 0)
			handle_optional_vaules(p);
		s->buf++;
	}
	puts("Ring done");
	if (set_ring(&ob[i], &r) == RT_FAIL)
		p->ret |= RT_PARSE_RET_FAIL;
	p->flag &= ~(1UL << 12);
}

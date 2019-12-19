/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paraboloid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:13:00 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/18 20:53:51 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_paraboloid(t_parse *p)
{
	t_ol		*ob;
	t_arg_paraboloid	pa;
	t_str		*s;
	int		i;

	ob = p->ob;
	s = &p->str;
	i = p->index;
	ob[i].object = ft_mem(&p->mem, sizeof(t_paraboloid));
	ft_putendl("Paraboloid is here");
	while (*s->buf != '\0' && ft_strcmp(s->line, "</paraboloid>") != 0)
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		if ((ft_strcmp(s->word, "center")) == 0)
			handle_3vec_number(s, &pa.cen);
		if ((ft_strcmp(s->word, "axis")) == 0)
			handle_3vec_number(s, &pa.axis);
		if ((ft_strcmp(s->word, "k")) == 0)
			handle_float_number(s, &pa.k);
		if ((ft_strcmp(s->word, "min")) == 0)
			handle_float_number(s, &pa.min);
		if ((ft_strcmp(s->word, "max")) == 0)
			handle_float_number(s, &pa.max);
		if ((ft_strcmp(s->word, "optional")) == 0)
			handle_optional_vaules(p);
		s->buf++;
	}
	p->flag &= ~(1UL << 16);
	if (set_paraboloid(&ob[i], &pa) == RT_FAIL)
		p->mask |= RT_ENV_MASK_PARSE_FAIL;
	ft_putendl("Paraboloid done");
}

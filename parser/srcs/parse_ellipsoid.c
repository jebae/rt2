/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ellipsoid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:22:38 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/18 20:55:10 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_ellipsoid(t_parse *p)
{
	t_ol		*ob;
	t_arg_ellipsoid	el;
	t_str		*s;
	int		i;

	ob = p->ob;
	s = &p->str;
	i = p->index;
	ob[i].object = ft_mem(&p->mem, sizeof(t_ellipsoid));
	ft_putendl("Ellipsoid is here");
	while (*s->buf != '\0' && ft_strcmp(s->line, "</ellipsoid>") != 0)
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		if ((ft_strcmp(s->word, "center")) == 0)
			handle_3vec_number(s, &el.cen);
		if ((ft_strcmp(s->word, "axis")) == 0)
			handle_3vec_number(s, &el.axis);
		if ((ft_strcmp(s->word, "d")) == 0)
			handle_float_number(s, &el.d);
		if ((ft_strcmp(s->word, "sum")) == 0)
			handle_float_number(s, &el.sum);
		if ((ft_strcmp(s->word, "optional")) == 0)
			handle_optional_vaules(p);
		s->buf++;
	}
	p->flag &= ~(1UL << 15);
	if (set_ellipsoid(&ob[i], &el) == RT_FAIL)
		p->mask |= RT_ENV_MASK_PARSE_FAIL;
	ft_putendl("Ellipsoid done");
}

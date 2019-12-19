/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_optional.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 20:54:10 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/18 19:06:05 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	handle_optional_vaules(t_parse *p)
{
	t_ol		*ob;
	t_str		*s;
	int		i;

	ob = p->ob;
	s = &p->str;
	i = p->index;
	printf("so i = %d\n", i);
	puts("optional HERE");
	while (*s->buf != '\0' && ft_strcmp(s->line, "</optional>") != 0)
	{
		if (*s->buf != '\n' && *s->buf)
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		if ((ft_strcmp(s->word, "specpower")) == 0)
			handle_int_number(s, &ob[i].specpower);
		if ((ft_strcmp(s->word, "specvalue")) == 0)
			handle_int_number(s, &ob[i].specvalue);
		if ((ft_strcmp(s->word, "ior")) == 0)
			handle_float_number(s, &ob[i].ior);
		if ((ft_strcmp(s->word, "reflectivity")) == 0)
			handle_float_number(s, &ob[i].reflectivity);
		if ((ft_strcmp(s->word, "transparency")) == 0)
			handle_float_number(s, &ob[i].transparency);
		if ((ft_strcmp(s->word, "color")) == 0)
			handle_3vec_number(s, &ob[i].dif);
		s->buf++;
	}
	puts("optional done");
}
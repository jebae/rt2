/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:22:04 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/16 22:22:18 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_plane(t_parse *p)
{
	t_ol		*ob;
	t_arg_plane	pl;
	t_str		*s;
	int		i;

	ob = p->ob;
	s = &p->str;
	i = p->index;
	ob[i].object = ft_mem(&p->mem, sizeof(t_plane));	
	puts("Plane here");
	while (*s->buf != '\0' && ft_strcmp(s->line, "</plane>") != 0)
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		if ((ft_strcmp(s->word, "normal")) == 0)
			handle_3vec_number(s, &pl.normal);
		if ((ft_strcmp(s->word, "d")) == 0)
			handle_float_number(s, &pl.d);
		if ((ft_strcmp(s->word, "optional")) == 0)
			handle_optional_vaules(p);
		s->buf++;
	}
	puts("Plane Done");
	// error message would be printed inside set_object
	//if (set_plane(&ob[i], &pl) == RT_FAIL)
	// handle when fail
	p->flag &= ~(1UL << 7);
}

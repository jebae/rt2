/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:41:54 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/06 19:05:53 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_distant_light(t_parse *p)
{
	t_ll		*li;
	t_arg_distant_light	sp;
	t_str		*s;
	int		i;

	li= p->li;
	s = &p->str;
	i = p->l_ind;
	li[i].light = ft_mem(&p->mem, sizeof(t_distant_light));
	puts("Distant light is here");
	while (*s->buf != '\0' && ft_strcmp(s->line, "</distant>") != 0)
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		if ((ft_strcmp(s->word, "dir")) == 0)
			handle_3vec_number(s, &sp.dir);
		if ((ft_strcmp(s->word, "rot")) == 0)
			handle_3vec_number(s, &sp.rot);
		s->buf++;
	}
	//if (set_distant_light(li, &sp) == RT_FAIL)
		// handle fail
	p->flag &= ~(1UL << 14);
	puts("Distant light done");
}

void	parse_spherical_light(t_parse *p)
{
	t_ll		*li;
	t_arg_spherical_light	sp;
	t_str		*s;
	int		i;

	li= p->li;
	s = &p->str;
	i = p->l_ind;
	li[i].light = ft_mem(&p->mem, sizeof(t_spherical_light));
	puts("Spherical light is here");
	while (*s->buf != '\0' && ft_strcmp(s->line, "</spherical>") != 0)
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		if ((ft_strcmp(s->word, "pos")) == 0)
			handle_3vec_number(s, &sp.pos);
		if ((ft_strcmp(s->word, "tra")) == 0)
			handle_3vec_number(s, &sp.tra);
		s->buf++;
	}
	//if (set_spherical_light(li, &sp) == RT_FAIL)
		// handle fail
	p->flag &= ~(1UL << 13);
	puts("spherical light done");
}

void	parse_lights(t_parse *p)
{
	t_str	*s;

	s = &p->str;
	if (p->l_ind > 5)
	{
		ft_putendl("Too many lights");
		return ;
	}
	if ((ft_strcmp(s->word, "spherical") == 0))
	{
		p->flag |= 1UL << 13;
		p->l_ind++;
	}
	if (p->flag & 1UL << 13)
		parse_spherical_light(p);
	if ((ft_strcmp(s->word, "distant") == 0))
	{
		p->flag |= 1UL << 14;
		p->l_ind++;
	}
	if (p->flag & 1UL << 14)
		parse_distant_light(p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:01:20 by almoraru          #+#    #+#             */
/*   Updated: 2019/11/28 03:58:38 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	init_strings(t_parse *p)
{
	t_mem *mem;
	t_str *s;

	mem = &p->mem;
	s = &p->str;
	s->line = (char *)ft_mem(mem, sizeof(char) * 1024);
	s->number = (char *)ft_mem(mem, sizeof(char) * 1024);
	s->sub_number = (char *)ft_mem(mem, sizeof(char) * 1024);
	s->word = (char *)ft_mem(mem, sizeof(char) * 1024);
	s->word2 = (char *)ft_mem(mem, sizeof(char) * 1024);
	s->time = (char *)ft_mem(mem, sizeof(char) * 1024);
	s->buf = (char *)ft_mem(mem, sizeof(char) * 1024 * 6);
	ft_putendl("Strings are initialized");
}

static void	init_mem(t_parse *p)
{
	t_mem	*mem;
	int		alloc;

	mem = &p->mem;
	alloc = 1024 * 1024 * 16;
	ft_bzero(mem, sizeof(t_mem*));
	is_alloc((mem->m = ft_memalloc(alloc)));
	mem->tsize = alloc;
	mem->usize = sizeof(int);
	ft_putendl("Memory is initialized");
}

int			init_everything(t_parse *p)
{
	init_mem(p);
	init_strings(p);
	p->flag |= 1UL;
	return (1);
}

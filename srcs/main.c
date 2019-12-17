/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:35:08 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 22:30:04 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		usage(void)
{
	ft_putendl("usage : ./rt [filename]");
}

int				main(int argc, char **argv)
{
	t_parse		p;
	t_env		e;

	if (argc != 2)
	{
		usage();
		return (1);
	}
	if (init_env(&e) == RT_FAIL)
	{
		clear_env(&e);
		return (1);
	}
	p.ob = e.ll_obj;
	p.li = e.ll_lit;
	parse(&p, argv[1]); // no need to protect? (e.g. wrong file)
	set_ray_grid_props(&e);
	run_event_loop(&e, &p, argv[1]);
	return (0);
}

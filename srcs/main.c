/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:35:08 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:36:53 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				main(int argc, char **argv)
{
	t_parse		p;
	t_env		e;

	(void)argc;
	if (init_env(&e) == RT_FAIL)
	{
		clear_env(&e);
		return (1);
	}
	p.ob = e.ll_obj;
	p.li = e.ll_lit;
	parse(&p, argv[1]);
	set_ray_grid_props(&e); // set ray grid props with camera parsed
	run_event_loop(&e);
	return (0);
}

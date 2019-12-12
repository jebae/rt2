/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:01:20 by mhernand          #+#    #+#             */
/*   Updated: 2019/12/12 18:19:03 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				main(int argc, char **argv)
{
	t_parse		p;
	t_env		e;

	(void)e;
	(void)argc;
	(void)argv;
	while (1)
	{
		parse(&p, argv[1]);
		// function to copy data from "p" to "e"
		// setup_camera -> save data to use in renderer
		// if (difference of xml file)
		//		multithread(e);
	}
	return (0);
}

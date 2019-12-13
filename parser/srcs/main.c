/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:53:13 by almoraru          #+#    #+#             */
/*   Updated: 2019/11/26 02:38:03 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	main(int ac, char **av)
{
	t_parse		p;

	ft_bzero(&p, sizeof(t_parse));
	if (ac > 1)
	{
		if (ac >= 3)
		{
			ft_putendl("options will be added later");
			return (0);
		}
		if ((p.fd = open(av[1], O_RDONLY)) < 0)
		{
			ft_putendl("File path no bueno");
			return (0);
		}
		//while(1)
		parse(&p, av[1]);
	}
	else
		ft_putendl("file not good");
	if (p.mem.m != NULL)
		free(p.mem.m);
	return (0);
}
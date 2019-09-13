/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:31:06 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/11 18:31:03 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sandbox.h"

int	key_hook(int key, void *param)
{
	if (key == 53)
		exit (0);
	return (0);
}

int	main(int ac, char **av)
{
	t_env	env;
	t_env	*e;

	e = &env;
	e = init(e);
	sand(e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->mlx);
	return (0);
}

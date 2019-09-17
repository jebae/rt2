/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:31:06 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/17 11:17:25 by sabonifa         ###   ########.fr       */
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

	/////////////////// S P H E R E /////////////////////
	t_ol obj; obj.cur_shape = 1; obj.cen.x = 0; obj.cen.y = 0;
	obj.cen.z = 20; obj.next = NULL; obj.radius = 50;
	t_ll *ll = NULL;
	t_ol	*ol;
	ol = &obj;
	/////////////////////////////////////////////////////

	/////////////////// P L A N E /////////////////////
	t_ol pla; pla.cur_shape = 4; pla.cen.x = 0; pla.cen.y = 0;
	pla.cen.z = 20; pla.next = NULL; pla.radius = 50;
	t_ll *ll = NULL;
	t_ol	*ol;
	ol = &pla;
	/////////////////////////////////////////////////////

	e = &env;
	e->cam.campos.x = 0; e->cam.campos.y = 0; e->cam.campos.z = -50;
	(e->w) = init(&(e->w));
	sand2(e, ol, ll);
	mlx_key_hook(e->w.wp, key_hook, e);
	mlx_loop(e->w.mp);
	return (0);
}

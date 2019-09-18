/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:31:06 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/18 17:39:42 by sabonifa         ###   ########.fr       */
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
	t_ll	*ll = NULL;
	t_ol	*ol;
	ol = &obj;
	/////////////////////////////////////////////////////

	/////////////////// P L A N E /////////////////////
	t_ol pla; pla.cur_shape = 4;
	pla.nor.x = 5; pla.nor.y = 1; pla.nor.z = 3; pla.d = 2;
	pla.next = NULL; pla.radius = 50;
	// t_ll	*ll = NULL;
	t_ol	*ol_pla;
	ol_pla = &pla;
	/////////////////////////////////////////////////////

	///////////////// C Y L I N D E R ///////////////////
	t_ol cl; cl.cur_shape = 3;
	cl.dir.x = 1; cl.dir.y = 0; cl.dir.z = 3; 
	cl.cen.x = 5; cl.cen.y = 1; cl.cen.z = 3; 	
	cl.next = NULL; cl.radius = 50;
	// t_ll	*ll = NULL;
	t_ol	*ol_cl;
	ol_cl = &cl;
	/////////////////////////////////////////////////////

	///////////////////// C O N E  ///////////////////////
	t_ol co; co.cur_shape = 2;
	co.dir.x = 10; co.dir.y = 10; co.dir.z = 0; 
	co.cen.x = 0; co.cen.y = 0; co.cen.z = 10; 	
	co.next = NULL; co.radius = 20; co.angle = M_PI / 6;
	// t_ll	*ll = NULL;
	t_ol	*ol_co;
	ol_co = &co;
	/////////////////////////////////////////////////////

	e = &env;
	e->cam.campos.x = 0; e->cam.campos.y = 0; e->cam.campos.z = -50;
	(e->w) = init(&(e->w));
//	sand2(e, ol_pla, ll);
//	sand2(e, ol, ll);
	sand2(e, ol_co, ll);
	mlx_key_hook(e->w.wp, key_hook, e);
	mlx_loop(e->w.mp);
	return (0);
}

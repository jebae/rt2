/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:31:06 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/23 19:07:19 by sabonifa         ###   ########.fr       */
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

	/////////////////// L I G H T //////////////////////
	t_ll	light; light.pos.x = 30; light.pos.y = 30; light.pos.z = 0;	
	t_ll	*ll = &light;
	///////////////////////////////////////////////////

	/////////////////// C A M E R A //////////////////////
	e = &env;
	e->cam.campos.x = 0; e->cam.campos.y = 0; e->cam.campos.z = -50;
	e->cam.left.x = 0.33; e->cam.left.y = 0; e->cam.left.z = 0;
	e->cam.up.x = 0; e->cam.up.y = 0.33; e->cam.up.z = 0;
	e->cam.forw.x = 0; e->cam.forw.y = 0; e->cam.forw.z = 1;
	e->cam.f_wdth = WIDTH; e->cam.f_hght = WIDTH; e->cam.focal_length = 100;

	e->amb.col.r = 0xFF * 0.1; e->amb.col.g = 0xFF * 0.1; e->amb.col.b = 0xFF * 0.1;
	///////////////////////////////////////////////////

	/////////////////// S P H E R E /////////////////////
	t_ol obj; obj.cur_shape = 1; obj.cen.x = 0; obj.cen.y = 0;
	obj.cen.z = 10; obj.next = NULL; obj.radius = 30;
	t_ol	*ol;
	ol = &obj;
	/////////////////////////////////////////////////////

	/////////////////// P L A N E /////////////////////
	t_ol pla; pla.cur_shape = 4;
	pla.nor.x = 5; pla.nor.y = 1; pla.nor.z = 3; pla.d = 2;
	pla.next = NULL; pla.radius = 50;
	t_ol	*ol_pla;
	ol_pla = &pla;
	/////////////////////////////////////////////////////

	///////////////// C Y L I N D E R ///////////////////
	t_ol cl; cl.cur_shape = 3;
	cl.dir.x = 2; cl.dir.y = 2; cl.dir.z = 0; 
	cl.cen.x = 0; cl.cen.y = 0; cl.cen.z = 50;
	cl.next = NULL; cl.radius = 60;
	t_ol	*ol_cl;
	ol_cl = &cl;
	/////////////////////////////////////////////////////

	///////////////////// C O N E  ///////////////////////
	t_ol co; co.cur_shape = 2;
	co.dir.x = 10; co.dir.y = -10; co.dir.z = 0; 
	co.cen.x = 0; co.cen.y = -2; co.cen.z = 10; 	
	co.next = ol; co.radius = 5; co.angle = M_PI / 6;
	t_ol	*ol_co;
	ol_co = &co;
	/////////////////////////////////////////////////////

//	e->cam.campos.x = 0; e->cam.campos.y = 0; e->cam.campos.z = -50;
	(e->w) = init(&(e->w));
	// sand2(e, ol_pla, ll);
	// sand2(e, ol, ll);
	// sand2(e, ol_co, ll);
//	sand2(e, ol_cl, ll);
	raycast(e, ol, ll);
	mlx_key_hook(e->w.wp, key_hook, e);
	mlx_loop(e->w.mp);
	return (0);
}

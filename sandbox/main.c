/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:31:06 by sabonifa          #+#    #+#             */
/*   Updated: 2019/10/02 15:52:44 by sabonifa         ###   ########.fr       */
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
	t_ll	light; light.pos.x = 0; light.pos.y = -10; light.pos.z = 25;	
	t_ll	*ll = &light;
	t_ll	light2; light2.pos.x = 0; light2.pos.y = 0; light2.pos.z = -20;
	light2.next = NULL;	
	light.next = NULL;	
	ll = &light;
	///////////////////////////////////////////////////

	/////////////////// C A M E R A //////////////////////
	e = &env;
	e->cam.campos.x = 0; e->cam.campos.y = 0; e->cam.campos.z = 0;
	e->cam.left.x = 0.33; e->cam.left.y = 0; e->cam.left.z = 0;
	e->cam.up.x = 0; e->cam.up.y = 0.33; e->cam.up.z = 0;
	e->cam.forw.x = 0; e->cam.forw.y = 0; e->cam.forw.z = 1;
	e->cam.f_wdth = WIDTH / 128; e->cam.f_hght = WIDTH / 128; e->cam.focal_length = 3;

	e->amb.col.r = 0xFF * 0.1; e->amb.col.g = 0xFF * 0.1; e->amb.col.b = 0xFF * 0.2;
	///////////////////////////////////////////////////

	/////////////////// S P H E R E /////////////////////
	t_ol obj; obj.cur_shape = 1; obj.cen.x = 5; obj.cen.y = 5;
	obj.cen.z = 30; obj.next = NULL; obj.radius = 3;
	t_ol	*ol;
	ol = &obj;
	/////////////////////////////////////////////////////

	/////////////////// P L A N E /////////////////////
	t_ol pla; pla.cur_shape = 4;
	pla.nor.x = 0; pla.nor.y = 1; pla.nor.z = 0; pla.d = 2;
	pla.next = NULL; pla.radius = 50;
	t_ol	*ol_pla;
	ol_pla = &pla;
	/////////////////////////////////////////////////////

	///////////////// C Y L I N D E R ///////////////////
	t_ol cl; cl.cur_shape = 3;
	cl.dir.x = 0; cl.dir.y = 100; cl.dir.z = 0; 
	cl.cen.x = 0; cl.cen.y = 0; cl.cen.z = 20;
	cl.next = NULL; cl.radius = 3;
	t_ol	*ol_cl;
	ol_cl = &cl;
	/////////////////////////////////////////////////////

	///////////////////// C O N E  ///////////////////////
	t_ol co; co.cur_shape = 2;
	co.dir.x = 0; co.dir.y = 100; co.dir.z = 0; 
	co.cen.x = 3; co.cen.y = 3; co.cen.z = 10; 	
	co.next = NULL; co.radius = 5; co.angle = M_PI / 6;
	t_ol	*ol_co;
	ol_co = &co;
	/////////////////////////////////////////////////////

//	e->cam.campos.x = 0; e->cam.campos.y = 0; e->cam.campos.z = -50;
	(e->w) = init(&(e->w));
	raycast(e, ol_pla, ll);
//	raycast(e, ol_cl, ll);
//	raycast(e, ol_co, ll);
//	raycast(e, ol, ll);
	mlx_key_hook(e->w.wp, key_hook, e);
	mlx_loop(e->w.mp);
	return (0);
}

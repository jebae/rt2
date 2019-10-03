/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rtv1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:55:08 by mhernand          #+#    #+#             */
/*   Updated: 2019/10/02 13:51:49 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    start_rtv1(t_env *e)
{
	//cam
	e->cam.left.x = 0.33; e->cam.left.y = 0; e->cam.left.z = 0;
	e->cam.up.x = 0; e->cam.up.y = 0.33; e->cam.up.z = 0;
	e->cam.forw.x = 0; e->cam.forw.y = 0; e->cam.forw.z = 1;
	e->cam.f_wdth = WIDTH / 128; e->cam.f_hght = WIDTH / 128; e->cam.focal_length = 3;
	
	//amb
	e->amb.col.r = 0xFF * 0.1; e->amb.col.g = 0xFF * 0.1; e->amb.col.b = 0xFF * 0.2;

	/////////////////// L I G H T //////////////////////
	t_ll	light; light.pos.x = 0; light.pos.y = -10; light.pos.z = 25;	
	t_ll	*ll = &light;
	t_ll	light2; light2.pos.x = 0; light2.pos.y = 0; light2.pos.z = -20;
	light2.next = NULL;	
	light.next = NULL;	
	ll = &light;
	///////////////////////////////////////////////////

	/////////////////// C A M E R A //////////////////////
	e->cam.campos.x = 0; e->cam.campos.y = 0; e->cam.campos.z = 0;
	e->cam.left.x = 0.33; e->cam.left.y = 0; e->cam.left.z = 0;
	e->cam.up.x = 0; e->cam.up.y = 0.33; e->cam.up.z = 0;
	e->cam.forw.x = 0; e->cam.forw.y = 0; e->cam.forw.z = 1;
	e->cam.f_wdth = WIDTH / 128; e->cam.f_hght = WIDTH / 128; e->cam.focal_length = 3;

	e->amb.col.r = 0xFF * 0.1; e->amb.col.g = 0xFF * 0.1; e->amb.col.b = 0xFF * 0.2;
	///////////////////////////////////////////////////

	/////////////////// S P H E R E /////////////////////
	t_ol obj; obj.cur_shape = 1; obj.cen.x = 0; obj.cen.y = -1;
	obj.cen.z = 30; obj.next = NULL; obj.radius = 3;
	t_ol	*ol;
	ol = &obj;
	/////////////////////////////////////////////////////

	/////////////////// P L A N E /////////////////////
	t_ol pla; pla.cur_shape = 4;
	pla.nor.x = 0; pla.nor.y = 1; pla.nor.z = 0; pla.d = 2;
	pla.next = &obj; pla.radius = 50;
	t_ol	*ol_pla;
	ol_pla = &pla;
	/////////////////////////////////////////////////////
	
	//raycast
	printf("hello i am light [%f] [%f] [%f]\n", e->ll_lit->pos.x, e->ll_lit->pos.y, e->ll_lit->pos.z);
	printf("hello i am FAKE light [%f] [%f] [%f]\n", ll->pos.x, ll->pos.y, ll->pos.z);
	printf("obj 1 :%d, obj 2 :%d\n", e->ll_obj->cur_shape, e->ll_obj->next->cur_shape);
	//raycast(e, e->ll_obj->next, e->ll_lit);
	raycast(e, ol_pla, ll);
	mlx_put_image_to_window(e->w.mp, e->w.wp, e->w.ip, 0, 0);
	mlx_hook(e->w.wp, 2, 1L << 2, key_press, e);
	mlx_hook(e->w.wp, 3, 1L << 3, key_release, e);
	mlx_hook(e->w.wp, 17, 1L << 17, quit, e);
	mlx_loop_hook(e->w.mp, touch, e);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rtv1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:55:08 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/26 13:22:10 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    start_rtv1(t_env *e)
{
	//cam
	e->cam.left.x = 0.33; e->cam.left.y = 0; e->cam.left.z = 0;
	e->cam.up.x = 0; e->cam.up.y = 0.33; e->cam.up.z = 0;
	e->cam.forw.x = 0; e->cam.forw.y = 0; e->cam.forw.z = 1;
	e->cam.f_wdth = WIDTH; e->cam.f_hght = WIDTH; e->cam.focal_length = 100;
	
	//amb
	e->amb.col.r = 0xFF * 0.1; e->amb.col.g = 0xFF * 0.1; e->amb.col.b = 0xFF * 0.2;

	//raycast
	raycast(e, e->ll_obj, e->ll_lit);
	mlx_put_image_to_window(e->w.mp, e->w.wp, e->w.ip, 0, 0);
	mlx_hook(e->w.wp, 2, 1L << 2, key_press, e);
	mlx_hook(e->w.wp, 3, 1L << 3, key_release, e);
	mlx_hook(e->w.wp, 17, 1L << 17, quit, e);
	mlx_loop_hook(e->w.mp, touch, e);
}

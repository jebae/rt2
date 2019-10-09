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
#include "raycast.h"

t_env	*setup_camera(t_env *e)
{
    t_vec3        tmp;

    tmp.x = 0;
    tmp.y = 1;
    tmp.z = 0;

    e->cam.forw = v_normalise(e->cam.camdir);
    e->cam.left = (v_cross(tmp, e->cam.forw));
    e->cam.up = v_normalise(v_cross(e->cam.forw, e->cam.left));
	e->cam.f_wdth = WIDTH / 128; e->cam.f_hght = WIDTH / 128; e->cam.focal_length = 3;
    return (e);
}

void    start_rtv1(t_env *e)
{
	//cam
	// e->cam.campos.x = 0; e->cam.campos.y = 0; e->cam.campos.z = 0;
	// e->cam.left.x = 0.33; e->cam.left.y = 0; e->cam.left.z = 0;
	// e->cam.up.x = 0; e->cam.up.y = 0.33; e->cam.up.z = 0;
	// e->cam.forw.x = 0; e->cam.forw.y = 0; e->cam.forw.z = 0.33;
	// e->cam.f_wdth = WIDTH / 128; e->cam.f_hght = WIDTH / 128; e->cam.focal_length = 3;
	
	
	//raycast
	e = setup_camera(e);
	printf("forward = (%f %f %f)\n", e->cam.forw.x, e->cam.forw.y, e->cam.forw.z);
	printf("left = (%f %f %f)\n", e->cam.left.x, e->cam.left.y, e->cam.left.z);
	printf("up = (%f %f %f)\n", e->cam.up.x, e->cam.up.y, e->cam.up.z);


	raycast(e, e->ll_obj, e->ll_lit);
	// raycast(e, ol_cl, e->ll_lit);
	// raycast(e, ol_co, e->ll_lit);
	// raycast(e, ol, e->ll_lit);
	mlx_put_image_to_window(e->w.mp, e->w.wp, e->w.ip, 0, 0);
	mlx_hook(e->w.wp, 2, 1L << 2, key_press, e);
	mlx_hook(e->w.wp, 3, 1L << 3, key_release, e);
	mlx_hook(e->w.wp, 17, 1L << 17, quit, e);
	mlx_loop_hook(e->w.mp, touch, e);
}
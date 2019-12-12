/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rtv1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:55:08 by mhernand          #+#    #+#             */
/*   Updated: 2019/12/09 17:09:07 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_env	*setup_camera(t_env *e)
{
	t_vec3	tmp;

	ft_bzero((void*)&tmp, sizeof(tmp));
	if (e->cam.campos.x == 0 && e->cam.campos.y == 0 && e->cam.campos.z == 0)
	{
		ft_putstr("The cam can't be positioned at <0, 0 ,0>\n");
		exit(0);
	}
	if (e->cam.camdir.x != 0 || e->cam.camdir.z != 0)
		tmp.y = 1;
	else
	{
		tmp.y = 10;
		tmp.z = 1;
	}
	tmp = v3_normalise(tmp);
	e->cam.forw = v3_normalise(e->cam.camdir);
	e->cam.left = (v3_cross(tmp, e->cam.forw));
	e->cam.up = v3_normalise(v3_cross(e->cam.forw, e->cam.left));
	e->cam.f_wdth = WIDTH / 384;
	e->cam.f_hght = WIDTH / 384;
	e->cam.focal_length = 1;
	return (e);
}

void	start_rtv1(t_env *e)
{
	e = setup_camera(e);
	// e->ll_obj = apply_extra(e->ll_obj);
	//e->image = &(e->w.ip);
	multi_thread(e);
	mlx_put_image_to_window(e->w.mp, e->w.wp, e->w.ip, 0, 0);
	//mlx_hook(e->w.wp, 2, 1L << 2, key_press, e);
	//mlx_hook(e->w.wp, 3, 1L << 3, key_release, e);
	//mlx_hook(e->w.wp, 17, 1L << 17, NULL, e);
	//mlx_loop_hook(e->w.mp, touch, e);
}
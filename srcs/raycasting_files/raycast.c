/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:15:40 by sabonifa          #+#    #+#             */
/*   Updated: 2019/10/09 11:23:18 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

double			intersection(t_ray ray, t_ol *ol)
{
	if (ol->cur_shape == 1)
		return (v_intersect_sp2(ray, ol));
	if (ol->cur_shape == 2)
		return (v_intersect_co(ray, ol));
	if (ol->cur_shape == 3)
		return (v_intersect_cy(ray, ol));
	if (ol->cur_shape == 4)
		return (v_intersect_pl(ray, ol));
	return (0);
}

double			to_vertex(int x, double f_width, int w_width)
{
	return (x * f_width / w_width - (f_width / 2));
}

t_ray			cast_ray(int x, int y, t_camera cam)
{
	t_ray		ray;
	t_vec3		up;
	t_vec3		left;
	t_vec3		forw;

	ray.ori = cam.campos;
	left = v_mult(cam.left, to_vertex(x, cam.f_wdth, WIDTH));
	up = v_mult(cam.up, to_vertex(y, cam.f_wdth, WIDTH));
	forw = v_mult(cam.forw, cam.focal_length);
	left = v_add(left, up, '+');
	left = v_add(left, forw, '+');
	ray.dir = v_normalise(left);
	ray.t = FAR;
	return (ray);
}

void			raycast_2(t_env *e, t_shader sh, t_ll *ll, t_ray ray)
{
	while (e->tp_o != NULL)
	{
		e->r = intersection(ray, e->tp_o);
		if (e->r > 0 && e->r < FAR && e->r < ray.t)
		{
			ray.t = e->r < ray.t ? e->r : ray.t;
			e->tp_l = ll;
			sh = init_shader();
			while (e->tp_l != NULL)
			{
				sh = shader_add(sh, compute_color(ray, e->tp_o, e->tp_l, e));
				e->tp_l = e->tp_l->next;
			}
			color_pixel(e->x, e->y, sh, e);
		}
		e->tp_o = e->tp_o->next;
	}
}

int				raycast(t_env *e, t_ol *ol, t_ll *ll)
{
	t_ray		ray;
	t_shader	sh;

	ft_bzero(&sh, sizeof(sh));
	while (e->x < WIDTH)
	{
		e->y = 0;
		while (e->y < WIDTH)
		{
			ray = cast_ray(e->x, e->y, e->cam);
			e->tp_o = ol;
			raycast_2(e, sh, ll, ray);
			e->y++;
		}
		e->x++;
	}
	return (0);
}

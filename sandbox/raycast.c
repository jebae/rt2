/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:15:40 by sabonifa          #+#    #+#             */
/*   Updated: 2019/10/01 15:03:27 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sandbox.h"

double  intersection2(t_ray ray, t_ol *ol, t_env *e)
{
	if (ol->cur_shape == 1)
		return (v_intersect_sp2(ray, ol, e));
	if (ol->cur_shape == 2)
		return (v_intersect_co(ray, ol, e));
	if (ol->cur_shape == 3)
		return (v_intersect_cy(ray, ol, e));
	return (0);
}

double  to_vertex(int x, double f_width, int w_width)
{
	return ( x * f_width / w_width - (f_width / 2));
}

t_ray   cast_ray(int x, int y, t_camera cam)
{
	t_ray   ray;
	t_vec3    up;
	t_vec3    left;
	t_vec3    forw;

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

int raycast(t_env *e, t_ol *ol, t_ll *ll)
{
	int x = 0;
	int y = 0;
	t_ray   ray;
	t_ll    *tp_l;
	t_ol    *tp_o;
	t_shader	sh;

	double r;
	while (x < WIDTH)
	{
		y = 0;
		while (y < WIDTH)
		{
			// cast a ray
			ray = cast_ray(x, y, e->cam);
			tp_o = ol;
			while (tp_o != NULL)
			{
				// intersect
				r = intersection2(ray, tp_o, e);
				ray.t = r < ray.t ? r : ray.t;//check if there is an intersection
				unsigned int c  = 0;
				unsigned int s = 0;
				if (ray.t > 0 && ray.t < FAR)
				{
					tp_l = ll;
					sh = init_shader();
					while (tp_l != NULL)
					{
						sh = shader_add(sh, compute_color(ray, tp_o, tp_l));
						tp_l = tp_l->next;
					}
					color_pixel(x, y, sh, e);
				}
				tp_o = tp_o->next;
			}
			y++;
		}
		x++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:15:40 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/19 18:59:20 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sandbox.h"

double	intersection(t_vec3 ray, t_ol *ol, t_env *e)
{
	if (ol->cur_shape == 1)
		return (v_intersect_sp(ray, ol, e));
//	if (ol->cur_shape == 2)
//		return (v_intersect_co(ray, ol, e));
	if (ol->cur_shape == 3)
		return (v_intersect_cy(ray, ol, e));
	if (ol->cur_shape == 4)
		return (v_intersect_pl(ray, ol, e));
	return (0);
}

double  intersection2(t_ray ray, t_ol *ol, t_env *e)
{
	if (ol->cur_shape == 1)
		return (v_intersect_sp2(ray, ol, e));
	if (ol->cur_shape == 2)
		return (v_intersect_co(ray, ol, e));
//	if (ol->cur_shape == 3)
//		return (v_intersect_cy(ray, ol, e));
	return (0);
}

int	sand2(t_env *e, t_ol *ol, t_ll *ll)
{
	int x = -1 + X0;
	int y = -1 + Y0;
	t_vec3  ray;
	t_ol	*templ;
	double	r;
	double	t;
	t_point cam_pos; cam_pos.x = 0; cam_pos.y = 0; cam_pos.z = -50;

	templ = ol;
	while (++x < -X0) //For each pixel
	{
		y = -1 + Y0;
		while(++y < -Y0)
		{
			t = FAR;
			r = 0;
			ray = create_v(e->cam.campos, create_pt(x, y, 0));
			ray = v_normalise(ray); //cast a ray from camera to point xy
			templ = ol;
			while (templ != NULL) //for each object
			{
				r = intersection(ray, ol, e);
				t = r < t ? r : t;//check if there is an intersection
				templ = templ->next;
			}
			if (t > 0 && t < FAR)
			{
				if (ol->cur_shape == 1)
					mlx_pixel_put(e->w.mp, e->w.wp, x-X0, y-Y0, 0xFFFFFF);//color pixel
				else if (ol->cur_shape == 2)
					mlx_pixel_put(e->w.mp, e->w.wp, x-X0, y-Y0, 0x00FF00);//color pixel
				else if (ol->cur_shape == 3)
					mlx_pixel_put(e->w.mp, e->w.wp, x-X0, y-Y0, 0x0FF0FF);//color pixel
				else if (ol->cur_shape == 4)
					mlx_pixel_put(e->w.mp, e->w.wp, x-X0, y-Y0, 0xFF0000);//color pixel	
			}
		}
	}
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
				r = intersection2(ray, ol, e);
				ray.t = r < ray.t ? r : ray.t;//check if there is an intersection
				int c  = 0;
				if (ray.t > 0 && ray.t < FAR)
				{
					t_point p;
					p.x = ray.dir.x * ray.t;
					p.y = ray.dir.y * ray.t;
					p.z = ray.dir.z * ray.t;
					c += color (p, ol, ll);
					c = c << 24;
					mlx_pixel_put(e->w.mp, e->w.wp, x, y, 0xFFFFFF);
					//color pixel
					/*  tp_l = *ll;
						while (tp_l != NULL)
						{
					//send shadow ray
					//send light ray
					//compute light
					tp_l = tp_l->next;
					}*/
				}
				tp_o = tp_o->next;
			}
			y++;
		}
		x++;
	}
	return (0);
}

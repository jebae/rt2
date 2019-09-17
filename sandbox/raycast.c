/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:15:40 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/14 18:41:53 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sandbox.h"

double	intersection(t_vector ray, t_ol *ol, t_env *e)
{
	if (ol->cur_shape == 0)
		return (v_intersect_sp(ray, ol, e));
	return (0);
}

int	sand2(t_env *e, t_ol *ol, t_ll *ll)
{
	int x = -1 + X0;
	int y = -1 + Y0;
	t_vector  ray;
	t_ol	*templ;
	double	r;
	double	t;
	t_point cam_pos; cam_pos.x = 0; cam_pos.y = 0; cam_pos.z = -50;

	templ = ol;
	while (++ x < -X0) //For each pixel
	{
		y = -1 + Y0;
		while(++y < -Y0)
		{
			t = FAR;
			r = 0;
			ray = create_v(e->cam.campos, create_pt(x, y, 0));
			ray = v_normalise(ray);
								//cast a ray from camera to point xy
			templ = ol;
			while (templ != NULL) //for each object
			{
				r = intersection(ray, ol, e);
				t = r < t ? r : t;//check if there is an intersection
				templ = templ->next;
			}
			if (t > 0 && t < FAR)
				mlx_pixel_put(e->w.mp, e->w.wp, x-X0, y-Y0, 0xFFFFFF);//color pixel	
		}
	}
	return (0);
}

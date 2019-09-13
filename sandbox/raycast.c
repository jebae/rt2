/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:15:40 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/12 19:07:09 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sandbox.h"

int	intersect(t_vector ray)
{
	//solve equat
	t_point cam; cam.x = 0; cam.y = 0; cam.z = -50;
	int a = ray.x * ray.x + ray.y * ray.y + ray.z * ray.z;
	int b = 2* (ray.x * cam.x + ray.y*cam.y + ray.z * cam.z);
	int c = cam.x*cam.x + cam.y*cam.y + cam.z*cam.z - RAYON * RAYON;

	int delta = b * b - 4 * a * c;
//	printf("b : %d, delta : %d\n", b, delta);
	if (delta > 0)
		return (0);
	return (1);
}

t_vector	raycast(int x, int y, t_point cam)
{
	t_vector	ray;

	ray.x = x - cam.x;
	ray.y = y - cam.y;
	ray.z = 0 - cam.z;
	
	int n = ray.x * ray.x + ray.y * ray.y + ray.z * ray.z;
	n = sqrt(n);
//	printf("n : %d\n", ray.x);
	ray.x /= n;;
	ray.y /= n;
	ray.z /=n;;
	

	return (ray);
}

int	intersectxy(int x, int y)
{
	int x1 = x; int y1 = y; int z1 = 0;
	int x0 = 0; int y0 = 0; int z0 = -50;
	int dx = x1 - x0;
	int dy = y1 - y0;
	int dz = z1 - z0;

	int a = dx*dx + dy*dy + dz*dz;
	int b = 2*dx*(-x0+cx) +  2*dy*(-y0+cy) +  2*dz*(-z0+cz);
	int c = cx*cx + cy*cy + cz*cz + x0*x0 + y0*y0 + z0*z0 +\
			-2*(cx*x0 + cy*y0 + cz*z0) - RAYON*RAYON;
	int delta = b * b - 4 * a * c;
	if (delta < 0)
		return (0);
	return (1);
}

int	sand(t_env *e)
{
	int x = -1;
	int y = -1;
	t_vector  ray;
	t_point cam; cam.x = 0; cam.y = 0; cam.z = -50;

	while (++ x + X0 < -X0) //For each pixel
	{
		y = -1;
		while(++y + Y0 < -Y0)
		{
			ray = vector(point(cx,cy,cz), point(x+X0, y+Y0, 0));
			ray = v_normalise(ray);
//			ray = raycast(x+X0, y+Y0, cam); //cast a unit ray
			if (v_intersecit(ray)) //for object, see if ray intersect object
					mlx_pixel_put(e->mlx, e->win, x, y, 0xFFFFFF);//color pixel
			mlx_pixel_put(e->mlx, e->win, WIDTH / 2, WIDTH / 2, 0xFF0000);
		}
	}
	return (0);
}

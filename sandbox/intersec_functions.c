/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:08:14 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/19 18:17:02 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sandbox.h"

double	v_intersect_sp(t_vec3 ray, t_ol *ol, t_env *e)
{
	t_vec3 c_s; //vector camera->sphere center

	c_s = create_v(e->cam.campos, ol->cen );
	double a;
	double b;
	double c;
	double delta;
	a = 1.0;
	b = 2 * (v_scal(ray, c_s));
	c = v_scal(c_s, c_s) - ol->radius * ol->radius;
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (0); //return val to be modified to send the closest valid solution
	else
		return (1);	
}

double  v_intersect_sp2(t_ray ray, t_ol *ol, t_env *e)
{
	t_vec3 c_s; //vector camera->sphere center

	c_s = create_v(ray.ori, ol->cen );
	double a;
	double b;
	double c;
	double delta;
	double t = 0;
	double t2;
	a = v_scal(ray.dir, ray.dir);
	b = 2 * (v_scal(ray.dir, c_s));
	c = v_scal(c_s, c_s) - ol->radius * ol->radius;
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (0); //return val to be modified to send the closest valid solution
	else
	{
		t = -(-b + sqrt(delta)) / (2 * a);
		t2 = -(-b - sqrt(delta)) / (2 * a);
		if (t <= 0 && t2 <= 0)
			//          return (0);
			t = t > 0 ? t : t2;
		t = t2 < t && t2 > 0 ? t2 : t;
	}
	return (t);
}

double	v_intersect_pl(t_vec3 ray, t_ol *ol, t_env *e)
{
	// D is the dir of the ray --> ray 
	// don't know what 't' is
	// o is ray origin --> cam pos;
	// t = -X | V / D | V
	double		t = 0; 
	t_vec3	tmp;
	t_point		plane_point;
	t_vec3	diff;

	// hello = create new vector that is the difference betweent camera position and point in the plane 
	plane_point.x = (double)ol->d / ol->nor.x;
	plane_point.y = 0;
	plane_point.z = 0;

	diff = create_v((t_point)e->cam.campos, plane_point);
	tmp.x = ol->nor.x;
	tmp.y = ol->nor.y;
	tmp.z = ol->nor.z;
	t = v_scal(diff, tmp) / v_scal(ray, tmp);

	if (t < 0)
		return (0); //return val to be modified to send the closest valid solution
	else
		return (1);
	return (0);
}

// double	v_intersect_cy(t_vector ray, t_ol *ol, t_env *e)
// {
// 	(void)e;
// 	(void)ol;
// 	(void)ray;
// 	double		t = 0; 
// 	// V is a unit length vector that determines cylinder's axis

// 	// m = D | V * t + X | V // m is the closest point on the axis to the hit point
// 	// m = v_scal(ray, (t_point)ol.cen) * t + v_scal(point on cyn, (t_point)ol.cen);

// 	// len() ? implement nous-memes

// 	// a = v_scal(ray, ray) - (v_scal(ray, (t_point)ol.cen)) * 2
// 	// c = v_scal(point on cy, point on sy) - (v_scal(point on cy, (t_point)ol.cen)) * 2 - ol.radius * 2
// 	// b = 2 * (v_scal(ray, point on cy) - (v_scal(ray, (t_point)ol.cen) * (v_scal(point on cy, (t_point)ol.cen))))

// 	// m = v_scal(ray, (t_point)ol.cen) * t + v_scal(point on cy, (t_point)ol.cen)
// 	// N = normalize(P - C - V * m)

// 	if (t < 0)
// 		return (0); //return val to be modified to send the closest valid solution
// 	else
// 		return (1);
// 	return (0);
// }

double	v_intersect_co(t_ray ray, t_ol *ol, t_env *e)
{
	(void)e;
	(void)ol;
	(void)ray;
	double		t = 0; 
	double		t_2 = 0; 
	double		a = 0;
	double		b = 0;
	double		c = 0;
	double		det = 0;
	t_vec3	co;
	t_vec3		tmp_ray;
	t_vec3	nor_dir = v_normalise(ol->dir);

	// the D is the ray and V is the direction vector
	co = create_v(ray.ori, ol->cen);

	a = (v_scal(ray.dir, nor_dir) * v_scal(ray.dir, nor_dir)) - (cos(ol->angle) * cos(ol->angle));

	b = 2 * ((v_scal(ray.dir, nor_dir) * v_scal(co, nor_dir)) - v_scal(ray.dir, co) * (cos(ol->angle) * cos(ol->angle)));

	c = (v_scal(co, nor_dir) * v_scal(co, nor_dir)) - (v_scal(co, co) * (cos(ol->angle) * cos(ol->angle)));

	det = b * b - 4 * a * c;
	if (det < 0)
		return (0);
	if (det == 0)
		t = b / (2 * a);
	else if (det > 0)
	{
		t = -(-b + sqrt(det) )/ (2 * a);
		t_2 = -(-b - sqrt(det)) / (2 * a);
		if (t <= 0 && t_2 <= 0)
			return (0);
		else
		{
			t = t < 0 ? t_2 : t;
			t = t < t_2 ? t : t_2;
		}
	}
	if (t < 0)
		return (0); //return val to be modified to send the closest valid solution
	else
	{
		tmp_ray.x = ol->cen.x - t * ray.dir.x; tmp_ray.y = ol->cen.y - t * ray.dir.y; tmp_ray.z = ol->cen.z - t * ray.dir.z; //vector from the point of intersection toward center
		if (ol->angle < M_PI / 2 && v_scal(tmp_ray, nor_dir) > 0)
			return (t);
		else 
			return (0);
	}

}

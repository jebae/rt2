/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 10:52:58 by sabonifa          #+#    #+#             */
/*   Updated: 2019/10/02 11:41:29 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"raycast.h"

t_point		find_point_from_ray(t_ray ray)
{
	t_point 	point;

	point.x = ray.ori.x + ray.dir.x * ray.t;
   	point.y = ray.ori.y + ray.dir.y * ray.t;
   	point.z = ray.ori.z + ray.dir.z * ray.t;
	return (point);
}

t_col		diffuse_color(t_vec3 normal, t_vec3 light, t_ol *ol)
{
	t_col	col;
	double	It;
	double kd = 1; //ol->kd
	t_vec3 n_light;

	n_light = v_normalise(light);
	It = kd * v_scal(n_light, normal);
	It = It < 0 ? 0 : It;
	It = It > 1.0 ? 1.0 : It;
	col.r = It * ol->dif.x;
	col.g = It * ol->dif.y;
	col.b = It * ol->dif.z;
	return (col);	
}

t_col		specular_color(t_ray ray, t_vec3 normal, t_ol *ol, t_ll *ll)
{
	t_vec3	L;
	double tmp;
	t_vec3	R;
	t_vec3	V; 
	t_col	c;

	V = v_mult(ray.dir, -1);
	L = create_v(find_point_from_ray(ray), ll->pos);
	L = v_normalise(L);
	tmp = v_scal(normal, L);
	tmp = tmp < 0 ? 0 : tmp;
	R = v_mult(normal, 2 * tmp);
	R = v_add(R, L, '-');
	tmp = v_scal(R, V);
	tmp = tmp < 0 ? 0 : tmp;
	tmp = pow(tmp, ol->specpower);
	c.r = tmp * ll->its.x * ol->specvalue / 100;
	c.g = tmp * ll->its.y * ol->specvalue / 100;
	c.b = tmp * ll->its.z * ol->specvalue / 100;
	return (c);
}

double			send_shadow_ray(t_point point, t_vec3 light, t_ol *ol)
{
	t_ray	shadow_ray;
	t_ol	*tp_o;
	double	r;

	r = 0;
	shadow_ray.ori = point;
	shadow_ray.dir = v_mult(light, 1);
	shadow_ray.dir = v_normalise(light);
	shadow_ray.t = v_norm(light);
	tp_o = ol;
	while (tp_o != NULL)
		{
			r = intersection2(shadow_ray, tp_o);
			if (r > 0.00001)
			{
				shadow_ray.t = r < shadow_ray.t ? r : shadow_ray.t;
			}
			tp_o = tp_o->next;
		}
		return (shadow_ray.t);
}

t_shader		compute_color(t_ray ray,t_ol *ol, t_ll *ll,t_env *e)
{
	t_shader	shader;
	t_point		point;
	t_vec3		normal;
	t_vec3		light;

	point = find_point_from_ray(ray);
	normal = get_normal(ray, ol);
	light = create_v(point, ll->pos);
	shader = init_shader();
	if (send_shadow_ray(point, light, e->ll_obj) < v_norm(light))
	{
		return (shader);
	}
	light = v_normalise(light);
	shader.diff = color_add(shader.diff, diffuse_color(normal, light, ol));
	shader.spec = color_add(shader.spec, specular_color(ray, normal, ol, ll));
	return (shader);
}

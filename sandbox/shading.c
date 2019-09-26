/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 10:52:58 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/26 13:09:51 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"sandbox.h"

double		send_shadow_ray(t_point point, t_vec3 light,  t_ol *ol)
{
	t_env *e; //remove
	t_ray	s_ray;
	t_ol	*tp_o;
	double	r;

	tp_o = ol;
	s_ray.ori = point;
	s_ray.dir = light;
	s_ray.dir = v_normalise(s_ray.dir);
	s_ray.t = FAR;
	while (tp_o != NULL)
	{
		r = intersection2(s_ray, tp_o, e);
		s_ray.t = r < s_ray.t ? r : s_ray.t;
		tp_o = tp_o->next;
	}
	return (s_ray.t);
}

t_col		diffuse_color(t_vec3 normal, t_vec3 light, t_ol *ol)
{
	t_col	col;
	double	It;
	double kd = 5000; //ol->kd
	t_vec3 n_light;
	t_vec3 li;
	double	norm;

	/////
	li.x = 100.0;
	//////
	norm = v_norm(light);
	n_light = v_normalise(light);
	It = kd * -v_scal(n_light, normal);
	It = It < 0 ? 0 : It;
	It /= M_PI * pow(norm, 2);
	//It *= li.x;
	It = It > 1.0 ? 1.0 : It;
	col.r = It * 0xFF; //ol->col.r;
	col.g = It * 0; //ol->col.g;
	col.b = It * 0; //ol->col.b;
	return (col);	
}

t_col		specular_color(t_ray ray, t_vec3 normal, t_ol *ol, t_ll *ll)
{
	t_vec3	L;
	double tmp;
	t_vec3	R;
	t_point	point;
	t_col	c;

	point.x = ray.dir.x * -ray.t;
   	point.y = ray.dir.y * -ray.t;
   	point.z = ray.dir.z * ray.t;
	L = create_v(point, ll->pos);
	L = v_normalise(L);
	tmp = v_scal(normal, L);
	R = v_mult(normal, 2 * tmp);
	R = v_add(R, L, '-');
	tmp = v_scal(R, v_mult(ray.dir, -1));
	tmp = tmp < 0 ? 0 : tmp;
		int sp = 10;
	tmp = pow(tmp, sp);	//ol->sp;
	c.r = 0.5 *0xFF * tmp; //ll->col.r
	c.g = 0.5 * 0xFF * tmp; //ll->col.g
	c.b = 0.5 * 0xFF * tmp; //ll->col.b
	return (c);
}

t_shader		compute_color(t_ray ray,t_ol *ol, t_ll *ll)
{
	t_shader	shader;
	t_point		point;
	t_vec3		normal;
	t_vec3		light;

	point.x = ray.dir.x * ray.t; point.y = ray.dir.y * ray.t; point.z = ray.dir.z * ray.t;
	normal = get_normal(ray, ol);
	//light = create_v(point, ll->pos);
	light = create_v(point, ll->pos);
 /*
  	light.x = -1;
	light.y = -1;
	light.z = 1;
	*/

//	light = v_normalise(light);
	//send shadow ray
	shader = init_shader();
	/*
	if (send_shadow_ray(point, light, ol) <= v_norm(light))
	{
		return (shader);
	}
	*/
	t_col col = diffuse_color(normal, light, ol);
	shader.diff = color_add(shader.diff, col);
	shader.spec = color_add(shader.spec, specular_color(ray, normal, ol, ll));
	return (shader);
}

//Pixel color = L ambiant + L diffuse + L specular

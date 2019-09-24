/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 10:52:58 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/24 19:16:23 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"sandbox.h"

////////////////////////AUTRE FICHIER
t_vec3		normal_sphere(t_ray ray, t_ol * ol)
{
	t_vec3	normal;
	t_point	point;

	point.x = ray.dir.x * ray.t;
	point.y = ray.dir.y * ray.t;
	point.z = ray.dir.z * ray.t;
	normal = create_v(ol->cen, point);
	normal = v_normalise(normal);
	return (normal);
}

t_vec3		normal_cylinder(t_ray ray, t_ol *ol)
{
	t_vec3	normal;
	t_vec3	oc;
	double	m;

	oc = create_v(ray.ori, ol->cen);
	oc = v_normalise(oc);
	m = ray.t * v_scal(v_normalise(ray.dir), v_normalise(ol->dir)) +
	   	v_scal(oc, v_normalise(ol->dir));
	//P - C - V* m
	normal.x = ray.dir.x * ray.t - ol->cen.x - ol->dir.x * m;
	normal.y = ray.dir.y * ray.t - ol->cen.y - ol->dir.y * m;
	normal.z = ray.dir.z * ray.t - ol->cen.z - ol->dir.z * m;
	normal = v_normalise(normal);
	return (normal);
}

t_vec3		normal_cone(t_ray ray, t_ol *ol)
{
	t_vec3	normal;
	t_vec3	oc;
	double	m;
	double k;

	k = tan(ol->angle / 2);
	oc = create_v(ray.ori, ol->cen);
	oc = v_normalise(oc);
	m = ray.t * v_scal(ray.dir, ol->dir) + v_scal(oc, ol->dir);
	//P - C - V* m
	normal.x = ray.dir.x * ray.t - ol->cen.x - ol->dir.x * m * (1 + k * k);
	normal.y = ray.dir.y * ray.t - ol->cen.y - ol->dir.y * m * (1 + k * k);
	normal.z = ray.dir.z * ray.t - ol->cen.z - ol->dir.z * m * (1 + k * k);
	normal = v_normalise(normal);
	return (normal);
}


t_vec3		get_normal(t_ray ray, t_ol *ol)
{
	t_vec3 normal;
	if (ol->cur_shape == 1)
		normal = normal_sphere(ray, ol);
	if (ol->cur_shape == 2)
		normal = normal_cone(ray, ol);
	if (ol->cur_shape == 3)
		normal = normal_cylinder(ray, ol);
	return (normal);
}


//////////////////////////////////////
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

t_col		color_add(t_col c1, t_col c2)
{
	t_col	c;

	c.r = (c1.r + c2.r);
	c.g = (c1.g + c2.g);
	c.b = (c1.b + c2.b);
	c.r = c.r > 0xFF ? 0xFF : c.r;
	c.g = c.g > 0xFF ? 0xFF : c.g;
	c.b = c.b > 0xFF ? 0xFF : c.b;
	return (c);
}

t_col		diffuse_color(t_vec3 normal, t_vec3 light, t_ol *ol)
{
	t_col	col;
	double	It;
	double kd = 0.9; //ol->kd

	It = kd * -v_scal(light, normal);
//	It = It < 0 ? 0 : It;
	col.r = It * 0; //ol->col.r;
	col.g = It * 0; //ol->col.g;
	col.b = It * 0xFF; //ol->col.b;
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
		int sp = 500;
	tmp = pow(tmp, sp);	//ol->sp;
	c.r = 0xFF * tmp; //ll->col.r
	c.g = 0xFF * tmp; //ll->col.g
	c.b = 0xFF * tmp; //ll->col.b
	return (c);
}

t_shader		init_shader(void)
{
	t_shader	shader;

	shader.diff.r = 0;
	shader.diff.g = 0;
	shader.diff.b = 0;
	shader.spec.r = 0;
	shader.spec.g = 0;
	shader.spec.b = 0;
	return (shader);
}

t_shader		shader_add(t_shader sh1, t_shader sh2)
{
	t_shader	s;

	s.diff = color_add(sh1.diff, sh2.diff);
	s.spec = color_add(sh1.spec, sh2.spec);
	return (s);
}

t_shader		compute_color(t_ray ray,t_ol *ol, t_ll *ll)
{
	t_shader	shader;
	t_point		point;
	t_vec3		normal;
	t_vec3		light;

	point.x = ray.dir.x * ray.t; point.y = ray.dir.y * ray.t; point.z = ray.dir.z * ray.t;
	normal = get_normal(ray, ol);
	light = create_v(point, ll->pos);
	light = v_normalise(light);
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

void	color_pixel(int x, int y, t_shader sh, t_env *e)
{
	t_col	c;

	c = color_add(sh.diff, sh.spec);
	c = color_add(c, e->amb.col);
	mlx_pixel_put(e->w.mp, e->w.wp, x, y, (c.r << 16) + (c.g << 8) + c.b);
}










//Pixel color = L ambiant + L diffuse + L specular

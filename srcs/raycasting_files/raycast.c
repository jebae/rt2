#include "raycast.h"

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
	left = v3_scalar(cam.left, to_vertex(x, cam.f_wdth, WIDTH));
	up = v3_scalar(cam.up, to_vertex(y, cam.f_wdth, WIDTH));
	forw = v3_scalar (cam.forw, cam.focal_length);
	left = v3_add(left, up);
	left = v3_add(left, forw);
	//ray.dir = v_normalise(left);
	ray.dir = v3_normalise(left);
	ray.t = FAR;
	return (ray);
}

int				trace(t_env *e, t_trace_record *rec)
{
	int			i;
	double		t;

	rec->ray.t = FAR;
	i = 0;
	while (i < e->num_objs)
	{
		t = e->ll_obj[i].intersect(rec->ray, e->ll_obj[i].object);
		if (t > 0 && t < FAR && t < rec->ray.t)
		{
			rec->ray.t = t;
			rec->obj = &(e->ll_obj[i]);
		}
		i++;
	}
	if (rec->ray.t == FAR)
		return (RT_FALSE);
	rec->point = find_point_from_ray(rec->ray);
	rec->normal = rec->obj->get_normal(rec->ray, rec->obj->object);
	// set color regarding texture_mapping
	// set normal regarding bump_mapping
	return (RT_TRUE);
}

void			calc_shade(t_env *e, t_trace_record *rec)
{
	int			i;
	t_shader	sh;

	sh = init_shader();
	i = 0;
	while (i < e->num_lights)
	{
		sh = shader_add(sh, compute_color(rec, &(e->ll_lit[i]), e));
		i++;
	}
	color_pixel(e->x, e->y, sh, e);
}

int				raycast(t_env *e)
{
	t_trace_record	rec;

	while (e->x < WIDTH)
	{
		e->y = e->y_min;
		while (e->y < e->y_max)
		{
			rec.ray = cast_ray(e->x, e->y, e->cam);
			if (trace(e, &rec))
				calc_shade(e, &rec);
			e->y++;
		}
		e->x++;
	}
	return (0);
}

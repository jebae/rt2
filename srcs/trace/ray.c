#include "rt.h"

static double	to_vertex(int x, double f_width, int w_width)
{
	return (x * f_width / w_width - (f_width / 2));
}

t_ray			cast_ray(int x, int y, t_env *e)
{
	t_ray		ray;
	t_vec3		up;
	t_vec3		left;
	t_vec3		forw;
	t_camera	*cam;

	cam = &e->cam;
	ray.ori = cam->campos;
	left = v3_scalar(cam->left, to_vertex(x, cam->f_wdth, e->width));
	up = v3_scalar(cam->up, to_vertex(y, cam->f_hght, e->height));
	forw = v3_scalar(cam->forw, cam->focal_length);
	left = v3_add(left, up);
	left = v3_add(left, forw);
	ray.dir = v3_normalise(left);
	ray.t = FAR;
	return (ray);
}

#include "rt.h"

t_ray			cast_ray(int x, int y, t_env *e)
{
	t_ray		ray;
	ray.ori = e->cam.campos;
	ray.dir = v3_add(e->offset, v3_scalar(e->dx, x));
	ray.dir = v3_add(ray.dir, v3_scalar(e->dy, y));
	ray.dir = v3_normalise(ray.dir);
	ray.t = FAR;
	return (ray);
}

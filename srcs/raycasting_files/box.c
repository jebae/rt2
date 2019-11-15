#include "raycast.h"

static void		swap_double(double *a, double *b)
{
	double		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static double	get_t(double *ray_ori, double *ray_dir, double *vmax)
{
	int			i;
	double		tmin[3];
	double		tmax[3];

	i = 0;
	while (i < 3)
	{
		tmin[i] = -ray_ori[i] / ray_dir[i];
		tmax[i] = (vmax[i] - ray_ori[i]) / ray_dir[i];
		if (tmin[i] > tmax[i])
			swap_double(&(tmin[i]), &(tmax[i]));
		if (tmin[0] > tmax[i] || tmax[0] < tmin[i])
			return (FAR);
		tmin[0] = (tmin[0] < tmin[i]) ? tmin[i] : tmin[0];
		tmax[0] = (tmax[0] > tmax[i]) ? tmax[i] : tmax[0];
		i++;
	}
	if (tmin[0] > 0.0)
		return (tmin[0]);
	else if (tmax[0] > 0.0)
		return (tmax[0]);
	return (FAR);
}

double			v_intersect_box(t_ray ray, void *object)
{
	t_box		*box;

	box = (t_box *)object;
	ray.ori = v_add(ray.ori, box->vmin, '-');
	ray.ori = m_mult(box->mat, ray.ori);
	ray.dir = m_mult(box->mat, ray.dir);
	return (get_t(
		(double *)&ray.ori, (double *)&ray.dir, (double *)&box->vmax));
}

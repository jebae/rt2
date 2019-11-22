#include "raycast.h"

static int		validate(t_arg_ring *arg)
{
	if (arg->r1 < 0.0 || arg->r2 < APPROX_0 || arg->r1 >= arg->r2 ||
		v3_norm2(arg->normal) < APPROX_0)
		return (RT_FAIL);
	return (RT_SUCCESS);
}

int				set_ring(t_ol *ol, t_arg_ring *arg)
{
	t_ring	*ring;

	if (validate(arg) == RT_FAIL)
		return (RT_FAIL);
	ol->intersect = &v_intersect_ring;
	ol->get_normal = &normal_ring;
	ring = (t_ring *)ol->object;
	ring->center = arg->center;
	ring->normal = v3_normalise(arg->normal);
	ring->r1 = arg->r1;
	ring->r2 = arg->r2;
	ring->d = v3_dotpdt(ring->center, ring->normal);
	pick_axis_from_plane(&ring->normal, &ol->axis_mat);
	return (RT_SUCCESS);
}

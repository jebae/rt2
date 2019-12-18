#include "rt.test.h"

static void		add_ellipsoid(t_ol *ol, int *num_objs)
{
	t_arg_ellipsoid	arg;

	ol = ol + *num_objs;
	ol->object = ft_memalloc(sizeof(t_ellipsoid));

	// texture and color
	ol->specpower = 15;
	ol->specvalue = 650;
	ol->reflectivity = 0.0;
	ol->transparency = 0.0;
	ol->ior = 1.5;
	ol->dif = (t_vec3){0, 205, 0};

	// set
    arg.cen = (t_vec3){0.0, 0.0, 5.0};
    arg.axis = (t_vec3){1.0, 0.0, 0.0};
	arg.d = 1.0;
	arg.sum = 2.5;
	set_ellipsoid(ol, &arg);
	(*num_objs)++;
}

static void		set_objects(t_ol *ol, int *num_objs)
{
	add_ellipsoid(ol, num_objs);
}

static void		set_lights(t_ll *ll, int *num_lights)
{
	t_arg_distant_light	arg_dl;

	ll->light = ft_memalloc(sizeof(t_distant_light));
	ll->its = (t_vec3){30, 30, 30};
	arg_dl.dir = (t_vec3){0.5, -1.0, -1.0};
	set_distant_light(ll, &arg_dl);
	(*num_lights)++;
}

void			set_scene_ellipsoid(t_env *e)
{
	e->amb = (t_vec3){0.1, 0.1, 0.1};

	set_objects(e->ll_obj, &e->num_objs);
	set_lights(e->ll_lit, &e->num_lights);
}

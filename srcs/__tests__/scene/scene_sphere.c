#include "rt.test.h"

static void		add_earth(t_ol *ol, int *num_objs)
{
	t_arg_sphere	arg;

	ol = ol + *num_objs;
	ol->object = ft_memalloc(sizeof(t_sphere));

	// texture and color
	set_texels("./contents/earth.jpg", 1, &ol->texture);
	ol->specpower = 15;
	ol->specvalue = 650;
	ol->reflectivity = 0.0;
	ol->transparency = 0.0;
	ol->ior = 1.5;

	// set
    arg.cen = (t_vec3){0.0, -1.0, 3.0};
    arg.radius = 2.0;
	set_sphere(ol, &arg);
	(*num_objs)++;
}

static void		add_concrete_sphere(t_ol *ol, int *num_objs)
{
	t_arg_sphere	arg;

	ol = ol + *num_objs;
	ol->object = ft_memalloc(sizeof(t_sphere));

	// texture and color
	set_texels("./contents/concrete_bump.png", 2, &ol->bump_map);
	ol->specpower = 15;
	ol->specvalue = 650;
	ol->reflectivity = 0.0;
	ol->transparency = 0.0;
	ol->ior = 1.5;
	ol->dif = (t_vec3){0xa0, 0xa0, 0xa0};

	// set
    arg.cen = (t_vec3){-3.0, 0.0, 5.0};
    arg.radius = 4.0;
	set_sphere(ol, &arg);
	(*num_objs)++;
}

static void		set_objects(t_ol *ol, int *num_objs)
{
	add_earth(ol, num_objs);
	add_concrete_sphere(ol, num_objs);
}

static void		set_lights(t_ll *ll, int *num_lights)
{
	t_arg_distant_light		arg_dl;
	t_arg_spherical_light	arg_sl;

	ll[0].light = ft_memalloc(sizeof(t_distant_light));
	ll[0].its = (t_vec3){30, 30, 30};
	arg_dl.dir = (t_vec3){0.5, -1.0, -1.0};
	set_distant_light(&ll[0], &arg_dl);
	(*num_lights)++;

	ll[1].light = ft_memalloc(sizeof(t_spherical_light));
	ll[1].its = (t_vec3){30, 30, 30};
	arg_sl.pos = (t_vec3){0.5, -1.0, -1.0};
	set_spherical_light(&ll[1], &arg_sl);
	(*num_lights)++;
}

void			set_scene_sphere(t_env *e)
{
	e->amb = (t_vec3){0.1, 0.1, 0.1};

	set_objects(e->ll_obj, &e->num_objs);
	set_lights(e->ll_lit, &e->num_lights);
}

#include "rt.test.h"

static void		add_earth(t_ol *ol, int *num_objs)
{
	t_arg_sphere	arg;

	ol = ol + *num_objs;
	ol->object = ft_memalloc(sizeof(t_sphere));

	// texture and color
	set_texels("./contents/earth.jpg", "1", &ol->texture);
	ol->specpower = 15;
	ol->specvalue = 650;
	ol->reflectivity = 0.0;
	ol->transparency = 0.0;

	// set
    arg.cen = (t_vec3){0.0, -1.0, 4.0};
    arg.radius = 2.0;
	set_sphere(ol, &arg);
	(*num_objs)++;
}

static void		add_moon(t_ol *ol, int *num_objs)
{
	t_arg_sphere	arg;

	ol = ol + *num_objs;
	ol->object = ft_memalloc(sizeof(t_sphere));

	// texture and color
	set_texels("./contents/moon.jpg", "1", &ol->texture);
	ol->specpower = 15;
	ol->specvalue = 650;
	ol->reflectivity = 0.0;
	ol->transparency = 0.0;

	// set
    arg.cen = (t_vec3){2.0, -1.0, 1.0};
    arg.radius = 0.5;
	set_sphere(ol, &arg);
	(*num_objs)++;
}

static void		add_floor(t_ol *ol, int *num_objs)
{
	t_arg_rectangle		arg;

	ol = ol + *num_objs;
	ol->object = ft_memalloc(sizeof(t_rectangle));

	// texture and color
	set_texels("./contents/water_bump2.jpg", "6", &ol->bump_map);
	ol->specpower = 15;
	ol->specvalue = 650;
	ol->reflectivity = 0.3;
	ol->transparency = 0.0;
	ol->dif = (t_vec3){41, 109, 152};

	// set
	arg.p = (t_vec3){-12.0, 5.0, 1.0};
	arg.a = (t_vec3){24.0, 0.0, 0.0};
	arg.b = (t_vec3){0.0, 0.0, 24.0};
	set_rectangle(ol, &arg);
	(*num_objs)++;
}

static void		add_mirror(t_ol *ol, int *num_objs)
{
	t_arg_rectangle		arg;

	ol = ol + *num_objs;
	ol->object = ft_memalloc(sizeof(t_rectangle));

	// texture and color
	ol->specpower = 15;
	ol->specvalue = 650;
	ol->reflectivity = 0.9;
	ol->transparency = 0.0;
	ol->dif = (t_vec3){255, 255, 255};

	// set
	arg.p = (t_vec3){-12.0, -5.0, 10.0};
	arg.a = (t_vec3){-2.0, 0.0, -15.0};
	arg.b = (t_vec3){0.0, 10.0, 0.0};
	set_rectangle(ol, &arg);
	(*num_objs)++;
}

static void		set_objects(t_ol *ol, int *num_objs)
{
	add_earth(ol, num_objs);
	add_moon(ol, num_objs);
	add_floor(ol, num_objs);
	add_mirror(ol, num_objs);
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

void			set_scene1(t_env *e)
{
	e->amb = (t_vec3){0.1, 0.1, 0.1};

	set_objects(e->ll_obj, &e->num_objs);
	set_lights(e->ll_lit, &e->num_lights);
}

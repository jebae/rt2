#include "rt.test.h"

static void		set_objects(t_ol *ol, int *num_objs)
{
	setup_sphere("1", ol);
	set_texels("./contents/earth.jpg", "1", &ol->texture);
	ol->dif = (t_vec3){227, 225, 0};
	ol->specpower = 15;
	ol->specvalue = 650;
	(*num_objs)++;
	ol++;

	setup_cylinder("1", ol);
	set_texels("./contents/tabaco.jpg", "1", &ol->texture);
	set_texels("./contents/leather_bump.jpg", "1", &ol->bump_map);
	ol->dif = (t_vec3){130, 24, 100};
	ol->specpower = 15;
	ol->specvalue = 650;
	(*num_objs)++;
	ol++;

	setup_pyramid("1", ol);
	ol->dif = (t_vec3){66, 245, 242};
	ol->specpower = 15;
	ol->specvalue = 650;
	(*num_objs)++;
	ol++;

	setup_rectangle("1", ol);
	set_texels("./contents/water_bump2.jpg", "2", &ol->bump_map);
	ol->dif = (t_vec3){245, 66, 114};
	ol->specpower = 15;
	ol->specvalue = 650;
	(*num_objs)++;
	ol++;
}

static void		set_lights(t_ll *ll, int *num_lights)
{
	t_arg_distant_light	arg_dl;

	ll->light = ft_memalloc(sizeof(t_distant_light));
	arg_dl.dir = (t_vec3){0.5, -1.0, -1.0};
	set_distant_light(ll, &arg_dl);
	(*num_lights)++;
}

void			set_scene1(t_env *e)
{
	e->amb.col = (t_col){1, 1, 1};
	e->amb.specpower = 0;

	set_objects(e->ll_obj, &e->num_objs);
	set_lights(e->ll_lit, &e->num_lights);
}

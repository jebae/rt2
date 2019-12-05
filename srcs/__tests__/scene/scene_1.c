#include "rt.test.h"

static void		set_sphere(t_ol *ol, int *num_objs)
{
	setup_sphere("1", ol);
	ol->dir = (t_vec3){227, 225, 0};
	ol->specpower = 15;
	ol->specvalue = 650;
	ol->texture.buffer = NULL;
	ol->bump_map.buffer = NULL;
	*(num_objs)++;
}

static void		set_light()
{

}

void			set_scene1(t_env *e)
{
	e->amb.col = (t_col){1, 1, 1};
	e->amb.specpower = 0;
}

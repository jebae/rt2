#include "rt.test.h"

static void		init_scene(t_env *e)
{
	e->width = WIDTH * 2;
	e->height = HEIGHT * 2;
	e->num_pixels = e->width * e->height;
	e->data = ft_memalloc(sizeof(unsigned int) * e->num_pixels);
	e->num_objs = 0;
	e->num_lights = 0;
	e->mask = 0;
	for (int i=0; i < 20; i++)
		ft_bzero(e->ll_obj + i, sizeof(t_ol));
	for (int i=0; i < 5; i++)
		ft_bzero(e->ll_lit + i, sizeof(t_ll));
}

void			setup_scene(t_env *e)
{
	init_scene(e);
	e->cam.campos = (t_vec3){0.0, 0.0, -1.0};
	e->cam.camdir = (t_vec3){0.0, 0.0, 1.0};
	e->cam.left = (t_vec3){1.0, 0.0, 0.0};
	e->cam.up = (t_vec3){0.0, 1.0, 0.0};
	e->cam.forw = (t_vec3){0.0, 0.0, 1.0};
	e->cam.focal_length = 1.0;
	e->cam.f_wdth = e->width / 384;
	e->cam.f_hght = e->height / 384;
}


void		clear_scene(t_env *e)
{
	t_ol	*ol;

	ft_memdel((void **)&e->data);
	for (int i=0; i < e->num_objs; i++)
	{
		ol = e->ll_obj + i;
		ft_memdel((void **)&ol->object);
		if (ol->texture.buffer)
			ft_memdel((void **)&ol->texture.buffer);
		if (ol->bump_map.buffer)
			ft_memdel((void **)&ol->bump_map.buffer);
	}
	for (int i=0; i < 5; i++)
		ft_memdel((void **)&e->ll_lit[i].light);
}

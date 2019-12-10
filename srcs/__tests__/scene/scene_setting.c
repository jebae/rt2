#include "rt.test.h"

void		init_scene(t_env *e)
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

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
	double		g_x;
	double		g_y;

	init_scene(e);
	e->cam.campos = (t_vec3){0.0, 0.0, -5.0};
	e->cam.camdir = (t_vec3){0.0, 0.0, 1.0};
	e->cam.left = (t_vec3){1.0, 0.0, 0.0};
	e->cam.up = (t_vec3){0.0, 1.0, 0.0};
	g_x = tan(M_PI / 2.0 / 2.0);
	g_y = g_x * e->height / e->width;
	e->dx = v3_scalar(e->cam.left, g_x);
	e->dy = v3_scalar(e->cam.up, g_y);
	e->offset = v3_sub(e->cam.camdir, e->dx);
	e->offset = v3_sub(e->offset, e->dy);
	e->dx = v3_scalar(e->dx, 2.0 / (e->width - 1.0));
	e->dy = v3_scalar(e->dy, 2.0 / (e->height - 1.0));
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

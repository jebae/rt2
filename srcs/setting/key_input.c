#include "rt.h"

static void		key_change_object(SDL_Keycode sym, t_env *e)
{
	if (sym == SDLK_LSHIFT)
	{
		if (e->current_obj_index == 0)
			e->current_obj_index = e->num_objs - 1;
		else
			e->current_obj_index--;
	}
	else if (sym == SDLK_RSHIFT)
	{
		e->current_obj_index++;
		e->current_obj_index %= e->num_objs;
	}
}

static void		key_rotate(SDL_Keycode sym, t_env *e)
{
	if (sym == SDLK_COMMA)
	{
		rotate_object(e, DEGREE_1 * 10.0);
		render(e);
	}
	else if (sym == SDLK_PERIOD)
	{
		rotate_object(e, -DEGREE_1 * 10.0);
		render(e);
	}
}

static void		key_translate(SDL_Keycode sym, t_env *e)
{
	if (sym == SDLK_LEFT)
	{
		translate_object(e, v3_scalar(e->cam.right, -1.0));
		render(e);
	}
	else if (sym == SDLK_RIGHT)
	{
		translate_object(e, e->cam.right);
		render(e);
	}
	else if (sym == SDLK_UP)
	{
		translate_object(e, v3_scalar(e->cam.down, -1.0));
		render(e);
	}
	else if (sym == SDLK_DOWN)
	{
		translate_object(e, e->cam.down);
		render(e);
	}
}

void			key_input(SDL_Keycode sym, t_env *e)
{
	if (sym == SDLK_ESCAPE)
	{
		clear_env(e);
		SDL_Quit();
		exit(0);
	}
	else if (sym == SDLK_i)
		buffer2img(e->img_buf, e->width / 2, e->height / 2);
	key_translate(sym, e);
	key_rotate(sym, e);
	key_change_object(sym, e);
}

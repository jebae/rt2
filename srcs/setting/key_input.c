#include "rt.h"

void		key_input(SDL_Keycode sym, t_env *e)
{
	if (sym == SDLK_ESCAPE)
	{
		clear_env(e);
		SDL_Quit();
		exit(0);
	}
	else if (sym == SDLK_COMMA)
		rotate_object(e, DEGREE_1 * 10.0);
	else if (sym == SDLK_PERIOD)
		rotate_object(e, -DEGREE_1 * 10.0);
}

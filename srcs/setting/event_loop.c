#include "rt.h"

void		run_event_loop(t_env *e)
{
	SDL_Event	*event;

	event = &e->sdl.event;
	while (1)
	{
		while (SDL_PollEvent(event))
		{
			if (event->type == SDL_QUIT)
			{
				clear_env(e);
				SDL_Quit();
				return ;
			}
			if (event->type == SDL_KEYDOWN)
				key_input(event->key.keysym.sym, e);
		}
	}
}

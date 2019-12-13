/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:01:20 by mhernand          #+#    #+#             */
/*   Updated: 2019/12/13 18:12:55 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				main(int argc, char **argv)
{
	t_parse		p;
	t_env		e;
	unsigned int	*ptr;

	(void)argc;
	ft_bzero(&p, sizeof(p));
	ft_bzero(&e, sizeof(e));
	p.ob = e.ll_obj;
	p.li = e.ll_lit;
	SDL_Init(SDL_INIT_VIDEO);
	if ((e.sdl.window = SDL_CreateWindow("RT", 0, 0, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)) == NULL)
		printf("SDL window error\n");
	if ((e.sdl.renderer = SDL_CreateRenderer(e.sdl.window, -1, 0)) == NULL)
		printf("SDL renderer error\n");
	if ((e.sdl.tex = SDL_CreateTexture(e.sdl.renderer, SDL_PIXELFORMAT_BGRA32, SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT)) == NULL)
		printf("SDL texture error\n");
	ptr = malloc(sizeof(unsigned int) * WIDTH * HEIGHT);
	for (int i=0; i < HEIGHT; i++)
	{
		for (int j=0; j < WIDTH; j++)
			ptr[j + i * WIDTH] = 0x00ff0000;
	}
	SDL_UpdateTexture(e.sdl.tex, NULL, ptr, sizeof(unsigned int) * WIDTH);
	SDL_RenderClear(e.sdl.renderer);
	SDL_RenderCopy(e.sdl.renderer, e.sdl.tex, NULL, NULL);
    SDL_RenderPresent(e.sdl.renderer);
	while (1)
	{
		while (SDL_PollEvent(&e.sdl.event)) {
			if (e.sdl.event.type == SDL_QUIT) {
				return (0);
			}
			if (e.sdl.event.key.keysym.sym == SDLK_a)
				ft_putendl("A");
			if (e.sdl.event.key.keysym.sym == SDLK_ESCAPE)
				return(0);
		}
		// function to copy data from "p" to "e"
		// setup_camera -> save data to use in renderer
		// if (difference of xml file)
		//		multithread(e);
	}
	return (0);
}

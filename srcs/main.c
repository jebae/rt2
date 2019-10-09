/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:01:20 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/25 14:43:03 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				quit(t_env *e)
{
	if (e->w.ip)
		mlx_destroy_image(e->w.mp, e->w.ip);
	if (e->w.wp)
		mlx_destroy_window(e->w.mp, e->w.wp);
	if (e->w.mp)
		free(e->w.mp);
	exit(0);
	return (0);
}

int				errors(t_env *e, int i)
{
	if (i == 0)
		ft_putendl("usage:\t./rtv1 scene");
	if (i == 1)
		ft_putendl("error: not a valid file descriptor.");
	if (i == 2)
		ft_putendl("error: mlx init error.");
	if (i == 3)
		ft_putendl("error: not a valid parameter.");
	quit(e);
	return (0);
}

int				main(int argc, char **argv)
{
	t_parser	p;
	t_env		e;
	int			ret;
	int			fd;

	ft_bzero(&p, sizeof(p));
	ft_bzero(&e, sizeof(e));
	if (argc != 2)
		errors(&e, 0);
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		errors(&e, 1);
	if ((ret = parser(&e, &p, fd)) != 0)
		error(&e, &p, ret);
	if (!(e.w.mp = mlx_init()) \
			|| !(e.w.wp = mlx_new_window(e.w.mp, WIDTH, HEIGHT, "RTv1")))
		errors(&e, 2);
	if (!(e.w.ip = mlx_new_image(e.w.mp, WIDTH, HEIGHT)))
		errors(&e, 2);
	if (!(e.data = mlx_get_data_addr(e.w.ip, &e.w.bpp, &e.w.sl, &e.w.end)))
		errors(&e, 2);
	start_rtv1(&e);
	mlx_loop(e.w.mp);
	printf("---------success~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:19:48 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/19 13:08:11 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	check_time(t_parse *p, struct stat *att, unsigned int *flag, char *path)
{
	t_str	*s;

	s = &p->str;
	ft_putendl(s->time);
	SDL_Delay(500);
	if (ft_strcmp(s->time, ctime(&att->st_mtime)) != 0)
	{
		ft_putendl("FILE IS MODIFIED");
		*flag |= 1UL << 1;
		p->mask |= RT_ENV_MASK_PARSE_RELOAD;
		clear_texels_buffers(p->ob);
	}
	if (*flag & 1UL << 1)
	{
		ft_bzero(s->time, 1024);
		ft_strcpy(s->time, ctime(&att->st_mtime));
		update_parser(p, path);
		*flag &= ~(1UL << 1);
	}
	if (!(*flag & 1UL << 2))
	{
		update_parser(p, path);
		*flag |= 1UL << 2;
	}
}

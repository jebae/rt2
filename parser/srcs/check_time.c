/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:19:48 by almoraru          #+#    #+#             */
/*   Updated: 2019/11/26 02:51:20 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	check_time(t_parse *p, struct stat *att, unsigned int *flag)
{
	t_str	*s;

	s = &p->str;
	ft_putendl(s->time);
	// sleep(1);
	if (ft_strcmp(s->time, ctime(&att->st_mtime)) != 0)
	{
		ft_putendl("FILE IS MODIFIED");
		*flag |= 1UL << 1;
	}
	if (*flag & 1UL << 1)
	{
		ft_bzero(s->time, 1024);
		ft_strcpy(s->time, ctime(&att->st_mtime));
	}
	update_parser(p);
}

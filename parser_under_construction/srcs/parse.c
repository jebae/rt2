/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:55:02 by almoraru          #+#    #+#             */
/*   Updated: 2019/11/14 15:13:53 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		parse(t_parse *p, char *path)
{
	struct stat	*att;
	t_str			*s;

	att = &p->att;
	s = &p->str;
	stat(path, att);
	if (!(p->flag & 1UL))
	{
		init_everything(p);
		ft_strcpy(s->time, ctime(&att->st_mtime));
	}
	check_time(p, att, &p->flag);
	// TODO(almoraru): add a condition to check the difference every 5-10 sec
	return(1);
}

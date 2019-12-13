/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:55:02 by almoraru          #+#    #+#             */
/*   Updated: 2019/11/26 02:50:58 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
	return(1);
}

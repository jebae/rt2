/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:55:02 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 13:08:52 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int					parse(t_parse *p, char *path)
{
	struct stat		*att;
	t_str			*s;

	att = &p->att;
	s = &p->str;
	if (stat(path, att) != 0)
		return (1);
	if (!(p->flag & 1UL))
	{
		init_everything(p, path);
		ft_strcpy(s->time, ctime(&att->st_mtime));
	}
	check_time(p, att, &p->flag, path);
	return (1);
}

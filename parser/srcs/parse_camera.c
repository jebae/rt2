/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 02:32:31 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/15 21:23:18 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_camera(t_arg_camera *cam, t_str *s, unsigned int *flag)
{
	if ((ft_strcmp(s->word, "camera")) == 0)
		*flag |= 1UL << 3;
	if (*flag & 1UL << 3)
	{
		while (*s->buf != '\0' && ft_strcmp(s->line, "</camera>") != 0)
		{
			if (*s->buf != '\n')
				ft_cpynline(s->line, s->buf);
			ft_cpyword(s->line, s->word);
			while (*s->buf != '\n' && *s->buf)
				s->buf++;
			if ((ft_strcmp(s->word, "pos")) == 0)
				handle_3vec_number(s, &cam->right);
			if ((ft_strcmp(s->word, "dir")) == 0)
				handle_3vec_number(s, &cam->dir);
			if ((ft_strcmp(s->word, "right")) == 0)
				handle_3vec_number(s, &cam->right);
			s->buf++;
		}
		*flag &= ~(1UL << 3);
	}
}

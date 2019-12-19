/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 02:32:31 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/19 13:01:51 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_camera(t_parse *p, t_str *s, unsigned int *flag)
{
	t_arg_camera	c;

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
				handle_3vec_number(s, &c.pos);
			if ((ft_strcmp(s->word, "dir")) == 0)
				handle_3vec_number(s, &c.dir);
			if ((ft_strcmp(s->word, "right")) == 0)
				handle_3vec_number(s, &c.right);
			s->buf++;
		}
		*flag &= ~(1UL << 3);
		if (set_camera(&c, p->cam) == RT_FAIL)
			p->mask |= RT_ENV_MASK_PARSE_FAIL;
	}
}

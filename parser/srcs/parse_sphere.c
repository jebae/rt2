/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:13:58 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/16 22:19:57 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_sphere(t_parse *p)
{
	t_ol		*ob;
	t_arg_sphere	sp;
	t_str		*s;
	int		i;
	int		tex_mode;

	ob = p->ob;
	s = &p->str;
	i = p->index;
	ob[i].object = ft_mem(&p->mem, sizeof(t_sphere));
	ft_putendl("Sphere is here");
	while (*s->buf != '\0' && ft_strcmp(s->line, "</sphere>") != 0)
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		if ((ft_strcmp(s->word, "center")) == 0)
			handle_3vec_number(s, &sp.cen);
		if ((ft_strcmp(s->word, "radius")) == 0)
			handle_float_number(s, &sp.radius);
		if ((ft_strcmp(s->word, "optional")) == 0)
			handle_optional_vaules(p);
		if ((ft_strcmp(s->word, "tex_mode")) == 0)
			tex_mode = handle_int_number(s, tex_mode);
		if (tex_mode == 1)
		{
			ft_putendl("texture mode detected");
			tex_mode = 0;
		}
		//set texture
		if (tex_mode == 2)
			ft_putendl("bump mapping detected");
		//set bump mapping
		s->buf++;
	}
	p->flag &= ~(1UL << 4);
	// error message would be printed inside set_object
	//if (set_sphere(&ob[i], &sp) == RT_FAIL)
	// handle when fail
	ft_putendl("sphere done");
}

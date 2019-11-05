/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vocab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:46:12 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/24 13:58:41 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			globals_two(t_parser *p, char *tabless, int ret_tabs)
{
	if (ft_strcmp("</specs>", tabless) == 0 && ret_tabs == 1)
	{
		if ((p->ret_p = open_close(&p->specs)) != 0)
		{
			ft_strfree(tabless);
			return (p->ret_p);
		}
	}
	if (ft_strcmp("<objects>", tabless) == 0 && ret_tabs == 1)
	{
		p->objects += 1;
		p->skip = 1;
	}
	if (ft_strcmp("</objects>", tabless) == 0 && ret_tabs == 1)
	{
		if ((p->ret_p = open_close(&p->objects)) != 0)
		{
			ft_strfree(tabless);
			return (p->ret_p);
		}
	}
	return (0);
}

int			globals(t_parser *p, char *gnl_line)
{
	int		ret_tabs;
	char	*tabless;

	ret_tabs = 0;
	p->skip = 0;
	ret_tabs = ft_charfreq(gnl_line, '\t');
	tabless = ft_strtrim(gnl_line);
	if ((ft_strcmp("<scene>", tabless) == 0) && ret_tabs == 0)
		p->scene += 1;
	if (ft_strcmp("</scene>", tabless) == 0 && ret_tabs == 0)
		p->scene += 1;
	if (ft_strcmp("<specs>", tabless) == 0 && ret_tabs == 1)
	{
		p->specs += 1;
		p->skip = 1;
	}
	if ((p->ret_p = globals_two(p, tabless, ret_tabs)) != 0)
		return (p->ret_p);
	ft_strfree(tabless);
	return (0);
}

void		set_vocab(t_parser *p)
{
	p->vocab_one[0] = "sphere";
	p->vocab_one[1] = "cylinder";
	p->vocab_one[2] = "cone";
	p->vocab_one[3] = "plane";
	p->vocab_two[0] = "position";
	p->vocab_two[1] = "direction";
	p->vocab_two[2] = "diffusion";
	p->vocab_two[3] = "reflection";
	p->vocab_two[4] = "specvalue";
	p->vocab_two[5] = "specpower";
	p->vocab_two[6] = "intensity";
	p->vocab_two[7] = "translate";
	p->vocab_two[8] = "rotate";
	p->vocab_two[9] = "rotate_x";
	p->vocab_two[10] = "rotate_y";
	p->vocab_two[11] = "rotate_z";
	p->vocab_two[12] = "angle";
	p->vocab_two[13] = "color";
	p->vocab_two[14] = "center";
	p->vocab_two[15] = "d";
	p->vocab_two[16] = "radius";
	p->vocab_two[17] = "ambient";
	p->vocab_two[18] = "normal";
}

void		reset_shape_atb_two(t_parser *p)
{
	p->y_atb.radius = 0;
	p->y_atb.center = 0;
	p->y_atb.diffusion = 0;
	p->y_atb.reflection = 0;
	p->y_atb.specpower = 0;
	p->y_atb.specvalue = 0;
	p->y_atb.angle = 0;
	p->y_atb.rotate_x = 0;
	p->y_atb.rotate_y = 0;
	p->y_atb.rotate_z = 0;
	p->y_atb.translate = 0;
	p->y_atb.direction = 0;
	p->p_atb.normal = 0;
	p->p_atb.d = 0;
	p->p_atb.diffusion = 0;
	p->p_atb.reflection = 0;
	p->p_atb.specpower = 0;
	p->p_atb.specvalue = 0;
	p->p_atb.rotate_x = 0;
	p->p_atb.rotate_y = 0;
	p->p_atb.rotate_z = 0;
	p->p_atb.translate = 0;
}

void		reset_shape_atb(t_parser *p)
{
	p->s_atb.radius = 0;
	p->s_atb.center = 0;
	p->s_atb.diffusion = 0;
	p->s_atb.reflection = 0;
	p->s_atb.specpower = 0;
	p->s_atb.specvalue = 0;
	p->s_atb.rotate_x = 0;
	p->s_atb.rotate_y = 0;
	p->s_atb.rotate_z = 0;
	p->s_atb.translate = 0;
	p->c_atb.radius = 0;
	p->c_atb.center = 0;
	p->c_atb.diffusion = 0;
	p->c_atb.reflection = 0;
	p->c_atb.specpower = 0;
	p->c_atb.specvalue = 0;
	p->c_atb.angle = 0;
	p->c_atb.rotate_x = 0;
	p->c_atb.rotate_y = 0;
	p->c_atb.rotate_z = 0;
	p->c_atb.translate = 0;
	p->c_atb.direction = 0;
	reset_shape_atb_two(p);
}

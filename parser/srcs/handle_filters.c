/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_filters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 04:33:19 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/19 04:34:15 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"


void	handle_cel_shading(t_parse *p)
{
	t_str *s;

	s = &p->str;
	if ((ft_strcmp(s->word, "cel_shading")) == 0)
	{
		ft_cpymiddleword(s->word3, s->line);
		if ((ft_strcmp(s->word, "cel_shading")) == 0)
		{
			if (!(p->flag & 1UL << 17))
			{
				p->mask |= RT_ENV_MASK_CEL_SHADING;
				p->flag |= 1UL << 17;
			}
		}
	}
}

void	parse_filters(t_parse *p)
{
	t_str *s;

	s = &p->str;
	if ((ft_strcmp(s->word, "filter")) == 0)
	{
		ft_cpymiddleword(s->word3, s->line);
		if ((ft_strcmp(s->word3, "blur")) == 0)
		{
			if (!(p->flag & 1UL << 18))
			{
				p->mask |= RT_ENV_MASK_GAUSSIAN_BLUR;
				p->flag |= 1UL << 18;
			}
		}
		if ((ft_strcmp(s->word3, "sephia")) == 0)
		{
			if (!(p->flag & 1UL << 18))
			{
				p->mask |= RT_ENV_MASK_SEPHIA;
				p->flag |= 1UL << 18;
			}
		}
		if ((ft_strcmp(s->word3, "gray")) == 0)
		{
			if (!(p->flag & 1UL << 18))
			{
				p->mask |= RT_ENV_MASK_GRAY_SCALE;
				p->flag |= 1UL << 18;
			}
		}
		if ((ft_strcmp(s->word3, "negative")) == 0)
		{
			if (!(p->flag & 1UL << 18))
			{
				p->mask |= RT_ENV_MASK_NEGATIVE;
				p->flag |= 1UL << 18;
			}
		}
	}

}

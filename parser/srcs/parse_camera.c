/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 02:32:31 by almoraru          #+#    #+#             */
/*   Updated: 2019/11/26 04:24:46 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_camera(t_camera *cam, t_str *s, unsigned int *flag)
{
	if (!(*flag & 1UL << 2) ||  !(*flag & 1UL << 3))
	{
		if (ft_strcmp(s->word, "location") == 0)
		{
			if (ft_check_line_for_numbers(s->line))
				handle_3vec_number(s, &cam->campos);
			*flag |= 1UL << 2;
		}
		if (ft_strcmp(s->word, "focus") == 0)
		{
			if (ft_check_line_for_numbers(s->line))
				handle_3vec_number(s, &cam->camdir);
			*flag |= 1UL << 3;
		}
	}
}

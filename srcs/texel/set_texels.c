/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:36:39 by jebae             #+#    #+#             */
/*   Updated: 2019/12/17 22:29:42 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "stb_image.hpp"

int			set_texels(
	const char *filename,
	int repeat,
	t_texels *texels
)
{
	texels->buffer = (unsigned int *)stbi_load(
		filename, &texels->width, &texels->height,
		NULL, STBI_rgb_alpha);
	if (texels->buffer == NULL)
		return (handle_fail("set_texels : wrong file"));
	if (repeat <= 0)
		return (handle_fail("set_texels : repeat 0 or below 0"));
	texels->repeat = repeat;
	return (RT_SUCCESS);
}

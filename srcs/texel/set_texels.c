/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:36:39 by jebae             #+#    #+#             */
/*   Updated: 2019/12/17 16:36:42 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.test.h"
#include "stb_image.h"

void		set_texels(
	const char *filename,
	int repeat,
	t_texels *texels
)
{
	texels->buffer = (unsigned int *)stbi_load(
		filename, &texels->width, &texels->height,
		NULL, STBI_rgb_alpha);
	texels->repeat = repeat;
}

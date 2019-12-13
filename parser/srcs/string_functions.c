/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 01:19:22 by almoraru          #+#    #+#             */
/*   Updated: 2019/11/28 04:51:55 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_cpynline(char *dest, char *src)
{
	ft_bzero(dest, ft_strlen(dest));
	while (*src != '\n' && *src != '\0')
	{
		if (!(ft_iswhitespace(*src)))
			*dest++ = *src++;
		else
			src++;
	}
	*dest = '\0';
}

void	ft_cpynumbers(char *line, char *numbers)
{
	int flag;

	flag = 0;
	ft_bzero(numbers, ft_strlen(numbers));
	while (*line != '\0')
	{
		if (*line == '>')
			flag |= 1UL;
		if (*line == '/')
			flag |= 1UL << 1;
		if (ft_is_good_number(*line) && (flag & 1UL) && !(flag & 1UL << 1))
			*numbers++ = *line++;
		else
			line++;
	}
	*numbers = '\0';
}

void	ft_cpyword(char *line, char *word)
{
	int flag;

	flag = 0;
	ft_bzero(word, ft_strlen(word));
	while (*line != '\0')
	{
		if (*line == '/')
			flag |= 1UL;
		if ((ft_isalpha(*line) && !(flag & 1UL))
			|| ((*line == '_') && !(flag & 1UL)))
			*word++ = *line;
		line++;
	}
	*word = '\0';
}

void		ft_second_word(char *line, char *word2)
{
	int	fg;

	fg = 0;
	ft_bzero(word2, ft_strlen(word2));
	while (*line != '\0')
	{
		if (*line == '/')
			fg |= 1UL;
		if ((fg & 1UL && ft_isalpha(*line))
			|| ((*line == '_') && (fg & 1UL)))
			*word2++ = *line;
		line++;
	}
	*word2 = '\0';
}

void	ft_cpyonenbr(char *dest, char *src)
{
	if (dest != NULL)
		ft_bzero(dest, ft_strlen(dest));
	while (ft_isalpha(*src))
		src++;
	while (*src != '\0' && *src != ',')
		*dest++ = *src++;
	*dest = '\0';
}

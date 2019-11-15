/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:17:06 by almoraru          #+#    #+#             */
/*   Updated: 2019/11/14 15:27:16 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
void	ft_cpynline(char *dest, char *src)
{
	ft_bzero(dest, ft_strlen(dest));//KEEP THIS FOR LATER
	while (*src != '\n' && *src != '\0')
		*dest++ = *src++;
	*dest = '\0';
}
int		update_parser(t_parse *p)
{
	t_str	*s;

	s = &p->str;
	ft_putendl(s->line);
	int size = read(p->fd, s->buf, BUFF_SIZE);
	s->buf[size] = '\0';
	ft_putendl("THIS IS BUFFER PRINTING\n");
	ft_putendl(s->buf);
	// LOOP, fuck you victor !
	while (*s->buf != '\0')
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		while(*s->buf != '\n' && *s->buf != '\0')
			s->buf++;
		ft_putendl("\nTHIS IS A LINE\n");
		ft_putendl(s->line);
		if (*s->buf == '\n')
		{
			// ft_putendl("\nTHIS IS A LINE\n");
			// ft_putendl(s->line);
			// TODO: Copy numbers to string and ATOI them(or ATOF)
			//ft_cpynumbers(line, number)
			ft_putendl("\nTHIS IS WHERE WE GET NUMBERS\n");
			ft_putendl(s->number);
			
			break;
		}
		s->buf++;
	}

	return (0);
}
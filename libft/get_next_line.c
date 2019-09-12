/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:07:44 by mhernand          #+#    #+#             */
/*   Updated: 2019/02/10 19:40:51 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_mystruct	*ft_bonus(t_mystruct **bon, t_mystruct **tmp, int fd)
{
	*tmp = *bon;
	if (*bon)
	{
		while (*tmp && (*tmp)->next)
		{
			if (*tmp && (*tmp)->fd == fd)
				return (*tmp);
			*tmp = (*tmp)->next;
		}
		if ((*tmp)->fd == fd)
			return (*tmp);
		if (!((*tmp)->next = (t_mystruct*)malloc(sizeof(t_mystruct))))
			return (NULL);
		*tmp = (*tmp)->next;
	}
	else
	{
		if (!(*tmp = (t_mystruct*)malloc(sizeof(t_mystruct))))
			return (NULL);
	}
	(*tmp)->fd = fd;
	(*tmp)->line = NULL;
	(*tmp)->etc = NULL;
	(*tmp)->next = NULL;
	return (*tmp);
}

static char			*ft_free(char **s1, char *s2, int n)
{
	char			*tmp;

	tmp = NULL;
	tmp = *s1;
	if (n == 1)
		*s1 = ft_strjoin(*s1, s2);
	else if (n == 2)
		*s1 = ft_strsub(*s1, ft_strlen(s2) + 1, ft_strlen(*s1));
	if (tmp)
		free(tmp);
	tmp = 0;
	return (*s1);
}

static int			ft_more_lines(t_mystruct **bon)
{
	int				i;
	int				ret;

	ret = 0;
	i = 0;
	while ((*bon)->etc[i] != '\0' && (*bon)->etc[i] != '\n')
		i++;
	if ((*bon)->etc[i] == '\n')
	{
		(*bon)->line = ft_strsub((*bon)->etc, 0, ft_strclen((*bon)->etc, '\n'));
		(*bon)->etc = ft_free(&(*bon)->etc, (*bon)->line, 2);
		ret = 1;
	}
	else if ((*bon)->etc[i] == '\0')
	{
		(*bon)->line = ft_strsub((*bon)->etc, 0, ft_strlen((*bon)->etc));
		free((*bon)->etc);
		(*bon)->etc = 0;
		ret = (i > 0 ? 1 : 0);
	}
	return (ret);
}

static int			ft_lines(t_mystruct **bon, char *buffy)
{
	int				rd;

	rd = 0;
	if (*bon)
	{
		if ((*bon)->etc != NULL && !(buffy[0]) && ft_strchr((*bon)->etc, '\n'))
			return (ft_more_lines(bon));
		while ((rd = read((*bon)->fd, buffy, BUFF_SIZE)) > 0)
		{
			buffy[rd] = 0;
			(*bon)->etc = ft_free(&(*bon)->etc, buffy, 1);
			if (ft_strchr((*bon)->etc, '\n') != NULL)
			{
				(*bon)->line = ft_strsub((*bon)->etc, 0,
						ft_strclen((*bon)->etc, '\n'));
				(*bon)->etc = ft_free(&(*bon)->etc, (*bon)->line, 2);
				return ((!(*bon)->line || !(*bon)->etc
							|| (!(*bon)->line && !(*bon)->etc)) ? 0 : 1);
			}
		}
	}
	if (rd == 0 && (*bon)->etc)
		return (ft_more_lines(bon));
	return (rd < 0 ? -1 : 0);
}

int					get_next_line(const int fd, char **line)
{
	char					buffy[BUFF_SIZE + 1];
	static t_mystruct		*bon[MAX_FD];
	t_mystruct				*tmp;
	int						ret;

	ret = 0;
	if (fd < 0 || !line || fd > MAX_FD || BUFF_SIZE < 1)
		return (-1);
	bon[fd] = ft_bonus(&bon[fd], &tmp, fd);
	if (fd >= 0 && line)
	{
		ret = ft_lines(&bon[fd], buffy);
		*line = (bon[fd])->line;
	}
	if (ret == 0)
	{
		free(bon[fd]);
		bon[fd] = 0;
	}
	return (ret);
}

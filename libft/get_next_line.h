/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:04:40 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/24 18:05:43 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 16
# define MAX_FD 4864
# include "libft.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct			s_mystruct
{
	int					fd;
	char				*line;
	char				*etc;
	struct s_mystruct	*next;
}						t_mystruct;

int						get_next_line(const int fd, char **line);

#endif

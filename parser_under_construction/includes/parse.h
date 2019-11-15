/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:48:20 by almoraru          #+#    #+#             */
/*   Updated: 2019/11/14 15:26:11 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <sys/stat.h>
# include <sys/types.h>

# define BUFF_SIZE 1024 * 20
typedef struct	s_mem
{
	void	*m;
	size_t	usize;
	size_t	tsize;
}				t_mem;

typedef struct	s_str
{
	char		*buf;
	char		*line;
	char		*number;
	char		*sub_number;
	char		*option;
	char		*time;
}				t_str;

typedef struct	s_parse
{
	t_mem		mem;
	t_str		str;
	struct stat	att;
	unsigned int	flag;
	int			ret;
	int			fd;
}				t_parse;

int				parse(t_parse *p, char *path);
int				init_everything(t_parse *p);
int				update_parser(t_parse *p);
void			is_alloc(void *mem);
void			check_time(t_parse *p, struct stat *att, unsigned int *flag);
void			*ft_mem(t_mem *mem, size_t size);


#endif

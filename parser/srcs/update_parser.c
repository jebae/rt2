/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:17:06 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 13:28:30 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_brackets(char *line)
{
	int i;
	int b1s;
	int b2s;

	i = 0;
	b1s = 0;
	b2s = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '<' && i == 0)
			b1s++;
		if (line[i] == '<' && line[i + 1] == '/')
			b1s++;
		if (line[i] == '>' && b1s == 1)
			b2s++;
		if (line[i] == '>' && line[i + 1] == '\0')
			b2s++;
		i++;
	}
	if (b1s != 2 || b2s != 2)
		return (0);
	return (1);
}

int		ft_one_bracket(char *line, int b_ret)
{
	int	i;
	int	bs;

	i = 0;
	bs = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '<' && i == 0)
		{
			if (line[i + 1] != '/' && b_ret == 1)
				bs++;
			else if (line[i + 1] == '/' && b_ret == 2)
				bs++;
		}
		if (line[i] == '>' && line[i + 1] == '\0' && bs == 1)
			bs++;
		i++;
	}
	if (bs != 2)
		return (0);
	return (1);
}

int		ft_check_spec_bytes_opening(int *op_cl)
{
	int	i;

	i = 1;
	while (++i < 10)
	{
		if (i % 2 == 0)
		{
			if ((*op_cl & 1UL << i) && !(*op_cl & 1UL << (i + 1)))
				return (0);
			else if (!(*op_cl & 1UL << i) && (*op_cl & 1UL << (i + 1)))
				return (0);
		}
	}
	return (1);
}

int		ft_check_spec_bytes_closing(int *op_cl, int num)
{
	int	i;

	i = 1;
	if (!(*op_cl & 1UL << num))
		return (0);
	while (++i < 10)
	{
		if (i % 2 == 0 && i != num)
		{
			if ((*op_cl & 1UL << i) && !(*op_cl & 1UL << (i + 1)))
				return (0);
			else if (!(*op_cl & 1UL << i) && (*op_cl & 1UL << (i + 1)))
				return (0);
		}
	}
	return (1);
}

int		ft_turn_byte_on(int *op_cl, int num)
{
	int	i;

	i = 9;
	if ((*op_cl & 1UL << 8) == 0 || (*op_cl & 1UL << num))
		return (0);
	while (++i < 19)
		if ((*op_cl & 1UL << i))
			return (0);							
	*op_cl |= 1UL << num;
	return (1);
}

int		ft_turn_byte_off(int *op_cl, int num)
{
	int	i;

	i = 10;
	if ((*op_cl & 1UL << 8) == 0 || !(*op_cl & 1UL << num))
		return (0);
	while (++i < 19)
		if ((*op_cl & 1UL << i) == 1)
			return (0);
	*op_cl &= ~(1UL << num);
	return (1);
}

int		ft_open_close(char *line, int *op_cl, char *word)
{
	int i;

	i = -1;
	if (!(ft_strchr(line, '/')))
	{
		if (ft_strcmp(word, "scene") == 0)
		{
			while (++i < 19)
				if ((*op_cl & 1UL << i) == 1)
					ft_putstr("SOMETHING IS NOT OPENED CORRECTLY!"):
			*op_cl |= 1UL;
		}
		if (ft_strcmp(word, "camera") == 0)
		{
			if (!(ft_check_spec_bytes_opening(op_cl)))
				ft_putstr("FAILING TO OPEN A CAMERA!!!\n");
			*op_cl |= 1UL << 2;
		}
		if (ft_strcmp(word, "filter") == 0)
		{
			if (!(ft_check_spec_bytes_opening(op_cl)))
				ft_putstr("FAILING TO OPEN FILTER !!!\n");				
			*op_cl |= 1UL << 4;
		}
		if (ft_strcmp(word, "light") == 0)
		{
			if (!(ft_check_spec_bytes_opening(op_cl)))
				ft_putstr("FAILING TO OPEN A LIGHT !!!\n");					
			*op_cl |= 1UL << 6;
		}
		if (ft_strcmp(word, "objects") == 0)
		{
			if (!(ft_check_spec_bytes_opening(op_cl)))
				ft_putstr("FAILING TO OPEN OBJECTS !!!\n");					
			*op_cl |= 1UL << 8;
		}
		if (ft_strcmp(word, "sphere") == 0)
			if (!(ft_turn_byte_on(op_cl, 10)))
				ft_putstr("OPENING FAIL 10 !\n");
		if (ft_strcmp(word, "cone") == 0)
			if (!(ft_turn_byte_on(op_cl, 11)))
				ft_putstr("OPENING FAIL 11 !\n");
		if (ft_strcmp(word, "cylinder") == 0)
			if (!(ft_turn_byte_on(op_cl, 12)))
				ft_putstr("OPENING FAIL 12 !\n");
		if (ft_strcmp(word, "plane") == 0)
			if (!(ft_turn_byte_on(op_cl, 13)))
				ft_putstr("OPENING FAIL 13 !\n");
		if (ft_strcmp(word, "rectangle") == 0)
			if (!(ft_turn_byte_on(op_cl, 14)))
				ft_putstr("OPENING FAIL 14 !\n");
		if (ft_strcmp(word, "box") == 0)
			if (!(ft_turn_byte_on(op_cl, 15)))
				ft_putstr("OPENING FAIL  !\n");
		if (ft_strcmp(word, "triangle") == 0)
			if (!(ft_turn_byte_on(op_cl, 16)))
				ft_putstr("OPENING FAIL TRIANGLE !\n");
		if (ft_strcmp(word, "pyramid") == 0)
			if (!(ft_turn_byte_on(op_cl, 17)))
				ft_putstr("OPENING FAIL PYRAMID !\n");
		if (ft_strcmp(word, "ring") == 0)
			if (!(ft_turn_byte_on(op_cl, 18)))
				ft_putstr("OPENING FAIL RING !\n");
	}
	else if (ft_strchr(line, '/'))
	{
		if ((ft_strcmp(word, "scene")) == 0)
		{
			if (((*op_cl & 1UL) != 1) || ((*op_cl & 1UL << 1)) 
					|| (!(*op_cl & 1UL << 2)) || (!(*op_cl & 1UL << 3))
					|| (!(*op_cl & 1UL << 4)) || (!(*op_cl & 1UL << 5))
					|| ((*op_cl & 1UL << 6)) || ((*op_cl & 1UL << 7))
					|| (!(*op_cl & 1UL << 8)) || (!(*op_cl & 1UL << 9)))				
				ft_putstr("SOMETHING IS NOT CLOSED CORRECTLY!"):
			i = 9;
			while (++i < 19)
				if ((*op_cl & 1UL << i))
					ft_putstr("SOMETHING IS NOT CLOSED CORRECTLY!"):
			*op_cl |= 1UL << 1;
		}
		if (ft_strcmp(word, "camera") == 0)
		{
			if (!(ft_check_spec_bytes_closing(op_cl, 2)))
				ft_putstr("FAILING CLOSING SPEC 1 !\n");
			*op_cl |= 1UL << 3;
		}
		if (ft_strcmp(word, "filter") == 0)
		{
			if (!(ft_check_spec_bytes_closing(op_cl, 4)))
				ft_putstr("FAILING CLOSING SPEC 1 !\n");
			*op_cl |= 1UL << 5;
		}
		if (ft_strcmp(word, "light") == 0)
		{
			if (!(ft_check_spec_bytes_closing(op_cl, 6)))
				ft_putstr("FAILING CLOSING SPEC 1 !\n");					
			*op_cl |= 1UL << 7;
		}
		if (ft_strcmp(word, "objects") == 0)
		{
			if (!(ft_check_spec_bytes_closing(op_cl, 8)))
				ft_putstr("FAILING CLOSING SPEC 1 !\n");
			*op_cl |= 1UL << 9;
		}
		i = 10;
		if (ft_strcmp(word, "sphere") == 0)
			if (!(ft_turn_byte_off(op_cl, 10)))
				ft_putstr("CLOSING FAIL 10 !\n");
		if (ft_strcmp(word, "cone") == 0)
			if (!(ft_turn_byte_off(op_cl, 11)))
				ft_putstr("CLOSING FAIL 11 !\n");
		if (ft_strcmp(word, "cylinder") == 0)
			if (!(ft_turn_byte_off(op_cl, 12)))
				ft_putstr("CLOSING FAIL 12 !\n");
		if (ft_strcmp(word, "plane") == 0)
			if (!(ft_turn_byte_off(op_cl, 13)))
				ft_putstr("CLOSING FAIL 13 !\n");
		if (ft_strcmp(word, "rectangle") == 0)
			if (!(ft_turn_byte_off(op_cl, 14)))
				ft_putstr("CLOSING FAIL 14 !\n");
		if (ft_strcmp(word, "box") == 0)
			if (!(ft_turn_byte_off(op_cl, 15)))
				ft_putstr("CLOSING FAIL 15 !\n");
		if (ft_strcmp(word, "triangle") == 0)
			if (!(ft_turn_byte_off(op_cl, 16)))
				ft_putstr("CLOSING FAIL 16 !\n");
		if (ft_strcmp(word, "pyramid") == 0)
			if (!(ft_turn_byte_off(op_cl, 17)))
				ft_putstr("CLOSING FAIL 17 !\n");
		if (ft_strcmp(word, "ring") == 0)
			if (!(ft_turn_byte_off(op_cl, 18)))
				ft_putstr("CLOSING FAIL 18 !\n");
	}
	return (1);
}

void	parse_line(t_parse *p)
{
	t_str *s;

	s = &p->str;
	parse_camera(p, s, &p->flag);
	parse_ambient(p);
	parse_lights(p);
	parse_objects(p);
	parse_filters(p);
	handle_cel_shading(p);
}

int			parse_buffer(t_parse *p)
{
	t_str *s;

	s = &p->str;
	while (*s->buf != '\0')
	{
		if (*s->buf != '\n' && *s->buf != '\0')
			ft_cpynline(s->line, s->buf);
		if (ft_strlen(s->line) > 1024)
		{
			ft_putendl("line too big!");
			return (0);
		}
		while (*s->buf != '\n' && *s->buf != '\0')
			s->buf++;
		ft_cpyword(s->line, s->word);
		if (ft_check_line_for_numbers(s->line))
		{
			ft_second_word(s->line, s->word2);
			if (ft_strcmp(s->word, s->word2) != 0)
				ft_putendl("XML TAGS DONT CORRESPOND");
			if (!(ft_brackets(s->line)))
				ft_putendl("WRONG NUMBER OF BRACKETS");
			ft_cpynumbers(s->line, s->number);
		}
		else
		{
			if (!(ft_open_close(s->line, &s->op_cl, s->word)))
				ft_putendl("CONFLICTING TAGS GOING ON !");
			if (!(ft_strchr(s->line, '/')))
			{
				if (!(ft_one_bracket(s->line, 1)))
					ft_putendl("WRONG NUMBER OF BRACKETS");
			}
			else
			{
				if (!(ft_one_bracket(s->line, 2)))
					ft_putendl("WRONG NUMBER OF BRACKETS");
			}
			if (ft_strcmp(s->word, "light") == 0
					&& ft_strchr(s->line, '/') != NULL)
			{
				s->op_cl &= ~(1UL << 6);
				s->op_cl &= ~(1UL << 7);
			}
		}
		parse_line(p);
		s->buf++;
	}
	if (!(s->op_cl & 1UL << 1))
		ft_putstr("scene not closed !\n");
	return (1);
}

int		update_parser(t_parse *p, char *path)
{
	t_str	*s;
	int i;

	s = &p->str;
	i = 0;
	if (p->flag & 1UL << 2)
	{
		i = 0;
		init_everything(p, path);
		ft_putendl("Reopened file!");
	}
	while ((p->size = read(p->fd, &s->buf[i], BUFF_SIZE)) > 0 && (i < 1024 * 12))
		i += p->size;
	s->buf[i] = '\0';
	if (s->buf[0] != '<')
		return (0);
	parse_buffer(p);
	return (0);
}

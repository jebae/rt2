/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:17:06 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/05 20:23:29 by almoraru         ###   ########.fr       */
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
	printf("i am total brackets : [%d]\n", bs);
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

/*
**	Lord have mercy and split this function like
**	Moses split the Red Sea :p
*/
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
				printf("these bytes are not closed properly --> [%d]\n", i); // this test needs to fail					 
			*op_cl |= 1UL;
		}
		if (ft_strcmp(word, "camera") == 0) // 2 / 3
		{
			if (!(ft_check_spec_bytes_opening(op_cl)))
				printf("FAILING SPECS OPEN 1 !!!\n");
			*op_cl |= 1UL << 2;
		}
		if (ft_strcmp(word, "filter") == 0) // 4 / 5
		{
			if (!(ft_check_spec_bytes_opening(op_cl)))
				printf("FAILING SPECS OPEN 2 !!!\n");				
			*op_cl |= 1UL << 4;
		}
		if (ft_strcmp(word, "light") == 0) // 6 / 7
		{
			if (!(ft_check_spec_bytes_opening(op_cl)))
				printf("FAILING SPECS OPEN 3 !!!\n");					
			*op_cl |= 1UL << 6;
		}
		if (ft_strcmp(word, "objects") == 0) // 8 / 9
		{
			if (!(ft_check_spec_bytes_opening(op_cl)))
				printf("FAILING SPECS OPEN 4 !!!\n");					
			*op_cl |= 1UL << 8;
		}
		if (ft_strcmp(word, "sphere") == 0) // 10
			if (!(ft_turn_byte_on(op_cl, 10)))
			printf("OPENING FAIL 10 !\n");
		if (ft_strcmp(word, "cone") == 0) // 11
			if (!(ft_turn_byte_on(op_cl, 11)))
			printf("OPENING FAIL 11 !\n");
		if (ft_strcmp(word, "cylinder") == 0) // 12
			if (!(ft_turn_byte_on(op_cl, 12)))
			printf("OPENING FAIL 12 !\n");
		if (ft_strcmp(word, "plane") == 0) // 13
			if (!(ft_turn_byte_on(op_cl, 13)))
			printf("OPENING FAIL 13 !\n");
		if (ft_strcmp(word, "rectangle") == 0) // 14
			if (!(ft_turn_byte_on(op_cl, 14)))
			printf("OPENING FAIL 14 !\n");
		if (ft_strcmp(word, "box") == 0) // 15
			if (!(ft_turn_byte_on(op_cl, 15)))
			printf("OPENING FAIL 15 !\n");
		if (ft_strcmp(word, "triangle") == 0) // 16
			if (!(ft_turn_byte_on(op_cl, 16)))
			printf("OPENING FAIL 16 !\n");
		if (ft_strcmp(word, "pyramid") == 0) // 17
			if (!(ft_turn_byte_on(op_cl, 17)))
			printf("OPENING FAIL 17 !\n");
		if (ft_strcmp(word, "ring") == 0) // 18
			if (!(ft_turn_byte_on(op_cl, 18)))
			printf("OPENING FAIL 18 !\n");
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
				printf("something is on should not be!\n"); // this test needs to fail
			i = 9;
			while (++i < 19)
				if ((*op_cl & 1UL << i))
				printf("these bytes are not closed properly --> [%d]\n", i); // this test needs to fail
			*op_cl |= 1UL << 1;
		}
		if (ft_strcmp(word, "camera") == 0) // 2 / 3
		{
			if (!(ft_check_spec_bytes_closing(op_cl, 2)))
				printf("FAILING CLOSING SPEC 1 !\n");
			*op_cl |= 1UL << 3;
		}
		if (ft_strcmp(word, "filter") == 0) // 4 / 5
		{
			if (!(ft_check_spec_bytes_closing(op_cl, 4)))
				printf("FAILING CLOSING SPEC 1 !\n");
			*op_cl |= 1UL << 5;
		}
		if (ft_strcmp(word, "light") == 0) // 6 / 7
		{
			if (!(ft_check_spec_bytes_closing(op_cl, 6)))
				printf("FAILING CLOSING SPEC 1 !\n");					
			*op_cl |= 1UL << 7;
		}
		if (ft_strcmp(word, "objects") == 0) // 8 / 9
		{
			if (!(ft_check_spec_bytes_closing(op_cl, 8)))
				printf("FAILING CLOSING SPEC 1 !\n");
			*op_cl |= 1UL << 9;
		}
		i = 10;
		if (ft_strcmp(word, "sphere") == 0) // 10
			if (!(ft_turn_byte_off(op_cl, 10)))
			printf("CLOSING FAIL 10 !\n");
		if (ft_strcmp(word, "cone") == 0) // 11
			if (!(ft_turn_byte_off(op_cl, 11)))
			printf("CLOSING FAIL 11 !\n");
		if (ft_strcmp(word, "cylinder") == 0) // 12
			if (!(ft_turn_byte_off(op_cl, 12)))
			printf("CLOSING FAIL 12 !\n");
		if (ft_strcmp(word, "plane") == 0) // 13
			if (!(ft_turn_byte_off(op_cl, 13)))
			printf("CLOSING FAIL 13 !\n");
		if (ft_strcmp(word, "rectangle") == 0) // 14
			if (!(ft_turn_byte_off(op_cl, 14)))
			printf("CLOSING FAIL 14 !\n");
		if (ft_strcmp(word, "box") == 0) // 15
			if (!(ft_turn_byte_off(op_cl, 15)))
			printf("CLOSING FAIL 15 !\n");
		if (ft_strcmp(word, "triangle") == 0) // 16
			if (!(ft_turn_byte_off(op_cl, 16)))
			printf("CLOSING FAIL 16 !\n");
		if (ft_strcmp(word, "pyramid") == 0) // 17
			if (!(ft_turn_byte_off(op_cl, 17)))
			printf("CLOSING FAIL 17 !\n");
		if (ft_strcmp(word, "ring") == 0) // 18
			if (!(ft_turn_byte_off(op_cl, 18)))
			printf("CLOSING FAIL 18 !\n");
	}
	return (1);
}

void	parse_line(t_parse *p)
{
	t_str *s;

	s = &p->str;
	parse_camera(&p->cam, s, &p->flag);
	parse_lights(p);
	parse_objects(p);
}

int		update_parser(t_parse *p)
{
	t_str	*s;
	int		size;

	s = &p->str;
	size = read(p->fd, s->buf, BUFF_SIZE);
	s->buf[size] = '\0';
	if (size > BUFF_SIZE)
		exit(1);
	// ft_putendl(s->buf); // printing
	while (*s->buf != '\0')
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		while (*s->buf != '\n' && *s->buf != '\0')
			s->buf++;
		// ft_putstr("\nLine = ");   ft_putendl(s->line); // printing LINE
		ft_cpyword(s->line, s->word);
		// ft_putstr("\nWord 1 = ");   ft_putstr(s->word);  // printing WORD ONE
		if (ft_check_line_for_numbers(s->line))
		{
			ft_second_word(s->line, s->word2);
			// ft_putstr("\nWord 2 = ");   ft_putendl(s->word2);  // printing WORD TWO
			if (ft_strcmp(s->word, s->word2) != 0)
				ft_putendl("not the same word =========");
			if (!(ft_brackets(s->line)))
				ft_putendl("WRONG NUMBER OF BRACKETS");
			ft_cpynumbers(s->line, s->number);
			// ft_putendl(s->number);
		}
		else
		{
			ft_putstr("\nLine = ");   ft_putendl(s->line); // printing LINE
			if (!(ft_open_close(s->line, &s->op_cl, s->word)))
				ft_putendl("CONFLICTING TAGS GOING ON !~~~~~~~~~~~~");
			if (!(ft_strchr(s->line, '/')))
			{
				if (!(ft_one_bracket(s->line, 1)))
					printf("wrong # of brackets !\n");
			}
			else
			{
				if (!(ft_one_bracket(s->line, 2)))
					printf("wrong # of brackets !\n");
			}
			if (ft_strcmp(s->word, "light") == 0 && ft_strchr(s->line, '/') != NULL) // set light bits back to zero if > 1 lights
			{
				s->op_cl &= ~(1UL << 6);
				s->op_cl &= ~(1UL << 7);
			}
		}
		parse_line(p);
		s->buf++;
	}
	if (!(s->op_cl & 1UL << 1))
		printf("scene not closed !\n");
	return (0);
}

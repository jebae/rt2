/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:48:20 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/12 17:35:07 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "rt_struct.h"

# define BUFF_SIZE 1024 * 4

/*
**	INIT FUNCTIONS
*/
int				init_everything(t_parse *p);

/*
**	PARSE FUNCTIONS
*/
int				parse(t_parse *p, char *path);
int				update_parser(t_parse *p);
void			parse_camera(t_camera *cam, t_str *s, unsigned int *flag);
void			parse_objects(t_parse *p);
void			parse_lights(t_parse *p);

/*
**	CHECK FUNCTONS
*/
void			check_time(t_parse *p, struct stat *att, unsigned int *flag);

/*
**	MEMORY FUNCTIONS
*/
void			*ft_mem(t_mem *mem, size_t size);
void			is_alloc(void *mem);

/*
**	STRING FUNCTIONS
*/
void			ft_cpynline(char *dest, char *src);
void			ft_cpynumbers(char *line, char *numbers);
void			ft_cpyonenbr(char *dest, char *src);
void			ft_cpyword(char *line, char *word);
void			ft_second_word(char *line, char *word2);
int				ft_check_line_for_numbers(char *line);
int				ft_is_good_number(char c);
int				check_sub_number(char *sub);

/*
**	NUMBER FUNCTOINS
*/
void			handle_3vec_number(t_str *s, t_vec3 *vec);
void			handle_float_number(t_str *s, double *nb);

/*
**	UTIL FUNCTIONS
*/
void			handle_float_vec(t_vec3 *vec, char *sub_number, int i);
void			handle_int_vec(t_vec3 *vec, char *sub_number, int i);

#endif

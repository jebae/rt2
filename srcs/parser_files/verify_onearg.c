/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_onearg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:59:46 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/24 14:10:43 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		verifyanglebrackets_one(t_parser *p)
{
	p->l = -1;
	p->e1 = 0;
	p->e2 = 0;
	p->t = ft_strtrim(p->gnl_line);
	if (p->t[0] != '<' || p->t[ft_strlen(p->t) - 1] != '>')
	{
		ft_strfree(p->t);
		return (-1);
	}
	while (p->t[++p->l])
	{
		if (p->t[p->l] == '<' && p->l == 0)
			p->e1++;
		if (p->t[p->l] == '>' && p->t[p->l + 1] != '\0' && p->e1 == 1)
			p->e1++;
		if (p->t[p->l] == '<' && p->t[p->l + 1] == '/')
			p->e2++;
		if (p->t[p->l] == '>' && p->t[p->l + 1] == '\0' && p->e2 == 1)
			p->e2++;
	}
	if (p->e1 != 2 || p->e2 != 2)
		return (-1);
	ft_strfree(p->t);
	return (0);
}

int		verifyvocab_one(t_parser *p)
{
	p->voc_i = -1;
	p->voc_check = -1;
	p->i = ft_strclen(p->gnl_line, '<') + 1;
	p->j = ft_strclen(p->gnl_line, '>');
	p->k = ft_strclen(p->gnl_line, '/') + 1;
	p->strone = ft_strsub(p->gnl_line, p->i, (p->j - p->i));
	p->i = ft_strlen(p->gnl_line) - 1;
	if (p->gnl_line[p->i] != '>')
		return (-1);
	p->strtwo = ft_strsub(p->gnl_line, p->k, (p->i - p->k));
	if (ft_strcmp(p->strone, p->strtwo) != 0)
		return (-1);
	else
		while (++p->voc_i < 16)
			if (ft_strcmp(p->strone, p->vocab_two[p->voc_i]) == 0)
				p->voc_check++;
	if ((p->ret_p = verify_tag_to_argument(p, p->strone, 1)) != 0)
		return (p->ret_p);
	ft_strfree(p->strone);
	ft_strfree(p->strtwo);
	return (p->voc_check);
}

int		verifyargs_one(t_env *e, t_parser *p, t_ll **l_head, t_ol **o_head)
{
	int		num_check;
	int		fake_check;

	p->i = 0;
	num_check = 0;
	fake_check = 0;
	p->strone = ft_strsub(p->gnl_line, p->j + 1, ((p->k - 3) - p->j));
	p->strtwo = ft_strsub(p->gnl_line, 4, ft_strclen(p->gnl_line, '>') - 4);
	if (p->strone[p->i] == '-')
		p->i++;
	while (p->strone[p->i])
	{
		if (ft_isdigit(p->strone[p->i]) == 1)
			num_check++;
		if (ft_isdigit(p->strone[p->i]) == 0)
			fake_check++;
		p->i++;
	}
	if ((p->ret_p = verify_numbers_one(e, p, *l_head, *o_head)) != 0)
		return (p->ret_p);
	if (fake_check > 0 || num_check == 0)
		return (18);
	ft_strfree(p->strone);
	ft_strfree(p->strtwo);
	return (0);
}

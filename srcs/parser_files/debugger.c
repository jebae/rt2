/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:59:32 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/24 16:50:35 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		lineless_errors_two(t_parser *p, int i)
{
	if (i == 38)
	{
		ft_putendl("Oops ! There are conflicting object tags.");
		ft_strfree(p->tmp);
	}
	if (i == 39)
	{
		ft_putstr("Oops ! It looks like a 'sphere' object is ");
		ft_putendl("missing an attribute.");
	}
	if (i == 40)
	{
		ft_putstr("Oops ! It looks like a 'sphere' object ");
		ft_putendl("has too many attributes.");
	}
	if (i == 41)
	{
		ft_putstr("Oops ! It looks like a 'sphere' object's status is set ");
		ft_putendl("to 'basic' but extra parameters were passed.");
	}
	if (i > 42)
		lineless_errors_three(p, i);
}

void		lineless_errors(t_parser *p, int i)
{
	if (i == 26)
		ft_putendl("Oops ! Looks like <cam>/<amb>/<light> is missing.");
	if (i == 27)
		ft_putendl("Oops ! Looks like there are conflicting light tags.");
	if (i == 28)
	{
		ft_putstr("Oops ! Looks like a <cam>/<amb>/<light> is not ");
		ft_putendl("closed properly.");
	}
	if (i == 29)
		ft_putendl("Oops ! Looks like there are conflicting <light> tags.");
	if (i == 30)
		ft_putendl("Oops ! Looks like there are conflicting <sphere> tags.");
	if (i == 31)
		ft_putendl("Oops ! Looks like there are conflicting <cone> tags.");
	if (i == 32)
		ft_putendl("Oops ! Looks like there are conflicting <cylinder> tags.");
	if (i == 33)
		ft_putendl("Oops ! Looks like there are conflicting <plane> tags.");
	if (i == 34)
		ft_putendl("Oops ! There are conflicting object closing tags.");
	if (i == 37)
		ft_putendl("Oops ! There is a problem with the camera/amb tags.");
	if (i > 37)
		lineless_errors_two(p, i);
}

void		errors_three(int i)
{
	if (i == 14)
		ft_putendl("Oops ! Looks like something is missing/mispelled.");
	if (i == 15)
		ft_putendl("Oops ! Looks like this line is missing an '=' sign.");
	if (i == 16)
		ft_putendl("Oops ! Looks like 'status' is not properly indicated.");
	if (i == 17)
		ft_putendl("Oops ! Looks like this line has poor formatting.");
	if (i == 18)
		ft_putendl("Oops ! Looks like this line was given poor arguments.");
	if (i == 19)
		ft_putendl("Oops ! Looks like there is too many/little commas.");
	if (i == 20)
		ft_putendl("Oops ! Looks like this 'object' tag is not correct.");
	if (i == 21)
	{
		ft_putstr("Oops ! Looks like this 'object' tag isn't open/closed ");
		ft_putendl("correctly.");
	}
}

void		errors_two(int i)
{
	if (i == 4)
	{
		ft_putstr("Oops ! Looks like <scene>/<objects>/<specs> tag was ");
		ft_putendl("not opened/closed/formatted properly.");
	}
	if (i == 5)
		ft_putendl("Oops ! Looks like there was poor tabulation.");
	if (i == 6)
		ft_putendl("Oops ! Looks like the <scene> tag wasn't closed properly.");
	if (i == 7)
		ft_putendl("Oops ! Looks like the start and end tags don't match.");
	if (i == 8)
		ft_putendl("Oops ! Looks like you misspelled/missing tags.");
	if (i == 9)
		ft_putendl("Oops ! Looks angle brackets are not well implemented.");
	if (i == 10)
		ft_putendl("Oops ! Looks like <cam> is not properly opened/closed.");
	if (i == 11)
		ft_putendl("Oops ! Looks like <amb> is not properly opened/closed.");
	if (i == 12)
		ft_putendl("Oops ! Looks like <light> is not properly opened/closed.");
	if (i == 13)
		ft_putendl("Oops ! Looks like this tag is not properly formatted.");
	if (i > 13)
		errors_three(i);
}

int			error(t_env *e, t_parser *p, int i)
{
	(void)e;
	if (i < 26)
	{
		errors_two(i);
		ft_putstr("The problem lies in line : ");
		ft_putnbr(p->gnl_i);
		ft_putchar('\n');
	}
	if (i > 25)
		lineless_errors(p, i);
	quit(e);
	return (0);
}

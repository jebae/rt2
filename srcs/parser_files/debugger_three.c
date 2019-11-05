/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:30:41 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/24 16:52:29 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		line_errors_3(t_parser *p, int i)
{
	if (i == 86)
	{
		ft_putstr("Oops ! This object tag [");
		ft_putstr(p->strtwo);
		ft_putendl("] has a range between 0 and 255. ");
	}
	if (i == 87)
	{
		ft_putstr("Oops ! This rotation tag is greater than 1");
		ft_putendl(" or less then -1. ");
	}
}

void		line_errors_2(t_parser *p, int i)
{
	if (i == 83)
	{
		ft_putstr("Oops ! It looks like [");
		ft_putstr(p->strtwo);
		ft_putendl("] was given a zero/negative value. ");
	}
	if (i == 84)
	{
		ft_putstr("Oops ! It looks like [");
		ft_putstr(p->strtwo);
		ft_putendl("] was given a value greater than 360 or less than 0. ");
	}
	if (i == 85)
	{
		ft_putstr("Oops ! It looks like [");
		ft_putstr(p->strtwo);
		ft_putstr("] was given all zero value,");
		ft_putendl(" at least one value must be greater/less than zero. ");
	}
	if (i > 85)
		line_errors_3(p, i);
}

void		line_errors(t_parser *p, int i)
{
	if (i == 81)
	{
		ft_putstr("Oops ! It looks like [");
		ft_putstr(p->tmp);
		ft_putstr("] was given the incorrect number of arguments. ");
		ft_putendl("This attribute takes three parameters.");
	}
	if (i == 82)
	{
		ft_putstr("Oops ! It looks like [");
		ft_putstr(p->tmp);
		ft_putstr("] was given the incorrect number of arguments. ");
		ft_putendl("This attribute takes one parameter.");
	}
	if (i > 83)
		line_errors_2(p, i);
	ft_putstr("The problem lies in line : ");
	ft_putnbr(p->gnl_i);
	ft_putchar('\n');
}

void		lineless_errors_nine(int i)
{
	if (i == 69)
	{
		ft_putstr("Oops ! It looks like a 'light' spec status is ");
		ft_putendl("set to 'basic' but extra parameters were passed.");
	}
	if (i == 70)
	{
		ft_putstr("Oops ! It looks like a 'light' spec status is ");
		ft_putendl("set to 'extra' but some parameters are missing.");
	}
	if (i == 71)
		ft_putendl("Oops ! Bad malloc.");
	if (i == 72)
		ft_putendl("Oops ! Poor file.");
}

void		lineless_errors_eight(t_parser *p, int i)
{
	if (i == 65)
	{
		ft_putstr("Oops ! It looks like the 'amb' spec was ");
		ft_putendl("given an incorrect attribute.");
	}
	if (i == 66)
		ft_putendl("Oops ! It appears a 'light' spec is missng an attribute.");
	if (i == 67)
	{
		ft_putstr("Oops ! It looks like a 'light' spec was ");
		ft_putendl("given too many attributes.");
	}
	if (i == 68)
	{
		ft_putstr("Oops ! It looks like a 'light' spec was ");
		ft_putendl("given an incorrect attribute.");
	}
	if (i > 68 && i < 80)
		lineless_errors_nine(i);
	if (i > 80)
		line_errors(p, i);
}

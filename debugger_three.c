/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:30:41 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/06 13:30:43 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

void		line_errors(t_env *e, int i)
{
	if (i == 81)
	{
		ft_putstr("Oops ! It looks like [");
		ft_putstr(e->p.tmp);
		ft_putstr("] was given the incorrect number of arguments. ");
		ft_putendl("This attribute takes three parameters.");
		ft_strfree(e->p.tmp);		
	}
	if (i == 82)
	{
		ft_putstr("Oops ! It looks like [");
		ft_putstr(e->p.tmp);
		ft_putstr("] was given the incorrect number of arguments. ");
		ft_putendl("This attribute takes one parameter.");
		ft_strfree(e->p.tmp);		
	}
	if (i == 83)
	{
		ft_putstr("Oops ! It looks like [");
		ft_putstr(e->p.strtwo);
		ft_putendl("] was given a zero/negative value. ");
		ft_strfree(e->p.strone);
		ft_strfree(e->p.strtwo);
	}
	if (i == 84)
	{
		ft_putstr("Oops ! It looks like [");
		ft_putstr(e->p.strtwo);
		ft_putendl("] was given a value greater than 360 or less than 0. ");
		ft_strfree(e->p.strone);
		ft_strfree(e->p.strtwo);
	}
	if (i == 85)
	{
		ft_putstr("Oops ! It looks like [");
		ft_putstr(e->p.strtwo);
		ft_putendl("] was given all zero value, at least one value must be greater/less than zero. ");
		ft_strfree(e->p.strone);
		ft_strfree(e->p.strtwo);
	}
	if (i == 86)
	{
		ft_putstr("Oops ! This object tag [");
		ft_putstr(e->p.strtwo);
		ft_putendl("] has a range between 0 and 255. ");
		ft_strfree(e->p.strone);
		ft_strfree(e->p.strtwo);
	}
	ft_putstr("The problem lies in line : ");
	ft_putnbr(e->p.gnl_i);
	ft_putchar('\n'); //add free strings here if there is an error return value !
}

void		lineless_errors_eight(t_env *e, int i)
{
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
		ft_putstr("Oops ! Bad malloc.");
    if (i > 80)
        line_errors(e, i);
}
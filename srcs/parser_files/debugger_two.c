/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:30:41 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/24 16:51:35 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		lineless_errors_seven(t_parser *p, int i)
{
	if (i == 60)
		ft_putendl("Oops ! It appears the 'cam' spec is missng an attribute.");
	if (i == 61)
	{
		ft_putstr("Oops ! It appears the 'cam' spec was ");
		ft_putendl("given too many attributes.");
	}
	if (i == 62)
	{
		ft_putstr("Oops ! It looks like the 'cam' spec was given ");
		ft_putendl("an incorrect attribute.");
	}
	if (i == 63)
		ft_putendl("Oops ! It appears the 'amb' spec is missng an attribute.");
	if (i == 64)
	{
		ft_putstr("Oops ! It looks like the 'amb' spec was ");
		ft_putendl("given too many attributes.");
	}
	if (i > 64)
		lineless_errors_eight(p, i);
}

void		lineless_errors_six(t_parser *p, int i)
{
	if (i == 55)
	{
		ft_putstr("Oops ! It looks like a 'sphere' object was ");
		ft_putendl("given a wrong attribute.");
	}
	if (i == 56)
	{
		ft_putstr("Oops ! It appears a 'cone' object was ");
		ft_putendl("given a wrong attribute.");
	}
	if (i == 57)
	{
		ft_putstr("Oops ! It looks like a 'cylinder' object was ");
		ft_putendl("given a wrong attribute.");
	}
	if (i == 58)
	{
		ft_putstr("Oops ! It looks like a 'plane' object was ");
		ft_putendl("given a wrong attribute.");
	}
	if (i == 59)
		ft_putendl("Oops ! It appears not a single object was given.");
	if (i > 59)
		lineless_errors_seven(p, i);
}

void		lineless_errors_five(t_parser *p, int i)
{
	if (i == 51)
	{
		ft_putstr("Oops ! It looks like a 'plane' object is ");
		ft_putendl("missing an attribute.");
	}
	if (i == 52)
	{
		ft_putstr("Oops ! It looks like a 'plane' object has ");
		ft_putendl("too many attributes.");
	}
	if (i == 53)
	{
		ft_putstr("Oops ! It looks like a 'plane' object's status is ");
		ft_putendl("set to 'basic' but extra parameters were passed.");
	}
	if (i == 54)
	{
		ft_putstr("Oops ! It looks like a 'plane' object's status is ");
		ft_putendl("set to 'extra' but some parameters are missing.");
	}
	if (i > 54)
		lineless_errors_six(p, i);
}

void		lineless_errors_four(t_parser *p, int i)
{
	if (i == 47)
	{
		ft_putstr("Oops ! It looks like a 'cylinder' object is ");
		ft_putendl("missing an attribute.");
	}
	if (i == 48)
	{
		ft_putstr("Oops ! It looks like a 'cylinder' object has ");
		ft_putendl("too many attributes.");
	}
	if (i == 49)
	{
		ft_putstr("Oops ! It looks like a 'cylinder' object's status ");
		ft_putendl("is set to 'basic' but extra parameters were passed.");
	}
	if (i == 50)
	{
		ft_putstr("Oops ! It looks like a 'cylinder' object's status ");
		ft_putendl("is set to 'extra' but some parameters are missing.");
	}
	if (i > 50)
		lineless_errors_five(p, i);
}

void		lineless_errors_three(t_parser *p, int i)
{
	if (i == 42)
	{
		ft_putstr("Oops ! It looks like a 'sphere' object's status is set ");
		ft_putendl("to 'extra' but some parameters are missing.");
	}
	if (i == 43)
		ft_putstr("Oops ! It appears a 'cone' object is missing an attribute.");
	if (i == 44)
	{
		ft_putstr("Oops ! It looks like a 'cone' object has ");
		ft_putendl("too many attributes.");
	}
	if (i == 45)
	{
		ft_putstr("Oops ! It looks like a 'cone' object's status is ");
		ft_putendl("set to 'basic' but extra parameters were passed.");
	}
	if (i == 46)
	{
		ft_putstr("Oops ! It looks like a 'cone' object's status is ");
		ft_putendl("set to 'extra' but some parameters are missing.");
	}
	if (i > 46)
		lineless_errors_four(p, i);
}

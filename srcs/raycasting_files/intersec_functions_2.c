/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec_functions_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:44:27 by mhernand          #+#    #+#             */
/*   Updated: 2019/11/15 17:57:17 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

double	find_closest_intersection(double a, double b, double c)
{
	double	delta;
	double	t1;
	double	t2;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (FAR);
	else
	{
		t1 = (-b + sqrt(delta)) / (2 * a);
		t2 = (-b - sqrt(delta)) / (2 * a);
		if (t1 <= 0 && t2 <= 0)
			return (0);
		t1 = t1 > 0 ? t1 : t2;
		t1 = t2 < t1 && t2 > 0 ? t2 : t1;
	}
	return (t1);
}

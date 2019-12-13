/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:14:20 by almoraru          #+#    #+#             */
/*   Updated: 2019/11/14 15:37:52 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	is_alloc(void *mem)
{
	if (mem == NULL)
	{
		ft_putendl("Not enough memory!");
		ft_putendl("Freeing...");
		free(mem);
		ft_putendl("Done");
	}
}

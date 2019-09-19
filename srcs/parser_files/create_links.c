/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:36:14 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/11 15:26:55 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		add_link_light(t_env *e, t_ll **head)
{
	// printf("printing pos X --> [%d]\n", &(*head)->pos.x);
	(void)e;
	t_ll	*new;
	t_ll	*last;

	last = *head;
	new = NULL;
	if (!(new = (t_ll*)malloc(sizeof(t_ll))))
		return (-1);
	ft_bzero(&new->pos, sizeof(new->pos));
	ft_bzero(&new->its, sizeof(new->its));
	ft_bzero(&new->rot, sizeof(new->rot));
	ft_bzero(&new->tra, sizeof(new->tra));
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = new;
	}
	return (0);
}

void	clean_link(t_ol *new)
{
	new->d = 0;
	new->angle = 0;
	new->radius = 0;
	new->s_pow = 0;
	new->s_val = 0;
	new->cur_shape = 0;
	new->s_pow = 0;
	new->s_val = 0;
	new->ref = 0;
	ft_bzero(&new->dif, sizeof(new->dif));
	ft_bzero(&new->dir, sizeof(new->dir));
	ft_bzero(&new->cen, sizeof(new->cen)); // axis
	ft_bzero(&new->nor, sizeof(new->nor));
	ft_bzero(&new->rot, sizeof(new->rot));
	ft_bzero(&new->tra, sizeof(new->tra));
}

int		add_link_obj(t_env *e, t_ol **head)
{
	(void)e;
	t_ol	*new;
	t_ol	*last;

	last = *head;
	new = NULL;
	if (!(new = (t_ol*)malloc(sizeof(t_ol))))
		return (-1);
	clean_link(new);
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	return (0);
}

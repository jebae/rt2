/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:58:55 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/25 15:58:58 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rtv1.h"

int             key_press(int key, t_env *e)
{
        e->k[key] = 1;
        return (0);
}

int             key_release(int key, t_env *e)
{
        e->k[key] = 0;
        return (0);
}

int             touch(t_env *e)
{
        if (e->k[ESC] == 1)
            quit(e);
        return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:40:37 by mhernand          #+#    #+#             */
/*   Updated: 2018/12/02 17:40:39 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t   ft_firstchar_index(char *str)
{
    size_t  i;

    i = 0;
    while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
        i++;
    return (i);
}

static size_t   ft_lastchar_index(char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        i++;
    i--;
    while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && i > 0)
        i--;
    return (i);
}

char            *ft_strtrim(char const *s)
{
    size_t  first_char;
    size_t  last_char;
    size_t  i;
    char    *trim;

    if (!s)
        return (NULL);
    if (*s == 0)
        return ("");
    first_char = ft_firstchar_index((char*)s);
    last_char = ft_lastchar_index((char*)s);
    i = last_char - first_char + 1;
    if (first_char > last_char)
        i = 0;
    if (!(trim = (char*)malloc(sizeof(*trim) * (i + 1))))
        return (NULL);
    i = 0;
    while (first_char + i <= last_char)
    {
        trim[i] = s[first_char + i];
        i++;
    }
    trim[i] = 0;
    return (trim);
}
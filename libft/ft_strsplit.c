/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:39:44 by mhernand          #+#    #+#             */
/*   Updated: 2019/05/10 17:36:06 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_words(char const *s, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	if (s[0] == '\0')
		return (0);
	if (s[len - 1] != c)
		j += 1;
	if (s[i] != c)
		j += 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			j++;
		i++;
	}
	if (j == 1)
		return (0);
	return (j);
}

static char	*ft_wordtable(char const *s, char c, int *i)
{
	int		j;
	int		k;
	char	*mini_tab;

	k = *i;
	j = 0;
	while (s[k] != c && s[k] != '\0')
	{
		if ((s[k] != c && s[k + 1] == c) || (s[k] != c && s[k + 1] == '\0'))
			mini_tab = ft_strsub(s, (size_t)*i, ((size_t)k - *i + 1));
		k++;
		j++;
	}
	if (j != 0)
		*i = k - 1;
	return (mini_tab);
}

static char	**ft_findwords(char const *s, char c)
{
	char	**tab;
	int		n_w;
	int		i;
	int		x;

	tab = NULL;
	if (!(tab = (char**)malloc(sizeof(char*) * (nb_words(s, c)))))
		return (NULL);
	n_w = nb_words(s, c) - 1;
	i = -1;
	x = 0;
	while (s[++i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			tab[x] = ft_wordtable(s, c, &i);
			if (!tab[x])
				free(tab[x]);
			x++;
		}
	}
	tab[x] = 0;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if ((!s) || (!c))
		return (NULL);
	if (nb_words(s, c) == 0)
	{
		tab = (char**)malloc(sizeof(char*) * 1);
		tab[0] = 0;
		return (tab);
	}
	if (s[0] == '\0')
		return (NULL);
	return (ft_findwords(s, c));
}

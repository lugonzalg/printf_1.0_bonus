/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:16:55 by lugonzal          #+#    #+#             */
/*Updated: 2021/05/28 14:16:57 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static char	**ft_frlloc(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (tab);
}

static int	ft_strc(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

static int	ft_tab_len(const char *s, char c)
{
	int	i;
	int	row;

	row = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i] != 0)
			row++;
		while (s[i] != c && s[i])
			i++;
	}
	return (row);
}

static char	**ft_handle_tab(const char *str, char c, char **tab, int k)
{
	int	j;
	int	i;
	int	x;

	i = 0;
	j = 0;
	while (str[i] && j < k)
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] != c)
		{
			x = ft_strc(str + i, c);
			tab[j] = ft_substr(str, i, x);
			if (tab[j] == NULL)
				return (ft_frlloc(tab));
			j++;
			tab[j] = NULL;
		}
		while (str[i] && str[i] != c)
			i++;
	}
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	int		j;
	char	**tab;
	char	**tmp_tab;

	if (!s)
		return (NULL);
	j = ft_tab_len(s, c);
	tab = (char **)malloc((j + 1) * (sizeof(char *)));
	if (!tab)
		return (NULL);
	*tab = NULL;
	if (!j)
		return (tab);
	tmp_tab = ft_handle_tab(s, c, tab, j);
	if (!tmp_tab)
		return (NULL);
	return (tab);
}

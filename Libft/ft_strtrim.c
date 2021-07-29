/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:57:14 by lugonzal          #+#    #+#             */
/*Updated: 2021/05/28 12:09:02 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
static int	ft_check(char *s1, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == *s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		size;

	if (!set || !s1)
		return ((char *)s1);
	while (*s1)
	{
		if (ft_check((char *)s1, (char *)set))
			s1++;
		else
			break ;
	}
	size = ft_strlen(s1) - 1;
	while (s1[size])
	{
		if (ft_check((char *)&s1[size], (char *)set))
			size--;
		else
			break ;
	}
	if (size <= 0)
		size = 1;
	str = ft_substr(s1, 0, size + 1);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:27:18 by lugonzal          #+#    #+#             */
/*Updated: 2021/05/26 19:33:56 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	i = 0;
	str = (char *)haystack;
	if (needle[i] == '\0')
		return (str);
	while (str[j] && len > j)
	{
		i = 0;
		while (str[j + i] == needle[i] && len > j + i)
		{
			i++;
			if (needle[i] == '\0')
			{
				return ((str + j));
			}
		}
		j++;
	}
	return (NULL);
}

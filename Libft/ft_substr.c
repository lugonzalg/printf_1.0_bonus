/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 19:12:03 by lugonzal          #+#    #+#             */
/*Updated: 2021/05/27 20:12:50 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*n_str;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (len < 0)
		len = ft_strlen(s);
	i = 0;
	n_str = (char *)malloc(len * sizeof(char) + 1);
	if (!n_str)
		return (NULL);
	if (start > size)
	{
		*n_str = '\0';
		return (n_str);
	}
	while (len-- && s[start + i])
	{
		n_str[i] = s[start + i];
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}

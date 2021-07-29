/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:30:28 by lugonzal          #+#    #+#             */
/*Updated: 2021/05/26 10:30:33 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_2;
	unsigned char	*src_2;
	size_t			i;

	dst_2 = (unsigned char *) dst;
	src_2 = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		dst_2[i] = src_2[i];
		if (src_2[i] == (unsigned char)c)
			break ;
		i++;
	}
	if (src_2[i] == '\0' || i == n)
		return (NULL);
	return (dst_2 + 1 + i);
}

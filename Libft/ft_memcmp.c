/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:31:13 by lugonzal          #+#    #+#             */
/*Updated: 2021/05/26 10:31:15 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_2;
	unsigned char	*s2_2;

	s1_2 = (unsigned char *) s1;
	s2_2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*s1_2 != *s2_2)
			return (*s1_2 - *s2_2);
		s1_2++;
		s2_2++;
	}
	return (0);
}

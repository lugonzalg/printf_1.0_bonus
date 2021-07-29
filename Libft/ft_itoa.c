/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:42:22 by lugonzal          #+#    #+#             */
/*Updated: 2021/05/28 17:50:37 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
static int	ft_power_num(unsigned int num)
{
	int	i;

	i = 0;
	while (num > 9)
	{	
		num /= 10;
		i++;
	}
	i++;
	return (i);
}

static char	*ft_putnbr(long	num, char *str)
{
	unsigned int	i;
	unsigned int	size;

	size = ft_power_num(num) - 1;
	i = 0;
	str[size + 1] = '\0';
	if (num == 0)
		str[size] = num % 10 + '0';
	while (num > 0)
	{		
		str[size] = num % 10 + '0';
		num /= 10;
		size--;
	}
	return (str);
}

char	*ft_itoa(long n)
{
	char			*str;
	int				negativo;

	negativo = 0;
	if (n < 0)
	{
		negativo = 1;
		n = -n;
	}
	str = (char *)malloc((ft_power_num(n) + negativo) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	if (negativo)
	{	
		*str = '-';
		str++;
	}
	return (ft_putnbr(n, str) - negativo);
}

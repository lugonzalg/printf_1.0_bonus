/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:04:40 by lugonzal          #+#    #+#             */
/*Updated: 2021/05/27 14:05:26 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
int	ft_atoi(const char *str)
{
	int	out;
	int	i;
	int	neg;

	neg = 1;
	i = 0;
	out = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (out * neg);
		out = out * 10 + (str[i] - '0');
		i++;
	}
	return (out * neg);
}

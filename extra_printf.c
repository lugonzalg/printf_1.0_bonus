/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 19:58:38 by lugonzal          #+#    #+#             */
/*Updated: 2021/07/17 19:58:53 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "Libft/libft.h"

int	check_str(char **p_str, char *str)
{
	int	i;

	i = 1;
	if (ft_strchr("0123456789 +-#scdiuxXp%.", str[i]))
	{
		while (str[i])
		{
			if (ft_strchr("scdiuxXp%", str[i]))
				return (1);
			i++;
		}
		(*p_str) += i;
	}
	else
		(*p_str)++;
	return (0);
}

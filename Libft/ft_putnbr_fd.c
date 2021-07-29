/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:29:35 by lugonzal          #+#    #+#             */
/*Updated: 2021/06/02 18:31:42 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
static void	ft_write(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_write(n / 10, fd);
		ft_write(n % 10, fd);
	}
	else
	{
		n += '0';
		write(fd, &n, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n2;

	if (n < 0)
	{
		write(fd, "-", 1);
		n2 = (unsigned int)(-n);
	}
	else
		n2 = (unsigned int) n;
	ft_write(n2, fd);
}

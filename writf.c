/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:07:52 by lugonzal          #+#    #+#             */
/*Updated: 2021/07/15 18:12:07 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"
#include <stdlib.h>

static void	write_width(t_code *f_code, char *handle)
{
	long	size;

	if ((f_code->alt_format && handle[0] > 48) || f_code->type == 'p')
		f_code->width -= 2;
	if (f_code->left)
		f_code->zero = 32;
	if (f_code->positive && !f_code->negative && ft_strchr("diu", f_code->type))
		f_code->width--;
	size = (long)ft_strlen(handle);
	if (f_code->type == 's' && f_code->precision > size)
		f_code->precision = size;
	while (f_code->width > f_code->precision
		&& f_code->width > size)
	{
		ft_putchar_fd(f_code->zero, 1);
		f_code->width--;
		f_code->length++;
	}
}

static void	write_sign_space(t_code *f_code, int on)
{
	if (on == 1 && ft_strchr("diu", f_code->type))
	{
		if (f_code->positive && !f_code->negative)
		{
			ft_putchar_fd('+', 1);
			f_code->length++;
		}
		else if (f_code->negative)
			ft_putchar_fd('-', 1);
	}
	if (on == 2 && f_code->space && !f_code->negative
		&& !f_code->positive && f_code->type != 's')
	{
		ft_putchar_fd(' ', 1);
		f_code->length++;
		f_code->width--;
	}
	if (!on)
	{
		if (f_code->type == 'x' || f_code->type == 'p')
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0X", 1);
		f_code->length += 2;
	}
}

void	write_precision_s(t_code *f_code, char *handle)
{
	int	i;

	i = 0;
	while (handle[i] && f_code->precision)
	{
		ft_putchar_fd(handle[i], 1);
		f_code->precision--;
		i++;
		f_code->length++;
	}
}

void	write_precision(t_code *f_code, char *handle)
{
	int	i;

	i = 0;
	if ((f_code->alt_format && handle[0] > 48 && ft_strchr("xX", f_code->type))
		|| f_code->type == 'p')
		write_sign_space(f_code, 0);
	while (f_code->precision > (long)ft_strlen(handle))
	{
		ft_putchar_fd('0', 1);
		f_code->precision--;
		if (f_code->left && f_code->width > 0)
			f_code->width--;
		f_code->length++;
	}
	while (handle[i] || (i == 0 && f_code->type == 'c'))
	{
		ft_putchar_fd(handle[i], 1);
		f_code->precision--;
		i++;
		f_code->length++;
	}
}

void	writf(t_code *f_code, char *handle, void(*wr)(t_code *, char *))
{
	if ((f_code->width > f_code->precision && f_code->precision > -1)
		|| (f_code->type == 'c' && handle[0] == '0'))
		f_code->zero = 32;
	if (handle[0] == '0' && !f_code->precision)
		handle[0] = '\0';
	write_sign_space(f_code, 2);
	if (f_code->left)
	{
		if ((f_code->negative || f_code->positive))
			write_sign_space(f_code, 1);
		wr(f_code, handle);
		write_width(f_code, handle);
	}
	else
	{
		if ((f_code->negative || f_code->positive) && f_code->zero == 48
			&& ft_strchr("diuxX", f_code->type))
			write_sign_space(f_code, 1);
		write_width(f_code, handle);
		if ((f_code->negative || f_code->positive) && f_code->zero != 48
			&& ft_strchr("diuxX", f_code->type))
			write_sign_space(f_code, 1);
		wr(f_code, handle);
	}
	free(handle);
}

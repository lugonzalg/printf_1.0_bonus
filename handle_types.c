/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:07:29 by lugonzal          #+#    #+#             */
/*Updated: 2021/07/15 18:12:03 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "Libft/libft.h"

static void	to_hex_str(uintptr_t n, char *hex)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		to_hex_str(n / 16, hex);
		to_hex_str(n % 16, hex);
	}
	else if (n >= 0 && n < 17)
	{
		if (n > 9)
			n += 39;
		while (hex[i] != '\0')
			i++;
		hex[i] = n + 48;
		hex[i + 1] = '\0';
	}
}

static char	*flags_hex(char str, char *handle, va_list head)
{
	int				i;

	i = -1;
	handle = (char *)malloc(sizeof(char) * 17);
	handle[0] = '\0';
	if (str == 'p')
		to_hex_str(va_arg(head, uintptr_t), handle);
	else if (str == 'x' || str == 'X')
	{
		to_hex_str(va_arg(head, unsigned int), handle);
		if (str == 'X')
		{
			while (handle[++i])
				handle[i] = ft_toupper(handle[i]);
		}
	}
	return (handle);
}

static char	*flags_num(char str, char *handle, va_list head, t_code *f_code)
{
	long int			n;

	n = 0;
	if (str == 'd' || str == 'i')
		n = va_arg(head, int);
	else if (str == 'u')
		n = va_arg(head, unsigned int);
	if (n < 0)
	{
		f_code->negative = 1;
		f_code->width--;
		f_code->length++;
		n = -n;
	}
	if (ft_strchr("diu", str))
		handle = ft_itoa(n);
	if (str == 'c')
	{
		handle = malloc(2);
		handle[0] = va_arg(head, int);
		if (!handle[0])
			f_code->width--;
		handle[1] = '\0';
	}
	return (handle);
}

long	handle_types(char str, va_list head, t_code *f_code)
{
	void	(*wr)(t_code *, char *);
	char	*handle;

	handle = NULL;
	wr = write_precision;
	if (ft_strchr("pxX", str))
		handle = flags_hex(str, handle, head);
	else if (ft_strchr("diuc", str))
		handle = flags_num(str, handle, head, f_code);
	else if (str == 's')
	{
		handle = ft_substr(va_arg(head, char *), 0, f_code->precision);
		if (!handle)
		{
			if (f_code->precision < 0)
				f_code->precision = 6;
			handle = ft_substr("(null)", 0, f_code->precision);
		}
		wr = write_precision_s;
	}
	else if (str == '%')
		handle = ft_strdup("%");
	f_code->type = str;
	writf(f_code, handle, wr);
	return (1);
}

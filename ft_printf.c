/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:06:59 by lugonzal          #+#    #+#             */
/*Updated: 2021/07/15 18:12:00 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "Libft/libft.h"
#include <stdlib.h>

static void	init_code(t_code *f_code)
{
	f_code->width = -1;
	f_code->precision = -1;
	f_code->zero = 32;
	f_code->left = 0;
	f_code->progress = 0;
	f_code->type = 0;
	f_code->negative = 0;
	f_code->length = 0;
	f_code->alt_format = 0;
	f_code->space = 0;
	f_code->positive = 0;
	f_code->extra_flags = 0;
}

static int	create_num(char *str)
{
	int			i;
	char		*num;

	num = (char *)malloc(sizeof(char) * 11);
	num[0] = '\0';
	i = 0;
	while (ft_isdigit(str[i]))
	{
		num[i] = str[i];
		num[i + 1] = '\0';
		i++;
	}
	i = ft_atoi(num);
	free(num);
	return (i);
}

static int	extra_flags(char *str, t_code *f_code)
{
	int	i;

	i = -1;
	while (ft_strchr("%# -+0", str[++i]))
	{
		if (str[i] == '#' && !f_code->alt_format)
			f_code->alt_format = 1;
		if (str[i] == ' ' && !f_code->space)
			f_code->space = 1;
		if (str[i] == '-' && !f_code->left)
			f_code->left = 1;
		if (str[i] == '+' && !f_code->positive)
			f_code->positive = 1;
		if (str[i] == '0' && f_code->zero != 48 && f_code->width == -1)
			f_code->zero = 48;
	}
	f_code->extra_flags = 1;
	return (i);
}

static t_code	*width_precision(char *str)
{
	size_t		i;
	t_code		*f_code;

	init_code((f_code = (t_code *)malloc(sizeof(t_code))));
	i = 0;
	while (!ft_strchr("cspdiuxX%", str[i]) && str[i] && !ft_isalpha(str[i]))
	{
		if (ft_strchr("# -+0", str[i]) && !f_code->extra_flags)
			extra_flags(str + i, f_code);
		if (ft_isdigit(str[i]) && f_code->width < 1
			&& f_code->precision < 1)
			f_code->width = create_num(&str[i]);
		if (str[i] == '.' && f_code->precision == -1)
			f_code->precision = create_num(&str[i + 1]);
		i++;
	}
	f_code->progress += i;
	return (f_code);
}

int	ft_printf(const char *str, ...)
{
	va_list		head;
	t_code		*f_code;
	int			out;

	out = 0;
	va_start(head, str);
	while (*str)
	{
		if (*str == '%' && check_str((char **)&str, (char *)str))
		{
			f_code = width_precision((char *)str + 1);
			str += f_code->progress + 1;
			str += handle_types((char)(*str), head, f_code);
			out += f_code->length;
			free(f_code);
		}
		if (*str && *str != '%')
		{
			ft_putchar_fd((char)(*str), 1);
			str++;
			out++;
		}
	}
	va_end(head);
	return (out);
}

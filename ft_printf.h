#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_code
{
	long	zero;
	long	left;
	long	width;
	long	precision;
	long	progress;
	long	negative;
	char	type;
	long	length;
	long	alt_format;
	long	space;
	long	positive;
	long	extra_flags;
}	t_code;

int		ft_printf(const char *str, ...);
long	handle_types(char str, va_list head, t_code *f_code);
void	writf(t_code *f_code, char *handle, void (*wr)(t_code *, char *));
void	write_precision_s(t_code *f_code, char *handle);
void	write_precision(t_code *f_code, char *handle);
int		check_str(char **p_str, char *str);

#endif

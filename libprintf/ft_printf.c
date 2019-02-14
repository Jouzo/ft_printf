#include <stdarg.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int			fill_buff(char *buf, int *p_buf, t_args *args, int len)
{
	int		i;

	i = 0;
	if (len > BUFF_SIZE)
		i = big_fill_zero(buf, p_buf, args, len);
	ft_memset(buf + *p_buf, '0', len - BUFF_SIZE * i);
	*p_buf += len - BUFF_SIZE * i;
	return (i);
}

void		init_args(t_args *args)
{
	args->prec = 0;
	args->width = 0;
	args->spec = 0;
	args->conv = 0;
	args->is_long_double = 0;
	args->is_short = 0;
	args->is_long = 0;
	args->is_long_long = 0;
	args->is_char = 0;
	args->is_sizet = 0;
	args->alt = 0;
	args->space = 0;
	args->left = 0;
	args->showsign = 0;
	args->zero = 0;
	args->minus = 0;
	args->base = 10;
	args->capital = 0;
}

void		let_there_bprintf(int fd, char *buf, t_args *args)
{
	args->fd = fd;
	args->len = 0;
	ft_bzero(buf, BUFF_SIZE + 1);
}

int			dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	t_args	args;
	char	buf[BUFF_SIZE + 1];
	int		i;
	int		j;

	i = 0;
	j = 0;
	let_there_bprintf(fd, buf, &args);
	va_start(ap, format);
	if (format[0] == '%' && ft_strlen(format) == 1)
		return (0);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
			buf[j++] = format[i++];
		if (format[i] == '%')
		{
			init_args(&args);
			i += assign(format + i, &args);
			j += conversion(buf, ap, &args, &j);
		}
	}
	va_end(ap);
	return (args.len += ft_printstr(buf, j, args));
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_args	args;
	char	buf[BUFF_SIZE + 1];
	int		i;
	int		j;

	i = 0;
	j = 0;
	let_there_bprintf(1, buf, &args);
	va_start(ap, format);
	if (format[0] == '%' && ft_strlen(format) == 1)
		return (0);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
			buf[j++] = format[i++];
		if (format[i] == '%')
		{
			init_args(&args);
			i += assign(format + i, &args);
			j += conversion(buf, ap, &args, &j);
		}
	}
	va_end(ap);
	return (args.len += ft_printstr(buf, j, args));
}

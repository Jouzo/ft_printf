#include "../includes/ft_printf.h"

void	padding_left(char *buf, t_args *args, int size, int *p_buf)
{
	int len;
	int i;

	i = 0;
	len = args->prec == -1 && (args->spec == 'x'
			|| args->spec == 'o') ? 0 : MAX(args->prec, size);
	if (args->minus)
		len++;
	if (args->alt && args->spec == 'o')
		args->width -= 1;
	if (args->alt && (args->spec == 'x' || args->spec == 'p'))
		args->width -= 2;
	len = len - args->showsign - args->space;
	if (args->width - len > 0)
	{
		if (args->width - len > BUFF_SIZE)
			i = big_padding_left(buf, p_buf, args, args->width - len);
		ft_memset(buf + *p_buf, ' ', args->width - len - BUFF_SIZE * i);
		*p_buf += args->width - len - BUFF_SIZE * i;
	}
}

void	fill_zero(char *buf, t_args *args, int size, int *p_buf)
{
	int min;
	int i;

	i = 0;
	min = 0;
	if (args->showsign && !args->minus && args->spec == 'd')
		print_sign(buf, p_buf, args);
	if (args->showsign || args->minus || args->space)
		min = 1;
	if (args->alt && args->spec == 'o')
		args->width -= 1;
	if (args->alt && (args->spec == 'x' || args->spec == 'p'))
		args->width -= 2;
	if (args->width - size - min > 0)
	{
		if (args->width - size - min > BUFF_SIZE)
			i = big_fill_zero(buf, p_buf, args, args->width - size - min);
		ft_memset(buf + *p_buf, '0', args->width - size - min - BUFF_SIZE * i);
		*p_buf += args->width - size - min - BUFF_SIZE * i;
	}
}

void	width_over_prec(char *buf, t_args *args, int size, int *p_buf)
{
	int i;
	int min;
	int len;

	i = 0;
	min = 0;
	if (args->prec <= size && (args->spec == 'd' || args->spec == 'o') && args->prec != -1)
		args->prec = 0;
	len = args->prec < size ? size : args->prec;
	if (args->showsign || args->minus || args->space)
		min = 1;
	if (args->alt == 1 && (args->spec == 'x' || args->spec == 'o' || args->spec == 'p'))
		min += args->spec == 'o' ? 1 : 2;
	if (args->width - len - min >= 0 && !args->left)
	{
		if (args->width - len - min > BUFF_SIZE * i)
			i += big_fill_prec(buf, p_buf, args, args->width - len - min);
		ft_memset(buf + *p_buf, ' ', args->width - len - min - BUFF_SIZE * i);
		*p_buf += args->width - len - min - BUFF_SIZE * i;
	}
	if (args->alt == 1 && (args->spec == 'x' || args->spec == 'o' || args->spec == 'p'))
		add_hash(buf, args, p_buf);
	if (args->showsign && !args->minus && args->spec == 'd')
		print_sign(buf, p_buf, args);
	if (args->minus)
		print_minus(buf, p_buf, args);
	if (args->prec - size > 0)
	{
		if (args->prec - size > BUFF_SIZE * i)
			i += big_fill_prec(buf, p_buf, args, args->prec - size);
		ft_memset(buf + *p_buf, '0', args->prec - size - BUFF_SIZE * i);
		*p_buf += args->prec - size - BUFF_SIZE * i;
	}
}

void	fill_prec(char *buf, t_args *args, int size, int *p_buf)
{
	int i;
	int min;

	i = 0;
	min = 0;
	if (args->prec <= size && (args->spec == 'd' || args->spec == 'o') && args->prec != -1)
		args->prec = 0;
	if (args->showsign || args->minus || args->space)
		min = 1;
	if (args->spec == 'o' && args->alt && args->prec > size)
		args->prec -= 1;
	if (args->prec - size > 0)
	{
		if (args->width - args->prec - min >= 0 && !args->left)
		{
			i = big_fill_prec(buf, p_buf, args, args->width - args->prec - min);
			ft_memset(buf + *p_buf, ' ', args->width - args->prec - min - BUFF_SIZE * i);
			*p_buf += args->width - args->prec - min - BUFF_SIZE * i;
		}
		if (args->showsign && !args->minus && args->spec == 'd')
			print_sign(buf, p_buf, args);
		if (args->prec - size > BUFF_SIZE * i)
			i += big_fill_prec(buf, p_buf, args, args->prec - size);
		ft_memset(buf + *p_buf, '0', args->prec - size - BUFF_SIZE * i);
		*p_buf += args->prec - size - BUFF_SIZE * i;
	}
	else if (!args->zero)
		padding_left(buf, args, args->width + size, p_buf);
	else
		padding_left(buf, args, size, p_buf);
}

void add_option(char *buf, t_args *args, char *conv, int *p_buf)
{
	if (((args->space && args->width && !args->left && !args->zero)
		|| (args->width && !args->zero && !args->left)) && args->prec == 0)
		padding_left(buf, args, ft_strlen(conv), p_buf);
	if (args->space && !args->showsign && args->spec == 'd' && !args->minus)
		one_space(buf, p_buf, args);
	if (args->alt == 1 && (args->spec == 'x' || args->spec == 'o'
	|| args->spec == 'p') && !(args->prec != 0 && args->prec < args->width))
		add_hash(buf, args, p_buf);
	if (args->minus && ((args->prec >= args->width) || (args->width && !args->prec)))
		print_minus(buf, p_buf, args);
	if (args->showsign && !args->minus && args->spec == 'd'
		&& args->prec >= args->width)
		print_sign(buf, p_buf, args);
	if ((args->prec != 0 && args->prec >= args->width))
		fill_prec(buf, args, ft_strlen(conv), p_buf);
	else if (args->prec != 0 && args->prec < args->width)
		width_over_prec(buf, args, ft_strlen(conv), p_buf);
	else if (args->zero && args->width && !args->left)
		fill_zero(buf, args, ft_strlen(conv), p_buf);
}

#include "../includes/ft_printf.h"

void padding_left(char *buf, t_args *args, int size_of_conversion, int *p_buf)
{
    int len;
    int i;

    i = 0;
	len = args->prec == -1 && (args->spec == 'x' || args->spec == 'o') ? 0 : MAX(args->prec, size_of_conversion);
	// printf("value of args->prec et sizeconv %i %i\n", args->prec, len);
    if (args->minus)
        len++;
    if (args->alt && args->spec == 'o')
        args->width -= 1;
    if (args->alt && (args->spec == 'x' || args->spec == 'p'))
        args->width -= 2;
	// printf("value of width %i\n", args->width);
	// printf("value of len %i\n", len);
    if (args->width - len - args->showsign - args->space > 0)
    {
        if (args->width - len - args->showsign - args->space > BUFF_SIZE)
			i = print_big_padding_left(buf, p_buf, args, args->width - len - args->showsign - args->space);
		ft_memset(buf + *p_buf, ' ', args->width - len - args->showsign - args->space - BUFF_SIZE * i);
		*p_buf += args->width - len - args->showsign - args->space - BUFF_SIZE * i;
	}
}

void fill_zero(char *buf, t_args *args, int size_of_conversion, int *p_buf)
{
	int min;
	int i;

	i = 0;
	min = 0;
	// printf("fill_zero : value of p_buf %i\n", *p_buf);
	if (args->showsign && !args->minus && args->spec == 'd')
		print_sign(buf, p_buf, args);
	if (args->spec == '%')
		padding_left(buf, args, size_of_conversion, p_buf);
	else
	{
		if (args->showsign || args->minus || args->space)
			min = 1;
		if (args->alt && args->spec == 'o')
			args->width -= 1;
		if (args->alt && (args->spec == 'x' || args->spec == 'p'))
			args->width -= 2;
		if (args->width - size_of_conversion - min > 0)
		{
			if (args->width - size_of_conversion - min > BUFF_SIZE)
				i = print_big_fill_zero(buf, p_buf, args, args->width - size_of_conversion - min);
			ft_memset(buf + *p_buf, '0', args->width - size_of_conversion - min - BUFF_SIZE * i);
			*p_buf += args->width - size_of_conversion - min - BUFF_SIZE * i;
		}
	}
}

void width_over_prec(char *buf, t_args *args, int size_of_conversion, int *p_buf)
{
	int i;
	int min;
	int len;

	i = 0;
	min = 0;
	if (args->prec <= size_of_conversion && (args->spec == 'd' || args->spec == 'o') && args->prec != -1)
		args->prec = 0;
	len = args->prec < size_of_conversion ? size_of_conversion : args->prec;
	if (args->showsign || args->minus || args->space)
		min = 1;
	if (args->width - len - min >= 0 && !args->left)
	{
		// printf("buffer : %s\n", buf);
		if (args->width - len - min > BUFF_SIZE * i)
			i += print_big_fill_prec(buf, p_buf, args, args->width - len - min);
		ft_memset(buf + *p_buf, ' ', args->width - len - min - BUFF_SIZE * i);
		*p_buf += args->width - len - min - BUFF_SIZE * i;

	}
	if (args->showsign && !args->minus && args->spec == 'd')
		print_sign(buf, p_buf, args);
	if (args->prec - size_of_conversion > 0)
	{
	if (args->prec - size_of_conversion > BUFF_SIZE * i)
		i += print_big_fill_prec(buf, p_buf, args, args->prec - size_of_conversion);
	ft_memset(buf + *p_buf, '0', args->prec - size_of_conversion - BUFF_SIZE * i);
	*p_buf += args->prec - size_of_conversion - BUFF_SIZE * i;
	}
}


void fill_prec(char *buf, t_args *args, int size_of_conversion, int *p_buf)
{
	int i;
	int min;

	i = 0;
	min = 0;
	// printf("fill prec : value of buf %s\n", buf);
	printf("size of conv : %i\n", size_of_conversion);
	// printf("fill prec : value of p_buf %i\n", *p_buf);
	if (args->prec <= size_of_conversion && (args->spec == 'd' || args->spec == 'o') && args->prec != -1)
		args->prec = 0;
	if (args->showsign || args->minus || args->space)
		min = 1;
	if (args->prec - size_of_conversion > 0)
	{
		if (args->width - args->prec - min >= 0 && !args->left)
		{
			i = print_big_fill_prec(buf, p_buf, args, args->width - args->prec - min);
			ft_memset(buf + *p_buf, ' ', args->width - args->prec - min - BUFF_SIZE * i);
			*p_buf += args->width - args->prec - min - BUFF_SIZE * i;
		}
		if (args->showsign && !args->minus && args->spec == 'd')
			print_sign(buf, p_buf, args);
		if (args->prec - size_of_conversion > BUFF_SIZE * i)
			i += print_big_fill_prec(buf, p_buf, args, args->prec - size_of_conversion);
		ft_memset(buf + *p_buf, '0', args->prec - size_of_conversion - BUFF_SIZE * i);
		*p_buf += args->prec - size_of_conversion - BUFF_SIZE * i;
		// printf("size of conv %d\n", size_of_conversion);
	}
	else if (!args->zero)
		padding_left(buf, args, args->width + size_of_conversion, p_buf);
	else
		padding_left(buf, args, size_of_conversion, p_buf);
	//  printf("fill prec : value of buf %s\n", buf);
}

void one_space(char *buf, int *p_buf, t_args *args)
{
	if (*p_buf == BUFF_SIZE)
		check_buf(buf, p_buf, args);
	ft_memset(buf + *p_buf, ' ', 1);
	*p_buf += 1;
}

void padding_right(char *buf, char *conv, t_args *args, int *p_buf)
{
	int len;
	int min;
	int i;

	i = 0;
	min = 0;
	len = (args->spec == 'p' || args->spec == 'x') && args->alt ? ft_strlen(conv) + 2 : ft_strlen(conv);
	len = args->spec == 'o' && args->alt ? len += 1 : len;
	if (args->showsign || args->minus || args->space)
		min = 1;
	len += min;
	if (len <= args->prec && args->prec)
		len = args->prec + min;	
	if (args->width - len > 0)
	{
		if (args->width - len > BUFF_SIZE)
			i = print_big_padding_right(buf + ft_strlen(conv), p_buf, args, args->width - len);
		ft_memset(buf + *p_buf + ft_strlen(conv), ' ', args->width - len - BUFF_SIZE * i);
		*p_buf += args->width - len - BUFF_SIZE * i;
	}
}

void print_sign(char *buf, int *p_buf, t_args *args)
{
	if (*p_buf == BUFF_SIZE)
		check_buf(buf, p_buf, args);
	ft_memset(buf + *p_buf, '+', 1);
	*p_buf += 1;
}

void print_minus(char *buf, int *p_buf, t_args *args)
{
	if (*p_buf == BUFF_SIZE)
		check_buf(buf, p_buf, args);
	ft_memset(buf + *p_buf, '-', 1);
	*p_buf += 1;
}

void add_hash(char *buf, t_args *args, int *p_buf)
{
	// printf("value of args->alt and args->spec and args->prec %i %c %i\n\n", args->alt, args->spec, args->prec);

	if ((args->spec == 'x' || args->spec == 'p') && args->prec != -1)
	{
		if (*p_buf + 1 == BUFF_SIZE || *p_buf == BUFF_SIZE)
			check_buf(buf, p_buf, args);
		ft_memset(buf + *p_buf, '0', 1);
		ft_memset(buf + *p_buf + 1, 'x' - args->capital * 2, 1);
		*p_buf += 2;
	}
	else if (args->spec == 'o')
	{
		// printf("DEDE\n");
		if (*p_buf == BUFF_SIZE)
			check_buf(buf, p_buf, args);
		ft_memset(buf + *p_buf, '0', 1);
		*p_buf += 1;
	}
}

void add_option(char *buf, t_args *args, char *conv, int *p_buf)
{
	printf("conv %s :\n", conv);
	if (((args->space && args->width && !args->left && !args->zero) || (args->width && !args->zero && !args->left)) && args->spec != 's' && args->prec == 0)
		padding_left(buf, args, ft_strlen(conv), p_buf);
	if (args->space && !args->showsign && args->spec == 'd' && !args->minus)
		one_space(buf, p_buf, args);	
	if (args->alt == 1 && (args->spec == 'x' || args->spec == 'o' || args->spec == 'p'))
		add_hash(buf, args, p_buf);
	if (args->minus)
		print_minus(buf, p_buf, args);
	if (args->showsign && !args->minus && args->spec == 'd' && args->prec >= args->width)
		print_sign(buf, p_buf, args);
	if (!args->prec && args->spec == 's' && !args->left)
		padding_left_string(buf, args, ft_strlen(conv), p_buf);
	if (args->prec && args->spec == 's' && !args->left)
		fill_prec_string(buf, args, ft_strlen(conv), p_buf);
	else if ((args->prec != 0 && args->spec != 's' && args->spec != 'p' && args->prec >= args->width))
		fill_prec(buf, args, ft_strlen(conv), p_buf);
	else if (args->prec != 0 && args->spec != 's' && args->spec != 'p' && args->prec < args->width)
		width_over_prec(buf, args, ft_strlen(conv), p_buf);
	else if (args->zero && args->width && !args->left)
		fill_zero(buf, args, ft_strlen(conv), p_buf);
}

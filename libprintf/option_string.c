#include "../includes/ft_printf.h"

void padding_left_string(char *buf, t_args *args, int size_of_conversion, int *p_buf)
{
	int i;

	// printf("DEDDE\n");
	// printf("value of prec in padding left %i\n", args->prec);

	i = 0;
	if (args->width - size_of_conversion > 0)
	{
		if (args->width - size_of_conversion > BUFF_SIZE)
			i = print_big_padding_left(buf, p_buf, args, args->width - size_of_conversion);
		ft_memset(buf + *p_buf, ' ', args->width - size_of_conversion - BUFF_SIZE * i);
		*p_buf += args->width - size_of_conversion - BUFF_SIZE * i;
	}
}

void fill_prec_string(char *buf, t_args *args, int size_of_conversion, int *p_buf)
{
	int len;
	int i;

	i = 0;
	len = size_of_conversion;

	// printf("value of len  in fill prec %i\n", len);
	// printf("value of prec %i\n", args->prec);
	
	if (args->prec && len > args->prec)
		len = args->prec;
	if (args->prec - size_of_conversion > 0)
	{
		if (args->width - len > 0)
		{
			if (args->width - len > BUFF_SIZE)
				i = print_big_fill_prec_string(buf, p_buf, args, args->width - len);
			ft_memset(buf + *p_buf, ' ', args->width - len - BUFF_SIZE * i);
			*p_buf += args->width - len - BUFF_SIZE * i;
		}
	}
	if (args->prec == -1)
		padding_left_string(buf, args, size_of_conversion, p_buf);
}

void padding_right_string(char *buf, char *conv, t_args *args, int *p_buf)
{
	int len;
	int i;
	int min;

	min = 0;
	i = 0;
	len = ft_strlen(conv);
	if (args->prec && len > args->prec)
		len = args->prec;
	// printf("value of args->prec %i\n", args->prec);
	 if (ft_strcmp(conv, "(null)") == 0 && args->prec == 0)
        len = 0;
	// // printf("value of conv %s\n", conv);

	// printf("value of len %i\n", len);
	*p_buf += len + min;
	if (args->width - len > 0 && len < args->width)
	{
		if (args->width - len > BUFF_SIZE)
			i = print_big_padding_right(buf, p_buf, args, args->width - len);
		ft_memset(buf + *p_buf, ' ', args->width - len - BUFF_SIZE * i);
		*p_buf += args->width - len - BUFF_SIZE * i - len;
	}
}

void fill_zero_string(char *buf, t_args *args, int size_of_conversion, int *p_buf)
{
	int min;
	int i;

	i = 0;
	min = 0;
	// printf("fill_zero : value of p_buf %i\n", *p_buf);
	// printf("value of size %i\n", size_of_conversion);
	if (args->space)
		min = 1;
	if (args->width - size_of_conversion - min > 0)
	{
		if (args->width - size_of_conversion - min > BUFF_SIZE)
			i = print_big_fill_zero(buf, p_buf, args, args->width - size_of_conversion - min);
		ft_memset(buf + *p_buf, '0', args->width - size_of_conversion - min - BUFF_SIZE * i);
		*p_buf += args->width - size_of_conversion - min - BUFF_SIZE * i;
	}
}

void width_over_prec_string(char *buf, t_args *args, char *conv, int *p_buf)
{
	int i;
	int len;

	i = 0;
	len = args->prec ? args->prec : ft_strlen(conv);
	// printf("value of conv %s\n", conv);

	// printf("value of len %i\n", len);
	if (ft_strcmp(conv, "") == 0)
		len = 0;
	// printf("value of width %i\n", args->width);
	
	if (args->width - len >= 0 && !args->left)
	{
		// printf("buffer : %s\n", buf);
		if (args->width - len > BUFF_SIZE * i)
			i += print_big_fill_prec(buf, p_buf, args, args->width - len);
		ft_memset(buf + *p_buf, ' ', args->width - len - BUFF_SIZE * i);
		*p_buf += args->width - len - BUFF_SIZE * i;
	}
}


void add_option_string(char *buf, t_args *args, char *conv, int *p_buf)
{
// 	// printf("DEDE\n");
// 	printf("the string %s\n", conv);
// printf("args prec %i\n", args->prec);
// printf("args left %i\n", args->left);
	if (args->zero && args->width && !args->left && args->spec == '%')
		fill_zero_string(buf, args, ft_strlen(conv), p_buf);
	if ((args->prec && !args->left && args->width < args->prec) || args->prec == -1)
		fill_prec_string(buf, args, ft_strlen(conv), p_buf);
	else if (args->prec && args->width && args->width > args->prec)
		width_over_prec_string(buf, args, conv, p_buf);
	else if ((!args->prec && !args->left && !args->zero && args->width) || ft_strcmp(conv, "(null)") == 0)
		padding_left_string(buf, args, ft_strlen(conv), p_buf);
}

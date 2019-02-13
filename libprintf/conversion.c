#include "../includes/ft_printf.h"

int conversion_int(char *buf, int nb, t_args *args, int *p_buf)
{
	int len;

	len = 0;
	if (args->is_short)
		nb = (short)nb;
	if (args->is_char)
		nb = (char)nb;
	if (args->spec == 'c' || args->spec == 'C')
	{
		if (*p_buf == BUFF_SIZE)
			check_buf(buf, p_buf, args);
		ft_itoc(nb, args, buf, p_buf);
		// printf("value of args->left %i\n", args->left);
		if (args->left)
			padding_right(buf, "", args, p_buf);
		len = nb != 0 ? 0 - args->left : 0;
	}
	else
		len = ft_itoa_base(nb, args, buf, p_buf);
	return (len);
}

int conversion_long(char *buf, long nb, t_args *args, int *p_buf)
{
	return (ft_ltoa_base(nb, args, buf, p_buf));
}

int conversion_long_long(char *buf, long nb, t_args *args, int *p_buf)
{
	return (ft_lltoa_base(nb, args, buf, p_buf));
}

int conversion_double(char *buf, long double nb, t_args *args, int *p_buf)
{
	return (ft_dtoa(nb, args, buf, p_buf));
}

int conversion_unsigned(char *buf, unsigned int nb, t_args *args, int *p_buf)
{
	if (args->is_short)
		nb = (unsigned short)nb;
	if (args->is_char)
		nb = (unsigned char)nb;
	return (ft_utoa_base(nb, args, buf, p_buf));
}

int conversion_long_unsigned(char *buf, unsigned long nb, t_args *args, int *p_buf)
{
	return (ft_ultoa_base(nb, args, buf, p_buf));
}

int conversion_long_long_unsigned(char *buf, unsigned long long nb, t_args *args, int *p_buf)
{
	return (ft_ulltoa_base(nb, args, buf, p_buf));
}

int conversion_string(char *buf, char *str, t_args *args, int *p_buf)
{
	if ((!args->prec || args->prec > (int)ft_strlen(str)) && str)
		args->prec = ft_strlen(str);
	if (args->prec == -1 && str)
		args->prec = 0;
	// printf("value of *p_buf %i\n", *p_buf);
	
	// printf("value of args->prec %i\n", args->prec);
	// if (args->prec == -1 && args->spec == 's')
	// {
	// 	len = 0;
	// 	*p_buf = *p_buf > 0 ? *p_buf - 1 : *p_buf;
	// }
	// printf("value of len %i\n", len);
	if (!str)
	{
		if (args->prec == 0)
			args->prec = 6;
		if (args->prec == -1)
			args->prec = 0;
		if (*p_buf + 6 > BUFF_SIZE)
			check_buf(buf, p_buf, args);
		add_option_string(buf, args, "(null)", p_buf);	
		ft_memcpy(buf + *p_buf, "(null)", args->prec);
		if (args->left && args->width)
			padding_right_string(buf, "(null)", args, p_buf);
		return (args->prec);
	}
	else
	{
		// printf("value of *p_buf %i\n", *p_buf);
		add_option_string(buf, args, str, p_buf);
		if (*p_buf + args->prec > BUFF_SIZE)
			check_buf(buf, p_buf, args);
		ft_memcpy(buf + *p_buf, str, args->prec);
		if (args->left && args->width)
			padding_right_string(buf, str, args, p_buf);
		return (args->prec);
	}
}

int conversion_percent(char *buf, char *str, t_args *args, int *p_buf)
{
	int len;
	
	len = ft_strlen(str);
	if (args->prec && ft_strlen(str) > (size_t)args->prec)
		len = args->prec;
	if (!str)
	{
		args->prec = args->prec == 0 ? 6: args->prec;
		if (*p_buf + 6 > BUFF_SIZE)
			check_buf(buf, p_buf, args);
		add_option_string(buf, args, "(null)", p_buf);	
		ft_memcpy(buf + *p_buf, "(null)", args->prec);
		return (args->prec);
	}
	else
	{
		// printf("value of *p_buf %i\n", *p_buf);
		add_option_string(buf, args, str, p_buf);
		if (*p_buf + len > BUFF_SIZE)
			check_buf(buf, p_buf, args);
		ft_memcpy(buf + *p_buf, str, len);
		if (args->left && args->width)
			padding_right_string(buf, str, args, p_buf);
		return (len);
	}
}
int conversion_void(char *buf, unsigned long long ptr, t_args *args, int *p_buf)
{
	args->alt = 1;
	args->base = 16;
	return (ft_lltoa_base(ptr, args, buf, p_buf));
}

int conversion_unicode(char *buf, wchar_t sign, t_args *args, int *p_buf)
{
	if (sign < 128)
		return conversion_int(buf, sign, args, p_buf);
	else if (sign < 2048)
		return (ft_uni2_to_buf(sign, args, buf, p_buf));
	else if (sign < 65536)
		return (ft_uni3_to_buf(sign, args, buf, p_buf));
	else if (sign < 2097152)
		return (ft_uni4_to_buf(sign, args, buf, p_buf));
	else
		return (0);
}

int conversion(char *buf, va_list ap, t_args *args, int *p_buf)
{

	if (args->is_sizet)
		if (args->spec == 'd')
			return conversion_long_long_unsigned(buf, (ssize_t)va_arg(ap, unsigned long long int), args, p_buf);
	if (args->spec == 'c' && args->is_long)
		args->spec = 'C';
	if (args->spec == 'c' || (args->spec == 'd' && !args->is_long && !args->is_long_long) || (args->spec == 'i' && !args->is_long && !args->is_long_long))
		return conversion_int(buf, va_arg(ap, int), args, p_buf);
	if ((args->spec == 'd' && args->is_long) || (args->spec == 'i' && args->is_long))
		return conversion_long(buf, va_arg(ap, long), args, p_buf);
	if ((args->spec == 'd' && args->is_long_long) || (args->spec == 'i' && args->is_long_long))
		return conversion_long_long(buf, va_arg(ap, long long), args, p_buf);
	if (args->spec == 's' || args->spec == 'S')
		return conversion_string(buf, va_arg(ap, char *), args, p_buf);
	if (args->spec == 'p')
		return conversion_void(buf, va_arg(ap, unsigned long long), args, p_buf);
	if ((args->spec == 'u' || args->spec == 'o' || args->spec == 'x') && !args->is_long && !args->is_long_long)
		return conversion_unsigned(buf, va_arg(ap, unsigned int), args, p_buf);
	if ((args->spec == 'u' || args->spec == 'o' || args->spec == 'x') && args->is_long)
		return conversion_long_unsigned(buf, va_arg(ap, unsigned long int), args, p_buf);
	if ((args->spec == 'u' || args->spec == 'o' || args->spec == 'x') && args->is_long_long)
		return conversion_long_long_unsigned(buf, va_arg(ap, unsigned long long int), args, p_buf);
	if (args->spec == 'f' && !args->is_long_double)
		return conversion_double(buf, va_arg(ap, double), args, p_buf);
	if (args->spec == 'f' && args->is_long_double)
		return conversion_double(buf, va_arg(ap, long double), args, p_buf);
	if (args->spec == '%')
		return conversion_percent(buf, "%", args, p_buf);
	if (args->spec == 'C')
		return conversion_unicode(buf, va_arg(ap, wchar_t), args, p_buf);
	return (0);
}

#include "../includes/ft_printf.h"

int (*conversions[10])(char *, va_list, t_args*, int*) =
{
	&conversion_int,
	&conversion_long,
	&conversion_long_long,
	&conversion_double,
	&conversion_unsigned,
	&conversion_long_unsigned,
	&conversion_long_long_unsigned,
	&conversion_string,
	&conversion_void,
	&conversion_unicode
};

int conversion_int(char *buf, va_list ap, t_args *args, int *p_buf)
{
	int nb;
	int len;

	len = 0;
	nb = va_arg(ap, int);
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
			padding_right_char(buf, "", args, p_buf);
	}
	else
		len = ft_itoa_base(nb, args, buf, p_buf);
	return (len);
}

int conversion_long(char *buf, va_list ap, t_args *args, int *p_buf)
{
	long nb;

	nb = va_arg(ap, long);
	return (ft_ltoa_base(nb, args, buf, p_buf));
}

int conversion_long_long(char *buf, va_list ap, t_args *args, int *p_buf)
{
	long long nb;

	nb = va_arg(ap, long long);
	return (ft_lltoa_base(nb, args, buf, p_buf));
}

int conversion_double(char *buf, va_list ap, t_args *args, int *p_buf)
{
	long double nb;

	if (args->is_long_double)
		nb = va_arg(ap, long double);
	else
		nb = va_arg(ap, double);
	return (ft_dtoa(nb, args, buf, p_buf));
}

int conversion_unsigned(char *buf, va_list ap, t_args *args, int *p_buf)
{
	unsigned int nb;

	nb = va_arg(ap, unsigned int);
	if (args->is_short)
		nb = (unsigned short)nb;
	if (args->is_char)
		nb = (unsigned char)nb;
	return (ft_utoa_base(nb, args, buf, p_buf));
}

int conversion_long_unsigned(char *buf, va_list ap, t_args *args, int *p_buf)
{
	unsigned long nb;

	nb = va_arg(ap, unsigned long int);
	return (ft_ultoa_base(nb, args, buf, p_buf));
}

int conversion_long_long_unsigned(char *buf, va_list ap, t_args *args, int *p_buf)
{
	unsigned long long nb;

	if (args->is_sizet)
		if (args->spec == 'd')
			nb = (ssize_t)va_arg(ap, unsigned long long int);
	nb = va_arg(ap, unsigned long long int);
	return (ft_ulltoa_base(nb, args, buf, p_buf));
}

int conversion_string(char *buf, va_list ap, t_args *args, int *p_buf)
{
	char *str;

	str = va_arg(ap, char *);
	if ((!args->prec || args->prec > (int)ft_strlen(str)) && str)
		args->prec = ft_strlen(str);
	if (args->prec == -1 && str)
		args->prec = 0;
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
int conversion_void(char *buf, va_list ap, t_args *args, int *p_buf)
{
	unsigned long long ptr;

	ptr = va_arg(ap, unsigned long long);
	args->alt = 1;
	args->base = 16;
	return (ft_lltoa_base(ptr, args, buf, p_buf));
}

int conversion_unicode(char *buf, va_list ap, t_args *args, int *p_buf)
{
	wchar_t sign;

	sign = va_arg(ap, wchar_t);
	if (sign < 128)
		return ft_uni_to_buf((int)sign, args, buf, p_buf);
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
	int (*conv)(char *, va_list, t_args*, int*);

	conv = conversions[args->conv + args->is_long + args->is_long_long];
	if (args->spec == '%')
		return conversion_percent(buf, "%", args, p_buf);
	else
		return ((*conv)(buf, ap, args, p_buf));
}

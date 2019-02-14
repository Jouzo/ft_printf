#include "../includes/ft_printf.h"

int		conversion_void(char *buf, va_list ap, t_args *args, int *p_buf)
{
	unsigned long long ptr;

	ptr = va_arg(ap, unsigned long long);
	args->alt = 1;
	args->base = 16;
	return (ft_lltoa_base(ptr, args, buf, p_buf));
}

int		conversion_unicode(char *buf, va_list ap, t_args *args, int *p_buf)
{
	wchar_t sign;

	sign = va_arg(ap, wchar_t);
	if (sign < 128)
		return (ft_uni_to_buf((int)sign, args, buf, p_buf));
	else if (sign < 2048)
		return (ft_uni2_to_buf(sign, args, buf, p_buf));
	else if (sign < 65536)
		return (ft_uni3_to_buf(sign, args, buf, p_buf));
	else if (sign < 2097152)
		return (ft_uni4_to_buf(sign, args, buf, p_buf));
	else
		return (0);
}

int		conversion_string2(char *buf, char *str, t_args *args, int *p_buf)
{
	add_option_string(buf, args, str, p_buf);
	if (*p_buf + args->prec > BUFF_SIZE)
		check_buf(buf, p_buf, args);
	ft_memcpy(buf + *p_buf, str, args->prec);
	if (args->left && args->width)
		padding_right_string(buf, str, args, p_buf);
	return (args->prec);
}

int		conversion_string(char *buf, va_list ap, t_args *args, int *p_buf)
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
		return (conversion_string2(buf, str, args, p_buf));
}

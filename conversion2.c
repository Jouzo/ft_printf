/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:42:12 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/04/28 17:35:32 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		conversion_int(char *buf, va_list ap, t_args *args, int *p_buf)
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
		if (args->left)
			padding_right_char(buf, "", args, p_buf);
	}
	else
		len = ft_itoa_base(nb, args, buf, p_buf);
	return (len);
}

int		conversion_long(char *buf, va_list ap, t_args *args, int *p_buf)
{
	long nb;

	nb = va_arg(ap, long);
	return (ft_ltoa_base(nb, args, buf, p_buf));
}

int		conversion_long_long(char *buf, va_list ap, t_args *args, int *p_buf)
{
	long long nb;

	nb = va_arg(ap, long long);
	return (ft_lltoa_base(nb, args, buf, p_buf));
}

int		conversion_double(char *buf, va_list ap, t_args *args, int *p_buf)
{
	long double nb;

	if (args->is_long_double)
		nb = va_arg(ap, long double);
	else
		nb = va_arg(ap, double);
	return (ft_dtoa(nb, args, buf, p_buf));
}

int		conversion_percent(char *buf, char *str, t_args *args, int *p_buf)
{
	int len;

	len = ft_strlen(str);
	if (args->prec && ft_strlen(str) > (size_t)args->prec)
		len = args->prec;
	if (!str)
	{
		args->prec = args->prec == 0 ? 6 : args->prec;
		if (*p_buf + 6 > BUFF_SIZE)
			check_buf(buf, p_buf, args);
		add_option_string(buf, args, "(null)", p_buf);
		ft_memcpy(buf + *p_buf, "(null)", args->prec);
		return (args->prec);
	}
	else
	{
		add_option_string(buf, args, str, p_buf);
		if (*p_buf + len > BUFF_SIZE)
			check_buf(buf, p_buf, args);
		ft_memcpy(buf + *p_buf, str, len);
		if (args->left && args->width)
			padding_right_string(buf, str, args, p_buf);
		return (len);
	}
}

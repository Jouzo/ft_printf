/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:42:12 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/11 13:57:02 by mmovahhe         ###   ########.fr       */
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

void	percent_option(char *buf, t_args *args, int *p_buf)
{
	int i;
	int len;

	i = 0;
	len = args->prec && args->prec > 0 ? args->prec : 1;
	if (args->width - len >= 0 && !args->left)
	{
		if (args->width - len > BUFF_SIZE * i)
			i += big_fill_prec(buf, p_buf, args, args->width - len);
		ft_memset(buf + *p_buf, ' ', args->width - 1);
		*p_buf += args->width - 1;
	}
}

int		conversion_percent(char *buf, char *str, t_args *args, int *p_buf)
{
	int len;
	len = 1;
	if (args->prec && args->prec > 0)
		len = args->prec;
	if (args->zero && args->width && !args->left && args->spec == '%')
		fill_zero_string(buf, args, 1, p_buf);
	else
		percent_option(buf, args, p_buf);
	if (*p_buf + len > BUFF_SIZE)
		check_buf(buf, p_buf, args);
	ft_memcpy(buf + *p_buf, "%", 1);
	if (args->left && args->width)
		padding_right_string(buf, str, args, p_buf);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:42:08 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/26 20:24:50 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conversion_void(char *buf, va_list ap, t_args *args, int *p_buf)
{
	unsigned long long ptr;

	ptr = va_arg(ap, unsigned long long);
	args->alt = 1;
	args->base = 16;
	return (ft_ulltoa_base(ptr, args, buf, p_buf));
}

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:29:00 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/24 23:29:03 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			conversion_long_string(char *buf,
				char *str, t_args *args, int *p_buf)
{
	int i;

	i = 0;
	add_option_string(buf, args, str, p_buf);
	if (*p_buf + args->prec > BUFF_SIZE)
		i = print_long_string(buf,
				p_buf, args, str);
	ft_memcpy(buf + *p_buf, str + BUFF_SIZE * i, args->prec - BUFF_SIZE * i);
	if (args->left && args->width)
		padding_right_string(buf, str, args, p_buf);
	return (args->prec - BUFF_SIZE * i);
}

int			conversion_string2(char *buf, char *str, t_args *args, int *p_buf)
{
	add_option_string(buf, args, str, p_buf);
	if (*p_buf + args->prec > BUFF_SIZE)
		check_buf(buf, p_buf, args);
	ft_memcpy(buf + *p_buf, str, args->prec);
	if (args->left && args->width)
		padding_right_string(buf, str, args, p_buf);
	return (args->prec);
}

int			conversion_string(char *buf, va_list ap, t_args *args, int *p_buf)
{
	char *str;

	str = va_arg(ap, char *);
	if ((!args->prec || args->prec > (int)ft_strlen(str)) && str)
		args->prec = ft_strlen(str);
	if (args->prec == -1 && str)
		args->prec = 0;
	if (ft_strlen(str) > BUFF_SIZE)
		return (conversion_long_string(buf, str, args, p_buf));
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

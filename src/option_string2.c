/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_string2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:44:36 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/26 20:24:50 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	padding_left_string(char *buf, t_args *args, int size, int *p_buf)
{
	int i;

	i = 0;
	if (args->width - size > 0)
	{
		if (args->width - size > BUFF_SIZE)
			i = big_padding_left(buf, p_buf, args, args->width - size);
		ft_memset(buf + *p_buf, ' ', args->width - size - BUFF_SIZE * i);
		*p_buf += args->width - size - BUFF_SIZE * i;
	}
}

void	fill_prec_string(char *buf, t_args *args, int size, int *p_buf)
{
	int len;
	int i;

	i = 0;
	len = size;
	if (args->prec && len > args->prec)
		len = args->prec;
	if (args->prec - size > 0)
	{
		if (args->width - len > 0)
		{
			if (args->width - len > BUFF_SIZE)
				i = big_fill_prec_string(buf, p_buf, args, args->width - len);
			ft_memset(buf + *p_buf, ' ', args->width - len - BUFF_SIZE * i);
			*p_buf += args->width - len - BUFF_SIZE * i;
		}
	}
	if (args->prec == -1)
		padding_left_string(buf, args, size, p_buf);
}

int		print_long_string(char *buf, int *p_buf, t_args *args, char *str)
{
	int i;

	i = 0;
	check_buf(buf, p_buf, args);
	while (args->prec - BUFF_SIZE * i > BUFF_SIZE)
	{
		ft_memcpy(buf + *p_buf, str + BUFF_SIZE * i, BUFF_SIZE - *p_buf);
		*p_buf += BUFF_SIZE - *p_buf;
		check_buf(buf, p_buf, args);
		i++;
	}
	return (i);
}

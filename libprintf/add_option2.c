/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_option2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:41:38 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/02/14 18:41:39 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	one_space(char *buf, int *p_buf, t_args *args)
{
	if (*p_buf == BUFF_SIZE)
		check_buf(buf, p_buf, args);
	ft_memset(buf + *p_buf, ' ', 1);
	*p_buf += 1;
}

void	padding_right(char *buf, char *conv, t_args *args, int *p_buf)
{
	int len;
	int min;
	int i;

	i = 0;
	min = 0;
	len = (args->spec == 'p' || args->spec == 'x')
			&& args->alt ? ft_strlen(conv) + 2 : ft_strlen(conv);
	len = args->spec == 'o' && args->alt ? len += 1 : len;
	if (args->showsign || args->minus || args->space)
		min = 1;
	len += min;
	if (len <= args->prec && args->prec)
		len = args->prec + min;
	if (args->width - len > 0)
	{
		if (args->width - len > BUFF_SIZE)
			i = big_padding_right(buf + ft_strlen(conv),
			p_buf, args, args->width - len);
		ft_memset(buf + *p_buf + ft_strlen(conv),
			' ', args->width - len - BUFF_SIZE * i);
		*p_buf += args->width - len - BUFF_SIZE * i;
	}
}

void	print_sign(char *buf, int *p_buf, t_args *args)
{
	if (*p_buf == BUFF_SIZE)
		check_buf(buf, p_buf, args);
	ft_memset(buf + *p_buf, '+', 1);
	*p_buf += 1;
}

void	print_minus(char *buf, int *p_buf, t_args *args)
{
	if (*p_buf == BUFF_SIZE)
		check_buf(buf, p_buf, args);
	ft_memset(buf + *p_buf, '-', 1);
	*p_buf += 1;
}

void	add_hash(char *buf, t_args *args, int *p_buf)
{
	if (args->spec == 'x' || args->spec == 'p')
	{
		if (*p_buf + 1 == BUFF_SIZE || *p_buf == BUFF_SIZE)
			check_buf(buf, p_buf, args);
		ft_memset(buf + *p_buf, '0', 1);
		ft_memset(buf + *p_buf + 1, 'x' - args->capital * 2, 1);
		*p_buf += 2;
	}
	else if (args->spec == 'o')
	{
		if (*p_buf == BUFF_SIZE)
			check_buf(buf, p_buf, args);
		ft_memset(buf + *p_buf, '0', 1);
		*p_buf += 1;
	}
}

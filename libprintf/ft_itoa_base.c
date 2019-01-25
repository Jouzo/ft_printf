/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 13:42:02 by exam              #+#    #+#             */
/*   Updated: 2019/01/25 23:29:48 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int value, int base, int capital)
{
	if (base < 2 || base > 16)
		return (0);
	char *str_base = "0123456789abcdef0123456789ABCDEF";
	char *res;
	int value_size;
	unsigned int abs_value;

	value_size = 0;
	abs_value = value;
	if (value < 0)
		abs_value = -value;
	while (abs_value > 0)
	{
		abs_value = abs_value / base;
		value_size++;
	}
	if (value < 0)
		abs_value = -value;
	else
		abs_value = value;
	if (base == 10 && value < 0)
	{
		abs_value = -value;
		value_size++;
		if (!(res = malloc(sizeof(char) * value_size)))
			return (NULL);
		while (value_size > 2)
		{
			res[value_size - 1] = str_base[(abs_value % base) + capital];
			abs_value /= base;
			value_size--;
		}
		res[1] = str_base[abs_value + capital];
		res[0] = '-';
	}
	else
	{
		if (!(res = malloc(sizeof(char) * value_size)))
			return (NULL);
		while (value_size > 1)
		{
			res[value_size - 1] = str_base[(abs_value % base) + capital];
			abs_value /= base;
			value_size--;
		}	
		res[0] = str_base[abs_value + capital];
	}
	return (res);
}

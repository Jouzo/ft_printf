/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:43:47 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/02/14 18:51:42 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printstr(char const *s, int p_buf, t_args args)
{
	if (s)
		return (write(args.fd, s, p_buf));
	return (0);
}

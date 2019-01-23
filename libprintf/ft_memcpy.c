/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:21:25 by jdescler          #+#    #+#             */
/*   Updated: 2019/01/23 20:23:25 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *ptr;

	ptr = dst;
	while (n--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (ptr);
}

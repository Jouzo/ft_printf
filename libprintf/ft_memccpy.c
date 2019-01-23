/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:03:23 by jdescler          #+#    #+#             */
/*   Updated: 2019/01/23 17:56:43 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = dst;
	while (n--)
	{
		if ((*ptr++ = (*(unsigned char *)src++)) == (unsigned char)c)
			return (ptr);
	}
	return (NULL);
}

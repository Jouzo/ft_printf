#include "../includes/ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *ptr;

	ptr = dst;
	while (n--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (ptr);
}

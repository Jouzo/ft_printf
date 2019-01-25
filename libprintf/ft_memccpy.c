#include "../includes/ft_printf.h"
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

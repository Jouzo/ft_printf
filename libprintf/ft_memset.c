#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;

	ptr = b;
	printf("INSIDE MEMSET\n");
	while (len--)
		*ptr++ = (unsigned char)c;
	return (b);
}

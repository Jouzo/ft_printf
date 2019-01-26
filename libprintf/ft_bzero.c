#include "../includes/ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	if (n != 0)
	{
		ft_memset(s, 0, n);
	}
}

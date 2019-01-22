
#include "libft.h"

void	printf_endl(char const *s)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
		ft_putchar('\n');
	}
}

#include "../includes/ft_printf.h"

size_t	ft_strlen(char const *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

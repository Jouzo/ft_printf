#include "ft_printf.h"
void	ft_printstr(char const *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}
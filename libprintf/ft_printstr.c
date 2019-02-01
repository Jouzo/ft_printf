#include "../includes/ft_printf.h"
int		ft_printstr(char const *s, int *p_buf)
{
	if (s)
		write(1, s, *p_buf);
	return (*p_buf);
}
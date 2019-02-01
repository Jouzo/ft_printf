#include "../includes/ft_printf.h"
int		ft_printstr(char const *s)
{
	int len;
	
	len = ft_strlen(s);
	if (s)
		write(1, s, len);
	return (len);
}
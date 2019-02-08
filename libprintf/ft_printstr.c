#include "../includes/ft_printf.h"
int		ft_printstr(char const *s, int *p_buf, t_args args)
{
	if (s)
		write(args.fd, s, *p_buf);
	return (*p_buf);
}
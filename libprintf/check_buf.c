#include "../includes/ft_printf.h"

void	check_buf(char *buf, int *p_buf, t_args *args)
{
	args->len += ft_printstr(buf, *p_buf, *args);
	ft_bzero(buf, *p_buf);
	*p_buf = 0;
}

#include "../includes/ft_printf.h"

void	ft_itoc(int nb, t_args *args, char *buf, int *p_buf)
{
	if (!nb)
		args->prec = 0;
	if (*p_buf == BUFF_SIZE)
		check_buf(buf, p_buf, args);
	add_option(buf, args, "1", p_buf);
	ft_memset(buf + *p_buf, nb, 1);
	*p_buf += 1;
}

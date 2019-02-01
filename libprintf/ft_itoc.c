#include "../includes/ft_printf.h"

void    ft_itoc(int nb, t_args args, char *buf, int *start)
{
    add_option(buf, args, "1", start);
    ft_memset(buf + *start, nb, 1);
    *start += 1;
}
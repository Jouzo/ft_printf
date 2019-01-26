#include "../includes/ft_printf.h"

void ft_itoc(int nb, char **buf, int *start, t_args args)
{
    add_option(*buf, args, "1", start);
    ft_memset(*buf + *start, nb, 1);
    ft_memset(*buf + *start + 1, '\0', 1);
    *start += 1;
}
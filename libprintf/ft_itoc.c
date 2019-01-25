#include "../includes/ft_printf.h"

void ft_itoc(int nb, char **conv)
{
    ft_memset(*conv, nb, 1);
    ft_memset(*conv + 1, '\0', 1);
}
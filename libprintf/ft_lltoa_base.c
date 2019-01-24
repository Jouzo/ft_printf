#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"
void    ft_itoa_base_b(int nb, int base, char **res)
{
    char *str_base;
    int i;
    int capitale = 0; // a rajouter dans la struct

    str_base = "0123456789abcdef0123456789ABCDEF";
    char buf[] = "000000000000000000";
    char *buf_bis;

    i = 0;
    while (nb > 0)
    {
        ft_memset(buf + i, str_base[nb % 10], 1);
        nb /= 10;
        i++;
    }
    buf[i] = '\0';
    ft_memcpy(buf_bis, buf, ft_strlen(buf) + 1);
    *res = buf_bis;
}

int main()
{
    char *res;
    
    ft_itoa_base_b(247, 10, &res);
    printf("%s", res);
}
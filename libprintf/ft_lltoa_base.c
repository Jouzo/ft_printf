#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"
#include <string.h>

void ft_itoa_base_b(int nb, int base, char **res)
{
    char str_base[33];

    ft_memcpy(str_base, "0123456789abcdef0123456789ABCDEF", 32);
    ft_memset(str_base + 32, '\0', 1);
    while (nb > 0)
    {
        ft_memset((*res), (str_base[(nb % 10)]), 1);
        nb /= 10;
    }
    printf("value of res in itoa %s", *res);
}

int main()
{
    char *res;

    ft_itoa_base_b(2147483647, 10, &res);
    printf("value of res after itoa %s", res);
}
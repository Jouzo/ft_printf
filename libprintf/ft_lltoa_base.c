#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"
void    ft_itoa_base_b(int nb, int base, char **res)
{
    char str_base[33];

    ft_memcpy(str_base, "0123456789abcdef0123456789ABCDEF", 32);
    ft_memset(str_base + 32, '\0', 1);
    int i;
    int capitale = 0; // a rajouter dans la struct
    int tmp;

    tmp = 0;
    i = 0;
    while (nb > 0)
    {
   printf("dede %c\n", str_base[nb % 10]);
        tmp = str_base[nb % 10];
   printf("dede %c\n", tmp);
        ft_memset(*res, tmp, 1);
        nb /= 10;
        i++;
        printf("value de mes boulles: enorme%s\n", *res);
    }

    printf("dede%s\n", *res);
}

int main()
{
    char *res;
    
    ft_itoa_base_b(2147483647, 10, &res);
    printf("dede");
    printf("%s", res);
}
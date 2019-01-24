#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"
void    ft_itoa_base_b(int nb, int base, char **res)
{
    char *str_base = "0123456789abcdef0123456789ABCDEF";

    int i;
    int capitale = 0; // a rajouter dans la struct
    int tmp;
    char buf[] = "000000000000000000";
    char *buf_bis;

    tmp = 0;
    i = 0;
    while (nb > 0)
    {
    //    printf("value tmp %c\n", str_base[nb % 10]);
        tmp = str_base[nb % 10];
        ft_memset(buf + i, tmp, 1);
    //    *res[i] = 'a';
        nb /= 10;
        i++;
        printf("value de res: %s\n", buf);
    }
    buf[i] = '\0';
    ft_memcpy(buf_bis, buf, ft_strlen(buf) + 1);
 //   printf("dede%s\n", *res);
    printf("value de buf_bis: %s\n", buf_bis);
    *res = buf_bis;
}

int main()
{
    char *res;
    
    ft_itoa_base_b(2147483647, 10, &res);
    printf("%s", res);
}
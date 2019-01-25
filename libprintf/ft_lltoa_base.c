#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

void ft_itoa(int n, char s[], int base)
{
    int i;
    int sign;
    char *str_base = "0123456789abcdef";

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    if (n > 0)
    s[i++] = str_base[n % base];
    while ((n /= base) > 0)
    {
        s[i++] = str_base[n % base];
    }
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
}

int main()
{
    char str[32];
    ft_itoa(2147483647, str, 16);
    printf("%s", str);
}
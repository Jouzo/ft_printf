#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	ft_printf("%zd", LLONG_MAX);
	ft_putchar('\n');
   	printf("%zd", LLONG_MAX);
    return (0);
}
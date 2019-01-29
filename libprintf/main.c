#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	ft_printf("%5.300d", 12);
	ft_putchar('\n');
   	printf("%5.300d", 12);
    return (0);
}
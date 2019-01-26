#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	ft_printf("{%010d}", 42);
	ft_putchar('\n');
   	printf("{%010d}", 42);
    return (0);
}
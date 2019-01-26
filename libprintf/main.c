#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	ft_printf("% o|%+o", 42, 42);
	ft_putchar('\n');
   	printf("% o|%+o", 42, 42);
    return (0);
}
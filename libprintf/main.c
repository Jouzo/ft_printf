#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	ft_printf("%O", 0);
	ft_putchar('\n');
   	printf("%O", 0);
    return (0);
}
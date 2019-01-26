#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	ft_printf("%#15X\n", -22);
   	printf("%#15X", -22);
    return (0);
}
#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	ft_printf("%5s\n", "42");
   	printf("%5p\n", "42");
    return (0);
}
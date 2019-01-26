#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	ft_printf("je mappelle %.2s tototo\n", "dddd");
   	printf("je mappelle %.2s tototo\n", "dddd");
    return (0);
}
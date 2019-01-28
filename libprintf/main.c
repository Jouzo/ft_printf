#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	ft_printf("je mappelle %08d\n", 123);
   	printf("je mappelle %08d", 123);
    return (0);
}
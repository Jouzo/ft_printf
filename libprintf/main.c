#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
<<<<<<< HEAD
	ft_printf("je mappelle %d\n", 123);
   	printf("je mappelle %d", 123);
=======
	ft_printf("{%010d}", 42);
	ft_putchar('\n');
   	printf("{%010d}", 42);
>>>>>>> e6e4253f6d0125d8084c5bbde54bb4c3f25071d7
    return (0);
}
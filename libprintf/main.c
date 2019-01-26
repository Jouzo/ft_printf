#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	char *a = "dede";

	ft_printf("je mappelle %p\n", a);
   	printf("je mappelle %p", a);
    return (0);
}
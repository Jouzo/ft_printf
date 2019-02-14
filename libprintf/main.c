#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	ft_printf("%p", NULL);
	printf("\n");
	printf("%p", NULL);
	return (0);
}

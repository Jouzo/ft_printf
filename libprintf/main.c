#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	int i, j;

	i = 0;
	i = ft_printf("{%s}", 0);
	printf("\n");
   	j = printf("{%s}", 0);
	printf("\n\nreturn value : %i %i\n", i, j);
    return (0);
}
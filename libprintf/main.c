#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"
#include <wchar.h>

int     main()
{
	int i, j;
	
	i = j = 0;
	i = ft_printf("%-5c", 42);
	printf("\n");
	j = printf("%-5c", 42);
	printf("\n\nreturn value : %i %i\n", i, j);
    return (0);
}
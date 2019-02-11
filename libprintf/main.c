#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"
#include <wchar.h>


int     main()
{
	int i, j;

	i = j = 0;

	j = printf("%X", 42);
	printf("\n");
	i = ft_printf("%X", 42);
	// printf("\n");
	printf("return value : %i %i\n", i, j);
    return (0);
}
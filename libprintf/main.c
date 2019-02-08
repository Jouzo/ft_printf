#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"
#include <wchar.h>
#include <locale.h>

int     main()
{
	int i, j;
	
	i = j = 0;
	i = ft_printf("%-5.2s is a string", "this");
	printf("\n");
	j = printf("%-5.2s is a string", "this");
	printf("\n\nreturn value : %i %i\n", i, j);

    return (0);
}
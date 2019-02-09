#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"
#include <wchar.h>

int     main()
{
	int i, j;
	
	i = j = 0;
	i = ft_printf("chaine -> %4s\n", "e");
	printf("\n");
	j = printf("chaine -> %4s\n", "e");
	printf("\n\nreturn value : %i %i\n", i, j);
    return (0);
}
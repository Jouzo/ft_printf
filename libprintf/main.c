#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"
#include <wchar.h>
#include <locale.h>

int     main()
{
	int i, j;
	
	i = j = 0;
	i = ft_printf("{%10.20000d}", 204353);
	printf("\n");
	j = printf("{%10.200000d}", 204353);
	printf("\n\nreturn value : %i %i\n", i, j);
    return (0);
}
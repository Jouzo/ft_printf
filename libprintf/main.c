#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"
#include <wchar.h>
#include <locale.h>

int     main()
{
	int i, j;
	i = 0;
	j = 0;

	i = ft_printf("%8.6s", "asas");
	printf("\n");
	j = printf("%8.6s", "asas");
	printf("\n\nreturn value : %i %i\n", i, j);
    return (0);
}
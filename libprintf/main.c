#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"
#include <wchar.h>
#include <locale.h>

int     main()
{
	int i, j;

	i = 0;
	i = ft_printf("%c salut", 0);
	printf("\n");
   	j = printf("%c salut", 0);
	printf("\n\nreturn value : %i %i\n", i, j);
    return (0);
}
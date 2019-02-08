#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"
#include <wchar.h>
#include <locale.h>

int     main()
{
	int i, j;
	
	i = j = 0;
	i = ft_printf("@moulitest: %.10x %#.0x", 0, 0);
	printf("\n");
	j = printf("@moulitest: %.10x %#.0x", 0, 0);
	printf("\n\nreturn value : %i %i\n", i, j);

    return (0);
}
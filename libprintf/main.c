#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"



int     main()
{
	int i, j;

	i = j = 0;

	printf("\n");
	j = printf("%zd", -1);
	printf("\n");
	i = ft_printf("%zd", -1);
	printf("--------------------------\n");
	printf("--------------------------\n");

	printf("return value : %i %i\n", i, j);
	printf("--------------------------\n");
	printf("--------------------------\n");

	return (0);
}

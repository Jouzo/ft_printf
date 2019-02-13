#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	int i, j;

	i = j = 0;

	printf("\n");
	i = ft_printf("@moulitest: %5.d %5.0d", 0, 0);
	printf("\n");
	j = printf("@moulitest: %5.d %5.0d", 0, 0);
	printf("\n");
	printf("return values : %d et %d\n", i, j);
	// ft_printf("mien %#.1o\n", 0);
	// printf("vrai %#.1o\n", 0);
	return (0);
}

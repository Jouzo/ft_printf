#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	int i, j;

	i = j = 0;
	ft_printf("our  printf : \n");
	i = ft_printf("%15.4d", -42);
	printf("\n");
	printf("--------------------------\n");
	printf("--------------------------\n");
	printf("real printf : \n");
	j = printf("%15.4d", -42);
	printf("\n");
	printf("return values : %d et %d\n", i, j);
	// ft_printf("mien %#.1o\n", 0);
	// printf("vrai %#.1o\n", 0);
	return (0);
}

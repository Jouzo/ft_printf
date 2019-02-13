#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	int i, j;

	i = j = 0;
	ft_printf("our  printf : \n");
	i = ft_printf("Coucou %.0s\n%s%---12s", "hi", "coco", NULL);
	printf("\n");
	printf("--------------------------\n");
	printf("--------------------------\n");
	printf("real printf : \n");
	j = printf("Coucou %.0s\n%s%---12s", "hi", "coco", NULL);
	printf("\n");
	printf("--------------------------\n");
	printf("--------------------------\n");
	printf("our  printf return value : %i\n", i);
	printf("real printf return value : %i\n", j);
	printf("--------------------------\n");
	printf("--------------------------\n");
	return (0);
}

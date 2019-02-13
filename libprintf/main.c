#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	int i, j;

	i = j = 0;
<<<<<<< HEAD

// "test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499

	printf("\n");
	i = ft_printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
	printf("\n");
	j = printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
	printf("\n");
	printf("return values : %d et %d\n", i, j);
=======
	ft_printf("our  printf : \n");
	i = ft_printf("%5.2s is a string", "");
	printf("\n");
	printf("--------------------------\n");
	printf("--------------------------\n");
	printf("real printf : \n");
	j = printf("%5.2s is a string", "");
	printf("\n");
	printf("--------------------------\n");
	printf("--------------------------\n");
	printf("our  printf return value : %i\n", i);
	printf("real printf return value : %i\n", j);
	printf("--------------------------\n");
	printf("--------------------------\n");
>>>>>>> f5c1f04bd3db165b26ae8712da5b2df002b07267
	return (0);
}

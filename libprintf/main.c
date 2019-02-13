#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	int i, j;

	i = j = 0;

// "test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499

	printf("\n");
	i = ft_printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
	printf("\n");
	j = printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
	printf("\n");
	printf("return values : %d et %d\n", i, j);
	return (0);
}

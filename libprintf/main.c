#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	int i, j;

	i = j = 0;

//"%0#10.0x", 0
//"%0#10.0x %0#x", 12345, 0
//"toto %##.0xet %#.X%###.1x", 0, 0, 0

char *a = "dede";

	printf("\n");
	i = ft_printf("@moulitest: %5.o %5.0o", 0, 0);
	printf("\n");
	j = printf("@moulitest: %5.o %5.0o", 0, 0);
	printf("\n");
	printf("return values : %d et %d\n", i, j);
	// ft_printf("mien %#.1o\n", 0);
	// printf("vrai %#.1o\n", 0);
	return (0);
}

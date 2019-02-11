#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"
#include <wchar.h>


int     main()
{
	int i, j;
	double test, test2;
	int prec;

	prec = 20;
	test = 1234567890123456789012.0;
	// test += 1.123456789;
	test2 = test - (long)test;
	// printf("\n\nget the decimal D%.20Lf\n\n", get_decimal(test, 6));
	i = j = 0;
	ft_printf("our printf value of test %+80.7f\n", test);
	printf("realprintf value of test %+80.7f\n", test);
	printf("----------------\n");
	ft_printf("%.12d\n", 12);
	printf("%.12d\n", 12);
	printf("----------------\n");
	ft_printf("%12.12s\n", "caca");
	printf("%12.12s\n", "caca");
	printf("----------------\n");
	ft_printf("%3x\n", 12);
	printf("%3x\n", 12);
	// printf("value of test before /= 10 : %.20Lf\n\n", test);
	// printf("value of test2 before /= 10 : %.20Lf\n\n", test2);

	// while (i < prec)
	// {
	// 	test2 *= 10;
	// 	i++;
	// 	printf("double cast to long %lu\n", (unsigned long)test2);
	// 	printf("get digit sur decimal %lu\n", (unsigned long)test2 % 10);
	// }
	// i = ft_printf("% 10.5d", 4242);
	// printf("\n");
	// j = printf("% 10.5d", 4242);
	// printf("\n\nreturn value : %i %i\n", i, j);
    return (0);
}
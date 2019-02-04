#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"
#include <wchar.h>
#include <locale.h>

int     main()
{
	int i, j;
	long long int s, e , m;
	double nb;

	double mantissa;
	int expo;

	expo = 0;
	nb = 13.25;
	s = e = 0;
	m = 0;
	i = j = 0;
	i = ft_printf("{%03.2d}", 0);
	printf("\n");
	j = printf("{%03.2d}", 0);
	printf("\n\nreturn value : %i %i\n", i, j);

	// get_sem(&s, &e, &m, nb);

	// mantissa = frexp(nb, &expo);
	// printf("value of mantissa : %f\n value of expo : %i\n", mantissa, expo);
	// double test;
	// printf("test = mantissa * pow(2, 4)\n");
	// test = mantissa * pow(2, 4);
	// printf("value of double test : %lf \n\n\n", test);
	// printf("s : %lld, e : %lld, m : %lld\n", s , e, m);
	// printf("nb as double : %.25lf\n", 13.25);

    return (0);
}
#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"
#include <wchar.h>


int     main()
{
	int i, j;
	long double test, test2;
	int prec;

	prec = 20;
	test = 12345678901234.12345678901234567890;
	// test += 1.123456789;
	test2 = test - (long)test;
	// printf("\n\nget the decimal %.20Lf\n\n", get_decimal(test, 6));
	i = j = 0;
	printf("printf value of test %.14Lf\n", test);
	ft_dtoa(test);
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


// void padding_right(char *buf, char *conv, t_args *args, int *p_buf)
// {
//     int len;
//     int min;

//     min = 0;
//     len = args->spec != 'p' ? ft_strlen(conv) : ft_strlen(conv) + 2;
//     len = args->spec == 'o' ? len + 1 : len;
//     // printf("\nvalue of len %i\n", len);
//     // printf("\nvalue of args->width - len - min - args->space %i\n", args->width - len - min - args->space);
//     // printf("\nvalue of args->width %i\n", args->width);
//     // printf("\nvalue of *p_buf %i\n", *p_buf);
//     // printf("\nvalue of ft_strlen(conv) %i\n", (int)ft_strlen(conv));
//     if (args->showsign || args->minus || args->space)
//         min = 1;
//     if (len + min + args->space < args->prec)
//         len = args->prec;
//     // printf("\nvalue of len %i\n", len);    
//     // printf("\nvalue of args->width - len - min - args->space %i\n", args->width - len - min - args->space);
//     if (args->width - len - min > 0 && args->prec < args->width)
//     {
//         ft_memset(buf + *p_buf + ft_strlen(conv), ' ', args->width - len  - min - args->space);
//         *p_buf += args->width - len  - min - args->space;
//     }
//     // printf("\nvalue of *p_buf %i\n", *p_buf);
// }
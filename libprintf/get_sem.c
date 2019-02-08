#include "../includes/ft_printf.h"

void    get_sem(long long int *s, long long int *e, long long int *m, double number)
{
unsigned long long int *ptr;
ptr = (unsigned long long int*)&number;

*s = *ptr >> 63;
*e = *ptr & 0x7FF0000000000000;
*e >>= 52;
*m = *ptr & 0xFFFFFFFFFFFFF;

// ft_printf("ptr as long long int : %lld\n", *ptr);


// ft_printf("s as long long int : %lld\n", *s);
ft_printf("e as long long int : %lld\n", *e);

// ft_printf("m as long long int : %lld\n", *m);


// ft_printf("s as binary : %b\n", *s);
// ft_printf("e as binary : %b\n", *e);

// ft_printf("m as binary : %b\n", *m);

}
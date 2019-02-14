#include "../includes/ft_printf.h"

unsigned long		get_deci(long double n, int i)
{
	long double		decimal;
	unsigned long	deci;
	unsigned long	to_round;

	decimal = (n - (unsigned long)n) * ft_pow(10, i);
	deci = (unsigned long)decimal;
	decimal = (n - (unsigned long)n) * ft_pow(10, i + 1);
	to_round = (unsigned long)decimal;
	if (to_round % 10 > 4)
		deci++;
	return (deci);
}

unsigned long		get_digit(long double n, int i)
{
	unsigned long	int_part;

	int_part = n < 0.0 ? (unsigned long)-n : (unsigned long)n;
	if (i + 1 == 20)
		return ('1');
	return (int_part % ft_pow(10, i + 1) / ft_pow(10, i) + '0');
}

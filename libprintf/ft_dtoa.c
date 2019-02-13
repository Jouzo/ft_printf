#include "../includes/ft_printf.h"

int add_dtoa(char *s, char *buf, int *p_buf, t_args *args)
{
	int len;

	len = ft_strlen(s);
	add_option_double(buf, args, s, p_buf);
	if (*p_buf + len > BUFF_SIZE)
		check_buf(buf, p_buf, args);
	ft_memcpy(buf + *p_buf, s, len);
	if (args->left && args->width > args->prec)
		padding_dright(buf, s, args, p_buf);
	return (len);
}

long double ft_powl(long double n, long double pow)
{
	return (pow > 0 ? n * ft_powl(n, pow - 1) : 1);
}

unsigned long ft_pow(unsigned long n, long pow)
{
	return (pow > 0 ? n * ft_pow(n, pow - 1) : 1);
}

int  get_size_int_part(long double n)
{
	int size;

	size = 0;
	while (n > 1)
	{
		n /= 10;
		size++;
	}
	return (size);
}

long get_decimal_digit(long decimal, double long n, int i)
{
	long ret;

	ret = decimal / ft_pow(10, i) % 10 + '0';
	if (get_size_int_part(n) > 15)
		ret = '0';
	return (ret);
}

unsigned long get_deci(long double n, int i)
{
	long double decimal;
	unsigned long deci;
	unsigned long to_round;

	decimal = (n - (unsigned long)n) * ft_pow(10, i);
	deci = (unsigned long)decimal;
	decimal = (n - (unsigned long)n) * ft_pow(10, i + 1);
	to_round = (unsigned long)decimal;
	if (to_round % 10 > 4)
		deci++;
	// if (get_size_int_part(n) > 15)
	//     deci = 0;
	return (deci);
}

unsigned long get_digit(long double n, int i)
{
	unsigned long int_part;

	int_part = n < 0.0 ? (unsigned long)-n : (unsigned long)n;
	// if (n < DINT_MAX)
	// printf("value int_part %% ft_pow(10, i + 1) / ft_pow(10, i) %lu\n", int_part % ft_pow(10, i + 1) / ft_pow(10, i));
	if (i + 1 == 20)
		return ('1');
	return (int_part % ft_pow(10, i + 1) / ft_pow(10, i) + '0');
	// return (0);
}

int ft_dtoa(long double n, t_args *args, char *buf, int *p_buf)
{
	unsigned long decimal;
	int i;
	char s[50];
	int prec;
	int j;

	ft_bzero(s, 50);
	j = 0;
	prec = args->prec == 0 ? 6 : args->prec;
	prec = args->prec == -1 ? 0 : prec;
	i = 0;
	args->minus = n < 0.0 ? 1 : 0;
	decimal = get_deci(n, prec);
	while (i < get_size_int_part(n))
	{
		s[i] = get_digit(n, i);
		i++;
	}
	ft_strrev(s);
	s[i++] = '.';
	while (prec--)
		s[i++] = get_decimal_digit(decimal, n, prec);
	s[i] = '\0';
	return (add_dtoa(s, buf, p_buf, args));
}

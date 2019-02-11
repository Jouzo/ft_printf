#include "../includes/ft_printf.h"

int		ft_ultoa_base(unsigned long int n, t_args *args, char *buf, int *p_buf)
{
	int		i;
	char	s[63];
	char	*str_base;

	str_base = "0123456789abcdef0123456789ABCDEF";
	i = 0;
	s[i++] = str_base[(n % args->base) + args->capital];
	while ((n /= args->base) > 0)
		s[i++] = str_base[(n % args->base) + args->capital];
	s[i] = '\0';
	return (add_toa(s, buf, p_buf, args));
}

int		ft_ulltoa_base(unsigned long long int n, t_args *ar, char *bf, int *p_b)
{
	int		i;
	char	s[63];
	char	*str_base;

	str_base = "0123456789abcdef0123456789ABCDEF";
	i = 0;
	s[i++] = str_base[(n % ar->base) + ar->capital];
	while ((n /= ar->base) > 0)
		s[i++] = str_base[(n % ar->base) + ar->capital];
	s[i] = '\0';
	return (add_toa(s, bf, p_b, ar));
}
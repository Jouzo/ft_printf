#include "../includes/ft_printf.h"

int		add_toa(char *s, char *buf, int *p_buf, t_args *args)
{
	int len;

	len = ft_strlen(s);
	ft_strrev(s);
	if (*s == '0' && len == 1)
		args->alt = 0;
	add_option(buf, args, s, p_buf);
	if (*p_buf + len > BUFF_SIZE)
		check_buf(buf, p_buf, args);
	ft_memcpy(buf + *p_buf, s, len);
	if ((args->spec == 'x' || args->spec == 'o' || args->spec == 'd'
				|| args->spec == 'u') && *s == '0'
			&& len == 1 && args->prec == -1)
		*p_buf -= 1;
	if (args->left && args->width > args->prec)
		padding_right(buf, s, args, p_buf);
	return (len);
}

int		ft_itoa_base(int n, t_args *args, char *buf, int *p_buf)
{
	int				i;
	char			s[31];
	char			*str_base;
	unsigned int	abs;

	str_base = "0123456789abcdef0123456789ABCDEF";
	abs = ABS(n);
	i = 0;
	s[i++] = str_base[(abs % args->base) + args->capital];
	while ((abs /= args->base) > 0)
		s[i++] = str_base[(abs % args->base) + args->capital];
	if (n < 0)
		args->minus = 1;
	s[i] = '\0';
	return (add_toa(s, buf, p_buf, args));
}

int		ft_ltoa_base(long n, t_args *args, char *buf, int *p_buf)
{
	int				i;
	char			s[63];
	char			*str_base;
	unsigned long	abs;

	str_base = "0123456789abcdef0123456789ABCDEF";
	abs = ABS(n);
	i = 0;
	s[i++] = str_base[(abs % args->base) + args->capital];
	while ((abs /= args->base) > 0)
		s[i++] = str_base[(abs % args->base) + args->capital];
	if (n < 0)
		args->minus = 1;
	s[i] = '\0';
	return (add_toa(s, buf, p_buf, args));
}

int		ft_lltoa_base(long long n, t_args *args, char *buf, int *p_buf)
{
	int					i;
	char				s[63];
	char				*str_base;
	unsigned long long	abs;

	str_base = "0123456789abcdef0123456789ABCDEF";
	abs = ABS(n);
	i = 0;
	s[i++] = str_base[(abs % args->base) + args->capital];
	while ((abs /= args->base) > 0)
		s[i++] = str_base[(abs % args->base) + args->capital];
	if (n < 0)
		args->minus = 1;
	s[i] = '\0';
	return (add_toa(s, buf, p_buf, args));
}

int		ft_utoa_base(unsigned int n, t_args *args, char *buf, int *p_buf)
{
	int		i;
	char	s[31];
	char	*str_base;

	str_base = "0123456789abcdef0123456789ABCDEF";
	i = 0;
	s[i++] = str_base[(n % args->base) + args->capital];
	while ((n /= args->base) > 0)
		s[i++] = str_base[(n % args->base) + args->capital];
	s[i] = '\0';
	return (add_toa(s, buf, p_buf, args));
}

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

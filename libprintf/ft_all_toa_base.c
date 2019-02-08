#include "../includes/ft_printf.h"

int add_toa(char *s, char *buf, int *p_buf, t_args args)
{
    int len;
    int min;

    min = 0;
    if (args.minus || args.showsign)
        min = 1;
    len = ft_strlen(s);
    ft_strrev(s);
    add_option(buf, args, s, p_buf);
    ft_memcpy(buf + *p_buf, s, ft_strlen(s));
    if (args.left)
        padding_right(buf, s, args, p_buf);
    return (len);
}

int ft_itoa_base(int n, t_args args, char *buf, int *p_buf)
{
    int i;
    char s[31];
    char *str_base = "0123456789abcdef0123456789ABCDEF";
    unsigned int abs;

    abs = ABS(n);
    i = 0;
    s[i++] = str_base[(abs % args.base) + args.capital];
    while ((abs /= args.base) > 0)
        s[i++] = str_base[(abs % args.base) + args.capital];
    if (n < 0)
        args.minus = 1;
    s[i] = '\0';
    return (add_toa(s, buf, p_buf, args));
}

int ft_ltoa_base(long n, t_args args, char *buf, int *p_buf)
{
    int i;
    char s[63];
    char *str_base = "0123456789abcdef0123456789ABCDEF";
    unsigned long abs;

    abs = ABS(n);
    i = 0;
    s[i++] = str_base[(abs % args.base) + args.capital];
    while ((abs /= args.base) > 0)
        s[i++] = str_base[(abs % args.base) + args.capital];
    if (n < 0)
        args.minus = 1;
    s[i] = '\0';
    return (add_toa(s, buf, p_buf, args));
}

int ft_lltoa_base(long long n, t_args args, char *buf, int *p_buf)
{
    int i;
    char s[63];
    char *str_base = "0123456789abcdef0123456789ABCDEF";
    unsigned long long abs;

    abs = ABS(n);
    i = 0;
    s[i++] = str_base[(abs % args.base) + args.capital];
    while ((abs /= args.base) > 0)
        s[i++] = str_base[(abs % args.base) + args.capital];
    if (n < 0)
        args.minus = 1;
    s[i] = '\0';
    return (add_toa(s, buf, p_buf, args));
}

int ft_utoa_base(unsigned int n, t_args args, char *buf, int *p_buf)
{
    int i;
    char s[31];
    char *str_base = "0123456789abcdef0123456789ABCDEF";
    if (n == 0)
        args.alt = 0;
    i = 0;
    s[i++] = str_base[(n % args.base) + args.capital];
    while ((n /= args.base) > 0)
        s[i++] = str_base[(n % args.base) + args.capital];
    s[i] = '\0';
    return (add_toa(s, buf, p_buf, args));
}

int ft_ultoa_base(unsigned long int n, t_args args, char *buf, int *p_buf)
{
    int i;
    char s[63];
    char *str_base = "0123456789abcdef0123456789ABCDEF";
    if (n == 0)
        args.alt = 0;
    i = 0;
    s[i++] = str_base[(n % args.base) + args.capital];
    while ((n /= args.base) > 0)
        s[i++] = str_base[(n % args.base) + args.capital];
    s[i] = '\0';
    return (add_toa(s, buf, p_buf, args));
}

int ft_ulltoa_base(unsigned long long int n, t_args args, char *buf, int *p_buf)
{
    int i;
    char s[63];
    char *str_base = "0123456789abcdef0123456789ABCDEF";
    if (n == 0)
        args.alt = 0;
    i = 0;
    s[i++] = str_base[(n % args.base) + args.capital];
    while ((n /= args.base) > 0)
        s[i++] = str_base[(n % args.base) + args.capital];
    s[i] = '\0';
    return (add_toa(s, buf, p_buf, args));
}

// int ft_dtoa(double n, t_args args, char *buf, int *p_buf)
// {
//     int i;
//     char s[63];
//     char *str_base = "0123456789abcdef0123456789ABCDEF";
//     if (n == 0)
//         args.alt = 0;
//     i = 0;
//     s[i++] = str_base[(n % args.base) + args.capital];
//     while ((n /= args.base) > 0)
//         s[i++] = str_base[(n % args.base) + args.capital];
//     s[i] = '\0';
//     return (add_toa(s, buf, p_buf, args));
// }
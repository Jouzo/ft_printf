#include "../includes/ft_printf.h"

int add_toa(char *s, char *buf, int *start, t_args args)
{
    int len;

    len = ft_strlen(s);
    ft_strrev(s);
    add_option(buf, args, s, start);
    ft_memcpy(buf + *start, s, ft_strlen(s));
    if (args.left)
        padding_right(buf, s, args, start);
    return (len);
}

int ft_itoa_base(int n, t_args args, char *buf, int *start)
{
    int i;
    char s[31];
    char *str_base = "0123456789abcdef0123456789ABCDEF";
    unsigned int abs;
//    int len;

    abs = n < 0 ? -n : n;
    i = 0;
    s[i++] = str_base[(abs % args.base) + args.capital];
    while ((abs /= args.base) > 0)
        s[i++] = str_base[(abs % args.base) + args.capital];
    if (n < 0){
        ft_memset(buf + *start, '-', 1);
        *start += 1;
        args.minus = 1;
    }
    s[i] = '\0';
    return (add_toa(s, buf, start, args));
}

int ft_ltoa_base(long n, t_args args, char *buf, int *start)
{
    int i;
    char s[31];
    char *str_base = "0123456789abcdef0123456789ABCDEF";
    unsigned long abs;
    int len;

    abs = n < 0 ? -n : n;
    i = 0;
    s[i++] = str_base[(abs % args.base) + args.capital];
    while ((abs /= args.base) > 0)
        s[i++] = str_base[(abs % args.base) + args.capital];
    if (n < 0){
        ft_memset(buf + *start, '-', 1);
        *start += 1;
        args.minus = 1;
    }
    s[i] = '\0';
    ft_strrev(s);
    len = ft_strlen(s);
    add_option(buf, args, s, start);
    ft_memcpy(buf + *start, s, ft_strlen(s));
    if (args.left)
        padding_right(buf, s, args, start);
    return (len);
}

int ft_lltoa_base(long long n, t_args args, char *buf, int *start)
{
    int i;
    char s[31];
    char *str_base = "0123456789abcdef0123456789ABCDEF";
    unsigned long long abs;
    int len;

    abs = n < 0 ? -n : n;
    i = 0;
    s[i++] = str_base[(abs % args.base) + args.capital];
    while ((abs /= args.base) > 0)
        s[i++] = str_base[(abs % args.base) + args.capital];
    if (n < 0){
        ft_memset(buf + *start, '-', 1);
        *start += 1;
        args.minus = 1;
    }
    s[i] = '\0';
    ft_strrev(s);
    len = ft_strlen(s);
    add_option(buf, args, s, start);
    ft_memcpy(buf + *start, s, ft_strlen(s));
    if (args.left)
        padding_right(buf, s, args, start);
    return (len);
}

int ft_utoa_base(unsigned int n, t_args args, char *buf, int *start)

{
    int i;
    char s[31];
    char *str_base = "0123456789abcdef0123456789ABCDEF";
    int len;

    i = 0;
    s[i++] = str_base[(n % args.base) + args.capital];
    while ((n /= args.base) > 0)
        s[i++] = str_base[(n % args.base) + args.capital];
    s[i] = '\0';
    ft_strrev(s);
    len = ft_strlen(s);
    add_option(buf, args, s, start);
    ft_memcpy(buf + *start, s, ft_strlen(s));
    if (args.left)
        padding_right(buf, s, args, start);
    return (len);
}

int ft_ultoa_base(unsigned long int n, t_args args, char *buf, int *start)
{
    int i;
    char s[31];
    char *str_base = "0123456789abcdef0123456789ABCDEF";
    int len;

    i = 0;
    s[i++] = str_base[(n % args.base) + args.capital];
    while ((n /= args.base) > 0)
        s[i++] = str_base[(n % args.base) + args.capital];
    s[i] = '\0';
    ft_strrev(s);
    len = ft_strlen(s);
    add_option(buf, args, s, start);
    ft_memcpy(buf + *start, s, ft_strlen(s));
    if (args.left)
        padding_right(buf, s, args, start);
    return (len);
}

int ft_ulltoa_base(unsigned long long int n, t_args args, char *buf, int *start)
{
    int i;
    char s[31];
    char *str_base = "0123456789abcdef0123456789ABCDEF";
    int len;

    i = 0;
    s[i++] = str_base[(n % args.base) + args.capital];
    while ((n /= args.base) > 0)
        s[i++] = str_base[(n % args.base) + args.capital];
    s[i] = '\0';
    ft_strrev(s);
    len = ft_strlen(s);
    add_option(buf, args, s, start);
    ft_memcpy(buf + *start, s, ft_strlen(s));
    if (args.left)
        padding_right(buf, s, args, start);
    return (len);
}
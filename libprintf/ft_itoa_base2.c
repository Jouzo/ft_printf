#include "../includes/ft_printf.h"

int ft_itoa_base2(int n, t_args args, char *buf, int *start)
{
    int i;
    char s[31];
    char *str_base = "0123456789abcdef0123456789ABCDEF";
    unsigned int abs;
    int len;

    abs = n < 0 ? -n : n;
    i = 0;
    s[i++] = str_base[(abs % args.base) + args.capital];
    while ((abs /= args.base) > 0)
        s[i++] = str_base[(abs % args.base) + args.capital];
    if (n < 0)
        s[i++] = '-';
    s[i] = '\0';
    ft_strrev(s);
    len = ft_strlen(s);
    add_option(buf, args, s, start);
    ft_memcpy(buf + *start, s, ft_strlen(s));
    printf("args.left %d\n", args.left);
    if (args.left)
        padding_right(buf, s, args.width, start);
    return (len);
}
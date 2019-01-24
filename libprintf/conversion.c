#include "ft_printf.h"

int     conversion_int(char *buf, int nb, t_args args, int *start)
{   
    char *conv;
    if (args.spec == 'c')
        ft_itoc(nb, &conv);
    else
        conv = ft_itoa_base(nb, 10);
    add_option(buf, args, conv, start);
    ft_memcpy(buf + *start, conv, ft_strlen(conv));
    if (args.left)
        padding_right(buf, conv, args.width, start);
    return (ft_strlen(conv));
}

int     conversion_string(char *buf, char *str, t_args args, int *start)
{
    char *conv;

    ft_memcpy(conv, str, ft_strlen(str));
    add_option(buf, args, conv, start);
    ft_memcpy(buf + *start, conv, ft_strlen(conv));
    if (args.left)
        padding_right(buf, conv, args.width, start);
    return (ft_strlen(conv));
}

int     conversion(char *buf, va_list ap, t_args args, int *start)
{
    char *conv;

    if (args.spec == 'c' || args.spec == 'd' || args.spec == 'i')
    {
        return conversion_int(buf, va_arg(ap, int), args, start);
    }
    if (args.spec == 's')
        return conversion_string(buf, va_arg(ap, char*), args, start);
    return (0);
}
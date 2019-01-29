#include "../includes/ft_printf.h"

void padding_left(char *buf, t_args args, int size_of_conversion, int *start)
{
    int len;

    len = args.prec > size_of_conversion ? args.prec : size_of_conversion;
    if (args.minus)
        len++;
    if (args.alt && args.spec == 'o')
        args.width -= 1;
    if (args.alt && args.spec == 'x')
        args.width -= 2;
    if (args.width - len - args.showsign - args.space > 0)
    {
        ft_memset(buf + *start, ' ', args.width - len - args.showsign - args.space);
        *start += args.width - len - args.showsign - args.space;
    }
}

void fill_zero(char *buf, t_args args, int size_of_conversion, int *start)
{
    int min;

    min = 0;
    if (args.spec == 's' || args.spec == '%') //|| ((args.width > args.prec) && (args.spec == 'x' || args.spec == 'o')))
        padding_left(buf, args, size_of_conversion, start);
    else
    {
        if ((args.showsign != args.minus) || (args.showsign && args.minus))
            min = 1;
        if (args.alt && args.spec == 'o')
            args.width -= 1;
        if (args.alt && args.spec == 'x')
            args.width -= 2;
        if (args.width - size_of_conversion - min > 0)
        {
            ft_memset(buf + *start, '0', args.width - size_of_conversion - min);
            *start += args.width - size_of_conversion - min;
        }
    }
}

void fill_prec(char *buf, t_args args, int size_of_conversion, int *start)
{
    if (args.spec != 's' && args.spec != '%')
    {
        if (args.prec - size_of_conversion > 0 && args.spec != 'f')
        {
            ft_memset(buf + *start, '0', args.prec - size_of_conversion);
            *start += args.prec - size_of_conversion;
        }
    }
}

void one_space(char *buf, int *start)
{
    ft_memset(buf + *start, ' ', 1);
    *start += 1;
}

void padding_right(char *buf, char *conv, t_args args, int *start)
{
    int len;
    int min;

    min = 0;
    len = ft_strlen(conv);
    if (args.showsign || args.minus)
        min = 1;
    if (len + min + args.zero + args.space < args.prec)
        len = args.prec;
    if (args.width - len + args.zero - min > 0 && args.prec < args.width)
    {
        ft_memset(buf + *start + ft_strlen(conv), ' ', args.width - len + args.zero - min - args.space);
        *start += args.width - len + args.zero - min - args.space;
    }
}

void print_sign(char *buf, int *start)
{
    ft_memset(buf + *start, '+', 1);
    *start += 1;
}

void print_minus(char *buf, int *start)
{
    ft_memset(buf + *start, '-', 1);
    *start += 1;
}

void add_hash(char *buf, t_args args, int *start)
{
    if (args.spec == 'x' || args.spec == 'p')
    {
        ft_memset(buf + *start, '0', 1);
        ft_memset(buf + *start + 1, 'x' - args.capital * 2, 1);
        *start += 2;
    }
    else if (args.spec == 'o')
    {
        ft_memset(buf + *start, '0', 1);
        *start += 1;
    }
}

void add_option(char *buf, t_args args, char *conv, int *start)
{
    if (args.space && !args.showsign && args.spec != 'o' && args.spec != 'x')
        one_space(buf, start);
    if ((args.space && args.width && !args.left && !args.zero) || (args.width && !args.zero && !args.left))
        padding_left(buf, args, ft_strlen(conv), start);
    if (args.alt == 1 && (args.spec == 'x' || args.spec == 'o' || args.spec == 'p'))
        add_hash(buf, args, start);
    if (args.minus)
        print_minus(buf, start);
    if (args.showsign && !args.minus && args.spec != 'o' && args.spec != 'x')
        print_sign(buf, start);
    if (args.prec)
        fill_prec(buf, args, ft_strlen(conv), start);
    if (args.zero && args.width && !args.left)
        fill_zero(buf, args, ft_strlen(conv), start);
}
#include "../includes/ft_printf.h"

void padding_left(char *buf, t_args args, int size_of_conversion, int *start)
{
    int len;

    len = args.prec > size_of_conversion ? args.prec : size_of_conversion;
    if (args.alt && (args.spec == 'o' || args.spec == 'O'))
        args.width -= 1;
    if (args.alt && (args.spec == 'x' || args.spec == 'X'))
        args.width -= 2;
    if (args.width - len - args.showsign > 0)
    {
        ft_memset(buf + *start, ' ', args.width - len - args.showsign);
        *start += args.width - len - args.showsign;
    }
}

void fill_zero(char *buf, t_args args, int size_of_conversion, int *start)
{
    if (args.spec == 's' || args.spec == '%')
        padding_left(buf, args, size_of_conversion, start);
    else
    {
        if (args.alt && (args.spec == 'o' || args.spec == 'O'))
            args.width -= 1;
        if (args.alt && (args.spec == 'x' || args.spec == 'X'))
            args.width -= 2;
        if (args.width - size_of_conversion - args.showsign > 0)
        {
            ft_memset(buf + *start, '0', args.width - size_of_conversion - args.showsign);
            *start += args.width - size_of_conversion - args.showsign;
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

    len = ft_strlen(conv);
    if (args.width - len - args.left > 0)
    {
        ft_memset(buf + *start + len, ' ', args.width - len - args.left);
        *start += args.width - len - args.left;
    }
}

void print_sign(char *buf, int *start)
{
    ft_memset(buf + *start, '+', 1);
    *start += 1;
}

void add_hash(char *buf, t_args args, int *start)
{
    if (args.spec == 'x' || args.spec == 'X')
    {
        ft_memset(buf + *start, '0', 1);
        ft_memset(buf + *start + 1, 'x' - args.capital * 2, 1);
        *start += 2;
    }
    else if (args.spec == 'o' || args.spec == 'O')
    {
        ft_memset(buf + *start, '0', 1);
        *start += 1;
    }
}

void add_option(char *buf, t_args args, char *conv, int *start)
{
    if (args.space && !args.width && !args.showsign && conv[0] != '-')
        one_space(buf, start);
    if ((args.space && args.width && !args.left && !args.zero) || (args.width && !args.zero && !args.left))
        padding_left(buf, args, ft_strlen(conv), start);
    if (args.alt == 1 && (args.spec == 'x' || args.spec == 'X' || args.spec == 'o'))
        add_hash(buf, args, start);
    if (args.showsign && conv[0] != '-')
        print_sign(buf, start);
    if (args.zero && args.width && !args.left)
        fill_zero(buf, args, ft_strlen(conv), start);
    if (args.prec && !args.left)
        fill_prec(buf, args, ft_strlen(conv), start);
}
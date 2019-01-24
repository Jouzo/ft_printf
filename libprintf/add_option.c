#include "ft_printf.h"

void fill_zero(char *buf, t_args args, int size_of_conversion, int *start)
{
    if (args.width - size_of_conversion > 0)
    {
        ft_memset(buf + *start, '0', args.width - size_of_conversion);
        *start += args.width - size_of_conversion;
    }
}

void padding_left(char *buf, t_args args, int size_of_conversion, int *start)
{
    if (args.width - size_of_conversion - args.showsign > 0)
    {
        ft_memset(buf + *start, ' ', args.width - size_of_conversion - args.showsign);
        *start += args.width - size_of_conversion - args.showsign;
    }
}

void    one_space(char *buf, t_args args, int size_of_conversion, int *start)
{
        ft_memset(buf + *start, ' ', 1);
        *start += 1;
}

void padding_right(char *buf, char *conv, int width, int *start)
{
    int len;

    len = ft_strlen(conv);
    if (width - len > 0)
    {
        ft_memset(buf + *start + len, ' ', width - len);
        *start += width - len;
    }
}

void print_sign(char *buf, int *start)
{
    ft_memset(buf + *start, '+', 1);
    *start += 1;
}

void add_option(char *buf, t_args args, char *conv, int *start)
{
    if (args.space && !args.width && !args.showsign && conv[0] != '-')
        one_space(buf, args, ft_strlen(conv), start);
    if ((args.space && args.width && !args.left) || (args.width && !args.zero && !args.left) )
        padding_left(buf, args, ft_strlen(conv), start);
    if (args.showsign && conv[0] != '-')
        print_sign(buf, start);
    if (args.zero && args.width && !args.left)
        fill_zero(buf, args, ft_strlen(conv), start);
}
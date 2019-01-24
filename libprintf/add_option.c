#include "ft_printf.h"

void fill_zero(char *buf, int nb, int size_of_conversion, int *start)
{
    if (nb - size_of_conversion > 0)
    {
        ft_memset(buf + *start, '0', nb - size_of_conversion);
        *start += nb - size_of_conversion;
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
    if ((args.space && args.width && !args.left) || (args.width && !args.zero && !args.left) )
        padding_left(buf, args, ft_strlen(conv), start);
    if (args.showsign && conv[0] != '-')
        print_sign(buf, start);
    if (args.zero && args.width && !args.left)
        fill_zero(buf, args.width, ft_strlen(conv), start);
}
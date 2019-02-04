#include "../includes/ft_printf.h"

void padding_left(char *buf, t_args args, int size_of_conversion, int *p_buf)
{
    int len;

    if (args.spec != 's')
        len = MAX(args.prec, size_of_conversion);
    else
        len = MAX(args.prec, size_of_conversion);
    if (args.minus)
        len++;
    if (args.alt && args.spec == 'o')
        args.width -= 1;
    if (args.alt && (args.spec == 'x' || args.spec == 'p'))
        args.width -= 2;
    if (args.width - len - args.showsign - args.space > 0)
    {
        ft_memset(buf + *p_buf, ' ', args.width - len - args.showsign - args.space);
        *p_buf += args.width - len - args.showsign - args.space;
    }
}

void fill_zero(char *buf, t_args args, int size_of_conversion, int *p_buf)
{
    int min;

    min = 0;
    if (/*args.spec == 's' || */args.spec == '%')
        padding_left(buf, args, size_of_conversion, p_buf);
    else
    {
        if (args.showsign || args.minus || args.space)
            min = 1;
        if (args.alt && args.spec == 'o')
            args.width -= 1;
        if (args.alt && (args.spec == 'x' || args.spec == 'p'))
            args.width -= 2;
        // args.width = args.width > args.prec ? args.prec : args.width;
        if (args.width - size_of_conversion - min > 0)
        {
            ft_memset(buf + *p_buf, '0', args.width - size_of_conversion - min);
            *p_buf += args.width - size_of_conversion - min;
        }
    }
}

void fill_prec(char *buf, t_args args, int size_of_conversion, int *p_buf)
{
    if (args.spec != 's' && args.spec != '%')
    {
        if (args.prec - size_of_conversion > 0 && args.spec != 'f')
        {
            ft_memset(buf + *p_buf, '0', args.prec - size_of_conversion);
            *p_buf += args.prec - size_of_conversion;
        }
    }
}

void one_space(char *buf, int *p_buf)
{
    ft_memset(buf + *p_buf, ' ', 1);
    *p_buf += 1;
}

void padding_right(char *buf, char *conv, t_args args, int *p_buf)
{
    int len;
    int min;

    min = 0;
    len = args.spec != 'p' ? ft_strlen(conv) : ft_strlen(conv) + 2;
    len = args.spec == 'o' ? len + 1 : len;
    // printf("\nvalue of len %i\n", len);
    // printf("\nvalue of args.width - len - min - args.space %i\n", args.width - len - min - args.space);
    // printf("\nvalue of args.width %i\n", args.width);
    // printf("\nvalue of *p_buf %i\n", *p_buf);
    // printf("\nvalue of ft_strlen(conv) %i\n", (int)ft_strlen(conv));
    if (args.showsign || args.minus)
        min = 1;
    if (len + min + args.space < args.prec)
        len = args.prec;
    // printf("\nvalue of len %i\n", len);    
    // printf("\nvalue of args.width - len - min - args.space %i\n", args.width - len - min - args.space);
    if (args.width - len - min - args.space > 0 && args.prec < args.width)
    {
        ft_memset(buf + *p_buf + ft_strlen(conv), ' ', args.width - len  - min - args.space);
        *p_buf += args.width - len  - min - args.space;
    }
    // printf("\nvalue of *p_buf %i\n", *p_buf);
}

void print_sign(char *buf, int *p_buf)
{
    ft_memset(buf + *p_buf, '+', 1);
    *p_buf += 1;
}

void print_minus(char *buf, int *p_buf)
{
    ft_memset(buf + *p_buf, '-', 1);
    *p_buf += 1;
}

void add_hash(char *buf, t_args args, int *p_buf)
{
    if (args.spec == 'x' || args.spec == 'p')
    {
        ft_memset(buf + *p_buf, '0', 1);
        ft_memset(buf + *p_buf + 1, 'x' - args.capital * 2, 1);
        *p_buf += 2;
    }
    else if (args.spec == 'o')
    {
        ft_memset(buf + *p_buf, '0', 1);
        *p_buf += 1;
    }
}

void add_option(char *buf, t_args args, char *conv, int *p_buf)
{
    if (args.space && !args.showsign && args.spec == 'd' && !args.minus)
        one_space(buf, p_buf);
    if ((args.space && args.width && !args.left && !args.zero) || (args.width && !args.zero && !args.left))
        padding_left(buf, args, ft_strlen(conv), p_buf);
    if (args.alt == 1 && (args.spec == 'x' || args.spec == 'o' || args.spec == 'p'))
        add_hash(buf, args, p_buf);
    if (args.minus)
        print_minus(buf, p_buf);
    if (args.showsign && !args.minus && args.spec != 'o' && args.spec != 'x' && args.spec != 'c' && args.spec != 'C')
        print_sign(buf, p_buf);
    if (args.prec)
        fill_prec(buf, args, ft_strlen(conv), p_buf);
    if (args.zero && args.width && !args.left)
        fill_zero(buf, args, ft_strlen(conv), p_buf);
}
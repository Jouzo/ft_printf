#include <stdarg.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

void init_args(t_args *args)
{
    args->prec = 0;           /* Precision. */
    args->width = 0;          /* Width.  */
    args->spec = 0;           /* Format letter.  */
    args->fd = 1;              /* FD for dprintf */
    args->is_long_double = 0; /* L flag.  */
    args->is_short = 0;       /* h flag.  */
    args->is_long = 0;        /* l flag.  */
    args->is_long_long = 0;   /* ll flag.  */
    args->is_char = 0;        /* hh flag.  */
    args->is_sizet = 0;       /* z flag */
    args->alt = 0;            /* # flag.  */
    args->space = 0;          /* Space flag.  */
    args->left = 0;           /* - flag.  */
    args->showsign = 0;       /* + flag.  */
    args->zero = 0;
    args->minus = 0;          /* if param is negatif  */
    args->base = 10;          /* base */
    args->capital = 0;        /* capital base for X and O */
}

int     dprintf(int fd, const char *format, ...)
{
    va_list ap;
    t_args args;
    char buf[BUFF_SIZE];
    int i;
    int j;

    args.fd = fd;
    args.len = 0;
    i = 0;
    j = 0;
        
    ft_bzero(buf, BUFF_SIZE);
    va_start(ap, format);
    if (format[0] == '%' && ft_strlen(format) == 1)
        return (0);
    while (format[i])
    {
        while (format[i] && format[i] != '%')
            buf[j++] = format[i++];
        if (format[i] == '%')
        {
            init_args(&args);
            i += assign(format + i, &args);
            j += conversion(buf, ap, &args, &j);
        }
    }
    va_end(ap);
    ft_printstr(buf, &j, args);
    args.len += j;
    return (args.len);
}

int     ft_printf(const char *format, ...)
{
    va_list ap;
    t_args args;
    char buf[BUFF_SIZE];
    int i;
    int j;

    args.len = 0;
    i = 0;
    j = 0;
    ft_bzero(buf, BUFF_SIZE);
    va_start(ap, format);
    if (format[0] == '%' && ft_strlen(format) == 1)
        return (0);
    while (format[i])
    {
        while (format[i] && format[i] != '%')
            buf[j++] = format[i++];
        if (format[i] == '%')
        {
            init_args(&args);
            i += assign(format + i, &args);
            j += conversion(buf, ap, &args, &j);
        }
    }
    va_end(ap);
    ft_printstr(buf, &j, args);
    args.len += j;
    return (args.len);
}
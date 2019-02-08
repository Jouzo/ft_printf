#include <stdarg.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

void init_args(t_args *args)
{
    int tmp;

    tmp = args->len;
    ft_bzero(args, sizeof(args));
    args->base = 10;
    args->len = tmp;
}

int ft_printf(const char *format, ...)
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
    ft_printstr(buf, &j);
    args.len += j;

    return (args.len);
}
#include <stdarg.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

void init_args(t_args *args)
{
    args->prec = 0;               /* Precision. */
    args->width = 0;              /* Width.  */
    args->spec = 0;               /* Format letter.  */
    args->is_long_double = 0; /* L flag.  */
    args->is_short = 0;       /* h flag.  */
    args->is_long = 0;        /* l flag.  */
    args->is_long_long = 0;        /* ll flag.  */
    args->is_char = 0;        /* hh flag.  */
    args->alt = 0;            /* # flag.  */
    args->space = 0;          /* Space flag.  */
    args->left = 0;           /* - flag.  */
    args->showsign = 0;       /* + flag.  */
    args->group = 0;          /* ' flag.  */
    args->extra = 0;          /* For special use.  */
    args->wide = 0;           /* Nonzero for wide character streams.  */
    args->i18n = 0;           /* I flag.  */
    args->is_binary128 = 0;   /* Floating-argument is ABI-compatible */
    // args->pad = 0;                /* Padding character.  */
}

// t_value get_value(va_list ap, char type) {

//     if (type == 'c') {
//             return va_arg(ap, char);
//     }
// }

int     conversion_int(char *buf, int nb)
{
    char *conv;

    conv = ft_itoa_base(nb, 10);
    ft_memcpy(buf, conv, ft_strlen(conv));
    return (ft_strlen(conv));
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    t_args args;
    char buf[10000];
    int i;
    int j;

    i = 0;
    j = 0;
    ft_bzero(buf, 10000);
    init_args(&args);
    va_start(ap, format);
    while (format[i])
    {
        while (format[i] && format[i] != '%')
            buf[j++] = format[i++];
        if (format[i] == '%')
        {
            i += assign(format + i, &args);
            //j += ft_convert(&buf + j, args, format); qui renvoie strlen(converted) et copie converted dans buf
            j += conversion_int(buf + j, va_arg(ap, int));
        }
    }
    va_end(ap);
    return (0);
}
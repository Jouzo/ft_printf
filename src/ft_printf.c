#include <stdarg.h>
#include <stdio.h>

int ft_printf(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);

    while (*format)
    {
         va_arg(ap, int);
    }
    va_end(ap);
}
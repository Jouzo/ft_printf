#include "../includes/ft_printf.h"

int     conversion_int(char *buf, int nb, t_args args, int *start)
{   
    int len;

    if (args.is_short)
        nb = (short)nb;
    if (args.is_char)
        nb = (char)nb;
    if (args.spec == 'c')
    {
        ft_itoc(nb, &buf, start, args);
        if (args.left)
            padding_right(buf, "", args.width, start);
        len = 0 - args.left;
    }
    else
        len = ft_itoa_base(nb, args, buf, start);
    return (len);
}

int     conversion_long(char *buf, long nb, t_args args, int *start)
{
    return (ft_ltoa_base(nb, args, buf, start));
}

int     conversion_long_long(char *buf, long nb, t_args args, int *start)
{
    return (ft_lltoa_base(nb, args, buf, start));
}

int     conversion_float(char *buf, double nb, t_args args, int *start)
{   
    int len;
    
    len = ft_itoa_base(nb, args, buf, start);
    return (len);
}

int     conversion_unsigned(char *buf, unsigned int nb, t_args args, int *start)
{   
    return (ft_utoa_base(nb, args, buf, start));
}

int     conversion_long_unsigned(char *buf, unsigned long nb, t_args args, int *start)
{   
    return (ft_ultoa_base(nb, args, buf, start));
}

int     conversion_long_long_unsigned(char *buf, unsigned long long nb, t_args args, int *start)
{   
    return (ft_ulltoa_base(nb, args, buf, start));
}

int     conversion_string(char *buf, char *str, t_args args, int *start)
{
    add_option(buf, args, str, start);
    ft_memcpy(buf + *start, str, ft_strlen(str));
    if (args.left)
        padding_right(buf, str, args.width, start);
    return (ft_strlen(str));
}

int     conversion_void(char *buf, void *ptr, t_args args, int *start)
{
    char *conv;

    //  conv = NULL;
   printf("value of void ptr dans conversion void %p\n\n", ptr);
    // ptr = ft_itoa_base(ptr, 16);
    conv= NULL;
    // flag alt pour rajouter 0x au debut de l'adresse
    args.alt = 1;
    ft_memcpy(conv, ptr, ft_strlen(ptr));
    add_option(buf, args, conv, start);
    ft_memcpy(buf + *start, conv, ft_strlen(conv));
    if (args.left)
        padding_right(buf, conv, args.width, start);
    return (ft_strlen(conv));
}

int     conversion(char *buf, va_list ap, t_args args, int *start)
{
    if (args.spec == 'c' || (args.spec == 'd' && !args.is_long && !args.is_long_long) || (args.spec == 'i' && !args.is_long && !args.is_long_long))
        return conversion_int(buf, va_arg(ap, int), args, start);
     if ((args.spec == 'd' && args.is_long) || (args.spec == 'i' && args.is_long))
        return conversion_long(buf, va_arg(ap, long), args, start);
    if ((args.spec == 'd' && args.is_long_long) || (args.spec == 'i' && args.is_long_long))
        return conversion_long_long(buf, va_arg(ap, long), args, start);
    if (args.spec == 's')
        return conversion_string(buf, va_arg(ap, char*), args, start);
    if (args.spec == 'p')
        return conversion_void(buf, va_arg(ap, char*), args, start);
    if ((args.spec == 'u'  || args.spec == 'o' || args.spec == 'x' || args.spec == 'X') && !args.is_long && !args.is_long_long)
        return conversion_unsigned(buf, va_arg(ap, unsigned int), args, start);
    if ((args.spec == 'u'  || args.spec == 'o' || args.spec == 'x' || args.spec == 'X') && args.is_long)
        return conversion_long_unsigned(buf, va_arg(ap, unsigned long int), args, start);
    if ((args.spec == 'u'  || args.spec == 'o' || args.spec == 'x' || args.spec == 'X') && args.is_long_long)
        return conversion_long_long_unsigned(buf, va_arg(ap, unsigned long long int), args, start);
    if (args.spec == 'f')
        return conversion_float(buf, va_arg(ap, unsigned long), args, start);
    return (0);
}
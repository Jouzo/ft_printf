#include "../includes/ft_printf.h"

int     conversion_int(char *buf, int nb, t_args args, int *start)
{   
    char *conv;
    if (args.spec == 'c')
        ft_itoc(nb, &conv);
    else
        ft_itoa_base(nb, conv, 10, args);
//      conv = ft_itoa_base(nb, 10);

    add_option(buf, args, conv, start);
    ft_memcpy(buf + *start, conv, ft_strlen(conv));
    if (args.left)
        padding_right(buf, conv, args.width, start);
    return (ft_strlen(conv));
}

int     conversion_float(char *buf, double nb, t_args args, int *start)
{   
    char *conv;
    
 //   conv = ft_itoa_base(nb, 10);
    ft_itoa_base(nb, conv, 10, args);
    add_option(buf, args, conv, start);
    ft_memcpy(buf + *start, conv, ft_strlen(conv));
    if (args.left)
        padding_right(buf, conv, args.width, start);
    return (ft_strlen(conv));
}

int     conversion_unsigned(char *buf, unsigned long nb, t_args args, int *start)
{   
    char *conv;
    
    conv = ft_itoa_base(nb, args.base);
    add_option(buf, args, conv, start);
    ft_memcpy(buf + *start, conv, ft_strlen(conv));
    if (args.left)
        padding_right(buf, conv, args.width, start);
    return (ft_strlen(conv));
}

int     conversion_string(char *buf, char *str, t_args args, int *start)
{
    char *conv;

    ft_memcpy(conv, str, ft_strlen(str));
    add_option(buf, args, conv, start);
    ft_memcpy(buf + *start, conv, ft_strlen(conv));
    if (args.left)
        padding_right(buf, conv, args.width, start);
    return (ft_strlen(conv));
}

int     conversion_void(char *buf, void *ptr, t_args args, int *start)
{
    char *conv;

    printf("value of void ptr dans conversion void %p\n\n", ptr);
    // str = ft_itoa_base(atoi(str), 16);

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
    char *conv;

    if (args.spec == 'c' || args.spec == 'd' || args.spec == 'i')
        return conversion_int(buf, va_arg(ap, int), args, start);
    if (args.spec == 's' || args.spec == 'p')
        return conversion_string(buf, va_arg(ap, char*), args, start);
    if (args.spec == 'p')
        return conversion_void(buf, va_arg(ap, char*), args, start);
    if (args.spec == 'u' || args.spec == 'o' || args.spec == 'x' || args.spec == 'X')
        return conversion_unsigned(buf, va_arg(ap, unsigned long), args, start);
    if (args.spec == 'f')
        return conversion_float(buf, va_arg(ap, unsigned long), args, start);
    return (0);
}
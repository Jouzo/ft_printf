#include "../includes/ft_printf.h"

int add_toa(char *s, char *buf, int *p_buf, t_args *args)
{
    int len;

    len = ft_strlen(s);
    ft_strrev(s);
    if (*s == '0' && len == 1)
        args->alt = 0;
    add_option(buf, args, s, p_buf);
    if (*p_buf + len > BUFF_SIZE)
        check_buf(buf, p_buf, args);
    // printf("add_toa avant memcpy: value of p_buf %i\n", *p_buf);    
    ft_memcpy(buf + *p_buf, s, len);
    // printf("add_toa apres memcpy: value of p_buf %i\n", *p_buf);
    if ((args->spec == 'x' || args->spec == 'o' || args->spec == 'd' || args->spec == 'u') && *s == '0' && len == 1 && args->prec == -1)
        *p_buf -= 1;
    if (args->left && args->width > args->prec)
        padding_right(buf, s, args, p_buf);
    return (len);
}

int ft_dtoa(long double n, t_args *args, char *buf, int *p_buf)
{
    int i;
    char s[31];

    i = 0;
    s[i++] = n % 10;
    while ((abs /= args->base) > 0)
        s[i++] = n % 10;
    if (n < 0)
        args->minus = 1;
    s[i] = '\0';
    return (add_toa(s, buf, p_buf, args));
}

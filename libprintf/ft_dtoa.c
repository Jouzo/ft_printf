#include "../includes/ft_printf.h"

// int add_dtoa(char *s, char *buf, int *p_buf, t_args *args)
// {
//     int len;

//     len = ft_strlen(s);
//     if (*s == '0' && len == 1)
//         args->alt = 0;
//     add_option(buf, args, s, p_buf);
//     if (*p_buf + len > BUFF_SIZE)
//         check_buf(buf, p_buf, args);
//     // printf("add_toa avant memcpy: value of p_buf %i\n", *p_buf);    
//     ft_memcpy(buf + *p_buf, s, len);
//     // printf("add_toa apres memcpy: value of p_buf %i\n", *p_buf);
//     if ((args->spec == 'x' || args->spec == 'o' || args->spec == 'd' || args->spec == 'u') && *s == '0' && len == 1 && args->prec == -1)
//         *p_buf -= 1;
//     if (args->left && args->width > args->prec)
//         padding_right(buf, s, args, p_buf);
//     return (len);
// }
long double ft_powl(long double n, long double pow)
{
    return (pow > 0 ? n * ft_powl(n, pow - 1) : 1);
}

long ft_pow(long n, long pow)
{
    return (pow > 0 ? n * ft_pow(n, pow - 1) : 1);
}

int  get_size_int_part(long double n)
{
    int size;

    size = 0;
    while (n > 1)
    {
        n /= 10;
        size++;
    }
    return (size);
}

long get_decimal(long double n, int i)
{
    long ret;

    ret = (long)(n * ft_pow(10, i + 1)) % 10;
    ret < 0 ? ret += 9 : ret;
    if (i == 18)
        ret += 9;
    return (ret);
}

int get_digit(unsigned long n, int i)
{
    // printf("value of ft_pow(10, i + 1) %ld\n", ft_pow(10, i + 1));
    // printf("value of ft_pow(10, i) %ld\n", ft_pow(10, i));

    return (n % ft_pow(10, i + 1) / ft_pow(10, i));
}

int ft_dtoa(long double n)//, t_args *args, char *buf, int *p_buf)
{
    long int_part;
    long double decimal;
    int i;
    char s[181];
    char buf[181];
    int prec;
    int j;

    j = 0;
    ft_bzero(s, 181);
    ft_bzero(buf, 181);
    prec = 29 - get_size_int_part(n);
    i = 0;
    int_part = (unsigned long)n;
    decimal = n - (long)n;
    while (i < get_size_int_part(n))
    {
        s[i] = get_digit(int_part, i) + '0';
        i++;
    }
    ft_strrev(s);
    s[i++] = '.';
    while (prec--)
    {
        // decimal *= 10;
        // printf("value of get_decimal(decimal, j++) + '0' : %li \n", get_decimal(decimal, j));
        s[i++] = get_decimal(decimal, j++) + '0';
        if (prec == 0)
            s[i - 1] += 1;
    }
    // if (n < 0)
    //     args->minus = 1;
    s[i] = '\0';
    ft_memcpy(buf, s, 29);
    printf("print buff dans dtoa %s\n", buf);    
    return (1);
    // return (add_dtoa(s, buf, p_buf, args));
}

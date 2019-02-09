#include "../includes/ft_printf.h"

void padding_left_string(char *buf, t_args *args, int size_of_conversion, int *p_buf)
{
    int i;

    i = 0;
    if (args->width - size_of_conversion > 0)
    {
        if (args->width - size_of_conversion > BUFF_SIZE)
            i = print_big_padding_left(buf, p_buf, args, args->width - size_of_conversion);
        ft_memset(buf + *p_buf, ' ', args->width - size_of_conversion - BUFF_SIZE * i);
        *p_buf += args->width - size_of_conversion - BUFF_SIZE * i;
    }
}

void fill_prec_string(char *buf, t_args *args, int size_of_conversion, int *p_buf)
{
    int len;
    int i;

    i = 0;
    len = size_of_conversion;
    if (args->prec && len > args->prec)
        len = args->prec;
    if (args->width - len > 0)
        {
            if (args->width - len > BUFF_SIZE)
                i = print_big_fill_prec_string(buf, p_buf, args, args->width - len);
            ft_memset(buf + *p_buf, ' ', args->width - len - BUFF_SIZE * i);
            *p_buf += args->width - len - BUFF_SIZE * i;
        }
}

void padding_right_string(char *buf, char *conv, t_args *args, int *p_buf)
{
    int len;
    int i;

    i = 0;
    len = ft_strlen(conv);
     if (args->prec && len > args->prec)
        len = args->prec;
    *p_buf += len;
    if (args->width - len> 0 && len < args->width)
    {
        if (args->width - len > BUFF_SIZE)
            i = print_big_padding_right(buf, p_buf, args, args->width - len);
        ft_memset(buf + *p_buf, ' ', args->width - len - BUFF_SIZE * i);
        *p_buf += args->width - len - BUFF_SIZE * i - len;
    }
}
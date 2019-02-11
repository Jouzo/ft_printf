#include "../includes/ft_printf.h"

void padding_dleft(char *buf, t_args *args, int size_of_conversion, int *p_buf)
{
    int len;
    int i;

    i = 0;
    len = MAX(args->prec, size_of_conversion);
    if (args->minus)
        len++;
    if (args->width - len - args->showsign - args->space > 0)
    {
        if (args->width - len - args->showsign - args->space > BUFF_SIZE)
            i = print_big_padding_left(buf, p_buf, args, args->width - len - args->showsign - args->space);
        ft_memset(buf + *p_buf, ' ', args->width - len - args->showsign - args->space - BUFF_SIZE * i);
        *p_buf += args->width - len - args->showsign - args->space - BUFF_SIZE * i;
    }
}

void fill_dzero(char *buf, t_args *args, int size_of_conversion, int *p_buf)
{
    int min;
    int i;
    int len;

    len = 0;
    i = 0;
    min = 0;
    if (args->showsign || args->minus || args->space)
        min = 1;
    if (args->width - size_of_conversion - min > 0)
    {
        if (args->width - size_of_conversion - min > BUFF_SIZE)
            i = print_big_fill_zero(buf, p_buf, args, args->width - size_of_conversion - min);
        ft_memset(buf + *p_buf, '0', args->width - size_of_conversion - min - BUFF_SIZE * i);
        *p_buf += args->width - size_of_conversion - min - BUFF_SIZE * i;
    }
}

void dwidth_over_prec(char *buf, t_args *args, int size_of_conversion, int *p_buf)
{
    int i;
    int min;

    i = 0;
    min = 0;
    // printf("size of conv : %i\n", size_of_conversion);
    // printf("fill prec : value of p_buf %i\n", *p_buf);
    if (args->showsign || args->minus || args->space)
        min = 1;
    if (args->width - size_of_conversion - min >= 0 && !args->left)
    {
        if (args->width - size_of_conversion - min > BUFF_SIZE * i)
            i += print_big_fill_prec(buf, p_buf, args, args->width - size_of_conversion - min);
        ft_memset(buf + *p_buf, ' ', args->width - size_of_conversion - min - BUFF_SIZE * i);
        *p_buf += args->width - size_of_conversion - min - BUFF_SIZE * i;
    }
    if (args->showsign && !args->minus)
        print_sign(buf, p_buf, args);
    if (args->space && !args->showsign && !args->minus)
        one_space(buf, p_buf, args);
}

// void fill_dprec(char *buf, t_args *args, int size_of_conversion, int *p_buf)
// {
//     int i;
//     int min;

//     i = 0;
//     min = 0;
//     // printf("size of conv : %i\n", size_of_conversion);
//     // printf("fill prec : value of p_buf %i\n", *p_buf);
//     if (args->showsign || args->minus || args->space)
//         min = 1;
//     if (args->prec - size_of_conversion > 0)
//     {
//         if (args->width - args->prec - min >= 0 && !args->left)
//         {
//             i = print_big_fill_prec(buf, p_buf, args, args->width - args->prec - min);
//             ft_memset(buf + *p_buf, ' ', args->width - args->prec - min - BUFF_SIZE * i);
//             *p_buf += args->width - args->prec - min - BUFF_SIZE * i;
//         }
//         if (args->showsign && !args->minus)
//             print_sign(buf, p_buf, args);
//         if (args->prec - size_of_conversion > BUFF_SIZE * i)
//             i += print_big_fill_prec(buf, p_buf, args, args->prec - size_of_conversion);
//         ft_memset(buf + *p_buf, '0', args->prec - size_of_conversion - BUFF_SIZE * i);
//         *p_buf += args->prec - size_of_conversion - BUFF_SIZE * i;
//     }
//     else if (!args->zero)
//         padding_left(buf, args, args->width + size_of_conversion, p_buf);
//     else
//         padding_left(buf, args, size_of_conversion, p_buf);
//     // printf("fill prec : value of p_buf %i\n", *p_buf);
// }

void padding_dright(char *buf, char *conv, t_args *args, int *p_buf)
{
    int len;
    int min;
    int i;

    i = 0;
    min = 0;
    len = args->spec != 'p' ? ft_strlen(conv) : ft_strlen(conv) + 2;
    *p_buf = args->spec == 'o' && args->alt ? *p_buf -= 1 : *p_buf;
    if (args->showsign || args->minus || args->space)
        min = 1;
    if (len + min + args->space < args->prec)
        len = args->prec;
    if (args->width - len - min > 0 && args->prec < args->width)
    {
        if (args->width - len - min > BUFF_SIZE)
            i = print_big_padding_right(buf + ft_strlen(conv), p_buf, args, args->width - len - min);
        ft_memset(buf + *p_buf + ft_strlen(conv), ' ', args->width - len - min - BUFF_SIZE * i);
        *p_buf += args->width - len - min - BUFF_SIZE * i;
    }
}

void add_option_double(char *buf, t_args *args, char *conv, int *p_buf)
{
    if (((args->space && args->width && !args->left && !args->zero) || (args->width && !args->zero && !args->left)) && args->prec == 0)
        padding_dleft(buf, args, ft_strlen(conv), p_buf);
    if (args->space && !args->showsign && !args->minus)
        one_space(buf, p_buf, args);
    if (args->minus)
        print_minus(buf, p_buf, args);
    if (args->showsign && !args->minus && args->prec >= args->width)
        print_sign(buf, p_buf, args);
    // else if (args->prec != 0 && args->prec >= args->width)
    //     fill_dprec(buf, args, ft_strlen(conv), p_buf);
    if (args->prec != 0 && args->prec < args->width)
        dwidth_over_prec(buf, args, ft_strlen(conv), p_buf);
    else if (args->zero && args->width && !args->left)
        fill_dzero(buf, args, ft_strlen(conv), p_buf);
}
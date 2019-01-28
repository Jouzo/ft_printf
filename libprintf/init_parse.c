#include <stdio.h>
#include "../includes/ft_printf.h"

void check_option(const char *str, int *i, t_args *args)
{
    char option[5];

    ft_memcpy(option, "-+#0 ", 5);
    while (ft_strchr(option, str[*i]))
    {
        if (str[*i] == '-')
            args->left = 1;
        if (str[*i] == '+')
            args->showsign = 1;
        if (str[*i] == '#')
            args->alt = 1;
        if (str[*i] == ' ')
            args->space = 1;
        if (str[*i] == '0')
            args->zero = 1;
        *i += 1;
    }
}

void check_larg_mini(const char *str, int *i, t_args *args)
{
    int res;

    res = 0;
    while (str[*i] <= '9' && str[*i] >= '0')
    {
        res = res * 10 + str[*i] - '0';
        *i += 1;
    }
    args->width = res;
}

void check_prec(const char *str, int *i, t_args *args)
{
    int res;

    res = 0;
    if (str[*i] == '.')
    {
        *i += 1;
        while (str[*i] <= '9' && str[*i] >= '0')
        {
            res = res * 10 + str[*i] - '0';
            *i += 1;
        }
        args->prec = res;
    }
}

void check_taille(const char *str, int *i, t_args *args)
{
    if (str[*i] == 'h')
    {
        if (str[*i + 1] == 'h')
        {
            args->is_char = 1;
            *i += 1;
        }
        else
            args->is_short = 1;
        *i += 1;
    }
    else if (str[*i] == 'l')
    {
        if (str[*i + 1] == 'l')
        {
            args->is_long_long = 1;
            *i += 1;
        }
        else
            args->is_long = 1;
        *i += 1;
    }
    else if (str[*i] == 'L')
    {
        args->is_long_double = 1;
        *i += 1;
    }
}

void check_type(const char *str, int *i, t_args *args)
{
    if (str[*i] == 'j')
        args->spec = 'j';
    if (str[*i] == 'c' || str[*i] == 'C')
        args->spec = 'c';
    else if (str[*i] == 's')
        args->spec = 's';
    else if (str[*i] == 'p')
        args->spec = 'p';
    else if (str[*i] == 'd' || str[*i] == 'i')
        args->spec = 'd';
    else if (str[*i] == 'D' || str[*i] == 'I')
    {
        args->spec = 'd';
        args->is_long = 1;
    }
    else if (str[*i] == 'o' || str[*i] == 'O')
    {
        if (str[*i] == 'O')
            args->is_long = 1;
        args->spec = 'o';
        args->base = 8;
    }
    else if (str[*i] == 'u' || str[*i] == 'U')
    {
    if (str[*i] == 'U')
            args->is_long = 1;
        args->spec = 'u';
    }
    else if (str[*i] == 'x' || str[*i] == 'X')
    {
        if (str[*i] == 'X')
            args->capital = 16;
        args->spec = 'x';
        args->base = 16;
    }
    else if (str[*i] == 'f')
        args->spec = 'f';
    else if (str[*i] == '%')
        args->spec = '%';
    *i += 1;
}

int assign(const char *str, t_args *args)
{
    int i;

    i = 1;
    check_option(str, &i, args);
    check_larg_mini(str, &i, args);
    check_prec(str, &i, args);
    check_taille(str, &i, args);
    check_type(str, &i, args);
    return (i);
}

#include <stdio.h>
#include "../includes/ft_printf.h"

void check_option(char *str, int *i, t_args *args)
{
    char *option;

    option = "-+#0 ";
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
        *i++;
    }
}

void check_larg_mini(char *str, int *i, t_args *args)
{
    int res;

    res = 0;
    while (str[*i] <= '9' && str[*i] >= '0')
    {
        res = res * 10 + str[*i] + '0';
        *i++;
    }
    args->width = res;
}

void check_prec(char *str, int *i, t_args *args)
{
    int res;

    res = 0;
    if (str[*i] == '.')
    {
        while (str[*i + 1] <= '9' && str[*i + 1] >= '0')
        {
            res = res * 10 + str[*i] + '0';
            *i++;
        }
        args->prec = res;
    }
}

void check_taille(char *str, int *i, t_args *args)
{
    if (str[*i] == 'h')
    {
        if (str[*i + 1] == 'h')
        {
            args->is_char = 1;
            *i++;
        }
        else
            args->is_short = 1;
        *i++;
    }
    else if (str[*i] == 'l')
    {
        if (str[*i + 1] == 'l')
        {
            args->is_long = 1;
            *i++;
        }
        else
            args->is_long_long = 1;
        *i++;
    }
    else if (str[*i] == 'L')
    {
        args->is_long_double = 1;
        *i++;
    }
}

void check_type(char *str, int *i, t_args *args)
{
"cspdiouxXf";
    if (str[*i] == 'c')
        args->spec = 'c';
    else if (str[*i] == 's')
        args->spec = 's';
    else if (str[*i] == 'p')
        args->spec = 'p';
    else if (str[*i] == 'd')
        args->spec = 'd';
    else if (str[*i] == 'i')
        args->spec = 'i';
    else if (str[*i] == 'o')
        args->spec = 'o';
    else if (str[*i] == 'u')
        args->spec = 'u';
    else if (str[*i] == 'x')
        args->spec = 'x';
    else if (str[*i] == 'X')
        args->spec = 'X';
    else if (str[*i] == 'f')
        args->spec = 'f';
    *i++;
}

void assign(char *str, t_args *args)
{
    int i;

    i = 0;
    check_option(str, &i, args);
    check_larg_mini(str, &i, args);
    check_prec(str, &i, args);
    check_taille(str, &i, args);
    check_type(str, &i, args);
}

int init_parse(const char *str, t_args *args)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == '%' && str[i + 1] != '%')
        {
            count++;
            init_list(&args);
            assign(str, &args);
        }
        i++;
    }
    return (count);
}

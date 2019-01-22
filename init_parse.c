#include <stdio.h>

void check_option(char *str, int *i)
{
    char *option;

    option = "-+#0 ";
    while (ft_strchr(option, str[*i]))
    {
        if (str[*i] == '-')
            list->left = 1;
        if (str[*i] == '+')
            list->showsign = 1;
        if (str[*i] == '#')
            list->alt = 1;
        if (str[*i] == ' ')
            list->space = 1;
        if (str[*i] == '0')
            list->zero = 1;
        *i++;
    }
}

void check_larg_mini(char *str, int *i)
{
    int res;

    res = 0;
    while (str[*i] <= '9' && str[*i] >= '0')
    {
        res = res * 10 + str[*i] + '0';
        *i++;
    }
    list->width = res;
}

void check_prec(char *str, int *i)
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
        list->prec = res;
    }
}

void check_taille(char *str, int *i)
{
    if (str[*i] == 'h')
    {
        if (str[*i + 1] == 'h')
        {
            list->is_char = 1;
            *i++;
        }
        else
            list->is_short = 1;
        *i++;
    }
    else if (str[*i] == 'l')
    {
        if (str[*i + 1] == 'l')
        {
            list->is_long = 1;
            *i++;
        }
        else
            list->is_long_long = 1;
        *i++;
    }
    else if (str[*i] == 'L')
    {
        list->is_long_double = 1;
        *i++;
    }
}

void check_type(char *str, int *i)
{
"cspdiouxXf";
    if (str[*i] == 'c')
        list->spec = 'c';
    else if (str[*i] == 's')
        list->spec = 's';
    else if (str[*i] == 'p')
        list->spec = 'p';
    else if (str[*i] == 'd')
        list->spec = 'd';
    else if (str[*i] == 'i')
        list->spec = 'i';
    else if (str[*i] == 'o')
        list->spec = 'o';
    else if (str[*i] == 'u')
        list->spec = 'u';
    else if (str[*i] == 'x')
        list->spec = 'x';
    else if (str[*i] == 'X')
        list->spec = 'X';
    else if (str[*i] == 'f')
        list->spec = 'f';
    *i++;
}

void assign(char *str)
{
    int i;

    i = 0;
    check_option(str, &i);
    check_larg_mini(str, &i);
    check_prec(str, &i);
    check_taille(str, &i);
}

int init_parse(char *str)
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
            //créer un maillon
            //initialize le maillon
            //appel de la fonction de detection de caracteristique et d'assignation
        }
        i++;
    }
    return (count);
}

int main()
{
    printf("%d", init_parse("%d%s%s"));
    return (0);
}
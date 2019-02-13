#include <stdio.h>
#include "../includes/ft_printf.h"

void	check_type1(const char *str, int *i, t_args *args)
{
	if (str[*i] == 'c')
		args->spec = 'c';
	else if (str[*i] == 'C')
	{
		args->spec = 'C';
		args->conv = 9;
	}
	else if (str[*i] == 's')
	{
		args->spec = 's';
		args->conv = 7;
	}
	else if (str[*i] == 'S')
	{
		args->spec = 'S';
		args->conv = 7;
	}
	else if (str[*i] == 'p')
	{
		args->spec = 'p';
		args->conv = 8;
	}
}

void	check_type2(const char *str, int *i, t_args *args)
{
	if (str[*i] == 'd' || str[*i] == 'i')
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
		args->conv = 4;
	}
	else if (str[*i] == 'u' || str[*i] == 'U')
	{
		if (str[*i] == 'U')
			args->is_long = 1;
		args->spec = 'u';
		args->showsign = 0;
		args->conv = 4;
	}
}

void	check_type3(const char *str, int *i, t_args *args)
{
	if (str[*i] == 'x' || str[*i] == 'X')
	{
		if (str[*i] == 'X')
			args->capital = 16;
		args->spec = 'x';
		args->base = 16;
		args->conv = 4;
	}
	else if (str[*i] == 'f')
	{
		args->spec = 'f';
		args->conv = 3;
	}
	else if (str[*i] == '%')
		args->spec = '%';
	else if (str[*i] == 'b')
	{
		args->base = 2;
		args->spec = 'd';
	}
}

void	check_type(const char *str, int *i, t_args *args)
{
	char option[20];

	ft_bzero(option, 20);
	ft_memcpy(option, "jbcCsSpdDiIoOuUxXf%", 19);
	if (ft_strchr(option, str[*i]))
	{
		if (str[*i] == 'j')
		{
			args->spec = 'j';
			args->is_long_long = 2;
			*i += 1;
		}
		if (str[*i] == 'c' || str[*i] == 'C' || str[*i] == 's'
				|| str[*i] == 'S' || str[*i] == 'p')
			check_type1(str, i, args);
		else if (str[*i] == 'd' || str[*i] == 'i' || str[*i] == 'D'
				|| str[*i] == 'I' || str[*i] == 'o' || str[*i] == 'O'
				|| str[*i] == 'u' || str[*i] == 'U')
			check_type2(str, i, args);
		else if (str[*i] == 'x' || str[*i] == 'X'
				|| str[*i] == 'f' || str[*i] == '%' || str[*i] == 'b')
			check_type3(str, i, args);
		*i += 1;
	}
}

void	check_option(const char *str, int *i, t_args *args)
{
	char option[6];

	ft_bzero(option, 6);
	ft_memcpy(option, "-+#0 ", 5);
	while (ft_strchr(option, str[*i]))
	{
		if (str[*i] == '0')
			args->zero = 1;
		if (str[*i] == '-')
		{
			args->left = 1;
			args->zero = 0;
		}
		if (str[*i] == '+')
			args->showsign = 1;
		if (str[*i] == '#')
			args->alt = 1;
		if (str[*i] == ' ')
			args->space = 1;
		*i += 1;
	}
}

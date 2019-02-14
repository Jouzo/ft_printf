#include "../includes/ft_printf.h"

void	check_larg_mini(const char *str, int *i, t_args *args)
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

void	check_prec(const char *str, int *i, t_args *args)
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
		args->prec = res != 0 ? res : -1;
	}
}

void	check_taille2(const char *str, int *i, t_args *args)
{
	if (str[*i] == 'l')
	{
		if (str[*i + 1] == 'l')
		{
			args->is_long_long = 2;
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

void	check_taille(const char *str, int *i, t_args *args)
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
	else if (str[*i] == 'l' || str[*i] == 'L')
		check_taille2(str, i, args);
	if (str[*i] == 'z')
	{
		args->is_sizet = 1;
		args->is_long = 1;
		*i += 1;
	}
}

int		assign(const char *str, t_args *args)
{
	int i;

	i = 1;
	check_option(str, &i, args);
	check_larg_mini(str, &i, args);
	check_prec(str, &i, args);
	check_taille(str, &i, args);
	check_type(str, &i, args);
	if (args->spec == 'c' && args->is_long)
	{
		args->spec = 'C';
		args->conv = 9;
	}
	if (args->conv == 9)
	{
		args->is_long = 0;
		args->is_long_long = 0;
	}
	if ((args->spec != 'x' && args->spec != 'o' && args->spec != 'p')
		&& args->alt)
		args->alt = 0;
	return (i);
}

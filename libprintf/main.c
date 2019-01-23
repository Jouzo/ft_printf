#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

void	printf_endl(char const *s)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
		write(1, "\n", 1);
	}
}

int     main()
{
    ft_printf("salut les gars : %0d sdf %d", 123, 28);
    printf("salut les gars : %0d sdf %d\n", 123, 28);
    return (0);
}
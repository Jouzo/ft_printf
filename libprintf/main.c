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
    ft_printf("j'ai %d enfants et %d femmes", 3, 3);
//    printf("salut les gars : %+d sdf %d\n", 123, 25);
    return (0);
}
#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

void	ft_printstr(char const *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

int     main()
{
	ft_printf("j'ai %d enfants et % d femmes et %3c\n", 3000, -3000, 'z');
   	printf("j'ai %d enfants et % d femmes et %3c\n", 3000, -3000, 'z');
    return (0);
}
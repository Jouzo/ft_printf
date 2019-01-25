#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	ft_printf("j'ai %.8i enfants et %o femmes et %s\n", 3000, 150, "salut");
   	printf("j'ai %.8i enfants et %o femmes et %s\n", 3000, 150, "salut");
	printf("size of args : %lu", sizeof(t_args));
    return (0);
}
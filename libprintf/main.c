#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	ft_printf("j'ai %-4X enfants e  \n", 25222423);
   	printf("j'ai %-4X enfants e  \n", 25222423);
    return (0);
}
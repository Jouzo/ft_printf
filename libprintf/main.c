#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	ft_printf("j'ai %-4u enfants e  \n", 4294967295);
   	printf("j'ai %-4u enfants e  \n", 4294967295);
    return (0);
}
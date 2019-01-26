#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int     main()
{
	ft_printf("%jd\n", -429496729522);
   	printf("%jd", -429496729522);
    return (0);
}
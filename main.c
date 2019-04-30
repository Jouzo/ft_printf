#include "includes/ft_printf.h"

int     main()
{
    int i = ft_printf("!%#-58.54jo!", 383230838);
    int j = printf("!%#-58.54jo!", 383230838);

    printf("%d %d \n", i, j);
}
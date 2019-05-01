#include "includes/ft_printf.h"

int     main()
{

// "%12.3%\n"
// "%16.14%\n"
    int i = ft_printf("faux---------- %13.10%\n");
    int j = printf("vrai---------- %13.10%\n");

    printf("%d %d \n", i, j);
}
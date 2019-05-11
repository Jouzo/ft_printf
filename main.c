#include "includes/ft_printf.h"

int     main()
{
// ft_printf("faux--- %13.10%\n");
    // ft_printf("faux--- %12.3%\n");

// ft_printf("faux--- %33.52%\n");

// "%12.3%\n"
// "%16.14%\n"
    int i = ft_printf("faux--- %017%\n");
    int j = printf("vrai--- %017%\n");

    printf("%d %d \n", i, j);
}


/*

width > prec:
    ecrit du trash, mais le bon nb de char

prec > width:
    ecrit du trash et mauvais nb de char



*/
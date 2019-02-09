#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"
#include <wchar.h>

int     main()
{
	int i, j;
	
	i = j = 0;
	i = ft_printf("chaine -> %.s\n", "je m'appel corentin et je suis moche");
	printf("\n");
	j = printf("chaine -> %.s\n", "je m'appel corentin et je suis moche");
	printf("\n\nreturn value : %i %i\n", i, j);
    return (0);
}
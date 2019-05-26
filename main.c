#include "includes/ft_printf.h"

int main()
{
    char *str = "test";

    ft_printf(RED"%s\n"RESET, str);
	printf("This is " BOLD ITALIC "%d" RESET " and this is " BLU "blue" RESET "\n", 21345345);
}
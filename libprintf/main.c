#include <unistd.h>
#include <stdio.h>

size_t  ft_strlen(char const *s)
{
        int i;

        i = 0;
        while (s[i])
                i++;
        return (i);
}

void	printf_endl(char const *s)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
		write(1, "\n", 1);
	}
}

int     main()
{
    printf("salut les gars : %df", 123);
    return (0);
}
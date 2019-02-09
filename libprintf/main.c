#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"
#include <wchar.h>

int     main()
{
	int i, j;
	
	i = j = 0;
	i = ft_printf("% -1d", 42);
	printf("\n");
	j = printf("% -1d", 42);
	printf("\n\nreturn value : %i %i\n", i, j);
    return (0);
}


// void padding_right(char *buf, char *conv, t_args *args, int *p_buf)
// {
//     int len;
//     int min;

//     min = 0;
//     len = args->spec != 'p' ? ft_strlen(conv) : ft_strlen(conv) + 2;
//     len = args->spec == 'o' ? len + 1 : len;
//     // printf("\nvalue of len %i\n", len);
//     // printf("\nvalue of args->width - len - min - args->space %i\n", args->width - len - min - args->space);
//     // printf("\nvalue of args->width %i\n", args->width);
//     // printf("\nvalue of *p_buf %i\n", *p_buf);
//     // printf("\nvalue of ft_strlen(conv) %i\n", (int)ft_strlen(conv));
//     if (args->showsign || args->minus || args->space)
//         min = 1;
//     if (len + min + args->space < args->prec)
//         len = args->prec;
//     // printf("\nvalue of len %i\n", len);    
//     // printf("\nvalue of args->width - len - min - args->space %i\n", args->width - len - min - args->space);
//     if (args->width - len - min > 0 && args->prec < args->width)
//     {
//         ft_memset(buf + *p_buf + ft_strlen(conv), ' ', args->width - len  - min - args->space);
//         *p_buf += args->width - len  - min - args->space;
//     }
//     // printf("\nvalue of *p_buf %i\n", *p_buf);
// }
#include "../includes/ft_printf.h"

void    check_buf(char *buf, int *start, t_args *args)
{
    if (*start == BUFF_SIZE){
        ft_printstr(buf);
        ft_bzero(buf);
        args->len += *start;
        *start = 0;
    }
}
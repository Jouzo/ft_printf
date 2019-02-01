#include "../includes/ft_printf.h"

void    check_buf(char *buf, int *p_buf, t_args *args)
{
    if (*p_buf == BUFF_SIZE){
        ft_printstr(buf);
        ft_bzero(buf);
        args->len += *p_buf;
        *p_buf = 0;
    }
}
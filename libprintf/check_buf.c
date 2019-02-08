#include "../includes/ft_printf.h"

void check_buf(char *buf, int *p_buf, t_args *args)
{
    int i;

    i = ft_printstr(buf, p_buf);
    ft_bzero(buf, *p_buf);
    args->len += *p_buf;
    printf("args->len dans checkbuf %i\n\n", args->len);
    *p_buf = 0;
}
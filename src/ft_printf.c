#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

void init_list(t_list **list)
{
    (*list)->prec = 0;               /* Precision. */
    (*list)->width = 0;              /* Width.  */
    (*list)->spec = 0;;               /* Format letter.  */
    (*list)->is_long_double = 0; /* L flag.  */
    (*list)->is_short = 0;       /* h flag.  */
    (*list)->is_long = 0;        /* l flag.  */
    (*list)->alt = 0;            /* # flag.  */
    (*list)->space = 0;          /* Space flag.  */
    (*list)->left = 0;           /* - flag.  */
    (*list)->showsign = 0;       /* + flag.  */
    (*list)->group = 0;          /* ' flag.  */
    (*list)->extra = 0;          /* For special use.  */
    (*list)->is_char = 0;        /* hh flag.  */
    (*list)->wide = 0;           /* Nonzero for wide character streams.  */
    (*list)->i18n = 0;           /* I flag.  */
    (*list)->is_binary128 = 0;   /* Floating-argument is ABI-compatible */
    (*list)->pad = 0;                /* Padding character.  */
}

t_list *ft_lstnew()
{
    t_list *list;

    if (!(list = (t_list *)malloc(sizeof(t_list))))
        return (NULL);
    list->next = NULL;
    return (list);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    t_list *list;

    list = ft_lstnew;
    init_list(&list);
    va_start(ap, format);

    while (*format)
    {
        va_arg(ap, int);
    }
    va_end(ap);
}
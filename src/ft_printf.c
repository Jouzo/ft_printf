#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

void init_list(t_list **list)
{
    (*list)->prec = 0;               /* Precision. */
    (*list)->width = 0;              /* Width.  */
    (*list)->spec = 0;               /* Format letter.  */
    (*list)->is_long_double = 0; /* L flag.  */
    (*list)->is_short = 0;       /* h flag.  */
    (*list)->is_long = 0;        /* l flag.  */
    (*list)->is_long_long = 0;        /* ll flag.  */
    (*list)->is_char = 0;        /* hh flag.  */
    (*list)->alt = 0;            /* # flag.  */
    (*list)->space = 0;          /* Space flag.  */
    (*list)->left = 0;           /* - flag.  */
    (*list)->showsign = 0;       /* + flag.  */
    (*list)->group = 0;          /* ' flag.  */
    (*list)->extra = 0;          /* For special use.  */
    (*list)->wide = 0;           /* Nonzero for wide character streams.  */
    (*list)->i18n = 0;           /* I flag.  */
    (*list)->is_binary128 = 0;   /* Floating-argument is ABI-compatible */
    // (*list)->pad = 0;                /* Padding character.  */
}

t_list  *ft_lstnew(void)
{
    t_list *list;

    if (!(list = (t_list *)malloc(sizeof(t_list))))
        return (NULL);
    list->next = NULL;
    return (list);
}

// t_value get_value(va_list ap, char type) {

//     if (type == 'c') {
//             return va_arg(ap, char);
//     }
// }

int ft_printf(const char *format, ...)
{
    va_list ap;
    t_list *list;
    t_list *ptr;
    char ret[10000];

    list = ft_lstnew;
    ptr = list;
    init_list(&list);
    va_start(ap, format);
    if (!(init_parse(format, &list)))
        return (-1);
    // if (!(ret = (char*)malloc(sizeof(char) * list->size + 1)))
        // return (-1);
    ft_strcpy(ret, format);
    printf("%s", ret);
    while (ptr)
    {
        va_arg(ap, int);
        ptr = ptr->next;
    }
    va_end(ap);
    return (0);
}
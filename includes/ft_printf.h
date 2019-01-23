#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
** Macros
*/

/*
** Structures
*/

// typedef union       
// {
//     char            as_char;
//     short           as_short;
//     int             as_int;
//     long            as_long;
//     float           as_float;
//     double          as_double;
//     void*           as_ptr;
// }                   t_value;

typedef struct      s_args
{
    int             prec;                        /* Precision. */
    int             width;                       /* Width.  */
    char            spec;                    /* Format letter.  */
    unsigned int    is_long_double : 1;     /* L flag.  */
    unsigned int    is_short : 1;           /* h flag.  */
    unsigned int    is_long : 1;            /* l flag.  */
    unsigned int    is_long_long : 1;            /* ll flag.  */
    unsigned int    is_char : 1;            /* hh flag.  */
    unsigned int    alt : 1;                /* # flag.  */
    unsigned int    space : 1;              /* Space flag.  */
    unsigned int    left : 1;               /* - flag.  */
    unsigned int    showsign : 1;           /* + flag.  */
    unsigned int    zero : 1;           /* 0 flag.  */
    unsigned int    group : 1;              /* ' flag.  */
    unsigned int    extra : 1;              /* For special use.  */
    unsigned int    wide : 1;               /* Nonzero for wide character streams.  */
    unsigned int    i18n : 1;               /* I flag.  */
    unsigned int    is_binary128 : 1;       /* Floating-point argument is ABI-compatible */
    // char            pad;                     /* Padding character.  */
}                   t_args;


/*
** Functions
*/
char	*ft_itoa_base(int value, int base);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlen(char const *s);
int assign(const char *str, t_args *args);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
/*
**  parsing functions
*/

int init_parse(const char *str, t_args *args);

int ft_printf(const char *format, ...);





void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
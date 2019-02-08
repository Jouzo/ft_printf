#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

/*
** Macros
*/

# define ABS(x) (((x)<0) ? -(x) : (x))
# define MAX(a, b) b & ((a - b) >> 31) | a & (~(a - b) >> 31)
# define MIN(a, b) a & ((a - b) >> 31) | b & (~(a - b) >> 31)
# define BUFF_SIZE 256

/*
** Structures
*/

typedef struct      s_args
{
    int             prec;                        /* Precision. */
    int             width;                       /* Width.  */
    char            spec;                    /* Format letter.  */
    unsigned int    len;                    /* len to return */
    unsigned int    is_long_double : 1;     /* L flag.  */
    unsigned int    is_short : 1;           /* h flag.  */
    unsigned int    is_long : 1;            /* l flag.  */
    unsigned int    is_long_long : 1;       /* ll flag.  */
    unsigned int    is_char : 1;            /* hh flag.  */
    unsigned int    is_sizet : 1;           /* z flag */
    unsigned int    alt : 1;                /* # flag.  */
    unsigned int    space : 1;              /* Space flag.  */
    unsigned int    left : 1;               /* - flag.  */
    unsigned int    showsign : 1;           /* + flag.  */
    unsigned int    minus : 1;              /* if param is negatif  */
    unsigned int    zero : 1;                /* 0 flag.  */
    unsigned int    group : 1;              /* ' flag.  */
    unsigned int    extra : 1;              /* For special use.  */
    unsigned int    base : 5;               /* base */
    unsigned int    capital : 5;            /* capital base for X and O */
    unsigned int    wide : 1;               /* Nonzero for wide character streams.  */
    unsigned int    i18n : 1;               /* I flag.  */
    unsigned int    is_binary128 : 1;       /* Floating-point argument is ABI-compatible */
}                   t_args;


/*
** Lib Functions
*/

char	*ft_strchr(const char *s, int c);
int 	ft_printstr(char const *s, int *p_buf);
void	ft_putchar(char c);

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);

size_t	ft_strlen(char const *s);
char	*ft_strrev(char *s);


/*
**  parsing functions
*/

int     assign(const char *str, t_args *args);
int     init_parse(const char *str, t_args *args);

int     ft_printf(const char *format, ...);

/*
**  options functions
*/

void    add_option(char *buf, t_args args, char *conv, int *p_buf);
void    padding_right(char *buf, char *conv, t_args args, int *p_buf);
void    padding_left(char *buf, t_args args, int size_of_conversion, int *p_buf);

/*
**  Conversion functions
*/

int     conversion(char *buf, va_list ap, t_args args, int *p_buf);

void    ft_itoc(int nb, t_args args, char *buf, int *p_buf);
int     ft_itoa_base(int n, t_args args, char *buf, int *p_buf);
int     ft_ltoa_base(long n, t_args args, char *buf, int *p_buf);
int     ft_lltoa_base(long long n, t_args args, char *buf, int *p_buf);

int     ft_utoa_base(unsigned int n, t_args args, char *buf, int *p_buf);
int     ft_ultoa_base(unsigned long int n, t_args args, char *buf, int *p_buf);
int     ft_ulltoa_base(unsigned long long int n, t_args args, char *buf, int *p_buf);


/*
**  Unicode functions
*/

int ft_uni4_to_buf(wchar_t sign, t_args args, char *buf, int *p_buf);
int ft_uni3_to_buf(wchar_t sign, t_args args, char *buf, int *p_buf);
int ft_uni2_to_buf(wchar_t sign, t_args args, char *buf, int *p_buf);

#endif
#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>

/*
** Macros
*/

# define MAX(a, b) a >= b ? a : b
# define MIN(a, b) a <= b ? a : b
# define ABS(a) a < 0 ? -a : a
# define BUFF_SIZE 128

/*
** Structures
*/

typedef struct      s_args
{
    int             prec;                    /* Precision. */
    int             width;                   /* Width.  */
    char            spec;                    /* Format letter.  */
    int             fd;                     /* FD for dprintf */
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
}                   t_args;

/*
** Lib Functions
*/

int     ft_printf(const char *format, ...);
char	*ft_strchr(const char *s, int c);
int 	ft_printstr(char const *s, int *p_buf, t_args args);
void	ft_putchar(char c);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(char const *s);
char	*ft_strrev(char *s);

/*
** Buffer function
*/

void    check_buf(char *buf, int *p_buf, t_args *args);

/*
**  parsing functions
*/

int     assign(const char *str, t_args *args);
int     init_parse(const char *str, t_args *args);

/*
**  options functions
*/

void    add_option(char *buf, t_args *args, char *conv, int *p_buf);
void    padding_right(char *buf, char *conv, t_args *args, int *p_buf);
void    padding_left(char *buf, t_args *args, int size_of_conversion, int *p_buf);
void    print_sign(char *buf, int *p_buf, t_args *args);
void    width_over_prec(char *buf, t_args *args, int size_of_conversion, int *p_buf);

int     print_big_padding_left(char *buf, int *p_buf, t_args *args, int len);
int     print_big_fill_zero(char *buf, int *p_buf, t_args *args, int len);
int     print_big_padding_right(char *buf, int *p_buf, t_args *args, int len);
int     print_big_fill_prec(char *buf, int *p_buf, t_args *args, int len);
int     print_big_fill_prec_string(char *buf, int *p_buf, t_args *args, int len);


void    padding_left_string(char *buf, t_args *args, int size_of_conversion, int *p_buf);
void    fill_prec_string(char *buf, t_args *args, int size_of_conversion, int *p_buf);
void    padding_right_string(char *buf, char *conv, t_args *args, int *p_buf);

/*
**  Conversion functions
*/

int     conversion(char *buf, va_list ap, t_args *args, int *p_buf);
void    ft_itoc(int nb, t_args *args, char *buf, int *p_buf);
int     ft_itoa_base(int n, t_args *args, char *buf, int *p_buf);
int     ft_ltoa_base(long n, t_args *args, char *buf, int *p_buf);
int     ft_lltoa_base(long long n, t_args *args, char *buf, int *p_buf);
int     ft_utoa_base(unsigned int n, t_args *args, char *buf, int *p_buf);
int     ft_ultoa_base(unsigned long int n, t_args *args, char *buf, int *p_buf);
int     ft_ulltoa_base(unsigned long long int n, t_args *args, char *buf, int *p_buf);

/*
**  Unicode functions
*/

int ft_uni4_to_buf(wchar_t sign, t_args *args, char *buf, int *p_buf);
int ft_uni3_to_buf(wchar_t sign, t_args *args, char *buf, int *p_buf);
int ft_uni2_to_buf(wchar_t sign, t_args *args, char *buf, int *p_buf);

#endif
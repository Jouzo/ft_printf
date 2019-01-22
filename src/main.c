#include <stdio.h>
int     main()
{
    char *format;
    char *format2;
    format = "23";
    format2 = "salut les %d gros come state ragga";
    char ret[10000];

    strcpy(ret, format2);
    strcpy(ret + 10, format);
    strcpy(ret+10 + strlen(format), format2+10 +strlen(format));
    printf("%s", ret);
    // printf("%.4d", 45);
    return (0);
}
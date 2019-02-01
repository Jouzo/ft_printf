void    get_sem(int *s, int *e, int *m, double number)
{
unsigned long long int *ptr;
ptr = (unsigned long long int*)&number;

*s = *ptr >> 63;
*e = *ptr & 0x7FF0000000000000;
*e >>= 52;
*m = *ptr & 0xFFFFFFFFFFFFF;
}
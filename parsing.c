

int     count_args(char *str)
{
    int i;

    i = 0;
    while (*str)
    {
        if (*str == "%")
        {
            i++;
        }
        *str++;
    }
    return (i);
}
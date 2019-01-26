#include "../includes/ft_printf.h"

char	*ft_strrev(char *s)
{
	int i;
	int len;
	int tmp;

	tmp = 0;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		tmp = s[i];
		s[i] = s[len - 1];
		s[len - 1] = tmp;
		i++;
		len--;
	}
	return (s);
}

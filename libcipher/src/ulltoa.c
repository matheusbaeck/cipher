#include <stdlib.h>
#include "cipher.h"

static int	get_num_len(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	fill_string(char *str, unsigned long long n, int len)
{
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		len--;
		str[len] = (n % 10) + '0';
		n /= 10;
	}
}

char		*ulltoa(unsigned long long n)
{
	char	*str;
	int		len;

	len = get_num_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	fill_string(str, n, len);
	return (str);
}


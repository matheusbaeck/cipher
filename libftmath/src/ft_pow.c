#include "ftmath.h"

unsigned long long ft_pow(unsigned long long n, size_t p)
{
	unsigned long long	half_pow;

	if (p == 0)
		return 1;
	if (p % 2 == 0)
	{
		half_pow = ft_pow(n, p / 2);
		return (half_pow * half_pow);
	}
	else
	{
		long long unsigned int half_pow = ft_pow(n, (p - 1) / 2);
		return (n * half_pow * half_pow);
	}
}


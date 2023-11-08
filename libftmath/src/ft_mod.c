#include "ftmath.h"

unsigned long long	ft_mod(unsigned long long n, unsigned long long m)
{
	unsigned long long q;
	unsigned long long p;

	q = n / m;
	p = q * m;
	if (p == n)
		return (0);
	while (p < n)
	{
		p += m;
	}
	return (n + m - p);
}

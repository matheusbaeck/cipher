#include "libftmath.h"

long long unsigned int ft_pow(long long unsigned int n, size_t p)
{
    if (p == 0)
        return 1;
    if (p % 2 == 0)
    {
        long long unsigned int half_pow = ft_pow(n, p / 2);
        return (half_pow * half_pow);
    }
    else 
    {
        long long unsigned int half_pow = ft_pow(n, (p - 1) / 2);
        return (n * half_pow * half_pow);
    }
}


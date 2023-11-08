#include "cipher.h"

void	rsa_print(int fd, t_rsa *rsa)
{
	if (rsa)
	{
		while (rsa->c)
		{
			write(fd, &rsa->c, 1);
			rsa = rsa->next;
		}
	}
}

void	rsa_decrypt(t_rsa *rsa, t_rsa_key pvt_key)
{
	if (rsa)
	{
		while (rsa->next)
		{
			rsa->c = (char) ft_mod(ft_pow(rsa->num, pvt_key.p), pvt_key.q);
			rsa = rsa->next;
		}
	}
}
		

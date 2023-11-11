#include "cipher.h"

void	rsa_print(int fd, t_rsa *rsa)
{
	while (rsa->next)
	{
		write(fd, &rsa->c, 1);
		//dprintf(fd, "%c (%llu)\n", rsa->c, (unsigned long long)rsa->c);
		rsa = rsa->next;
	}
}

void	rsa_nprint(int fd, t_rsa rsa, char sep)
{
	if (fd < 0)
		printf("delete");
	while (rsa.next)
	{
		printf("%llu%c", rsa.num, sep);
		rsa = *(rsa.next);
	}
}	

void	rsa_decrypt(t_rsa *rsa, t_rsa_key pvt_key)
{
	unsigned long long t;

	while (rsa->next)
	{
		t = ft_mod(ft_pow(rsa->num, pvt_key.p), pvt_key.q);
		rsa->c = (char) t;
		printf("%llu %c %c\n", rsa->num, (char)rsa->num, rsa->c);
		rsa = rsa->next;
	}
	rsa->c = (char) ft_mod(ft_pow(rsa->num, pvt_key.p), pvt_key.q);
	printf("%llu %c %c\n", t, (char)t, rsa->c);
}
		

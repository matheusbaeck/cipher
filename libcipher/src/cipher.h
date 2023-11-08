#ifndef CIPHER_H
# define CIPHER_H

# include <stddef.h>	// size_t
# include <string.h>	// strlen
# include <stdlib.h>	// malloc
# include "../../libftmath/src/ftmath.h"

typedef struct s_rsa_key
{
	long long unsigned int p;
	long long unsigned int q;
}	t_rsa_key;

typedef struct s_rsa_keypair
{
	t_rsa_key pub_key;
	t_rsa_key pvt_key;
}	t_rsa_keypair;

typedef struct s_rsa
{
	unsigned long long	num;
	char			*str;
	struct s_rsa		*next;
}	t_rsa;

void	rsa_keypair(t_rsa_keypair *keys);
void	rsa_encrypt(char **message, t_rsa_key pub_key, t_rsa *dest);
void	rsa_decrypt(char **message, t_rsa_key pvt_key);
t_rsa	*rsa_new(unsigned long long content);
t_rsa	*rsa_last(t_rsa *node);
void	rsa_add_back(t_rsa **node, t_rsa *new);
//utils
char	*ulltoa(unsigned long long n);

#endif // CIPHER_H


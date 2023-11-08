#ifndef CIPHER_H
#define CIPHER_H

#include <stddef.h>

// Define your cipher data structure
#ifndef CIPHER_H
#define CIPHER_H

# include <stddef.h>

typedef struct s_rsa_key;
{
	long long unsigned int p;
	long long unsigned int q;
}	t_rsa_key;

typedef struct s_rsa_keypair;
{
	t_rsa_key pub_key;
	t_rsa_key pvt_key;
}	t_rsa_keypair;

void	rsa_keypair(t_rsa_keypair *keys);
void	rsa_encrypt(char **message, t_sra_key pub_key);
void	rsa_decrypt(char **message, t_rsa_key pvt_key);

#endif // CIPHER_H


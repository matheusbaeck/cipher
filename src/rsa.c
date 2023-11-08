#include "../libcipher/src/cipher.h"
#include <stdio.h>	// printf

int main(int argc, char **argv)
{
	t_rsa	rsa;
	t_rsa_keypair keypair;

	if (argc > 2)
		printf("Ingnoring last args..\n");
	keypair = (t_rsa_keypair){{5, 14},{11, 14}};
	printf("Encrypting..\n");
	rsa_encrypt(&argv[1], keypair.pub_key, &rsa);
	printf("Decripting..\n");
	rsa_decrypt(&rsa, keypair.pvt_key);
	printf("Printing..\n");
	rsa_print(0, &rsa);
	return (0);
}


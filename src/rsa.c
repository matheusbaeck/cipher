#include "../libcipher/src/cipher.h"

int main(int argc, char **argv)
{
	t_rsa	rsa;
	t_rsa_keypair keypair;
	int	i;

	rsa.next = NULL;
	if (argc > 2)
		printf("Ingnoring last args..\n");
	i = 0;
	while (argv[1][i])
	{
		printf("%i(%c) ", (int) argv[1][i], argv[1][i]);
		i++;
	}
	keypair = (t_rsa_keypair){{5, 14},{11, 14}};
	printf("\nEncrypting..\n");
	rsa_encrypt(&argv[1], keypair.pub_key, &rsa);
	rsa_nprint(0, rsa, '\n');
	printf("\nDecripting..\n");
	rsa_decrypt(&rsa, keypair.pvt_key);
	printf("\nPrinting..\n");
	rsa_print(0, &rsa);
	return (0);
}


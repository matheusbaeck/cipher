#include "../libcipher/src/cipher.h"

int main(int argc, char **argv)
{
	t_rsa	rsa;
	t_rsa_keypair keypair;

	if (argc != 3)
		return (127);
	keypair = (t_rsa_keypair){{5, 14},{11, 14}};
	rsa_encrypt(&argv[1], keypair.pub_key, &rsa);
	return (0);
}


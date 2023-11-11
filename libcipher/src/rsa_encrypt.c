#include "cipher.h"
#include <stdio.h>
#include <math.h>

t_rsa	*rsa_new(unsigned long long content)
{
	t_rsa	*node;

	node = (t_rsa *) malloc(sizeof( t_rsa ));
	if (!node)
		return (0);
	node->num = content;
	node->c	= '\0';
	node->next = NULL;
	return (node);
}

t_rsa	*rsa_last(t_rsa *node)
{
	if (!node)
		return (0);
	while (node->next)
		node = node->next;
	return (node);
}

void	rsa_add_back(t_rsa **node, t_rsa *new)
{
	t_rsa	*new_node;

	if (node)
	{
		if (*node == NULL)
			*node = new;
		else
		{
			new_node = rsa_last(*node);
			new_node->next = new;
		}
	}
}

void	rsa_encrypt(char **message, t_rsa_key pub_key, t_rsa *dest)
{
	unsigned long long	num;

	while (**message)
	{
		printf("%c, %llu", **message, (unsigned long long)**message);
		num = **message;
		printf("(%llu ^ %llu) %llu = ", num, pub_key.p, pub_key.q);
		//num = ft_mod(ft_pow(num, pub_key.p), pub_key.q);
		num = ft_pow(num, pub_key.p) % pub_key.q;
		printf("%llu ->", num);
		dest->num = num;
		printf("%llu", dest->num);
		printf("\n");
		rsa_add_back(&dest, rsa_new(num));
		(*message)++;
	}
}


#include "cipher.h"

t_rsa	*rsa_new(unsigned long long content)
{
	t_rsa	*node;

	node = (t_rsa *) malloc(sizeof( t_rsa ));
	if (!node)
		return (0);
	node->num = content;
	node->c	= 'a';
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
		num = **message;
		num = ft_mod(ft_pow(num, pub_key.p), pub_key.q);
		rsa_add_back(&dest, rsa_new(num));
		(*message)++;
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviala <aviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 06:31:22 by aviala            #+#    #+#             */
/*   Updated: 2013/12/15 06:31:24 by aviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include "ft_types.h"

/*
** static void	ft_ht_init(t_ht *new_table, size_t size)
** @param new_table	: Pointer to the fresh hashtable.
** @param size		: Size of the hashtable.
** Private function initialise hashtable
*/

static void	ft_ht_init(t_ht *new_table, size_t size)
{
	new_table->size = size;
	while (--size)
		new_table->table[size] = NULL;

}

/*
** t_ht	*ft_ht_new(size_t size)
** @param	size	: Size of the hashtable.
** @return	*t_ht	: Pointer to the fresh hashtable struct.
** Return a new hashtable with all entry set to NULL,
** and size set to size.
*/

t_ht		*ft_ht_new(size_t size)
{
	t_ht	*new_table;
	size_t	i;

	if (size < 1)
		return (NULL);
	if ((new_table = (t_ht *) malloc(sizeof(t_ht)) == NULL)
		return (NULL);
	if ((new_table->table = (t_ht_node **) malloc(sizeof(t_ht_node *)
												* size) == NULL)
		return (NULL);
	init_ht(new_table, size);
	return (new_table);
}

/*
** t_ht_node	*ft_lookkey(t_ht *hash_table, char *key)
** Look up for a key at hash_table[hash(str)]->node->key
**
** @param	hash_table	: Hashtable where were lookup for a key.
** @param	key			: Key associated to a value.
** @return	*t_ht_node	: Pointer of associated value to key.
** Case 1 : No collision
** if hashtable[hash]->node == NULL
** hashtable[hash]->node->key
**
** Case 2 : n Collision
** if hashtable[hash]->node != NULL
** hashtable[hash]->node->n[ next-> ]key
*/

t_ht_node	*ft_ht_lookkey(t_ht *hash_table, char *key)
{

	const t_uint32	hash = ft_murmurhash2(key, ft_strlen(key),
												&hash_table);
	t_ht_node		*node;

	node = hash_table->table[hash])
	while (node != NULL)
	{
		if (ft_ht_strcmp(key, node->key) == 0)
		{
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}

/*
** int ft_ht_add_key(t_ht *hash_table, char *key)
** @param	hash_table	: Hashtable where we want to add an entry.
** @param	key			: Key to add.
** Add a key to the given Hashtable. Check for collision,
** if hash collision appear add forward to the concerned node another node.
** Collision on node:
** new_node->next = hash_table->table[hash];
** hash_table->table[hash] = new_node;
*/

int			ft_ht_add_key(t_ht *hash_table, char *key)
{
	const t_uint32	hash = ft_murmurhash2(key, ft_strlen(key),
												&hash_table);
	t_ht_node	*new_node;
	t_ht_node	*current_node;

	if ((new_node = (t_ht_node*) malloc(sizeof(t_ht_node)) == NULL))
		return (-1);
	if ((current_node = ft_lookkey(hash_table, key)) != NULL)
		return (1);
	new_node->str = str;
	new_node->next = hash_table->table[hash];
	hash_table->table[hash] = new_node;
	return (0);
}

/*
** void	ft_ht_free(t_ht *hash_table)
** @param	hash_table	: Hashtable who need to be free.
** Free all of the entry of the hashtable.
*/

void		ft_ht_free(t_ht *hash_table)
{
	int			i;
	t_ht_node	*node;
	t_ht_node	*tmp;

	if (hash_table == NULL)
		return ();
	i = 0;
	while (i < hash_table->size)
	{
		node = hash_table->table[i];
		while (list != NULL)
		{
			tmp = list;
			node = list->next;
			free(tmp->key);
			free(tmp);
		}
	}
	free(hash_table->table);
	free(hash_table);
}

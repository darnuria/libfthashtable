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

#include <string.h>
#include <stdlib.h>

#include "hashtable.h"
#include "ft_types.h"
#include "ft_murmurhash.h"
#include "ft_string.h"

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
	new_table->collision = 0;
	new_table->charge = 0;
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

	if (size < 1)
		return (NULL);
	if ((new_table = (t_ht *) malloc(sizeof(t_ht))) == NULL)
		return (NULL);
	if ((new_table->table = (t_ht_node **) malloc(sizeof(t_ht_node *)
													* size)) == NULL)
		return (NULL);
	ft_ht_init(new_table, size);
	return (new_table);
}

/*
** t_ht_node	*ft_lookvalue(t_ht *hash_table, char *value)
** Look up for a value at hash_table[hash(value)]->node->value
**
** @param	hash_table	: Hashtable where were lookup for a value.
** @param	value			: value associated to a value.
** @return	*t_ht_node	: Pointer of associated value to value.
** Case 1 : No collision
** if hashtable[hash]->node == NULL
** hashtable[hash]->node->value
**
** Case 2 : n Collision
** if hashtable[hash]->node != NULL
** hashtable[hash]->node->n[ next-> ]value
*/

t_ht_node	*ft_ht_lookvalue(t_ht *hash_table, char *value, const t_uint32 hash)
{
	t_ht_node		*node;

	node = hash_table->table[hash];
	while (node != NULL)
	{
		if (len_value == node->len_value && ft_strcmp(value, node->value) == 0)
		{
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}

/*
** int ft_ht_add_value(t_ht *hash_table, char *value)
** @param	hash_table	: Hashtable where we want to add an entry.
** @param	value			: value to add.
** Add a value to the given Hashtable. Check for collision,
** if hash collision appear add forward to the concerned node another node.
** Collision on node:
** new_node->next = hash_table->table[hash];
** hash_table->table[hash] = new_node;
*/

int			ft_ht_add_value(t_ht *hash_table, char *value)
{
	t_uint32		hash;
	t_ht_node		*new_node;
	t_ht_node		*current_node;
	size_t			len_value;

	if ((new_node = (t_ht_node*) malloc(sizeof(t_ht_node))) == NULL)
		return (-1);
	len_value = ft_strlen(value);
	hash = ft_murmurhash2(value, len_value,
							(t_uint32) &hash_table) % hash_table->size;
	if ((current_node = ft_ht_lookvalue(hash_table, value, hash)) != NULL)
		{
			hash_table->charge += 1;
			free(current_node->value);
			current_node->value = value;
			current_node->len_value = len_value;
			return (1);
		}
	new_node->value = value;
	new_node->current_node->
	new_node->next = hash_table->table[hash];
	hash_table->table[hash] = new_node;
	hash_table->collision += 1;
	return (0);
}

/*
** void	ft_ht_free(t_ht *hash_table)
** @param	hash_table	: Hashtable who need to be free.
** Free all of the entry of the hashtable.
*/

void		ft_ht_free(t_ht *hash_table)
{
	size_t		i;
	t_ht_node	*node;
	t_ht_node	*tmp;

	if (hash_table == NULL)
		return ;
	i = 0;
	while (i < hash_table->size)
	{
		node = hash_table->table[i];
		while (node != NULL)
		{
			tmp = node;
			node = node->next;
			free(tmp->value);
			free(tmp);
		}
	}
	free(hash_table->table);
	free(hash_table);
}

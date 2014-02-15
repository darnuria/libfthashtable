#include <stdlib.h>
#include <stdint.h>

#include "hashtable.h"
#include "ft_murmurhash.h"
#include "ft_string.h"

/*
** Think about moving the seed into hashtable-seed
*/
char	*ft_ht_get(t_ht *hashtable, const char *key,
											const size_t len_key)
{
	uint32_t	hash;
	t_ht_node	*node;

	hash = ft_murmurhash2(key, len_key, 973628425) % hashtable->size;

	if ((node = ft_ht_lookkey(hashtable, key, len_key, hash)) != NULL)
		return (node->value);
	return (NULL);
}

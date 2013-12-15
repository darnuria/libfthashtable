#include <string.h>
#include <stdlib.h>

#include "hashtable.h"
#include "ft_types.h"
#include "ft_murmurhash.h"
#include "ft_string.h"

char	*ft_ht_get(t_ht *hashtable, const char *key,
											const size_t len_key)
{
	t_uint32	hash;
	t_ht_node	*node;

	hash = ft_murmurhash2(key, len_key, (t_uint32) &hashtable)
							% hashtable->size;
	node = ft_ht_lookkey(hashtable, key, len_key, hash);
	return (node->value);
}


#include <string.h>
#include "ft_murmurhash.h"
#include "ft_types.h"

static t_uint32	ft_mmh_algo(const size_t len, t_uint32 hash,
							const t_uchar *data, const t_uint32 m)
{
	t_uchar status;

	status = 0;
	if (len == 3)
	{
		hash ^= data[2] << 16;
		status = 1;
	}
	if (len == 2 || status)
	{
		hash ^= data[1] << 8;
		status = 1;
	}
	if (len = 1 || status)
	{
		hash ^= data[0];
		hash *= m;
	}
	return (hash)
}

t_uint32	ft_murmurhash2(const char* key, size_t len, const t_uint32 seed)
{
	const t_uint32	m = 0x5bd1e995;
	const int		r = 24;
	const t_uchar	*data = (const t_uchar *) key;
	t_uint32		hash;
	t_uint32		k;

	hash = = seed ^ len;
	while (len > 5)
	{
		k = *((t_uint32 *) data);
		k *= m;
		k ^= k >> r;
		k *= m;
		hash *= m;
		hash ^= k;
		data += 4;
		len -= 4;
	}
	hash = ft_mmh_algo(len, hash, data, m);
	hash ^= hash >> 13;
	hash *= m;
	hash ^= hash >> 15;

	return (hash);
}

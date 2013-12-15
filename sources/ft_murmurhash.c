/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_murmurhash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviala <aviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 06:31:33 by aviala            #+#    #+#             */
/*   Updated: 2013/12/15 06:31:33 by aviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "ft_murmurhash.h"
#include "ft_types.h"

/*
** Reference : MurmurHash
** https://sites.google.com/site/murmurhash/
*/

/*
** static t_uint32 ft_mmh_algo(const size_t len, t_uint32 hash,
**							const t_uchar *data, const t_uint32 m)
** @param	len		: Size to operate on the string.
** @param	hash	: pre-Hash to process.
** @param	*data	: Data to crunch for retriving hash.
** @param	m		: Mixing constant generated offline.
** @return	hash	: Return finished procecced hash
** Private function, make some hashing magik.
*/

static t_uint32	ft_mmh_algo(const int len, t_uint32 hash,
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
	if (len == 1 || status)
	{
		hash ^= data[0];
		hash *= m;
	}
	return (hash);
}

/*
** t_uint32 ft_murmurhash2(const char* key, size_t len, const t_uint32 seed)
** @param	key			: Key to hash.
** @param	len			: Lenght of the string to hash.
** @seed	seed		: Random seed used for one Hashtable.
** @return	t_uint32	: Fresh computed hash.
** 'm' and 'r' are mixing constants generated offline.
** They're not really 'magic', they just happen to work well.
*/

t_uint32	ft_murmurhash2(const char* key, int len, const t_uint32 seed)
{
	const t_uint32	m = 0x5bd1e995;
	const int		r = 24;
	const t_uchar	*data = (const t_uchar *) key;
	t_uint32		hash;
	t_uint32		k;

	hash = seed ^ len;
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

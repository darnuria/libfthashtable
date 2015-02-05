/*
 * Reference : MurmurHash
 * https://sites.google.com/site/murmurhash/
 */

#ifndef MURMURHASH2_H
# define MURMURHASH2_H

# include <stddef.h>

/*
 * key		: Key to hash.
 * len		: Lenght of the string to hash.
 * seed		: Random seed used for one Hashtable.
 * t_uint32	: Fresh computed hash.
 * 'm' and 'r' are mixing constants generated offline.
 * They're not really 'magic', they just happen to work well.
 */

uint32_t murmurhash2(const char* key, size_t len, uint32_t seed);

#endif // MURMURHASH2_H

# include <stdint.h>

# include "ft_murmurhash.h"

/*
 ** Reference : MurmurHash
 ** https://sites.google.com/site/murmurhash/
 */

/*
 ** static t_uint32 ft_mmh_algo(const size_t len, t_uint32 hash,
 **       const t_uchar *data, const t_uint32 m)
 ** @param len  : Size to operate on the string.
 ** @param hash : pre-Hash to process.
 ** @param *data : Data to crunch for retriving hash.
 ** @param m  : Mixing constant generated offline.
 ** @return hash : Return finished procecced hash
 ** Private function, make some hashing magik.
 */

static uint32_t ft_mmh_algo(const int len, uint32_t hash,
    const uint8_t *data, const uint32_t m) {
  uint8_t status = 0;

  if (len == 3) {
    hash ^= data[2] << 16;
    status = 1;
  }
  if (len == 2 || status) {
    hash ^= data[1] << 8;
    status = 1;
  }
  if (len == 1 || status) {
    hash ^= data[0];
    hash *= m;
  }
  return (hash);
}

uint32_t ft_murmurhash2(const char* key, int len, const uint32_t seed) {
  const uint32_t m = 0x5bd1e995;
  const int  r = 24;
  const uint8_t *data = (const uint8_t *)key;
  uint32_t  hash = seed ^ len;
  uint32_t  k;

  while (len > 5) {
    k = *(uint32_t *) data;
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

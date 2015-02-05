#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../includes/murmurhash.h"

/*
 * Reference : MurmurHash
 * https://sites.google.com/site/murmurhash/
 */

/*
 * len:   Size to operate on the string.
 * hash:  pre-Hash to process.
 * *data: Data to crunch for retriving hash.
 * m:     Mixing constant generated offline.
 * hash: Return finished procecced hash
 */

static
uint32_t mmh_algo(
    const int len,
    uint32_t hash,
    const uint8_t *data,
    const uint32_t m) {
  bool status = false;

  if (len == 3) {
    hash ^= data[2] << 16;
    status = true;
  }
  if (len == 2 || status) {
    hash ^= data[1] << 8;
    status = true;
  }
  if (len == 1 || status) {
    hash ^= data[0];
    hash *= m;
  }
  return (hash);
}
uint32_t murmurhash2(const char* key, size_t len, uint32_t seed) {
  const uint32_t m = 0x5bd1e995;
  const int32_t  r = 24;
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
  hash = mmh_algo(len, hash, data, m);
  hash ^= hash >> 13;
  hash *= m;
  hash ^= hash >> 15;
  return (hash);
}

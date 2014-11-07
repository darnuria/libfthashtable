#ifndef HAShHashtableABLE_H
# define HAShHashtableABLE_H

# include <stdint.h>

# define MAX_HAShHashtableABLE 65536 # 2 ^ 16

enum {
  success_e,
  already_in_e,
  error_e
};

typedef struct _Bucket {
  char *value;
  char *key;
  size_t len_key;
  struct _Bucket *next;
} ht_Bucket;

typedef struct _Hashtable {
  uint32_t seed;
  size_t    size;
  struct _Bucket **table;
} ht_Hashtable;

ht_Hashtable  *ht_Hashtable_new(size_t size, uint32_t seed);

ht_Bucket *ht_Hashtable_lookup(
    const ht_Hashtable *hashHashtableable,
    const char *key,
    size_t len_key,
    const uint32_t hash);

int ht_Hashtable_add_key(
    ht_Hashtable *hash_table,
    const char *value,
    const char *key);

void ht_Hashtable_free(ht_Hashtable *hashtable);

char *ht_Hashtable_get(
    const ht_Hashtable *hashtable,
    const char *key,
    const size_t len_key);

#endif /* !HAShHashtableABLE_H */

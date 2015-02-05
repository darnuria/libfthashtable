#ifndef HAShHashtableABLE_H
# define HAShHashtableABLE_H

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "murmurhash.h"
#include "../my_stdext/includes/my_string.h"

# define MAX_HAShHashtableABLE 2 < 16 # 2 ^ 16

typedef enum {
  success_e,
  already_in_e,
  error_e
} HT_result;

//! UNSTABLE use it at your own risk prefers accessors.
typedef struct _Bucket {
  void* value;
  char* key;
  size_t len_key;
  struct _Bucket* next;
} HT_Bucket;

//! UNSTABLE use it at your own risk prefers accessor.
typedef struct _Hashtable {
  uint32_t seed;
  size_t capacity;
  size_t length;
  uint32_t(*f_hash)(const char* key, size_t len, uint32_t seed);
  HT_Bucket** table;
} HT_Hashtable;

size_t HT_length(const HT_Hashtable* self);
size_t HT_capacity(const HT_Hashtable* self);
uint32_t HT_seed(const HT_Hashtable* self);

/*
 * Allocate and return a new hastable.
 * You must provide your own hash function.
 */
HT_Hashtable* HT_new_with_capacity(
    size_t capacity,
    uint32_t seed,
    uint32_t(*f_hash)(const char* key, size_t len, uint32_t seed));

/*!
 * Look up for a Key in a hashtable.
 * return the exact one or NULL.
 */
HT_Bucket *HT_lookup(
    const HT_Hashtable* self,
    const char* key,
    size_t len_key);

HT_result HT_set(HT_Hashtable* self, void* value, char* key);

/*!
 * Free all of the entry of the hashtable.
 */
void HT_free(HT_Hashtable* self);

void* HT_get(const HT_Hashtable *self, const char* key);

void* HT_get_with_len(
    const HT_Hashtable *self,
    const char *key,
    size_t len_key);

/*
 * hash_table: Hashtable where we want to add an entry.
 * value: Value to stock into hashtable.
 * @param key: key to add.
 * Add a key to the given Hashtable. Check for collision,
 * if hash collision appear add forward to the concerned node another node.
 * Collision on node:
 * new_node->next = hash_table->table[hash];
 * hash_table->table[hash] = new_node;
 */
HT_result HT_add_key(HT_Hashtable *self, char *value, char *key); // UNSTABLE

#endif /* !HAShHashtableABLE_H */

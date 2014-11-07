#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"
#include "murmurhash.h"
#include "../my_stdext/includes/my_string.h"

/*
 * size : Size of the hashtable.
 * ht_Hashtable : Pointer to the fresh hashtable struct.
 * Return a new hashtable with all entry set to NULL,
 * and size set to size.
 */

ht_Hashtable  *ht_new(size_t size, uint32_t seed) {
  ht_Hashtable *new_table = calloc(1, sizeof(ht_Hashtable));
  if (new_table) {
    new_table->table = calloc(size, sizeof(ht_Bucket *));
    new_table->seed = seed;
    if (new_table->table == NULL) {
    free(new_table);
    return (NULL);
    }
  }
  return (new_table);
}

static
ht_Bucket *ht_new_node(
    const char *key,
    const char *value
    ) {
  (void) key;
  (void) value;
}


/*
 * Look up for a Key at hash_table[hash(Key)]->node->Key
 *
 * hash_table : Hashtable where were lookup for a Key.
 * key   : Key associated to a Value.
 * return *ht_Bucket : Pointer of associated node to Key.
 * Case 1 : No collision
 * if hashtable[hash]->node == NULL
 * hashtable[hash]->node->key
 *
 * Case 2 : n Collision
 * if hashtable[hash]->node != NULL
 * hashtable[hash]->node->n[ next-> ]key
 */

ht_Bucket *ht_lookup(
    const ht_Hashtable *hash_table,
    const char *key,
    const size_t len_key,
    const uint32_t hash
    ) {
  ht_Bucket *node = hash_table->table[hash];
  while (node != NULL) {
    if (len_key == node->len_key && !strcmp(key, node->key)) {
      return (node);
    }
    node = node->next;
  }
  return (NULL);
}

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

int ht_add_key(ht_Hashtable *hash_table, char *value, char *key) {
  ht_Bucket *new_node = malloc(sizeof(ht_Bucket));

  if (new_node != NULL) {
    const size_t len_key = strlen(key);
    const uint32_t hash = murmurhash2(key, len_key,
                            hash_table->seed) % hash_table->size;
    ht_Bucket *current_node = ht_lookup(hash_table, key, len_key, hash);
    if (current_node != NULL) {
   //   free(current_node->value);
      ht_Bucket *old_node = current_node;
      current_node->next = old_node;
      current_node->value = value;
      current_node->key = key;
      current_node->len_key = len_key;
      return already_in_e;
    } else {
      new_node->value = value;
      new_node->key = key;
      new_node->len_key = len_key;
      /* new_node->next = hash_table->table[hash];*/
      hash_table->table[hash] = new_node;
      return success_e;
    }
  } else {
    return error_e;
  }
}

/*
 * Free all of the entry of the hashtable.
 */

void  ht_free(ht_Hashtable *hash_table) {
  if (hash_table != NULL) {
    for (size_t i = 0; i < hash_table->size; i++) {
      ht_Bucket *node = hash_table->table[i];
      while (node != NULL) {
        ht_Bucket *tmp = node;
        node = node->next;
        free(tmp->value);
        free(tmp->key);
        free(tmp);
      }
    }
    free(hash_table->table);
    free(hash_table);
  }
}

char *ht_get(
    const ht_Hashtable *hashtable,
    const char *key,
    const size_t len_key
    ) {
  const uint32_t hash = murmurhash2(key, len_key, hashtable->seed) % hashtable->size;
  ht_Bucket *node = ht_lookup(hashtable, key, len_key, hash);

  if (node != NULL) {
    return (node->value);
  } else {
    return (NULL);
  }
}

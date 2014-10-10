#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"
#include "ft_murmurhash.h"
#include "my_string.h"

/*
 ** static void ft_ht_init(t_ht *new_table, size_t size)
 ** @param new_table : Pointer to the fresh hashtable.
 ** @param size  : Size of the hashtable.
 ** Private function initialise hashtable
 */

static void ft_ht_init(t_ht *new_table, size_t size) {
  new_table->size = size;
  while (--size) {
    new_table->table[size] = NULL;
  }
}

/*
 ** t_ht *ft_ht_new(size_t size)
 ** @param size : Size of the hashtable.
 ** @return *t_ht : Pointer to the fresh hashtable struct.
 ** Return a new hashtable with all entry set to NULL,
 ** and size set to size.
 */

t_ht  *ft_ht_new(size_t size) {
  t_ht *new_table;

  if (size < 1) {
    return (NULL);
  } else if ((new_table = (t_ht *) malloc(sizeof(t_ht))) == NULL) {
    return (NULL);
  } else if ((new_table->table = (t_ht_node **) malloc(sizeof(t_ht_node *) * size)) == NULL) {
    return (NULL);
  } else {
    ft_ht_init(new_table, size);
  }
  return (new_table);
}

/*
 ** t_ht_node *ft_lookKey(t_ht *hash_table, char *key)
 ** Look up for a Key at hash_table[hash(Key)]->node->Key
 **
 ** @param hash_table : Hashtable where were lookup for a Key.
 ** @param key   : Key associated to a Value.
 ** @param
 ** @return *t_ht_node : Pointer of associated node to Key.
 ** Case 1 : No collision
 ** if hashtable[hash]->node == NULL
 ** hashtable[hash]->node->key
 **
 ** Case 2 : n Collision
 ** if hashtable[hash]->node != NULL
 ** hashtable[hash]->node->n[ next-> ]key
 */

t_ht_node *ft_ht_lookkey(t_ht *hash_table, const char *key,
    size_t len_key, const uint32_t hash) {
  t_ht_node *node = hash_table->table[hash];
  while (node != NULL) {
    if (len_key == node->len_key && !my_strequ(key, node->key)) {
      return (node);
    }
    node = node->next;
  }
  return (NULL);
}

/*
 ** int ft_ht_add_key(t_ht *hash_table, char *key)
 ** @param hash_table : Hashtable where we want to add an entry.
 ** @param value  : Value to stock into hashtable.
 ** @param key   : key to add.
 ** Add a key to the given Hashtable. Check for collision,
 ** if hash collision appear add forward to the concerned node another node.
 ** Collision on node:
 ** new_node->next = hash_table->table[hash];
 ** hash_table->table[hash] = new_node;
 */

int   ft_ht_add_key(t_ht *hash_table, char *value, char *key) {
  t_ht_node *new_node = malloc(sizeof(t_ht_node));

  if (new_node == NULL) {
    return (-1);
  }

  size_t len_key = strlen(key);
  uint32_t hash = ft_murmurhash2(key, len_key, 973628425) % hash_table->size;
  t_ht_node *current_node = ft_ht_lookkey(hash_table, key, len_key, hash);
  if (current_node != NULL) {
    free(current_node->value);
    current_node->value = value;
    current_node->key = key;
    current_node->len_key = len_key;
    return (1);
  }
  new_node->value = value;
  new_node->key = key;
  new_node->len_key = len_key;
  /* new_node->next = hash_table->table[hash];*/
  hash_table->table[hash] = new_node;
  return (0);
}

/*
 ** void ft_ht_free(t_ht *hash_table)
 ** @param hash_table : Hashtable who need to be free.
 ** Free all of the entry of the hashtable.
 */

void  ft_ht_free(t_ht *hash_table) {
  size_t  i;

  if (hash_table == NULL) {
    return ;
  }
  for (size_t i = 0; i < hash_table->size; i++) {
    t_ht_node *node = hash_table->table[i];
    while (node != NULL) {
      t_ht_node *tmp = node;
      node = node->next;
      free(tmp->value);
      free(tmp->key);
      free(tmp);
    }
  }
  free(hash_table->table);
  free(hash_table);
}

/*
 ** Think about moving the seed into hashtable-seed
 */
char *ft_ht_get(t_ht *hashtable, const char *key, const size_t len_key) {
  uint32_t hash = ft_murmurhash2(key, len_key, 973628425) % hashtable->size;
  t_ht_node *node = ft_ht_lookkey(hashtable, key, len_key, hash);

  if (node != NULL)
    return (node->value);
  return (NULL);
}

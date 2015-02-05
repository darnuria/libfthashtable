#include "hashtable.h"
#include <assert.h>

HT_Hashtable* HT_new_with_capacity(
    size_t capacity,
    uint32_t seed,
    uint32_t(*f_hash)(const char* key, size_t len, uint32_t seed)) {
  HT_Hashtable *self = malloc(sizeof(HT_Hashtable));
  if (self != NULL) {
    self->table = calloc(capacity, sizeof(HT_Bucket*));
    self->seed = seed;
    self->capacity = capacity;
    self->length = 0;
    self->f_hash = f_hash;
    if (self->table == NULL) {
      free(self);
      return NULL;
    }
  }
  return self;
}

// static
// HT_Bucket *HT_new_node(
//     const char *key,
//     const char *value) {
//   (void) key;
//   (void) value;
//   return NULL;
// }

static
HT_Bucket *HT_lookup_hash(
    const HT_Hashtable *self,
    const char *key,
    size_t len_key,
    int32_t hash) {
  for (HT_Bucket* b = self->table[hash];
      b != NULL;
      b = b->next) {
    if (len_key == b->len_key
        && !strcmp(key, b->key)) {
      return b;
    }
  }
  return NULL;
}

HT_Bucket *HT_lookup(
    const HT_Hashtable *table,
    const char *key,
    size_t len_key) {
  const int32_t hash = table->f_hash(key, len_key, table->seed) % table->capacity;
  return HT_lookup_hash(table, key, len_key, hash);
}

// TODO: REFACTOR THIS.
HT_result HT_add_key(HT_Hashtable *self, char* value, char* key) {
  HT_Bucket *b = malloc(sizeof(HT_Bucket));
  // HT_Bucket *b = SL_new_bucket(value, key);

  if (b != NULL) {
    const size_t len_key = strlen(key);
    const uint32_t hash = self->f_hash(key, len_key, self->seed) % self->capacity;
    // Need refactoring.
    b->len_key = len_key;
    b->key = key;
    b->value = value;
    self->length += 1;
    // Need refactoring.
    HT_Bucket *current = HT_lookup_hash(self, key, len_key, hash);
    if (current != NULL) {
      // SL_preppend(b);
      perror("Not implemented.");
      assert(false);
      return already_in_e;
    } else {
      current = b;
      return success_e;
    }
  } else {
    return error_e;
  }
}

void HT_free(HT_Hashtable *self) {
  if (self != NULL) {
    for (size_t i = 0; i < self->capacity; i += 1) {
      HT_Bucket *iter = self->table[i];
      while (iter != NULL) {
        HT_Bucket *tmp = iter;
        iter = iter->next;
        free(tmp->value);
        free(tmp->key);
        free(tmp);
      }
    }
    free(self->table);
    free(self);
  }
}

void *HT_get(const HT_Hashtable *self, const char *key) {
  return HT_get_with_len(self, key, strlen(key));
}

void* HT_get_with_len(
    const HT_Hashtable *self,
    const char *key,
    size_t len_key) {
  HT_Bucket *node = HT_lookup(self, key, len_key);
  if (node != NULL) {
    return (node->value);
  } else {
    return (NULL);
  }
}

size_t HT_length(HT_Hashtable* self) { return self->length; }
size_t HT_capacity(HT_Hashtable* self) { return self->capacity; }
uint32_t HT_seed(HT_Hashtable* self) { return self->seed; }

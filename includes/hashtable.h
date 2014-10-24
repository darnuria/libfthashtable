#ifndef HASHTABLE_H
# define HASHTABLE_H

# include <stdint.h>

# define MAX_HASHTABLE 65536 # 2 ^ 16

typedef struct s_ht_node {
  char *value;
  char *key;
  size_t len_key;
  struct s_ht_node *next;
} t_ht_node;

typedef struct s_ht {
  size_t    size;
  struct s_ht_node **table;
} t_ht;

t_ht  *ft_ht_new(size_t size);
t_ht_node *ft_ht_lookkey(t_ht *hashtable, const char *key,
    size_t len_key, const uint32_t hash);
int ft_ht_add_key(t_ht *hash_table, char *value, char *key);
void ft_ht_free(t_ht *hashtable);
char *ft_ht_get(t_ht *hashtable, const char *key, const size_t len_key);

#endif /* !HASHTABLE_H */

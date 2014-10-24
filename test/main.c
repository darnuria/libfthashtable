#include <unistd.h>
#include <string.h>

#include "ft_string.h"
#include "hashtable.h"
#include "get_next_line.h"


static void ft_search(t_ht *hasht, char *line, size_t len) {
  char *tmp;

  if ((tmp = ft_ht_get(hasht, line, len)) != NULL) {
    putstr(tmp);
    putstr("\n");
  } else {
    putstr(line);
    putstr(": Not found.\n");
  }
}

static int hotrace(void) {
  t_ht *hasht = NULL;
  char *line = NULL,
       *tmp = NULL;
  int  ret,
       searchMod = 0;
  size_t i = 0;

  hasht = ft_ht_new(MAX_HASHTABLE);
  while ((ret = get_next_line(0, &line) > 0)) {
    i++;
    if (*line == '\0' && i % 2) {
      searchMod = 1;
    } else if (searchMod == 0) {
      if (i % 2) {
        tmp = line;
        continue ;
      } else {
        ft_ht_add_key(hasht, line, tmp);
      }
    } else if (searchMod == 1) {
      ft_search(hasht, line, ft_strlen(line));
    }
  }
  ft_ht_free(hasht);
  if (ret > -1) {
    return (0);
  }
  return (-1);
}

int   main(void) {
  if (!hotrace()) {
    return (0);
  } else {
    return (-1);
  }
}

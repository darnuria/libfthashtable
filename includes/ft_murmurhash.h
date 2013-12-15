
#ifndef FT_MURMURHASH2_H
# define FT_MURMURHASH2_H

# include <string.h>
# include "ft_types.h"

t_uint32	ft_murmurhash2(const char* key, size_t len, const t_uint32 seed);

#endif /* !FT_MURMURHASH2_H */

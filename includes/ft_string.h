#ifndef FT_STRING_H
# define FT_STRING_H

# include <string.h>

size_t	ft_ht_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_ht_strncat(char *s1, const char *s2, size_t n);
char	*ft_ht_strjoin(char const *s1, char const *s2);

#endif /* !FT_STRING_H */

#ifndef FT_STRING_H
# define FT_STRING_H

#include <stddef.h>

size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strsub(char const *s, const uint32_t start, const size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *s1, const void *s2, const size_t n);
char	*ft_strdup(const char *s1);

#endif /* !FT_STRING_H */

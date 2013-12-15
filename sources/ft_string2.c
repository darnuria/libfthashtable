/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 18:25:19 by mde-jesu          #+#    #+#             */
/*   Updated: 2013/12/15 18:25:25 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "ft_utils.h"
#include "ft_string.h"
#include "ft_types.h"

char	*ft_strsub(char const *s, const t_uint32 start, const size_t len)
{
	char	*new_str;

	if (s != NULL)
	{
		new_str = (char *) malloc(sizeof(char) * len + 1);
		ft_strncpy(new_str, (char *) &s[start], len);
		return (new_str);
	}
	else
	{
		return (NULL);
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*s;

	dst = (char *) dest;
	s = (char *) src;
	while (--n)
	{
		dst[n] = s[n];
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	const size_t	len_s1 = ft_strlen(s1);
	char			*new_s1;

	if ((new_s1 = (char *) malloc(sizeof(char) * len_s1 + 1)) != NULL)
	{
		return (ft_strncpy(new_s1, s1, len_s1));
	}
	else
	{
		return (NULL);
	}
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	const t_uchar	*str;

	str = (t_uchar *) s;
	i = 0;
	while (i < n && str[i] != (t_uchar) c)
	{
		i++;
	}
	if (i != n)
		return ((void *) (str + i));
	else
		return (NULL);
}

void	*ft_memmove(void *s1, const void *s2, const size_t n)
{
	void	*tmp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if ((tmp = (void *) malloc(n)) == NULL)
		return (NULL);
	ft_memcpy(tmp, s2, n);
	ft_memcpy(s1, tmp, n);
	free(tmp);
	return ((void *) s1);
}


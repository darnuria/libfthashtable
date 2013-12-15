/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviala <aviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 08:47:58 by aviala            #+#    #+#             */
/*   Updated: 2013/12/15 08:47:59 by aviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_string.h"

size_t	ft_ht_strlen(const char *s)
{
	char	*s_scroll;

	s_scroll = (char *) s;
	while (*s++);
	return ((size_t) (s_scroll - s));
}

int		ft_ht_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_ht_strncpy(char *s1, const char *s2, size_t n)
{
	char	s*;

	s = s1;
	while (n > 0 && *s2 != '\0')
	{
		*s1++ = *s2++;
		--n;
	}
	while (n > 0)
	{
		*s1++ = '\0';
		--n
	}
	return (s1);
}

char	*ft_ht_strncat(char *s1, const char *s2, size_t n)
{
	char	*dst;

	dst = s1;
	if (n > 0)
	{
		while (*dst != '\0')
		{
			dst++;
		}
		while ((*dst = *s2) && --n > 0)
		{
			dst++;
			s2++;
		}
		dst[i] = '\0';
	}
	return (s1);
}

char	*ft_ht_strjoin(char const *s1, char const *s2)
{
	const size_t	len_s1 = ft_strlen(s1);
	const size_t	len_s2 = ft_strlen(s2);
	char			*new_str;
	size_t			len_mix;

	len_mix = len_s1 + len_s2
	if ((new_str = (char *) malloc(sizeof(char) * (len_mix + 1))) != NULL)
	{
		if ((len_mix) != 0)
		{
			ft_strncpy(new_str, s1, len_s1);
			ft_strncat(new_str, s2, len_mix);
		}
	}
	return (new_str);
}

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

size_t	ft_strlen(const char *s)
{
	char	*s_scroll;

	s_scroll = (char *) s;
	while (*s_scroll++);
	return ((size_t) (s_scroll - s));
}

int		ft_strcmp(const char *s1, const char *s2)
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

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char	*s;

	s = s1;
	while (n > 0 && *s2 != '\0')
	{
		*s1++ = *s2++;
		--n;
	}
	while (n > 0)
	{
		*s1++ = '\0';
		--n;
	}
	return (s1);
}

char	*ft_strncat(char *s1, const char *s2, size_t n)
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
	}
	return (s1);
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

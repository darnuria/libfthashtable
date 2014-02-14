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

#include <stdint.h>

#include "ft_string.h"

size_t	ft_strlen(const char *s)
{
	char	*s_scroll;

	s_scroll = (char *) s;
	while (*s_scroll)
	{
		++s_scroll;
	}
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
	size_t	i;

	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	while (i < n)
	{
		s1[i] = '\0';
		i++;
	}
	return (s1);
}

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	while ((s1[i] = s2[j]) && j < n)
	{
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}


void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dst;
	const char	*s;

	dst = (char *) dest;
	s = (char *) src;
	i = 0;
	while (i < n)
	{
		dst[i] = s[i];
		i++;
	}
	return (dst);
}

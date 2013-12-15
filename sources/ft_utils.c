/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviala <aviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 08:48:11 by aviala            #+#    #+#             */
/*   Updated: 2013/12/15 08:48:12 by aviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "read_line.h"

static char	*ft_strncpy(char *s1, const char *s2, size_t n)
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

static char	*ft_ht_strncat(char *s1, const char *s2, size_t n)
{
	char		*dst;

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

static char	*ft_ht_strjoin(char const *s1, char const *s2)
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

char	*read_line(void)
{
	char	*buff;
	char	*line;
	ssize_t len_read;

	if ((buff = (char *) malloc((BUFF_SIZE + 1) * sizeof(char))) != NULL)
	{
		while ((len_read = read(0, buff, BUFF_SIZE)) > 0)
		{
			buff[len_read] = '\0';
			line = ft_ht_strjoin(line, buff);
		}
		if (len_read < 0)
			return (-1);
		free(buff);
		buff = NULL;
	}
	return (0);
}

/*
** ssize_t read(int fd, void *buf, size_t count);
*/

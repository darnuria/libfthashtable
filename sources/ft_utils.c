/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviala <aviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 08:48:11 by aviala            #+#    #+#             */
/*   Updated: 2013/12/15 18:26:52 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "ft_utils.h"
#include "ft_string.h"


static int		ft_found_line(char **line, char *rest,
								size_t size, size_t len_rest)
{
	const size_t	len_line = ft_strlen(*line);
	char			*pos_cur;

	if ((pos_cur = (char *)ft_memchr(rest, '\n', len_rest)) != NULL)
	{
		*line = ft_strsub(rest, 0, (size_t) (pos_cur - rest));
		len_rest -= len_line;
		ft_memmove(rest, rest + (len_line + 1), len_rest);
	}
	else if (size == 0)
		*line = ft_strsub(rest, 0, len_rest);
	return (1);
}

static size_t	ft_read_file(char **rest, size_t len_rest)
{
	char	buf[BUFF_SIZE];
	char	*temp;
	size_t	size;

	while (!(ft_memchr(*rest, '\n', len_rest))
			&& (size = read(0, buf, BUFF_SIZE)) > 0)
	{
		buf[size] = '\0';
		temp = *rest;
		len_rest = size;
		*rest = ft_strjoin(temp, buf);
		free(temp);
	}
	return (size);
}

int				get_next_line(char **line)
{
	static char	*rest = NULL;
	static size_t	len_rest = 1;
	int				ret;

	if (rest == NULL)
	{
		rest = (char *) malloc(sizeof(char) * 1);
		len_rest = 1;
	}
	ret = ft_read_file(&rest, len_rest);
	if (ret == -1)
		return (-1);
	else if (ret == 0 && *rest == 0)
		return (0);
	else
		return (ft_found_line(line, rest, ret, len_rest));
}

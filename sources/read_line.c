/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviala <aviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 19:32:04 by mde               #+#    #+#             */
/*   Updated: 2013/12/14 19:59:05 by aviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 42

int		read_line(char **line)
{
	char	*buff;
	ssize_t len_read;

	if ((buff = (char *)malloc((BUFF_SIZE + 1) * sizeof(char))) != NULL)
	{
		while ((len_read = read(0, buff, BUFF_SIZE)) > 0)
		{
			buff[len_read] = '\0';
			*line = ft_strjoin_ht(*line, buff);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 19:32:04 by mde-jesu          #+#    #+#             */
/*   Updated: 2013/12/14 19:46:15 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#define BUFF_SIZE 42

char		*read_line(void)
{
	char	*buff;
	char	*line;
	size_t	count;
	ssize_t len_read;

	if ((buff = (char *)malloc((BUFF_SIZE + 1) * sizeof(char))) == NULL)
		return (NULL);
	while ((len_read = read(0, buff, BUFF_SIZE)) > 0)
	{
		buff[len_read] = '\0';
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

/*
** ssize_t read(int fd, void *buf, size_t count);
*/

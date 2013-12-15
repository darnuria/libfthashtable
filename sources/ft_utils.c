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
#include "ft_utils.h"

/*
** int
**
**
*/

/* Pourri recode la. */
*line	read_line(void)
{
	static char	*rest = NULL;
	ssize_t		ret;

	if (rest == NULL)
	{
		if ((rest = (char*) malloc(sizeof(char) * 1)) == NULL)
			return (-1);
	}
	if ((ret = ft_read(&ret)) == -1)
		return (-1);
	else if (ret == 0 && *rest == '\0')
		return (0);
	else
		return (ft_line(line, rest, ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviala <aviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 06:55:30 by aviala            #+#    #+#             */
/*   Updated: 2013/12/15 06:55:51 by aviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

#include "ft_string.h"
#include "hashtable.h"
#include "get_next_line.h"

static void	ft_search(t_ht	*hasht, char *line)

static int	ft_putstr(const char *s)
{
	return (write(0, s, ft_strlen(s)));
}

static int	hotrace(void)
{
	t_ht	*hasht;
	char	*line;
	char	*tmp;
	int		ret;
	int		searchMod = 0;
	size_t	i;

	line = NULL;
	tmp = NULL;
	i = 0;
	hasht = ft_ht_new(MAX_HASHTABLE);
	while ((ret = get_next_line(0, &line) > 0))
	{
		i++;
		if (*line == '\n' && i % 2)
			searchMod = 1;
		else if (searchMod == 0)
		{
			if (i % 2)
			{
				tmp = line;
				continue ;
			}
			else
				ft_ht_add_key(hasht, line, tmp);
		}
		else if (searchMod == 1)
		{
			if ((tmp = ft_ht_get(hasht, line, ft_strlen(line))) != NULL)
			{
				ft_putstr(tmp);
				write(1, "\n", 1);
			}
			else
			{
				ft_putstr(line);
				ft_putstr(": Not found.\n");
			}
		}
	}
	ft_ht_free(hasht);
	if (ret > -1)
		return (0);
	return (-1);
}

int			main(void)
{
	if (!hotrace())
		return (0);
	return (-1);
}

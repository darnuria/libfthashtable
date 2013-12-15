/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviala <aviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 06:30:29 by aviala            #+#    #+#             */
/*   Updated: 2013/12/15 06:30:30 by aviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# include <string.h>
# include "ft_types.h"

# define MAX_HASHTABLE 2048000000

typedef struct	s_ht_node
{
	char				*value;
	char				*key;
	size_t				len_key;
	struct s_ht_node	*next;
}				t_ht_node;

typedef struct	s_ht
{
	size_t				size;
	size_t				charge;
	size_t				collisions;
	struct s_ht_node	**table;
}				t_ht;

t_ht		*ft_ht_new(size_t size);
t_ht_node	*ft_ht_lookkey(t_ht *hash_table, char *value,
								size_t len_value, const t_uint32 hash);
int			ft_ht_add_key(t_ht *hash_table, char *value, char *key);
void		ft_ht_free(t_ht *hash_table);

#endif /* !HASHTABLE_H */

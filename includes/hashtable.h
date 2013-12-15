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

typedef struct	s_ht_node
{
	char				*key;
	char				*value;
	struct s_ht_node	*next;
}				t_ht_node;

typedef struct	s_ht
{
	size_t		size;
	s_ht_node	**table;
}				t_ht;

#endif /* !HASHTABLE_H */

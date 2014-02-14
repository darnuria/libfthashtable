/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_murmurhash.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviala <aviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 06:30:52 by aviala            #+#    #+#             */
/*   Updated: 2013/12/15 06:30:53 by aviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Reference : MurmurHash
** https://sites.google.com/site/murmurhash/
*/

#ifndef FT_MURMURHASH2_H
# define FT_MURMURHASH2_H

# include <stddef.h>

/*
** t_uint32 ft_murmurhash2(const char* key, size_t len, const t_uint32 seed)
** @param	key			: Key to hash.
** @param	len			: Lenght of the string to hash.
** @seed	seed		: Random seed used for one Hashtable.
** @return	t_uint32	: Fresh computed hash.
** 'm' and 'r' are mixing constants generated offline.
** They're not really 'magic', they just happen to work well.
*/

uint32_t	ft_murmurhash2(const char* key, int len, const uint32_t seed);

#endif /* !FT_MURMURHASH2_H */

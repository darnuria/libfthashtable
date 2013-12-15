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

# include <string.h>
# include "ft_types.h"

t_uint32	ft_murmurhash2(const char* key, size_t len, const t_uint32 seed);

#endif /* !FT_MURMURHASH2_H */

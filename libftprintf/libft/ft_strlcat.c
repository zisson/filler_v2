/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:52:48 by zsina             #+#    #+#             */
/*   Updated: 2014/11/10 15:25:48 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst_cpy;
	const char	*src_cpy;
	size_t		i;
	size_t		dlen;

	dst_cpy = dst;
	src_cpy = src;
	i = size;
	while (i-- != 0 && *dst_cpy != '\0')
		++dst_cpy;
	dlen = dst_cpy - dst;
	i = size - dlen;
	if (i == 0)
		return (dlen + ft_strlen(src_cpy));
	while (*src_cpy != '\0')
	{
		if (i != 1)
		{
			*dst_cpy++ = *src_cpy;
			--i;
		}
		++src_cpy;
	}
	*dst_cpy = '\0';
	return (dlen + (src_cpy - src));
}

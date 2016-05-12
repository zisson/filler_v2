/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:36:02 by zsina             #+#    #+#             */
/*   Updated: 2014/11/16 22:20:44 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*dst_cpy;
	unsigned char	*src_cpy;
	size_t			i;

	i = 0;
	dst_cpy = (char *)dst;
	src_cpy = (unsigned char *)src;
	if ((!dst) || (!src))
		return (NULL);
	while (i < n)
	{
		if (src_cpy[i] == (unsigned char)c)
		{
			dst_cpy[i] = src_cpy[i];
			return (&dst_cpy[i + 1]);
		}
		dst_cpy[i] = src_cpy[i];
		i++;
	}
	return (NULL);
}

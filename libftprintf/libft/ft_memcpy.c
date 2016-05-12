/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:49:06 by zsina             #+#    #+#             */
/*   Updated: 2014/11/20 16:32:24 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*dst_cpy;
	unsigned char	*src_cpy;
	size_t			i;

	i = 0;
	dst_cpy = (char *)dst;
	src_cpy = (unsigned char *)src;
	if ((!dst_cpy))
		return (NULL);
	if ((!src_cpy) || (!n))
		return (dst_cpy);
	while (i < n)
	{
		dst_cpy[i] = src_cpy[i];
		i++;
	}
	return (dst_cpy);
}

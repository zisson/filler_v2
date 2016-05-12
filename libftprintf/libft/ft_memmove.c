/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:42:15 by zsina             #+#    #+#             */
/*   Updated: 2014/11/21 14:32:07 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	char			*save;
	char			*dst_cpy;
	char			*src_cpy;
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	dst_cpy = (char *)dst;
	src_cpy = (char *)src;
	if (src == dst)
		return (dst);
	save = (char *)ft_memalloc(n + 1);
	ft_memcpy(save, src_cpy, n);
	while (i < n)
	{
		dst_cpy[i] = save[i];
		i++;
	}
	free(save);
	return (dst);
}

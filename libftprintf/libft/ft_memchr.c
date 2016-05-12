/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 13:59:38 by zsina             #+#    #+#             */
/*   Updated: 2014/11/21 13:59:44 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		index;

	index = 0;
	if (!s)
		return (NULL);
	while (index < n)
	{
		if (*((unsigned char *)s + index) == (unsigned char)c)
			return ((unsigned char *)s + index);
		index++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:04:11 by zsina             #+#    #+#             */
/*   Updated: 2014/11/15 19:11:18 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ptr;
	char	c_cpy;
	size_t	i;

	i = 0;
	c_cpy = (char)c;
	ptr = (char *)b;
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = (char)c_cpy;
		i++;
	}
	return (ptr);
}

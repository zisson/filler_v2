/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 14:44:17 by zsina             #+#    #+#             */
/*   Updated: 2014/11/19 14:44:22 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(dst);
	if ((!src) && (!dst))
		return (NULL);
	if (!src)
		return (dst);
	if (!dst)
		return (char *)src;
	while (src[i])
	{
		dst[len] = src[i];
		i++;
		len++;
	}
	dst[len] = '\0';
	return (dst);
}

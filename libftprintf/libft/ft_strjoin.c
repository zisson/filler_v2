/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 22:10:12 by zsina             #+#    #+#             */
/*   Updated: 2015/08/18 12:07:38 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*save;
	size_t	i;
	size_t	j;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	if (!s1 && !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	save = ft_memalloc(i + j + 1);
	if (!save)
		return (NULL);
	save = ft_strcat(ft_strdup((char *)s1), ft_strdup((char *)s2));
	return (save);
}

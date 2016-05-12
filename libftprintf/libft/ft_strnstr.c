/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:44:26 by zsina             #+#    #+#             */
/*   Updated: 2014/11/18 10:51:13 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str)
		return (NULL);
	if ((!to_find) || (!to_find[0]))
		return (char *)(str);
	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == to_find[0])
		{
			j = 1;
			while (to_find[j] && str[i + j] == to_find[j]
					&& ((i + j) <= n))
				j++;
			if (to_find[j] == '\0')
				return (char *)(&(str[i]));
		}
		i++;
	}
	return (NULL);
}

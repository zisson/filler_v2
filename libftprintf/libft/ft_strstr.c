/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:36:35 by zsina             #+#    #+#             */
/*   Updated: 2014/11/17 16:02:13 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	char	*str_cpy;
	char	*to_find_cpy;
	size_t	i;
	size_t	j;

	i = 0;
	str_cpy = (char *)str;
	to_find_cpy = (char *)to_find;
	if (!str_cpy)
		return (NULL);
	if ((!to_find_cpy) || (!to_find_cpy[0]))
		return (str_cpy);
	while (str_cpy[i])
	{
		if (str_cpy[i] == to_find[0])
		{
			j = 1;
			while (to_find_cpy[j] && str_cpy[i + j] == to_find_cpy[j])
				j++;
			if (!to_find_cpy[j])
				return (&(str_cpy[i]));
		}
		i++;
	}
	return (NULL);
}

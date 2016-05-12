/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 11:21:53 by zsina             #+#    #+#             */
/*   Updated: 2015/11/12 11:21:55 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = ft_memalloc(n + 1);
	if (str)
	{
		ft_memcpy(str, s, n);
		*(str + n) = 0;
	}
	return (str);
}

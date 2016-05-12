/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:59:31 by zsina             #+#    #+#             */
/*   Updated: 2014/11/06 12:30:48 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char *tmp;

	tmp = s1;
	while (n > 0 && *s2 != '\0')
	{
		*tmp++ = *s2++;
		--n;
	}
	while (n > 0)
	{
		*tmp++ = '\0';
		--n;
	}
	return (s1);
}

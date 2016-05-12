/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:56:12 by zsina             #+#    #+#             */
/*   Updated: 2014/11/10 15:33:58 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *cp, int ch)
{
	char	*save;
	size_t	c;

	c = ft_strlen(cp);
	save = (char *)cp;
	if (!ch)
		return (&save[c]);
	while (c--)
	{
		if (save[c] == ch)
			return (&(save[c]));
	}
	return (NULL);
}

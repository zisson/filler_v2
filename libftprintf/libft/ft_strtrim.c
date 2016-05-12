/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 11:18:40 by zsina             #+#    #+#             */
/*   Updated: 2015/11/12 11:18:53 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int				ft_isspace(char c)
{
	return ((c == ' ' || c == '\t' || c == '\n'));
}

static const char		*check_end(const char *str)
{
	str = str + ft_strlen(str);
	while (ft_isspace(*(str - 1)))
		str--;
	return (str);
}

char					*ft_strtrim(const char *s)
{
	char		*str;
	const char	*end;
	const char	*begin;

	if (s == NULL)
		return (NULL);
	begin = s;
	while (ft_isspace(*begin))
		begin++;
	end = check_end(s);
	str = ft_strsub(begin, 0, (size_t)(end - begin));
	if (str == NULL)
	{
		str = (char *)malloc(1);
		str[0] = '\0';
	}
	return (str);
}

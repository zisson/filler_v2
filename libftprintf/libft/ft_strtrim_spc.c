/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_spc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 11:20:03 by zsina             #+#    #+#             */
/*   Updated: 2015/11/12 11:21:03 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim_spc(char const *s)
{
	int i;
	int j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	if (!s)
		return (NULL);
	while (ft_ispace(*(s + i)))
		i++;
	while (ft_ispace(*(s + j - 1)))
		j--;
	return (ft_strsub(s, i, (j != 0) ? j -= i : j));
}

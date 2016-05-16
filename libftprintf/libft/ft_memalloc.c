/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:32:42 by zsina             #+#    #+#             */
/*   Updated: 2014/12/15 15:50:52 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*value;

	if (!size)
		return (0);
	value = malloc(sizeof(void *) * size + 1);
	if (!value)
		return (void *)0;
	ft_bzero(value, size + 1);
	return (value);
}

void	*ft_memrealloc(void *s, size_t old_n, size_t new_n)
{
	t_uchar	*tmp;

	if (!new_n || old_n == new_n)
		return (s);
	if ((tmp = (t_uchar*)ft_memalloc(new_n * sizeof(t_uchar))))
	{
		old_n = (size_t)FT_MIN(old_n, new_n);
		ft_memcpy(tmp, s, old_n);
		if (s)
			free(s);
		s = tmp;
	}
	return (tmp);
}

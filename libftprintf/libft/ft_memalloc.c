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

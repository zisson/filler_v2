/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:15:48 by zsina             #+#    #+#             */
/*   Updated: 2016/04/07 12:20:20 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>
#include <errno.h>

void		*ft_xmalloc(size_t n)
{
	void	*p;

	p = malloc(n);
	if (!p)
	{
		ft_err(1, errno, "malloc(%d)", n);
		exit(EXIT_FAILURE);
	}
	return (p);
}

void		*ft_xrealloc(void *ptr, size_t n, size_t old)
{
	void	*p;

	if (old >= n)
		return (ptr);
	p = ft_xmalloc(n);
	ft_memcpy(p, ptr, old);
	ft_memset((char *)p + old, 0, n - old);
	free(ptr);
	return (p);
}

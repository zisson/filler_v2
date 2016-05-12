/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:43:19 by zsina             #+#    #+#             */
/*   Updated: 2015/11/25 11:50:36 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/list.h"
#include "includes/libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (node)
	{
		node->content = NULL;
		node->content_size = 0;
		node->next = NULL;
		if (content && content_size)
		{
			node->content_size = content_size;
			if (!(node->content = (void *)malloc(sizeof(content_size))))
				return (NULL);
			node->content = ft_memcpy(node->content, content, content_size);
		}
	}
	return (node);
}

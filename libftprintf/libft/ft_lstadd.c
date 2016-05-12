/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 11:25:25 by zsina             #+#    #+#             */
/*   Updated: 2015/11/25 11:34:41 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/list.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	if (!tmp)
		*alst = new;
	else
	{
		new->next = tmp;
		*alst = new;
	}
}

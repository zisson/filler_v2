/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 12:12:01 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 11:55:20 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_log(intmax_t n, int base)
{
	int	size;

	if (!n)
		return (1);
	size = 0;
	while (n)
	{
		n /= base;
		size++;
	}
	return (size);
}

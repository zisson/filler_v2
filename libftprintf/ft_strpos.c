/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_strpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 12:15:12 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 10:48:36 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_strpos(const char *str, char c)
{
	const char	*orig;

	orig = str;
	while (*str)
	{
		if (*str == c)
			return (str - orig);
		str++;
	}
	return (str - orig);
}

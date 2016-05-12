/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:39:16 by zsina             #+#    #+#             */
/*   Updated: 2014/11/18 11:15:39 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_nospace(const char *str)
{
	int	i;

	i = 0;
	while (ft_ispace(str[i]) || str[i] == '\r' || str[i] == '\f')
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	int	i;
	int	value;
	int	neg;

	i = ft_nospace(str);
	value = 0;
	neg = 0;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		value = value * 10;
		value += str[i] - '0';
		i++;
	}
	if (neg == 1)
		return (-value);
	return (value);
}

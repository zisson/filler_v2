/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolli.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 11:07:15 by zsina             #+#    #+#             */
/*   Updated: 2016/05/02 11:09:24 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long long int	ft_atolli(const char *str)
{
	int				signe;
	long long int	r;

	signe = 1;
	while ((*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f' ||
			*str == '\r' || *str == '\v') && *str != '\0')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	r = 0;
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10;
		r = r + ((int)*str - 48);
		str++;
	}
	return (r * signe);
}

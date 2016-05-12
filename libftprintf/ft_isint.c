/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 11:10:22 by zsina             #+#    #+#             */
/*   Updated: 2016/05/02 11:10:44 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_isint(char *s)
{
	long long int		lli;
	static const int	int_max = 2147483647;
	static const int	int_min = -2147483648;

	if (!ft_isnumber(s))
		return (0);
	if (ft_strlen(s) > 11)
		return (0);
	lli = ft_atolli(s);
	if (lli >= int_min && lli <= int_max)
		return (1);
	return (0);
}

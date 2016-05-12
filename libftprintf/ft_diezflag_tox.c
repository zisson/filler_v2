/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diezflag_tox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:40:58 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 11:52:39 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_managediez_tox(t_pfdata *data, const char *base, ssize_t outputlen,
		int strsize)
{
	if (data->prec == NO_PREC)
	{
		if (data->width != 0)
			data->width -= ft_strlen(base);
		else
			outputlen = strsize;
	}
	else if (data->prec != NO_PREC)
	{
		if (data->prec == 0)
			ft_swap(&data->prec, &data->width);
		else if (data->prec != 0)
		{
			if (data->prec < strsize)
				data->width -= ft_strlen(base);
			else
			{
				data->width -= ft_strlen(base);
				outputlen = data->prec;
			}
		}
	}
	return (outputlen);
}

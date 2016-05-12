/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diezflag_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:39:35 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 11:48:08 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_helper(t_pfdata *data, ssize_t outputlen)
{
	ft_swap(&data->prec, &data->width);
	data->prec = outputlen;
}

size_t			ft_managediez_top(t_pfdata *data, const char *base,
		ssize_t outputlen, int strsize)
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
			ft_helper(data, outputlen);
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

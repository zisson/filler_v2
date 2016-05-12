/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diezflag_tos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:40:10 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 11:49:47 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t	ft_diezhelp_tosprecnull(t_pfdata *data, size_t outputlen,
		const char *base, int strsize)
{
	if (data->width != 0)
	{
		if (data->type == 'S' && outputlen == 4)
			return (outputlen - 1);
		data->width -= ft_strlen(base);
	}
	else
		outputlen = strsize;
	return (outputlen);
}

static size_t	ft_diezhelp_tosprecval(t_pfdata *data, size_t outputlen,
		const char *base, int strsize)
{
	if (data->prec == 0)
	{
		ft_swap(&data->prec, &data->width);
		data->prec = outputlen;
	}
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
	return (outputlen);
}

size_t			ft_managediez_tos(t_pfdata *data, const char *base,
		ssize_t outputlen, int strsize)
{
	if (data->prec == NO_PREC)
		outputlen = ft_diezhelp_tosprecnull(data, outputlen, base, strsize);
	else if (data->prec != NO_PREC)
		outputlen = ft_diezhelp_tosprecval(data, outputlen, base, strsize);
	return (outputlen);
}

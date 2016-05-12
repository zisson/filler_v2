/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diezflag_too.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:38:59 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 11:40:25 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t	ft_diezhelp_tooprecnull(t_pfdata *data, size_t outputlen,
		const char *base, int strsize)
{
	if (data->width != 0)
		data->width -= ft_strlen(base);
	else
		outputlen = strsize;
	return (outputlen);
}

static size_t	ft_diezhelp_tooprecval(t_pfdata *data, size_t outputlen,
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
			data->prec -= ft_strlen(base);
		}
	}
	return (outputlen);
}

size_t			ft_managediez_too(t_pfdata *data, const char *base,
		ssize_t outputlen, int strsize)
{
	if (data->prec == NO_PREC)
		outputlen = ft_diezhelp_tooprecnull(data, outputlen, base, strsize);
	else if (data->prec != NO_PREC)
		outputlen = ft_diezhelp_tooprecval(data, outputlen, base, strsize);
	return (outputlen);
}

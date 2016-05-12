/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precisionwidth_tox.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:57:18 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 12:00:23 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t	ft_prec_wid(t_pfdata *data, int strsize, size_t outputlen)
{
	if (data->prec >= data->width)
	{
		if (data->prec < strsize)
			outputlen = data->prec;
	}
	if (data->prec < data->width)
	{
		if (data->prec >= strsize)
		{
			data->prec -= 1;
			data->width += 1;
		}
		if (data->prec < strsize)
			outputlen = data->prec;
	}
	return (outputlen);
}

size_t			ft_managx_precwid(ssize_t outputlen, int strsize,
		t_pfdata *data)
{
	if (data->prec == NO_PREC)
	{
		if (data->width == 0)
			outputlen = strsize;
	}
	if (data->prec == 0)
		outputlen = ft_prec_wid(data, strsize, outputlen);
	else
	{
		if (data->width < data->prec)
		{
			if (data->prec < strsize)
				return (outputlen);
		}
		else if (data->width >= data->prec)
		{
			if (data->prec < strsize)
				return (outputlen);
		}
	}
	return (outputlen);
}

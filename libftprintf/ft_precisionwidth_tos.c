/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precisionwidth_tos.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:57:02 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 11:59:45 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	size_t	ft_uppers_prec(t_pfdata *data, size_t outputlen)
{
	if (data->prec == 4 && data->type == 'S')
	{
		outputlen = data->prec - 1;
		data->prec = outputlen;
	}
	return (outputlen);
}

static size_t	ft_prec_wid(t_pfdata *data, int strsize, size_t outputlen)
{
	if (data->prec >= data->width)
	{
		if (data->prec >= strsize)
		{
			outputlen = strsize;
			data->prec = strsize;
		}
		if (data->prec < strsize)
			outputlen = ft_uppers_prec(data, outputlen);
		outputlen = data->prec;
	}
	if (data->prec < data->width)
	{
		if (data->prec >= strsize)
		{
			data->prec = strsize;
			outputlen = strsize;
		}
		if (data->prec < strsize)
			outputlen = ft_uppers_prec(data, outputlen);
		outputlen = data->prec;
	}
	return (outputlen);
}

static size_t	ft_zeroprec(t_pfdata *data, size_t outputlen)
{
	if (data->prec == data->width)
		outputlen = data->prec;
	if (data->width != data->prec)
		outputlen = ft_uppers_prec(data, outputlen);
	outputlen = 0;
	return (outputlen);
}

static size_t	ft_oneprec(t_pfdata *data, size_t outputlen, int strsize)
{
	if (data->prec >= data->width)
	{
		if (data->prec < strsize)
			outputlen = ft_uppers_prec(data, outputlen);
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

size_t			ft_managstr_precwid(ssize_t outputlen, int strsize,
		t_pfdata *data)
{
	if (data->prec == 0)
		outputlen = ft_zeroprec(data, outputlen);
	if (data->prec == 1)
		outputlen = ft_oneprec(data, outputlen, strsize);
	if (data->prec != NO_PREC && data->prec != 0 && data->prec != 1)
		outputlen = ft_prec_wid(data, strsize, outputlen);
	return (outputlen);
}

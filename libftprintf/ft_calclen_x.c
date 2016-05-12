/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calclen_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:38:08 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 11:35:47 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t	ft_zeroflag(t_pfdata *data, ssize_t ouputlen)
{
	if (data->prec == NO_PREC)
		ft_swap(&data->prec, &data->width);
	else if (data->prec != NO_PREC)
	{
		if (data->prec == 0)
		{
			ft_swap(&data->prec, &data->width);
			data->prec = ouputlen;
		}
		else if (data->prec != 0)
			ouputlen = data->prec;
	}
	return (ouputlen);
}

size_t			ft_calclen_x(int sign, int strsize, t_pfdata *data,
		const char *base)
{
	ssize_t		outputlen;

	outputlen = MAX(data->prec, strsize);
	if (sign < 0 || ((data->flag & PLUSFLAG || data->flag & SPACEFLAG)
				&& sign > 0))
	{
		outputlen++;
		strsize++;
	}
	if (data->flag)
	{
		if (data->flag & DIESEFLAG)
			outputlen = ft_managediez_tox(data, base, outputlen, strsize);
		if (data->flag & ZEROFLAG || data->flag & SPACEFLAG)
			outputlen = ft_zeroflag(data, outputlen);
	}
	else
		outputlen = ft_managx_precwid(outputlen, strsize, data);
	return (outputlen);
}

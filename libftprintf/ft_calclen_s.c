/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calclen_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 10:41:01 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 11:32:38 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t	ft_zeroflag(t_pfdata *data, ssize_t ouputlen)
{
	if (data->prec == NO_PREC)
		ft_swap(&data->prec, &data->width);
	else
	{
		if (data->prec == 0)
		{
			ft_swap(&data->prec, &data->width);
			ouputlen = data->width;
		}
		else if (data->prec != 0)
			ouputlen = data->prec;
	}
	return (ouputlen);
}

size_t			ft_calclen_s(int sign, int strsize, t_pfdata *data,
		const char *base)
{
	ssize_t		ouputlen;

	ouputlen = MAX(data->prec, strsize);
	if (sign < 0 || ((data->flag & PLUSFLAG || data->flag & SPACEFLAG)
				&& sign > 0))
	{
		ouputlen++;
		strsize++;
	}
	if (data->flag & DIESEFLAG)
		ouputlen = ft_managediez_tos(data, base, ouputlen, sign);
	if (data->flag & ZEROFLAG || data->flag & SPACEFLAG)
		ouputlen = ft_zeroflag(data, ouputlen);
	else
		ouputlen = ft_managstr_precwid(ouputlen, strsize, data);
	return (ouputlen);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calclen_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:36:31 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 10:40:16 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t		ft_zeroflag(t_pfdata *data, int sign, ssize_t outputlen)
{
	if (data->prec == NO_PREC)
	{
		ft_swap(&data->prec, &data->width);
		if (sign < 0 || ((data->flag & PLUSFLAG || data->flag & SPACEFLAG)
					&& sign >= 0))
			data->prec -= 1;
	}
	return (outputlen);
}

size_t				ft_calclen_di(int sign, int strsize, t_pfdata *data,
		const char *base)
{
	ssize_t			ouputlen;

	ouputlen = MAX(data->prec, strsize);
	if (sign < 0 || ((data->flag & PLUSFLAG || data->flag & SPACEFLAG)
				&& sign > 0))
	{
		ouputlen++;
		strsize++;
	}
	if (data->flag & DIESEFLAG)
		ouputlen = ft_managediez_todi(data, base, ouputlen, sign);
	if (data->flag & ZEROFLAG || data->flag & SPACEFLAG)
		ouputlen = ft_zeroflag(data, sign, ouputlen);
	else
		ouputlen = ft_managdi_precwid(ouputlen, strsize, data);
	return (ouputlen);
}

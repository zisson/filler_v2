/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precisionwidth_top.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:46:02 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 11:58:49 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t		ft_managp_precwid(ssize_t ouputlen, int strsize,
		t_pfdata *data)
{
	if (data->prec == NO_PREC)
	{
		if (data->width != 0)
			data->prec = strsize;
		else
			ouputlen = strsize;
	}
	else
	{
		if (data->width < data->prec)
		{
			if (data->prec < strsize)
				return (ouputlen);
		}
		else if (data->width >= data->prec)
		{
			if (data->prec < strsize)
				return (ouputlen);
		}
	}
	return (ouputlen);
}

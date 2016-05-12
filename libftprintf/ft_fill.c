/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 12:10:55 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 11:53:36 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t		ft_fillspc(int st, t_pfdata *data, int len)
{
	size_t	bytes;

	bytes = 0;
	if ((!st && (data->flag & MINUSFLAG))
			|| (st && !(data->flag & MINUSFLAG)))
	{
		bytes += ft_putnchar_fd(' ', ft_abszero(data->width - len),
				data->fd);
	}
	return (bytes);
}

size_t		ft_fillzero(t_pfdata *data, int logn)
{
	size_t	bytes;

	bytes = 0;
	bytes += ft_putnchar_fd('0', ft_abszero(data->prec - logn), data->fd);
	return (bytes);
}

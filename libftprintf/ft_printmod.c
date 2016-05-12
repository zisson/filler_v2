/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:59:13 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 12:04:37 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t		ft_printmod(t_pfdata *data)
{
	size_t		bytes;
	ssize_t		len;

	bytes = 0;
	len = (data->prec > 0 ? data->prec : 1);
	if (data->flag & ZEROFLAG)
	{
		if (data->prec == 0 && data->prec < data->width)
			ft_swap(&data->prec, &data->width);
	}
	bytes += ft_fillspc(1, data, len);
	bytes += ft_fillzero(data, len);
	bytes += ft_putchar_fd(data->type, data->fd);
	bytes += ft_fillspc(0, data, len);
	return (bytes);
}

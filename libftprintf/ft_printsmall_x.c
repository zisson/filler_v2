/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printsmall_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 10:01:12 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 12:43:47 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t		ft_upxo_gen(t_pfdata *data, const char *pre, const char *base)
{
	size_t			bytes;
	uintmax_t		n;
	ssize_t			len;
	int				ndigit;

	bytes = 0;
	n = ft_getarg_oux(data);
	ndigit = ft_log(n, ft_strlen(base));
	len = ft_calclen_o(1, ndigit, data, pre);
	bytes += ft_fillspc(1, data, len);
	if (data->flag & DIESEFLAG && n != 0)
		bytes += ft_putstr_fd(pre, data->fd);
	if (!n && data->prec == 0 && data->width == 0)
		return (ft_putstr_fd("", data->fd));
	bytes += ft_fillzero(data, ndigit);
	bytes += ft_putuintmax_fd(base, n, data->fd);
	bytes += ft_fillspc(0, data, len);
	return (bytes);
}

size_t		ft_x_gen(t_pfdata *data, const char *pre, const char *base)
{
	size_t			bytes;
	uintmax_t		n;
	ssize_t			len;
	int				ndigit;

	bytes = 0;
	n = ft_getarg_oux(data);
	ndigit = ft_log(n, ft_strlen(base));
	len = ft_calclen_x(1, ndigit, data, pre);
	bytes += ft_fillspc(1, data, len);
	if (data->flag & DIESEFLAG && n != 0)
		bytes += ft_putstr_fd(pre, data->fd);
	bytes += ft_fillzero(data, ndigit);
	if (!n && data->prec == 0)
		ft_putstr_fd("", data->fd);
	else
		bytes += ft_putuintmax_fd(base, n, data->fd);
	bytes += ft_fillspc(0, data, len);
	return (bytes);
}

size_t		ft_printsmall_x(t_pfdata *data)
{
	return (ft_x_gen(data, "0x", "0123456789abcdef"));
}

size_t		ft_printupper_x(t_pfdata *data)
{
	return (ft_upxo_gen(data, "0X", "0123456789ABCDEF"));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:59:30 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 12:06:24 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		*ft_getadr(t_pfdata *data)
{
	void	*p;

	p = va_arg(data->ap, void *);
	return (p);
}

size_t		ft_p_gen(t_pfdata *data, const char *pre, const char *base)
{
	size_t			bytes;
	uintmax_t		n;
	ssize_t			len;
	int				ndigit;

	bytes = 0;
	n = (uintmax_t)ft_getadr(data);
	ndigit = ft_log(n, ft_strlen(base));
	len = ft_calclen_p(n, ndigit, data, pre);
	bytes += ft_fillspc(1, data, len);
	bytes += ft_putstr_fd(pre, data->fd);
	if (!n && data->prec == 1 && data->width == 0)
		return (bytes);
	bytes += ft_fillzero(data, ndigit);
	bytes += ft_putuintmax_fd(base, n, data->fd);
	bytes += ft_fillspc(0, data, len);
	return (bytes);
}

size_t		ft_printp(t_pfdata *data)
{
	data->flag |= DIESEFLAG;
	return (ft_p_gen(data, "0x", "0123456789abcdef"));
}

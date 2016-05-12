/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printsmall_o.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 10:00:22 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 12:24:19 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>

static int	ft_usignechar(int n)
{
	if (n > USHRT_MAX)
		n = n - 32768;
	return (n);
}

size_t		ft_gensmall_o(t_pfdata *data, const char *pre, const char *base)
{
	size_t			bytes;
	uintmax_t		n;
	ssize_t			len;
	int				ndigit;

	bytes = 0;
	n = ft_getarg_oux(data);
	ndigit = ft_log(n, ft_strlen(base));
	len = ft_calclen_o(1, ndigit, data, pre);
	if (data->len[1] == 'h')
		n = ft_usignechar(n);
	bytes += ft_fillspc(1, data, len);
	if (data->flag & DIESEFLAG && n != 0)
		bytes += ft_putstr_fd(pre, data->fd);
	if (!n && data->prec == 0)
		return (bytes);
	bytes += ft_fillzero(data, ndigit);
	bytes += ft_putuintmax_fd(base, n, data->fd);
	bytes += ft_fillspc(0, data, len);
	return (bytes);
}

size_t		ft_oupper_gen(t_pfdata *data, const char *pre, const char *base)
{
	size_t				bytes;
	long long int		n;
	ssize_t				len;
	int					ndigit;

	bytes = 0;
	n = va_arg(data->ap, long long int);
	ndigit = ft_log(n, ft_strlen(base));
	len = ft_calclen_o(1, ndigit, data, pre);
	bytes += ft_fillspc(1, data, len);
	if (data->flag & DIESEFLAG && n != 0)
		bytes += ft_putstr_fd(pre, data->fd);
	bytes += ft_fillzero(data, ndigit);
	if (!n && data->prec == 0)
		return (ft_putstr_fd("", data->fd));
	bytes += ft_putnbrl_fd(base, n, data->fd);
	bytes += ft_fillspc(0, data, len);
	return (bytes);
}

size_t		ft_printsmall_o(t_pfdata *data)
{
	return (ft_gensmall_o(data, "0", "01234567"));
}

size_t		ft_printupper_o(t_pfdata *data)
{
	return (ft_oupper_gen(data, "0", "01234567"));
}

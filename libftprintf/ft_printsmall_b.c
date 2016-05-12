/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_print_prime.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:58:10 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 12:09:29 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned long long int	ft_getargb(t_pfdata *data)
{
	uintmax_t	n;

	if (data->len[0] == 'l')
		n = (unsigned long int)va_arg(data->ap, void *);
	else if (data->len[1] == 'l')
		n = (unsigned long long int)va_arg(data->ap, void *);
	else if (data->len[0] == 'h' && data->len[1] != 'h')
		n = (unsigned short int)va_arg(data->ap, void *);
	else if (data->len[1] == 'h' && data->len[0] == 'h')
		n = (unsigned char)va_arg(data->ap, void *);
	else if (data->len[0] == 'j')
		n = (uintmax_t)va_arg(data->ap, void *);
	else if (data->len[0] == 'z')
		n = (size_t)va_arg(data->ap, void *);
	else
		n = (unsigned int)va_arg(data->ap, void *);
	return (n);
}

size_t					ft_b_gen(t_pfdata *data, const char *pre,
		const char *base)
{
	size_t			bytes;
	uintmax_t		n;
	ssize_t			len;
	int				ndigit;

	bytes = 0;
	n = ft_getargb(data);
	if (!n)
		data->flag &= ~DIESEFLAG;
	if (!n)
	{
		if (data->flag & DIESEFLAG)
			return (ft_putstr_fd(pre, data->fd));
		else if (data->prec == 0 && data->width == 0)
			return (ft_putstr_fd("", data->fd));
	}
	ndigit = ft_log(n, ft_strlen(base));
	len = ft_calclen_di(n, ndigit, data, pre);
	bytes += ft_fillspc(1, data, len);
	if (data->flag & DIESEFLAG)
		bytes += ft_putstr_fd(pre, data->fd);
	bytes += ft_fillzero(data, ndigit);
	bytes += ft_putuintmax_fd(base, n, data->fd);
	bytes += ft_fillspc(0, data, len);
	return (bytes);
}

size_t					ft_printsmall_b(t_pfdata *data)
{
	return (ft_b_gen(data, "", "01"));
}

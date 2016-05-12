/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printsmall_di.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 10:00:05 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 12:21:14 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long long int		ft_getargdi(t_pfdata *data)
{
	long long int		n;

	if (data->len[0] == 'l')
		n = (long int)va_arg(data->ap, void *);
	else if (data->len[1] == 'l')
		n = (long long int)va_arg(data->ap, void *);
	else if (data->len[0] == 'h' && data->len[1] != 'h')
		n = (short int)va_arg(data->ap, void *);
	else if (data->len[1] == 'h' && data->len[0] == 'h')
		n = (signed char)va_arg(data->ap, void *);
	else if (data->len[0] == 'j')
		n = (intmax_t)va_arg(data->ap, void *);
	else if (data->len[0] == 'z')
		n = (size_t)va_arg(data->ap, void *);
	else
		n = (int)va_arg(data->ap, void *);
	return (n);
}

static int			ft_signechar(int n)
{
	if (n < SCHAR_MIN)
		n = n + 256;
	if (n > SCHAR_MAX)
		n = n - 256;
	return (n);
}

static long long	ft_helper(t_pfdata *data, long long n)
{
	if (data->len[1] == 'h')
		n = ft_signechar(n);
	return (n);
}

size_t				ft_printsmall_di(t_pfdata *data)
{
	size_t		bytes;
	long long	n;
	ssize_t		len;
	int			nbdigit;
	char		*pre;

	pre = "";
	bytes = 0;
	n = ft_getargdi(data);
	nbdigit = ft_log(n, 10);
	len = ft_calclen_di(n, nbdigit, data, pre);
	n = ft_helper(data, n);
	bytes += ft_fillspc(1, data, len);
	if (n < 0)
		bytes += ft_putchar_fd('-', data->fd);
	if (data->flag & PLUSFLAG && n >= 0)
		bytes += ft_putchar_fd('+', data->fd);
	if (data->flag & SPACEFLAG && n >= 0)
		bytes += ft_putchar_fd(' ', data->fd);
	bytes += ft_fillzero(data, nbdigit);
	if (!n && data->prec == 0)
		return (bytes);
	bytes += ft_putnbrl_fd("0123456789", n, data->fd);
	bytes += ft_fillspc(0, data, len);
	return (bytes);
}

size_t				ft_printupper_d(t_pfdata *data)
{
	size_t			bytes;
	long long int	n;
	ssize_t			len;
	int				nbdigit;
	char			*pre;

	pre = "";
	bytes = 0;
	n = va_arg(data->ap, long long int);
	nbdigit = ft_log(n, 10);
	len = ft_calclen_di(n, nbdigit, data, pre);
	bytes += ft_fillspc(1, data, len);
	if (n < 0)
		bytes += ft_putchar_fd('-', data->fd);
	if (data->flag & PLUSFLAG && n >= 0)
		bytes += ft_putchar_fd('+', data->fd);
	if (data->flag & SPACEFLAG && n >= 0)
		bytes += ft_putchar_fd(' ', data->fd);
	bytes += ft_fillzero(data, nbdigit);
	bytes += ft_putnbrl_fd("0123456789", n, data->fd);
	bytes += ft_fillspc(0, data, len);
	return (bytes);
}

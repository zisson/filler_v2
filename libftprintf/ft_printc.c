/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 10:45:58 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 12:18:23 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <wchar.h>

wint_t		ft_getargc(t_pfdata *data)
{
	wint_t		c;

	if (data->len[0] == 'l')
		c = va_arg(data->ap, wint_t);
	else
		c = va_arg(data->ap, int);
	return (c);
}

size_t		ft_printsmaller_c(t_pfdata *data)
{
	wint_t		caract;
	ssize_t		len;
	size_t		bytes;
	const char	*pre;

	pre = "";
	bytes = 0;
	caract = va_arg(data->ap, wint_t);
	data->val = (int*)&caract;
	if (!caract)
		bytes++;
	len = ft_calclen_upocu((int)caract, 1, data, pre);
	bytes += ft_fillspc(1, data, len);
	bytes += ft_fillzero(data, len);
	if (data->len[0] == 'l')
		bytes += ft_putstr_fd(ft_putwchar(caract), data->fd);
	else
		bytes += ft_putchar_fd(caract, data->fd);
	bytes += ft_fillspc(0, data, len);
	return (bytes);
}

size_t		ft_printupper_c(t_pfdata *data)
{
	wint_t		specar;
	ssize_t		len;
	size_t		bytes;
	const char	*pre;
	char		*tmp;

	pre = "";
	bytes = 0;
	specar = va_arg(data->ap, wint_t);
	data->val = &specar;
	if (!specar)
		bytes++;
	if (!specar && data->len[0] == 'h')
		bytes *= 2;
	tmp = ft_putwchar(specar);
	len = ft_calclen_upocu(1, 4, data, pre);
	bytes += ft_fillspc(1, data, len);
	bytes += ft_fillzero(data, len);
	if (data->len[1] == 'h' || data->len[0] == 'h')
		bytes += 1;
	else
		bytes += ft_putstr_fd(tmp, data->fd);
	bytes += ft_fillspc(0, data, len);
	return (bytes);
}

size_t		ft_printn(t_pfdata *data)
{
	int		*n;

	n = va_arg(data->ap, int *);
	*n = data->bytes;
	return (0);
}

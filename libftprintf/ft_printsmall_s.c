/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printsmall_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 10:00:44 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 12:41:09 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <wchar.h>

size_t			ft_printsmall_s(t_pfdata *data)
{
	size_t		bytes;
	ssize_t		len;
	char		*str;
	int			i;

	i = 0;
	bytes = 0;
	if (data->len[0] == 'l')
		return (ft_printupper_s(data));
	str = va_arg(data->ap, char *);
	data->val = (int*)str;
	if (!str && data->width == 0 && data->prec == -1)
		return (ft_putstr_fd("(null)", data->fd));
	len = ft_calclen_s(1, ft_strlen(str), data, PRE);
	bytes += ft_fillspc(1, data, len);
	bytes += ft_fillzero(data, ft_strlen(str));
	while (i < len && *str)
	{
		bytes += ft_putchar_fd(*str, data->fd);
		i++;
		str++;
	}
	bytes += ft_fillspc(0, data, len);
	return (bytes);
}

char			*ft_putwchar(wchar_t wide)
{
	char	str[5];

	ft_bzero(str, 5);
	if (wide < 128)
		str[0] = (char)wide;
	else if (wide < 2048)
	{
		str[0] = (wide >> 6) + 192;
		str[1] = (wide & 63) + 128;
	}
	else if (wide < 65536)
	{
		str[0] = (wide >> 12) + 224;
		str[1] = ((wide >> 6) & 63) + 128;
		str[2] = (wide & 63) + 128;
	}
	else if (wide < 1114112)
	{
		str[0] = (wide >> 18) + 240;
		str[1] = ((wide >> 12) & 63) + 128;
		str[2] = ((wide >> 6) & 63) + 128;
		str[3] = (wide & 63) + 128;
	}
	return (ft_strdup(str));
}

char			*ft_putwstr(wchar_t *src)
{
	char	*str;
	char	*ante;
	char	*post;

	if (!(str = ft_strnew(0)))
		return (NULL);
	while (*src)
	{
		ante = str;
		if (!(post = ft_putwchar(*src)))
			return (NULL);
		if (!(str = ft_strjoin(ante, post)))
			return (NULL);
		src++;
		ft_strdel(&ante);
		ft_strdel(&post);
	}
	return (str);
}

size_t			ft_printupper_s(t_pfdata *data)
{
	size_t		bytes;
	wchar_t		*wc;
	ssize_t		len;
	char		*str;
	int			i;

	i = 0;
	bytes = 0;
	wc = va_arg(data->ap, wchar_t *);
	if (!wc)
		return (ft_putstr_fd("(null)", data->fd));
	str = ft_putwstr(wc);
	len = ft_calclen_s(1, ft_strlen(str), data, PRE);
	bytes += ft_fillspc(1, data, len);
	bytes += ft_fillzero(data, len);
	while (i < len && *str)
	{
		bytes += ft_putchar_fd(*str, data->fd);
		i++;
		str++;
	}
	bytes += ft_fillspc(0, data, len);
	return (bytes);
}

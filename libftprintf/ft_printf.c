/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:58:58 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 12:04:20 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static const char		*ft_getflag(const char *p, int *flag)
{
	char				*q;

	*flag = 0;
	while ((q = ft_strchr(PRINTF_FLAGS, *p)) != NULL)
	{
		*flag |= (1 << (q - PRINTF_FLAGS));
		p++;
	}
	if (*flag & MINUSFLAG)
		*flag &= ~ZEROFLAG;
	if (*flag & PLUSFLAG)
		*flag &= ~SPACEFLAG;
	return (p);
}

const char				*ft_getarg(const char *p, t_pfdata *data)
{
	p = ft_getflag(p, &data->flag);
	data->width = ft_abszero(ft_strtol(p, &p, 10));
	if (*p == '.')
	{
		p++;
		data->prec = ft_abszero(ft_strtol(p, &p, 10));
	}
	else
		data->prec = NO_PREC;
	ft_memset(data->len, 0, 3);
	if (*p == 'h' || *p == 'l')
		data->len[0] = *p++;
	if (*p == 'h' || *p == 'l')
		data->len[1] = *p++;
	if (*p == 'z' || *p == 'j')
		data->len[0] = *p++;
	data->type = *p++;
	return (p);
}

int						ft_printf(char *fmt, ...)
{
	va_list		ap;
	size_t		bytes;

	va_start(ap, fmt);
	bytes = ft_vfdprintf(STDOUT_FILENO, fmt, ap);
	va_end(ap);
	return (bytes);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getargsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:42:42 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 11:54:43 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

uintmax_t		ft_getarg_oux(t_pfdata *data)
{
	uintmax_t		n;

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

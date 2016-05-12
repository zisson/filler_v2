/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:21:19 by zsina             #+#    #+#             */
/*   Updated: 2016/04/07 12:39:29 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_fdprintf(const int fd, const char *fmt, ...)
{
	va_list	ap;
	size_t	bytes;

	va_start(ap, fmt);
	bytes = ft_vfdprintf(fd, fmt, ap);
	va_end(ap);
	return (bytes);
}

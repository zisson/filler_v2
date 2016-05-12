/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:20:26 by zsina             #+#    #+#             */
/*   Updated: 2016/04/07 13:00:39 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

static void	ft_verr(int status, int errnum, const char *format, va_list ap)
{
	char	*s;

	s = strerror(errnum);
	if (!s)
		s = "Unknown error";
	ft_vfdprintf(STDERR_FILENO, format, ap);
	if (errnum)
		ft_fdprintf(STDERR_FILENO, ": %s\n", s);
	else
		ft_fdprintf(STDERR_FILENO, "\n");
	fsync(STDOUT_FILENO);
	fsync(STDERR_FILENO);
	exit(status);
}

void		ft_err(int status, int errnum, const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	ft_verr(status, errnum, format, ap);
	va_end(ap);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_putnbrl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 10:01:42 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 12:45:16 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

static size_t	ft_putuintmaxrec_fd(int fd, uintmax_t n, const char *base,
		int basen)
{
	size_t	size;

	if (n == 0)
		return (0);
	size = ft_putuintmaxrec_fd(fd, n / basen, base, basen);
	if (n > 0)
		ft_putchar_fd(base[n % basen], fd);
	else
		ft_putchar_fd(base[-1 * (n % basen)], fd);
	return (size + 1);
}

size_t			ft_putuintmax_fd(const char *base, uintmax_t nb, const int fd)
{
	size_t	size;

	size = 0;
	if (nb == 0)
		size += ft_putchar_fd(*base, fd);
	else
		size += ft_putuintmaxrec_fd(fd, nb, base, ft_strlen(base));
	return (size);
}

static size_t	ft_putnbrlrec_fd(const int fd, intmax_t n, const char *base,
		int basen)
{
	size_t	size;

	if (n == 0)
		return (0);
	size = ft_putnbrlrec_fd(fd, n / basen, base, basen);
	if (n > 0)
		ft_putchar_fd(base[n % basen], fd);
	else
		ft_putchar_fd(base[-1 * (n % basen)], fd);
	return (size + 1);
}

size_t			ft_putnbrl_fd(const char *base, intmax_t nb, const int fd)
{
	size_t	size;

	size = 0;
	if (nb == 0)
		size += ft_putchar_fd(base[0], fd);
	else
		size += ft_putnbrlrec_fd(fd, nb, base, ft_strlen(base));
	return (size);
}

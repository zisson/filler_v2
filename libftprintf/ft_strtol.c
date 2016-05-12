/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 12:15:28 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 12:57:04 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static const char	*g_digits = "0123456789abcdefghijklmnopqrstuvwxyz";

static long			ft_strtolrec(const char **str, int sig, int base)
{
	long	ret;
	int		i;

	ret = 0;
	while (**str && (i = ft_strpos(g_digits, ft_tolower(**str))) < base)
	{
		if (sig == -1)
			ret = ret * base - i;
		else
			ret = ret * base + i;
		(*str)++;
	}
	return (ret);
}

long int			ft_strtol(const char *p, const char **ret, int base)
{
	int		sig;
	long	res;

	sig = 1;
	while (*p == '-' || *p == '+')
	{
		if (*p == '-')
			sig = sig * (-1);
		p++;
	}
	res = ft_strtolrec(&p, sig, base);
	*ret = p;
	return (res);
}

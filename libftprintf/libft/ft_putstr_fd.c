/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 12:14:57 by zsina             #+#    #+#             */
/*   Updated: 2015/12/28 12:15:03 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_putstr_fd(const char *str, int fd)
{
	size_t	len;

	len = ft_strlen(str);
	if (len == 0)
		return (0);
	write(fd, str, len);
	return (len);
}

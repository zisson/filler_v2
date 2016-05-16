/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 16:14:55 by zsina             #+#    #+#             */
/*   Updated: 2015/11/12 11:11:37 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int	size_buf(char *buf)
{
	int		i;

	i = 0;
	while (i < GNL_BUFF_SIZE && buf[i] != '\n' && buf[i])
		i++;
	return (i);
}

static int	copy_buf(char *buf, char **line, int is_reading)
{
	char	endbuf;
	int		buffsize;
	int		linesize;

	buffsize = size_buf(buf);
	linesize = ft_strlen(*line);
	if (!(*line = ft_memrealloc(*line, linesize, linesize + buffsize + 1)))
		return (-1);
	if (!ft_memcpy(*line + linesize, buf, buffsize))
		return (-1);
	if (buffsize != GNL_BUFF_SIZE)
	{
		endbuf = buf[buffsize];
		if (!ft_memmove(buf, buf + buffsize + 1, GNL_BUFF_SIZE - buffsize - 1)
			|| !ft_memset(buf + GNL_BUFF_SIZE - buffsize - 1, 0, buffsize + 1))
			return (-1);
		if (endbuf == '\n')
			return (2);
		return ((is_reading || *buf) ? 1 : 0);
	}
	if (buf[GNL_BUFF_SIZE - 1] == '\n')
		return ((!ft_memset(buf, 0, buffsize)) ? -1 : 2);
	return ((!ft_memset(buf, 0, buffsize)) ? -1 : 0);
}

int			get_next_line(int const fd, char **line)
{
	int			ret;
	char		*tmp;
	static char	buf[GNL_BUFF_SIZE];

	tmp = NULL;
	ft_memdel((void **)line);
	if (fd < 0 || !line)
		return (-1);
	if (*buf)
		if ((ret = copy_buf(buf, &tmp, 0)))
			return ((*line = tmp) ? ret : ret);
	while ((ret = read(fd, buf, GNL_BUFF_SIZE)) > 0)
		if ((ret = copy_buf(buf, &tmp, 1)))
			return ((*line = tmp) ? ret : ret);
	return (((*line = tmp) && ret != -1 && *tmp) ? 1 : ret);
}

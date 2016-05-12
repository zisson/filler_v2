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

static t_read		*free_read(t_read *old, t_read *prev, t_read **start)
{
	if (!prev)
		*start = old->next;
	else
		prev->next = old->next;
	free(old->to_read);
	free(old);
	if (!prev)
		return (*start);
	else
		return (prev->next);
}

static t_read		*readnew(int fd)
{
	t_read		*old;
	void		*tmp;
	int			ret;

	old = ft_memalloc(sizeof(t_read));
	if (!(tmp = ft_memalloc(BUF_SIZE)))
	{
		free(old);
		return (NULL);
	}
	if ((ret = read(fd, tmp, BUF_SIZE)) < 0)
	{
		free(old);
		free(tmp);
		return (NULL);
	}
	old->to_read = (char *)tmp;
	old->fd = fd;
	old->size = ret;
	old->next = NULL;
	old->index = 0;
	return (old);
}

static int			ft_display(int num, t_read **tab, t_read **s, char **len)
{
	char	*tmp_str;
	int		index;

	if (!tab[0])
		return (-1);
	index = (tab[0])->index;
	if (num == -1 || !(tmp_str = (char *)ft_memalloc(sizeof(char) * num + 1)))
		return (-1);
	*len = tmp_str;
	while (num--)
	{
		*tmp_str++ = (tab[0])->to_read[index++];
		if (index == (tab[0])->size)
		{
			tab[0] = free_read(tab[0], tab[1], s);
			index = 0;
		}
	}
	*tmp_str = 0;
	if (!tab[0] || (index == tab[0]->size && tab[0]->size < BUF_SIZE))
		return (0);
	tab[0]->index = index + 1;
	if (tab[0]->index == tab[0]->size)
		tab[0] = free_read(tab[0], tab[1], s);
	return (1);
}

static int			endline_find(int fd, t_read *old)
{
	int		index;
	int		size;
	t_read	*list_tmp;

	size = 0;
	index = old->index;
	while (old->to_read[index] != '\n' && index < old->size)
	{
		index++;
		size++;
		if (index == old->size && old->size == BUF_SIZE)
		{
			if (!(list_tmp = readnew(fd)))
				return (-1);
			list_tmp->next = old->next;
			old->next = list_tmp;
			old = list_tmp;
			index = 0;
		}
	}
	return (size);
}

int					get_next_line(int fd, char **line)
{
	static t_read	*start = NULL;
	t_read			*old;
	t_read			*tmp_prev;
	t_read			*tab[2];

	if ((!line) || fd < 0)
		return (-1);
	tmp_prev = NULL;
	if (!start)
		start = readnew(fd);
	old = start;
	while (old->fd != fd)
	{
		if (!(old->next))
			old->next = readnew(fd);
		if (readnew(fd) == NULL)
			return (-1);
		tmp_prev = old;
		old = old->next;
	}
	tab[0] = old;
	tab[1] = tmp_prev;
	return (ft_display(endline_find(fd, old), tab, &start, line));
}

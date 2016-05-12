/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:28:25 by zsina             #+#    #+#             */
/*   Updated: 2014/11/10 15:38:49 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static size_t		word_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t		word_nb(const char *s, char c)
{
	size_t	i;
	size_t	len;
	int		its_word;

	i = 0;
	len = 0;
	its_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && its_word)
			its_word = !its_word;
		else if (s[i] != c && !its_word)
		{
			len++;
			its_word = !its_word;
		}
		i++;
	}
	return (len);
}

char				**memalloc_tab(size_t nb)
{
	char	**in_return;

	in_return = (char **)malloc((nb + 1) * sizeof(*in_return));
	if (in_return == NULL)
		return (NULL);
	in_return[0] = NULL;
	return (in_return);
}

static void			check_char(char **av, char const *s, char c)
{
	size_t	itab;
	size_t	len_word;
	char	*word;

	itab = 0;
	while (*s != 0)
	{
		len_word = word_len(s, c);
		if (len_word != 0)
		{
			word = ft_strsub(s, 0, len_word);
			av[itab] = word;
			itab++;
		}
		s += len_word;
		while (*s == c)
			s++;
	}
	av[itab] = NULL;
}

char				**ft_strsplit(char const *s, char c)
{
	char	**in_return;
	size_t	nb_word;

	if (s == NULL)
		return (memalloc_tab(0));
	nb_word = word_nb(s, c);
	in_return = (memalloc_tab(nb_word));
	if (in_return == NULL)
		return (NULL);
	check_char(in_return, s, c);
	return (in_return);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 13:02:05 by zsina             #+#    #+#             */
/*   Updated: 2016/05/02 13:55:48 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

# include <stdlib.h>

typedef struct	s_getopt
{
	int		ret;
	int		ind;
	int		opt;
	int		is_arg;
	char	*arg;
}				t_getopt;

t_getopt		ft_getopt(int ac, char **av, const char *opt_str);

#endif

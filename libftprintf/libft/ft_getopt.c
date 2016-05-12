/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:41:56 by zsina             #+#    #+#             */
/*   Updated: 2016/04/07 14:02:43 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/getopt.h"

static int	is_opt(t_getopt *opt, char **p, const char *opt_str)
{
	char *c;

	opt->opt = **p;
	c = ft_strchr(opt_str, *(*p)++);
	if (c)
	{
		opt->ret = *c;
		if (c[1] == ':')
			opt->is_arg = 1;
		return (1);
	}
	return (0);
}

static int	is_options(t_getopt *opt, char **p, char **av, const char *opt_str)
{
	if (*p == NULL)
	{
		*p = av[opt->ind];
		if (**p == '-')
		{
			if ((*p)[1] == '\0')
			{
				++(*p);
				opt->opt = '-';
				return (0);
			}
			(*p)++;
			return (is_opt(opt, p, opt_str));
		}
		return (0);
	}
	else
	{
		if (!is_opt(opt, p, opt_str))
			opt->ret = '?';
		return (1);
	}
}

static void	get_opt(t_getopt *opt, char **p, int ac, char **av)
{
	if (opt->is_arg)
	{
		if (**p != '\0')
		{
			opt->arg = *p;
			opt->ind++;
		}
		else if (opt->ind + 1 < ac)
		{
			opt->arg = av[opt->ind + 1];
			opt->ind += 2;
		}
		else
		{
			opt->ret = '?';
			opt->ind++;
		}
		*p = NULL;
		return ;
	}
	if (**p == '\0')
	{
		*p = NULL;
		opt->ind++;
	}
}

static void	sort_opt(int ac, char **av, int *t, t_getopt *opt)
{
	int i;
	int j;
	int n;

	n = 0;
	i = ac;
	while (--i >= 1)
	{
		if (t[i] == 0)
		{
			n++;
			continue;
		}
		j = i;
		while (j < ac - 1 && t[j + 1] == 0)
		{
			ft_swapstr(&av[j], &av[j + 1]);
			ft_swap(&t[j], &t[j + 1]);
			j++;
		}
	}
	opt->ind = n + 1;
	free(t);
}

t_getopt	ft_getopt(int ac, char **av, const char *opt_str)
{
	static t_getopt	opt = {0, 1, 0, 0, NULL};
	static char		*opt_ptr = NULL;
	static int		*elem_ind = NULL;

	if (elem_ind == NULL)
	{
		if ((elem_ind = (int *)malloc(ac * sizeof(int))) == NULL)
			exit(1);
		ft_memset(elem_ind, 0, ac * sizeof(int));
	}
	opt.arg = NULL;
	opt.is_arg = 0;
	while (opt.ind < ac && !is_options(&opt, &opt_ptr, av, opt_str))
	{
		elem_ind[opt.ind++] = 1;
		opt_ptr = NULL;
	}
	if (opt.ind >= ac)
	{
		opt.ret = -1;
		sort_opt(ac, av, elem_ind, &opt);
		return (opt);
	}
	get_opt(&opt, &opt_ptr, ac, av);
	return (opt);
}

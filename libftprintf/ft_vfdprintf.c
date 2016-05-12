/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfdprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 10:05:01 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 13:01:29 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <stdlib.h>

static const t_pftype	g_print_type[] =
{
	{'s', ft_printsmall_s},
	{'S', ft_printupper_s},
	{'d', ft_printsmall_di},
	{'i', ft_printsmall_di},
	{'p', ft_printp},
	{'%', ft_printmod},
	{'D', ft_printupper_d},
	{'o', ft_printsmall_o},
	{'O', ft_printupper_o},
	{'u', ft_printsmall_u},
	{'U', ft_printupper_u},
	{'x', ft_printsmall_x},
	{'X', ft_printupper_x},
	{'c', ft_printsmaller_c},
	{'C', ft_printupper_c},
	{'n', ft_printn},
	{'b', ft_printsmall_b},
	{0, 0},
};

static size_t			ft_printtoken(t_pfdata *data)
{
	const t_pftype		*p;

	p = g_print_type;
	while (p->type)
	{
		if (p->type == data->type)
			return (p->f(data));
		p++;
	}
	return (ft_printmod(data));
}

size_t					ft_print_hlspec(t_pfdata *data, const char *c,
		size_t *bytes)
{
	if (data->type == 'C' || data->type == 'c')
	{
		if (data->len[1] == 'l' || data->len[1] == 'h'
				|| *(data->val) == 0)
		{
			(*bytes)++;
			if ((data->prec == -1 && data->width == 0)
					&& (data->len[0] != 'h' || data->len[1] != 'h'))
				return (ft_putchar_fd(' ', data->fd));
			return (ft_putstr_fd("", data->fd));
		}
		else
			ft_putchar_fd(*c, data->fd);
	}
	else
		ft_putchar_fd(*c, data->fd);
	(*bytes)++;
	c++;
	return (*bytes);
}

static const char		*ft_handletok(const char *p, size_t *bytes,
		t_pfdata *data)
{
	data->bytes = *bytes;
	if (*p == PRINTF_OPTACT)
	{
		p++;
		if (*p == '\0')
			ft_putstr_fd("", data->fd);
		else
		{
			p = ft_getarg(p, data);
			(*bytes) += ft_printtoken(data);
		}
	}
	else
		ft_print_hlspec(data, p++, bytes);
	return (p);
}

int						ft_vfdprintf(const int fd, const char *fmt, va_list ap)
{
	const char	*p;
	size_t		bytes;
	t_pfdata	data;

	bytes = 0;
	ft_memset(&data, 0, sizeof(data));
	va_copy(data.ap, ap);
	data.fd = fd;
	data.val = 0;
	p = fmt;
	while (*p)
		p = ft_handletok(p, &bytes, &data);
	return (bytes);
}

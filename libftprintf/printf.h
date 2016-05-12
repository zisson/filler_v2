/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 10:05:38 by zsina             #+#    #+#             */
/*   Updated: 2016/04/07 14:01:29 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/includes/libft.h"
# include "libft/includes/list.h"
# include "libft/includes/getopt.h"
# include <stdarg.h>
# include <wchar.h>
# include <string.h>
# include <stdint.h>
# include <limits.h>

# define BLACK    "\033[1;30m"
# define RED      "\033[1;31m"
# define GREEN    "\033[1;32m"
# define YELLOW   "\033[1;33m"
# define BLUE     "\033[1;34m"
# define PURPLE   "\033[1;35m"
# define CYAN     "\033[1;36m"
# define GREY     "\033[1;37m"
# define DEFAULT_COLOR "\033[0;m"

# define PRINTF_FLAGS			"#+- 0"
# define NO_FLAG                0
# define DIESEFLAG				1
# define PLUSFLAG				2
# define MINUSFLAG				4
# define SPACEFLAG				8
# define ZEROFLAG				16
# define MULTFLAG				32

# define BIN					0
# define OCT					2
# define DEC					4
# define HEX					6
# define HEXB					8

# define BIN_BASE				1
# define OCT_BASE				3
# define DEC_BASE				5
# define HEX_BASE				7
# define HEXB_BASE		    	9

# define NO_PREC				-1
# define PRE					""
# define PRINTF_OPTACT		    '%'

# define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct				s_pfdata
{
	const char				*str;
	wint_t					*val;
	int						flag;
	int						width;
	int						prec;
	char					len[3];
	char					type;
	va_list					ap;
	size_t					bytes;
	int						fd;
}							t_pfdata;

typedef struct				s_pftype
{
	char					type;
	size_t					(*f)(t_pfdata *);
}							t_pftype;

int							ft_isint(char *s);
int							ft_isnumber(char *s);
long long int				ft_atolli(const char *str);
void						ft_swapstr(char **s1, char **s2);
void						ft_swapint(int *n1, int *n2);
int							ft_printf(char *fmt, ...);
int							ft_vfdprintf(const int fd, const char *fmt,
		va_list ap);
int							ft_fdprintf(const int fd, const char *fmt, ...);
const char					*ft_getarg(const char *p, t_pfdata *data);
int							ft_abs(int n);
int							ft_abszero(int n);
long int					ft_strtol(const char *p, const char **ret,
		int base);
int							ft_strpos(const char *str, char c);
size_t						ft_fillspc(int st, t_pfdata *data, int len);
size_t						ft_fillzero(t_pfdata *data, int logn);
size_t						ft_putnbrl_fd(const char *base, intmax_t nb,
		const int fd);
size_t						ft_putuintmax_fd(const char *base, uintmax_t nb,
		const int fd);
long long int				ft_getargdi(t_pfdata *data);
uintmax_t					ft_getarg_oux(t_pfdata *data);
unsigned long long int		ft_getargb(t_pfdata *data);
void						*ft_getadr(t_pfdata *data);
uintmax_t					ft_getargu(t_pfdata *data);
wint_t						ft_getargc(t_pfdata *data);
int							ft_log(intmax_t n, int base);
size_t						ft_managediez_tos(t_pfdata *data, const char *base,
		ssize_t outputlen, int strsize);
size_t						ft_managstr_precwid(ssize_t outputlen, int strsize,
		t_pfdata *data);
size_t						ft_calclen_s(int sign, int strsize, t_pfdata *data,
		const char *base);
size_t						ft_managcu_precwid(ssize_t outputlen, int strsize,
		t_pfdata *data);
size_t						ft_managediez_tocu(t_pfdata *data, const char *base,
		ssize_t outputlen, int strsize);
size_t						ft_calclen_upocu(int sign, int strsize,
		t_pfdata *data, const char *base);
size_t						ft_calclen_o(int sign, int strsize, t_pfdata *data,
		const char *base);
size_t						ft_managediez_too(t_pfdata *data, const char *base,
		ssize_t outputlen, int strsize);
size_t						ft_manago_precwid(ssize_t outputlen, int strsize,
		t_pfdata *data);
size_t						ft_managediez_todi(t_pfdata *data, const char *base,
		ssize_t outputlen, int strsize);
size_t						ft_managdi_precwid(ssize_t outputlen, int strsize,
		t_pfdata *data);
size_t						ft_calclen_di(int sign, int strsize, t_pfdata *data,
		const char *base);
size_t						ft_managp_precwid(ssize_t outputlen, int strsize,
		t_pfdata *data);
size_t						ft_managediez_top(t_pfdata *data, const char *base,
		ssize_t outputlen, int strsize);
size_t						ft_calclen_p(int sign, int strsize, t_pfdata *data,
		const char *base);
size_t						ft_managx_precwid(ssize_t outputlen, int strsize,
		t_pfdata *data);
size_t						ft_managediez_tox(t_pfdata *data, const char *base,
		ssize_t outputlen, int strsize);
size_t						ft_calclen_x(int sign, int strsize, t_pfdata *data,
		const char *base);
char						*ft_putwstr(wchar_t *src);
char						*ft_putwchar(wchar_t wide);
size_t						ft_printp(t_pfdata *data);
size_t						ft_printmod(t_pfdata *data);
size_t						ft_printupper_d(t_pfdata *data);
size_t						ft_printsmall_x(t_pfdata *data);
size_t						ft_printupper_x(t_pfdata *data);
size_t						ft_printsmall_o(t_pfdata *data);
size_t						ft_printupper_o(t_pfdata *data);
size_t						ft_printsmall_u(t_pfdata *data);
size_t						ft_printupper_u(t_pfdata *data);
size_t						ft_printsmall_b(t_pfdata *data);
size_t						ft_printsmall_di(t_pfdata *data);
size_t						ft_printsmall_s(t_pfdata *data);
size_t						ft_printupper_s(t_pfdata *data);
size_t						ft_printsmaller_c(t_pfdata *data);
size_t						ft_printupper_c(t_pfdata *data);
size_t						ft_printn(t_pfdata *data);
size_t						ft_b_gen(t_pfdata *data, const char *pre,
		const char *base);
size_t						ft_p_gen(t_pfdata *data, const char *pre,
		const char *base);
size_t						ft_x_gen(t_pfdata *data, const char *pre,
		const char *base);
size_t						ft_oupper_gen(t_pfdata *data, const char *pre,
		const char *base);
size_t						ft_upper_gen(t_pfdata *data, const char *pre,
		const char *base);
size_t						ft_u_gen(t_pfdata *data, const char *pre,
		const char *base);
size_t						ft_upxo_gen(t_pfdata *data, const char *pre,
		const char *base);
size_t						ft_gensmall_o(t_pfdata *data, const char *pre,
		const char *base);

/*
** FUNCTION ALLOC
*/
void						*ft_xmalloc(size_t n);
void						*ft_xrealloc(void *ptr, size_t n, size_t old);

/*
** FUNCTION ERROR
*/
void						ft_err(int status, int errnum, const char *format,
		...);

#endif

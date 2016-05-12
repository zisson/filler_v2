#include "filler.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*join;

	join = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	if ((join = (char *)malloc(sizeof(char) * (ft_strlen(s1)
						+ ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcat(join, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (join);
}

void   display_vmdata(t_vmdata *data)
{
    int i;

    i = 0;
    ft_putstr_fd("data->player_id: ", 2);
    ft_putchar_fd(data->player_id, 2);
    ft_putchar_fd('\n', 2);
    ft_putstr_fd("data->mapsize_y: ", 2);
    ft_putnbr_fd(data->mapsize_y, 2);
    ft_putchar_fd('\n', 2);
    ft_putstr_fd("data->mapsize_x: ", 2);
    ft_putnbr_fd(data->mapsize_x, 2);
    ft_putchar_fd('\n', 2);
    ft_putstr_fd("data->psize_y: ", 2);
    ft_putnbr_fd(data->psize_y, 2);
    ft_putchar_fd('\n', 2);
    ft_putstr_fd("data-psize_x: ", 2);
    ft_putnbr_fd(data->psize_x, 2);
    ft_putchar_fd('\n', 2);
    ft_putstr_fd("data-map: ", 2);
	ft_putchar_fd('\n', 2);
	if (!(data->map))
		return ;
	while (data->map[i])
	{
    	ft_putchar_fd(data->map[i], 1);
		i++;
	}
    ft_putchar_fd('\n', 2);

}

static void     ft_filler_calc(t_filldata *f, t_vmdata *vm_data)
{
    while ((vm_data->piece)[f->n])
	{
		if ((vm_data->piece)[f->n] == '*')
		{
			f->psize_x = f->n % vm_data->psize_x;
			f->psize_y = f->n / vm_data->psize_x;
			f->mapsize_x = f->i % vm_data->mapsize_x;
			f->mapsize_y = f->i / vm_data->mapsize_x;
			if (((f->ret = test_piece(f->i, f->n, vm_data)) == 1)
					&& ((f->mapsize_x - f->psize_x) >= 0)
					&& ((f->mapsize_y - f->psize_y) >= 0)
					&& ((f->mapsize_x - f->psize_x) + vm_data->psize_x < vm_data->mapsize_x)
					&& ((f->mapsize_y - f->psize_y) + vm_data->psize_y < vm_data->mapsize_y))
				break ;
			else
				f->ret = 0;
		}
		f->n++;
	}
}

static void    init_fillinfo(t_filldata *f)
{
    f->mapsize_x = 0;
    f->mapsize_y = 0;
    f->psize_x = 0;
    f->psize_y = 0;
    f->i = 0;
    f->ret = -1;
}

void    ft_filler(t_vmdata *vm_data)
{
    t_filldata  f;

    init_fillinfo(&f);
	while ((vm_data->map)[f.i])
	{
		if ((vm_data->map)[f.i] == vm_data->player_id ||
        (vm_data->map)[f.i] == vm_data->player_id + 32)
		{
			f.n = 0;
			ft_filler_calc(&f, vm_data);
			if (f.ret == 1)
				break ;
		}
		f.i++;
	}
	f.absc_x = f.mapsize_x - f.psize_x;
	f.ord_y = f.mapsize_y - f.psize_y;
	ft_putnbr_fd(f.ord_y, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(f.absc_x, 1);
	ft_putchar_fd('\n', 1);
}

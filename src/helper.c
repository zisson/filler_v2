#include "filler.h"

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
	ft_putstr_fd("data-psize_x: ", 2);
    ft_putnbr_fd(data->psize_x, 2);
    ft_putchar_fd('\n', 2);
    ft_putstr_fd("data->psize_y: ", 2);
    ft_putnbr_fd(data->psize_y, 2);
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

void    print_filldata(t_filldata *f)
{
    ft_putstr("-----------------------\n");
    ft_putstr_fd("f->mapsize_y: ", 2);
    ft_putnbr_fd(f->mapsize_y, 2);
    ft_putchar_fd('\n', 2);
    ft_putstr_fd("f->mapsize_x: ", 2);
    ft_putnbr_fd(f->mapsize_x, 2);
    ft_putchar_fd('\n', 2);
	ft_putstr_fd("f-psize_x: ", 2);
    ft_putnbr_fd(f->psize_x, 2);
    ft_putchar_fd('\n', 2);
    ft_putstr_fd("f->psize_y: ", 2);
    ft_putnbr_fd(f->psize_y, 2);
    ft_putchar_fd('\n', 2);
    ft_putstr("-----------------------\n");
}

void 	ft_print_piece(t_tpiece *p)
{
	ft_putstr("-----------------------\n");
	ft_putstr("info piece\n");
	ft_putstr("p->touch: ");
	ft_putnbr(p->touch);
	ft_putstr("\np->x_center: ");
	ft_putnbr(p->x_center);
	ft_putstr("\np->y_center: ");
	ft_putnbr(p->y_center);
	ft_putstr("\np->x_i: ");
	ft_putnbr(p->x_i);
	ft_putstr("\np->y_i: ");
	ft_putnbr(p->y_i);
	ft_putstr("\np->c: ");
	ft_putnbr(p->c);;
	ft_putstr("\np->x_pos: ");
	ft_putnbr(p->x_pos);
	ft_putstr("\np->y_pos: ");
	ft_putnbr(p->y_pos);
	ft_putstr("\np->pos_content: ");
	ft_putchar(p->pos_content);
	ft_putstr("\n-----------------------\n");
}

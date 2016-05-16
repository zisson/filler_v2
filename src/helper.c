#include "filler.h"

void    display_grid(t_grid *grid)
{
    int     i;

    i = 0;
    ft_putstr_fd("\ngrid->hig\n", 1);
    ft_putnbr_fd(grid->hig, 1);
    ft_putstr_fd("\ngrid->wid\n", 1);
    ft_putnbr_fd(grid->wid, 1);
    ft_putstr_fd("\ngrid->g\n", 1);
    if (!grid)
        return ;
    while (grid->g[i])
    {
        ft_putendl("Debeug");
        ft_putstr_fd(grid->g[i], 1);
        i++;
    }
}

void    display_filler(t_filler *f)
{
    int i;

    i = 0;
    ft_putstr_fd("\nf->x: ", 1);
    ft_putnbr_fd(f->x, 1);
    ft_putstr_fd("\nf->y: ", 1);
    ft_putnbr_fd(f->y, 1);
    ft_putstr_fd("\nf->way: ", 1);
    ft_putnbr_fd(f->way, 1);
    ft_putstr_fd("\nf->all_id: ", 1);
    ft_putstr_fd(f->all_id, 1);
    ft_putstr_fd("\nf->my_id: ", 1);
    ft_putstr_fd(f->my_id, 1);
    ft_putchar_fd('\n', 1);
    display_grid(&f->form);
    display_grid(&f->grid);
    ft_putchar_fd('\n', 1);
}

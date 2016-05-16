#include "filler.h"

void	free_grid(t_grid *grid)
{
	int	i;
	int	sizei;

	if (grid->g)
	{
		i = 0;
		sizei = grid->hig;
		while (++i < sizei)
			ft_memdel((void **)&grid->g[i++]);
		ft_memdel((void **)&grid->g);
	}
	grid->hig = 0;
	grid->wid = 0;
}

int		free_filler(t_filler *f, char **line)
{
	f->all_id[0] = 0;
	f->all_id[1] = 0;
	f->my_id[0] = 0;
	f->my_id[1] = 0;
	free_grid(&f->form);
	free_grid(&f->grid);
	ft_memdel((void **)line);
	write(1, "0 0\n", 4);
	return (0);
}

void	fill_line(t_grid *grid, int id, char *s)
{
	while (ft_isdigit(*s))
		s++;
	ft_memcpy(grid->g[id], ++s, grid->wid * sizeof(char));
}

int		read_grid(t_grid *grid, char **line)
{
	int	i;
	int	j;

	j = -1;
	while (++j < 50000000)
		;
	if (!read_line(line))
		return (0);
	if (!read_line(line))
		return (0);
	i = -1;
	while (++i < grid->hig)
	{
		if (!read_line(line))
			return (0);
		fill_line(grid, i, *line);
	}
	return (1);
}

int		read_line(char **line)
{
	int	ret;

	while ((ret = get_next_line(0, line)) != 2)
	{
		if (ret == -1)
			return (0);
	}
	return (1);
}

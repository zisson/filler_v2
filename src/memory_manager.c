#include "filler.h"

int			init_grid(t_grid *grid, char **line, int type)
{
	int		i;
	int		j;
	char	*s;

	if ((i = -1) && !read_line(line))
		return (0);
	s = (type == GRID) ? &(*line)[8] : &(*line)[6];
	grid->hig = ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
	if ((((grid->wid = ft_atoi(++s)) || 1) && type == GRID && !read_line(line))
			|| !(grid->g = (char **)malloc(grid->hig * sizeof(char *))))
		return (0);
	while (++i < grid->hig)
	{
		if (!(grid->g[i] = (char *)malloc(grid->wid * sizeof(char)))
				|| ((j = -1) && !read_line(line)))
			return (0);
		while (++j < 100000)
			;
		(type == GRID) ? fill_line(grid, i, *line)
			: ft_memcpy(grid->g[i], *line, grid->wid * sizeof(char));
	}
	return (1);
}

static void	player_id(t_filler *f, char *s)
{
	int	id;

	id = s[10] - '0';
	f->all_id[0] = (id == 1) ? 'o' : 'x';
	f->all_id[1] = (id == 1) ? 'O' : 'X';
	f->my_id[0] = (id == 1) ? 'x' : 'o';
	f->my_id[1] = (id == 1) ? 'X' : 'O';
}

int			init_map(t_filler *f, char **line)
{
	if (!read_line(line))
		return (0);
	player_id(f, *line);
	if (!init_grid(&f->grid, line, GRID))
		return (0);
	f->y = -1;
	f->way = 0;
	while (++f->y < f->grid.hig && (f->x = -1))
		while (++f->x < f->grid.wid)
			if (f->grid.g[f->y][f->x] == f->all_id[0]
					|| f->grid.g[f->y][f->x] == f->all_id[1])
			{
				if (!init_grid(&f->form, line, PIECE))
					return (0);
				return (1);
			}
	return (0);
}

int			my_find(t_filler *f, t_grid *g, int xy[4], int xymax[2])
{
	int	i;
	int	j;

	i = xy[0];
	while (i != xymax[0] && ((j = xy[1]) || 1))
	{
		while (j != xymax[1])
		{
			if (g->g[i][j] == f->all_id[1])
				return (1 + (f->x = j)
						+ (f->y = i));
				j += xy[3];
		}
		i += xy[2];
	}
	return (0);
}

int			find_next_case2(t_filler *f, t_grid *g, int xy[4], int xymax[2])
{
	if (((f->x > g->hig / 2 && f->way | UP)
			|| (f->x < g->hig / 2 && f->way | DOWN)) && ((xy[1] = f->x) || 1))
		xymax[1] = (f->way | LEFT) ? g->wid : -1;
	else if ((*xy = f->y) || 1)
		xymax[0] = (f->way | UP) ? g->hig : -1;
	if (my_find(f, g, xy, xymax))
		return (1);
	if ((f->x > g->hig / 2 && f->way | UP)
			|| (f->x < g->hig / 2 && f->way | DOWN))
	{
		xy[0] = f->y;
		xy[1] = (f->way | LEFT) ? 0 : g->wid - 1;
		xymax[0] = (f->way | UP) ? g->hig : -1;
		xymax[1] = f->x;
	}
	else
	{
		xy[0] = (f->way | UP) ? 0 : g->hig - 1;
		xy[1] = f->x;
		xymax[0] = f->y;
		xymax[1] = (f->way | LEFT) ? g->wid : -1;
	}
	return (my_find(f, g, xy, xymax));
}

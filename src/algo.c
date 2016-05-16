#include "filler.h"

static void	find_way(t_filler *f)
{
	int	i;
	int	j;
	int	minx;
	int	miny;

	i = -1;
	minx = INT_MAX / 2;
	miny = INT_MAX / 2;
	while (++i < f->grid.hig && (j = -1))
		while (++j < f->grid.wid)
			if (f->grid.g[i][j] == f->my_id[0]
					|| f->grid.g[i][j] == f->my_id[1])
				if (FT_ABS(f->y - i) + FT_ABS(f->x - j) <
					FT_ABS(miny - i) + FT_ABS(minx - j) && ((minx = j) || 1))
					miny = i;
	if (minx == INT_MAX / 2)
		f->way = LEFT | UP;
	else if (minx <= f->x && miny <= f->x)
		f->way = LEFT | UP;
	else if (minx <= f->x)
		f->way = LEFT | DOWN;
	else if (miny <= f->x)
		f->way = RIGHT | UP;
	else
		f->way = RIGHT | DOWN;
}

static int	put_form(t_filler *f, t_grid *g, int y, int x)
{
	int		i;
	int		j;
	t_grid	*p;

	p = &f->form;
	i = -1;
	while (++i < p->hig && (j = -1))
		while (++j < p->wid)
			if (p->g[i][j] == '*' && ((f->y - y + i < 0
				|| f->y - y + i >= g->hig || f->x - x + j < 0
				|| f->x - x + j >= g->wid) || (!(i == y && j == x) &&
				g->g[f->y - y + i][f->x - x + j] != '.')))
				return (0);
	return (1);
}

static int	test_form(t_filler *f, t_grid *g, int *x, int *y)
{
	int		i;
	int		j;
	t_grid	*p;
	int		im;
	int		jm;

	p = &f->form;
	i = (f->way | UP) ? p->hig : -1;
	im = (f->way | UP) ? -1 : p->hig;
	jm = (f->way | LEFT) ? -1 : p->wid;
	while ((i = (f->way | UP) ? i - 1 : i + 1) != im
		&& ((j = (f->way | LEFT) ? p->wid : -1) || 1))
		while ((j = (f->way | LEFT) ? j - 1 : j + 1) != jm)
			if (p->g[i][j] == '*' && put_form(f, g, i, j)
				&& ((*x = f->x - j) || 1)
				&& ((*y = f->y - i) || 1)
				&& ((i = (f->way | UP) ? -1 : p->hig) || 1)
				&& ((im = (f->way | UP) ? p->hig : -1) || 1)
				&& ((jm = (f->way | LEFT) ? p->wid : -1) || 1))
				while ((i = (f->way | UP) ? i + 1 : i - 1) != im
					&& ((j = (f->way | LEFT) ? -1 : p->wid) || 1))
					while ((j = (f->way | LEFT) ? j + 1 : j - 1) != jm)
						if (p->g[i][j] == '*' && ((f->x = *x + j) || 1))
							return ((f->y = *y + i) || 1);
	return (0);
}

static int	find_next_case(t_filler *f, t_grid *g)
{
	int		xy[4];
	int		xymax[2];

	xy[0] = (f->way | UP) ? 0 : g->hig - 1;
	xy[1] = (f->way | LEFT) ? 0 : g->wid - 1;
	xy[2] = (f->way | UP) ? 1 : -1;
	xy[3] = (f->way | LEFT) ? 1 : -1;
	xymax[0] = f->y;
	xymax[1] = f->x;
	if (my_find(f, g, xy, xymax))
		return (1);
	if (find_next_case2(f, g, xy, xymax))
		return (1);
	xy[0] = f->y;
	xy[1] = f->x;
	xymax[0] = (f->way | UP) ? g->hig : -1;
	xymax[1] = (f->way | LEFT) ? g->wid : -1;
	return (my_find(f, g, xy, xymax));
}

int			my_compute(t_filler *f)
{
	int	x;
	int	y;

	y = -1;
	while (++y < f->grid.hig && (x = -1))
		while (++x < f->grid.wid)
			if (f->grid.g[y][x] == f->all_id[0])
				f->grid.g[y][x] = f->all_id[1];
	while (1)
	{
		find_way(f);
		if (test_form(f, &f->grid, &x, &y))
			break ;
		f->grid.g[f->y][f->x] = f->all_id[0];
		if (!find_next_case(f, &f->grid))
			return (0);
	}
	ft_printf("%d %d\n", y, x);
	return (1);
}

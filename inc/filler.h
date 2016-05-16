
#ifndef FILLER_H
# define FILLER_H
# include "printf.h"

# define UP		1
# define DOWN	2
# define LEFT	4
# define RIGHT	8

# define GRID	1
# define PIECE	2

typedef struct	s_grid
{
	char	**g;
	int		hig;
	int		wid;
}				t_grid;

typedef struct	s_filler
{
	int		x;
	int		y;
	int		way;
	char	all_id[2];
	char	my_id[2];
	t_grid	form;
	t_grid	grid;
}				t_filler;

/*
**	utilities.c
*/
int				read_line(char **line);
void			free_grid(t_grid *grid);
int				read_grid(t_grid *grid, char **line);
int				free_filler(t_filler *f, char **line);
void			fill_line(t_grid *grid, int id, char *s);

/*
**	memory_manager
*/
int				init_map(t_filler *f, char **line);
int				init_grid(t_grid *grid, char **line, int type);
int				my_find(t_filler *f, t_grid *g, int xy[2], int xymax[2]);
int				find_next_case2(t_filler *f, t_grid *g, int xy[2],
				int xymax[2]);

/*
**	algo.c
*/
int				my_compute(t_filler *f);

/*
** helper.c
*/
void    display_filler(t_filler *f);
void    display_grid(t_grid *grid);

#endif

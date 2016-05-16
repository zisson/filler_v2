#include "filler.h"

int	main(void)
{
	t_filler	f;
	char		*line;

	line = NULL;
	if (!init_map(&f, &line))
		return (free_filler(&f, &line));
	if (!my_compute(&f))
		return (free_filler(&f, &line));
	free_grid(&f.form);
	while (1)
	{
		if (!read_grid(&f.grid, &line))
			return (free_filler(&f, &line));
		if (!init_grid(&f.form, &line, PIECE))
			return (free_filler(&f, &line));
		if (!my_compute(&f))
			return (free_filler(&f, &line));
		free_grid(&f.form);
	}
	return (free_filler(&f, &line));
}

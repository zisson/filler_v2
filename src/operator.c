#include "filler.h"

static int  test_piece_algo(t_tpiece *p, t_vmdata *vm_data)
{
    if ((p->pos_content = (vm_data->map)[(p->y_pos * vm_data->mapsize_x) + p->x_pos]) != '.')
    {
        if (p->pos_content == vm_data->player_id || p->pos_content == vm_data->player_id + 32)
        {
            p->touch++;
            if (p->touch > 1)
                return (0);
        }
        else
            return (0);
    }
    return (1);
}

int     test_piece(int i, int n, t_vmdata *vm_data)
{
    t_tpiece	p;

	p.touch = 0;
    p.c = 0;
	p.x_center = n % vm_data->psize_x;
	p.y_center = n / vm_data->psize_x;
	p.x_i = i % vm_data->mapsize_x;
	p.y_i = i / vm_data->mapsize_x;
	while ((vm_data->piece)[p.c])
	{
		if ((vm_data->piece)[p.c] == '*')
		{
			p.x_pos = p.x_i + ((p.c % vm_data->psize_x) - p.x_center);
			p.y_pos = p.y_i + ((p.c / vm_data->psize_x) - p.y_center);
			if ((p.y_pos * vm_data->mapsize_x) + p.x_pos < 0)
				return (0);
			if (test_piece_algo(&p, vm_data) == 0)
				return (0);
		}
		p.c++;
	}
	return (1);
}

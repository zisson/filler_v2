#include "filler.h"

void    get_vm_piece(t_vmdata *vm_data)
{
    int     i;
    char    *str;

    i = 0;
    ft_strdel(&(vm_data->piece));
    while (i < vm_data->psize_y)
    {
        get_next_line(0, &str);
        vm_data->piece = ft_strjoin_free(vm_data->piece, str);
        i++;
    }
    ft_filler(vm_data);
}

void    get_vm_info(t_vmdata *vm_data)
{
    int     i;
    char    *str;
    char    **newmap;

    i = 0;
    ft_strdel(&(vm_data->map));
    while (i <= vm_data->mapsize_y)
    {
        get_next_line(0, &str);
        if (i != 0)
        {
            vm_data->map = ft_strjoin_free(vm_data->map,
                (newmap = ft_strsplit(str, ' '))[1]);
        }
        i++;
    }

}

void    check_vminfo(char **line, t_vmdata *vm_data)
{
    char    **tab_line;

    tab_line = NULL;
    if (ft_strncmp(*line, "Plateau", 7) == 0)
    {
        tab_line = ft_strsplit(*line, ' ');
        vm_data->mapsize_y = ft_atoi(tab_line[1]);
        vm_data->mapsize_x = ft_atoi(tab_line[2]);
        get_vm_info(vm_data);
    }
    else if (ft_strncmp(*line, "Piece", 5) == 0)
    {
        tab_line = ft_strsplit(*line, ' ');
        vm_data->psize_y = ft_atoi(tab_line[1]);
        vm_data->psize_x = ft_atoi(tab_line[2]);
        get_vm_piece(vm_data);
    }
}

int     main(void)
{
    char        *line;
    t_vmdata    data;

    while (get_next_line(0, &line))
    {
        if (ft_strncmp(line, "$$$ exec p1 : [", 15) == 0)
            data.player_id = 'O';
        else if (ft_strncmp(line, "$$$ exec p2 : [", 15) == 0)
            data.player_id = 'X';
        check_vminfo(&line, &data);
    }
    if (line != NULL)
        ft_strdel(&line);
    return (0);
}

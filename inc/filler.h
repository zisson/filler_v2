
#ifndef FILLER_H
# define FILLER_H
# include "printf.h"

# define P1_CHAR	'O'
# define P2_CHAR	'X'
# define FAIL       0
#define SUCCESS     1

# define ERR_IL     -1
# define ERR_SM		-2
# define ERR_MAL	-3

typedef struct      s_vmata
{
    char            player_id;
    char            *map;
    char            *piece;
    int             mapsize_x;
    int             mapsize_y;
    int             psize_x;
    int             psize_y;
}                   t_vmdata;

typedef struct      s_filldata
{
    int		mapsize_x;
    int		mapsize_y;
    int		psize_x;
    int		psize_y;
    int		i;
    int		n;
    int		absc_x;
    int		ord_y;
    int		ret;
}                   t_filldata;

typedef struct      s_tpiece
{
    int     touch;
    int     x_center;
    int     y_center;
    int     x_i;
    int     y_i;
    int     c;
    char    pos_content;
    int		x_pos;
	int		y_pos;
}                   t_tpiece;

void   display_vmdata(t_vmdata *data);
void    check_vminfo(char **line, t_vmdata *vm_data);
void    get_vm_info(t_vmdata *vm_data);
void   display_vmdata(t_vmdata *data);
char	*ft_strjoin_free(char *s1, char *s2);
void    ft_filler(t_vmdata *vm_data);
int     test_piece(int i, int n, t_vmdata *vm_data);
#endif

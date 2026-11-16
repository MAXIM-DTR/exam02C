#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

# include <stdlib.h>

/* Structure pour représenter un point (coordonnées x, y) */
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void	fill(char **area, t_point size, t_point vec, char to_fill);
void	flood_fill(char **tab, t_point size, t_point begin);

#endif

/*
** flood_fill.h - header requis pour flood_fill.c
** Contient la definition de t_point et les prototypes des fonctions
*/
#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

# include <stdlib.h>

/*
** t_point - structure pour representer un point en 2D
** x: coordonnee horizontale (colonne)
** y: coordonnee verticale (ligne)
** Note: dans le tableau 2D, on accede avec area[y][x]
*/
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void	fill(char **area, t_point size, t_point vec, char to_fill);
void	flood_fill(char **tab, t_point size, t_point begin);

#endif

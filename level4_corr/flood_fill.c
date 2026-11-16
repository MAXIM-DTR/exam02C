/* flood_fill - remplit une zone d'un tableau 2D avec 'F'
** Prototype : void flood_fill(char **tab, t_point size, t_point begin);
** - tab   : le tableau 2D de caractères
** - size  : struct avec .x (largeur) et .y (hauteur)
** - begin : struct avec .x/.y = point de départ du remplissage
**
** L'algorithme DFS (récursif) remplace toutes les cellules
** adjacentes (haut/bas/gauche/droite) qui ont la même valeur
** que la cellule de départ, par 'F'.
**
** Fichier requis : flood_fill.h avec la struct t_point
*/

#include "flood_fill.h"

/* Fonction auxiliaire récursive */
void	fill(char **area, t_point size, t_point vec, char to_fill)
{
	/* Sortir si on est hors limites ou si la cellule n'a pas la bonne valeur */
	if (vec.y < 0 || vec.y >= size.y || vec.x < 0 || vec.x >= size.x ||
		area[vec.y][vec.x] != to_fill)
		return ;
	/* Remplir cette cellule */
	area[vec.y][vec.x] = 'F';
	/* Appels récursifs dans les 4 directions */
	fill(area, size, (t_point){vec.x - 1, vec.y}, to_fill);
	fill(area, size, (t_point){vec.x + 1, vec.y}, to_fill);
	fill(area, size, (t_point){vec.x, vec.y - 1}, to_fill);
	fill(area, size, (t_point){vec.x, vec.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	/* Lancer le remplissage depuis le point de départ */
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

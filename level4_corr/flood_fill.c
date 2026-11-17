/*
** flood_fill - remplit une zone d'un tableau 2D de chars avec 'F'
** Principe: comme le "pot de peinture" dans les logiciels de dessin
** Remplace tous les chars adjacents (haut/bas/gauche/droite) qui ont
** la meme valeur que la cellule de depart
**
** Parametre tab:   le tableau 2D de chars a modifier
** Parametre size:  struct t_point avec size.x=largeur, size.y=hauteur
** Parametre begin: struct t_point avec begin.x/.y = coordonnees de depart
**
** Algorithme DFS (Depth First Search) recursif:
** 1. Verifier qu'on est dans les bornes du tableau
** 2. Verifier que la cellule a la bonne valeur (celle qu'on remplace)
** 3. Remplacer par 'F'
** 4. Appeler recursivemement dans les 4 directions
** La recursion s'arrete naturellement quand on sort des bornes ou trouve un autre char
*/
#include "flood_fill.h"

/*
** fill - fonction auxiliaire recursive qui fait le vrai travail
** Parametre to_fill: le char original qu'on remplace (pris au debut depuis begin)
** On le passe en parametre pour ne pas avoir a y acceder autrement
*/
void	fill(char **area, t_point size, t_point vec, char to_fill)
{
	/* Conditions d'arret:
	** - vec.y < 0 || vec.y >= size.y: on sort du tableau verticalement
	** - vec.x < 0 || vec.x >= size.x: on sort du tableau horizontalement
	** - area[vec.y][vec.x] != to_fill: cellule differente de ce qu'on remplace
	**   (soit un char different, soit deja rempli avec 'F') */
	if (vec.y < 0 || vec.y >= size.y || vec.x < 0 || vec.x >= size.x ||
		area[vec.y][vec.x] != to_fill)
		return ;
	area[vec.y][vec.x] = 'F';  /* Marquer cette cellule comme remplie */
	/* Appels recursifs dans les 4 directions (compound literals pour t_point) */
	fill(area, size, (t_point){vec.x - 1, vec.y}, to_fill);  /* Gauche */
	fill(area, size, (t_point){vec.x + 1, vec.y}, to_fill);  /* Droite */
	fill(area, size, (t_point){vec.x, vec.y - 1}, to_fill);  /* Haut */
	fill(area, size, (t_point){vec.x, vec.y + 1}, to_fill);  /* Bas */
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	/* Lancer le remplissage en memorisant le char de depart a remplacer */
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

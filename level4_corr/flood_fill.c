/* flood_fill - remplissage par diffusion (comme Paint bucket tool)
** A partir d'un point, remplace tous les chars connectes (meme valeur)
** par 'F'. Connexion = haut, bas, gauche, droite (pas diagonal).
** Methode: recursion DFS - remplir le point, puis appeler sur les 4 voisins */
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

/* Fonction recursive qui fait le vrai travail */
void	fill(char **tab, t_point size, t_point pos, char target)
{
	/* Verifier qu'on est dans les limites du tableau */
	if (pos.x < 0 || pos.x >= size.x || pos.y < 0 || pos.y >= size.y)
		return ;
	/* Verifier que la case a le bon char (celui du point de depart) */
	if (tab[pos.y][pos.x] != target)
		return ;
	/* Remplir avec 'F' et appeler les 4 voisins */
	tab[pos.y][pos.x] = 'F';
	fill(tab, size, (t_point){pos.x + 1, pos.y}, target);
	fill(tab, size, (t_point){pos.x - 1, pos.y}, target);
	fill(tab, size, (t_point){pos.x, pos.y + 1}, target);
	fill(tab, size, (t_point){pos.x, pos.y - 1}, target);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target;

	target = tab[begin.y][begin.x];  /* Le char qu'on veut remplacer */
	if (target == 'F')
		return ;  /* Deja rempli */
	fill(tab, size, begin, target);
}

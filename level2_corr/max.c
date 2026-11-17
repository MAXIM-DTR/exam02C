/*
** max - retourne la valeur maximale d'un tableau d'entiers
** Parametre tab: le tableau, len: le nombre d'elements
** Retourne 0 si le tableau est vide (len == 0)
**
** Strategie: initialiser result avec tab[0] (le premier element)
** puis comparer avec tous les autres: si tab[i] > result, mettre a jour result
** A la fin result contient necessairement le plus grand element
*/

int	max(int *tab, unsigned int len)
{
	int				result;  /* Le max trouve jusqu'ici, initialise avec tab[0] */
	unsigned int	i;       /* Index courant (unsigned car len est unsigned) */

	if (len == 0)
		return (0);  /* Tableau vide: retourner 0 selon le sujet */
	result = tab[0];  /* Commencer avec le premier element comme max provisoire */
	i = 1;
	while (i < len)
	{
		if (tab[i] > result)
			result = tab[i];  /* Nouveau max trouve: mettre a jour */
		i++;
	}
	return (result);
}

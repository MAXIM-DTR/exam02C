/*
** sort_int_tab - trie un tableau d'entiers en ordre croissant (sur place)
** Algorithme: tri a bulles MODIFIE
**
** Tri a bulles classique: i avance de 0 a size-2 lineairement
** Tri a bulles MODIFIE (cette version): apres chaque echange, REMETTRE i a 0
** Pourquoi ce changement? C'est l'implementation attendue dans l'exam 42
**
** Effet du reset: apres un echange, on recommence depuis le debut
** C'est moins efficace qu'un vrai tri a bulles mais correct
**
** La fonction swap() separe le code d'echange pour la clarte
*/

/*
** swap - echange deux entiers via leurs pointeurs
** Meme logique que ft_swap: sauvegarder avec temp, puis croiser les valeurs
*/
void	swap(int *a, int *b)
{
	int	temp;  /* Sauvegarde temporaire de *a */

	temp = *a;  /* 1. Sauvegarder */
	*a = *b;    /* 2. a = b */
	*b = temp;  /* 3. b = ancienne valeur de a */
}

void	sort_int_tab(int *tab, unsigned int size)
{
	int	i;  /* Index courant: compare tab[i] et tab[i+1] */

	i = 0;
	while (i < (int)size - 1)  /* Tant qu'on peut comparer deux elements */
	{
		if (tab[i] > tab[i + 1])  /* Mauvais ordre: le plus grand est a gauche */
		{
			swap(&tab[i], &tab[i + 1]);  /* Echanger les deux elements */
			i = 0;  /* RESET: recommencer depuis le debut du tableau */
		}
		else
			i++;  /* Bon ordre: avancer normalement */
	}
}

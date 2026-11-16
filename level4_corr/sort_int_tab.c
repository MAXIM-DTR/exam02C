/* sort_int_tab - trie un tableau d'entiers par ordre croissant
** Prototype : void sort_int_tab(int *tab, unsigned int size);
** - tab  : le tableau à trier
** - size : nombre d'éléments dans le tableau
**
** Algorithme : tri à bulles modifié
**   - Après chaque échange, on repart depuis le début (i = 0)
**   - Plus lent qu'un bubble sort classique mais c'est l'implémentation attendue
**
** Exemple :
**   tab = [3, 1, 4, 1, 5] → [1, 1, 3, 4, 5]
*/

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_int_tab(int *tab, unsigned int size)
{
	int	i;

	i = 0;
	while (i < (int)size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			swap(&tab[i], &tab[i + 1]);
			i = 0; /* Repartir depuis le début après chaque échange */
		}
		else
			i++;
	}
}

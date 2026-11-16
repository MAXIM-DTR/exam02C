/* sort_int_tab - trie un tableau d'entiers (ordre croissant)
** Algorithme bubble sort:
** Comparer des paires adjacentes, echanger si dans le mauvais ordre
** Repeter jusqu'a ce qu'aucun echange ne soit fait */
#include <unistd.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				temp;
	int				swapped;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])  /* Dans le mauvais ordre? */
			{
				/* Echanger les deux elements */
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
		size--;  /* Le dernier element est deja en place */
	}
}

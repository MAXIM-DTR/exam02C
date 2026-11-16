/* sort_list - trie une liste chaînée selon une fonction de comparaison
** Prototype : t_list *sort_list(t_list *lst, int (*cmp)(int, int));
** - lst : pointeur vers le premier noeud de la liste
** - cmp : fonction de comparaison (retourne 0 si ordre incorrect)
**
** ATTENTION : data est un int (pas void *) dans cette version.
**
** Algorithme : tri à bulles sur la liste
**   - Si !cmp(a, b) == 1 (cmp retourne 0), on échange les data
**   - On répète jusqu'à ce qu'il n'y ait plus d'échanges
**
** Fichier requis : list.h avec la struct t_list (data = int)
*/

#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*node;
	int		tmp;
	int		swapped;

	swapped = 1;
	while (swapped) /* Continuer tant qu'il y a eu des échanges */
	{
		swapped = 0;
		node = lst;
		while (node && node->next)
		{
			/* Si cmp retourne 0, l'ordre est mauvais → échanger */
			if (!cmp(node->data, node->next->data))
			{
				tmp = node->data;
				node->data = node->next->data;
				node->next->data = tmp;
				swapped = 1;
			}
			node = node->next;
		}
	}
	return (lst);
}

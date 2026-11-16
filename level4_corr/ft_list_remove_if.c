/* ft_list_remove_if - supprime les noeuds dont le data correspond à data_ref
** Prototype : void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
** - begin_list : adresse du pointeur vers la liste (double pointeur)
** - data_ref   : valeur de référence à comparer
** - cmp        : fonction de comparaison (retourne 0 si égaux)
**
** Supprime et libère (free) tous les noeuds où cmp(data, data_ref) == 0.
** ATTENTION : pas de free_fct ici ! On libère seulement le noeud.
**
** Fichier requis : ft_list.h avec la struct t_list
*/

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;
	t_list	*prev;
	t_list	*tmp;

	prev = 0;
	current = *begin_list;
	while (current)
	{
		if (cmp(current->data, data_ref) == 0)
		{
			/* Ce noeud doit être supprimé */
			tmp = current->next;
			if (prev)
				prev->next = tmp; /* Relier le précédent au suivant */
			else
				*begin_list = tmp; /* Mettre à jour la tête de liste */
			free(current);
			current = tmp;
		}
		else
		{
			/* Pas de suppression, avancer */
			prev = current;
			current = current->next;
		}
	}
}

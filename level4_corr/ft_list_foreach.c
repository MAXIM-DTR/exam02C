/* ft_list_foreach - applique une fonction à chaque élément d'une liste
** Prototype : void ft_list_foreach(t_list *begin_list, void (*f)(void *));
** - begin_list : pointeur vers le premier noeud de la liste
** - f          : fonction à appliquer sur chaque champ data
**
** Exemple :
**   ft_list_foreach(list, &print_data); → appelle print_data sur chaque noeud
**
** Fichier requis : ft_list.h avec la struct t_list
*/

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	/* Parcourir la liste jusqu'à NULL */
	while (begin_list)
	{
		(*f)(begin_list->data); /* Appliquer la fonction sur le data */
		begin_list = begin_list->next;
	}
}

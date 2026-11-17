/*
** sort_list - trie une liste chainee selon la fonction de comparaison cmp
** Retourne un pointeur vers le premier element de la liste triee
**
** STRUCTURE DIFFERENTE: dans sort_list, 'data' est un INT (pas void*)
** (voir list.h fourni par 42, different de ft_list.h)
**
** LOGIQUE DE cmp:
** cmp(a, b) retourne NON-ZERO si a et b sont dans le BON ordre
** cmp(a, b) retourne 0 si a et b sont dans le MAUVAIS ordre
** Ex ascending: int ascending(int a, int b) { return (a <= b); }
** => si a <= b: ordre correct (retourne 1), si a > b: ordre incorrect (retourne 0)
**
** Donc: si !cmp(a, b) == 1 (cmp retourne 0) -> ECHANGER
**
** Algorithme: tri a bulles sur la liste
** On echange seulement les DATA (pas les pointeurs next)
** C'est plus simple que de modifier la structure de la liste
** swapped = flag pour savoir si un echange a eu lieu dans le dernier passage
*/
#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*node;     /* Noeud courant dans la liste */
	int		tmp;       /* Variable temporaire pour l'echange de data */
	int		swapped;   /* Flag: 1 si au moins un echange a eu lieu dans ce passage */

	swapped = 1;
	while (swapped)  /* Continuer tant qu'il y a eu des echanges dans le dernier passage */
	{
		swapped = 0;      /* Supposer qu'il n'y aura pas d'echanges */
		node = lst;       /* Recommencer depuis la tete de liste */
		while (node && node->next)  /* Tant qu'il y a deux noeuds a comparer */
		{
			/* !cmp(a, b): cmp retourne 0 = mauvais ordre -> echanger */
			if (!cmp(node->data, node->next->data))
			{
				/* Echanger les DATA (pas les pointeurs) */
				tmp = node->data;
				node->data = node->next->data;
				node->next->data = tmp;
				swapped = 1;  /* Un echange a eu lieu: il faudra re-parcourir */
			}
			node = node->next;  /* Passer au prochain couple a comparer */
		}
	}
	return (lst);  /* Retourner la tete de liste (inchangee, les data sont reorganises) */
}

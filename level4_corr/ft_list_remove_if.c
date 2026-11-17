/*
** ft_list_remove_if - supprime de la liste tous les noeuds dont le data
** correspond a data_ref (selon la fonction cmp)
**
** Parametre begin_list: DOUBLE POINTEUR vers la tete de liste
**   Pourquoi double pointeur? Car si on doit supprimer le premier noeud,
**   il faut modifier la variable du code appelant (qui pointe vers la tete)
**   Un simple pointeur ne permettrait pas ca (passage par valeur)
**
** Parametre cmp: fonction de comparaison, retourne 0 si les deux valeurs sont egales
**
** IMPORTANT: pas de free_fct! On ne libere que le NOEUD (la structure t_list)
** Le data lui-meme n'est pas libere (c'est la responsabilite de l'appelant)
**
** Technique des 3 pointeurs:
** - current: le noeud qu'on examine
** - prev: le noeud precedent (pour le relier au suivant en cas de suppression)
** - tmp: sauvegarde du noeud suivant avant de liberer current
*/
#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;  /* Le noeud actuellement examine */
	t_list	*prev;     /* Le noeud precedent (NULL si on est au debut) */
	t_list	*tmp;      /* Sauvegarde temporaire du noeud suivant */

	prev = 0;             /* Au debut, pas de noeud precedent */
	current = *begin_list; /* Commencer par la tete de liste */
	while (current)
	{
		if (cmp(current->data, data_ref) == 0)  /* data de current == data_ref */
		{
			tmp = current->next;  /* Sauvegarder le suivant AVANT de liberer */
			if (prev)
				prev->next = tmp;    /* Relier le precedent au suivant (bypass current) */
			else
				*begin_list = tmp;   /* Supprimer la tete: modifier la variable appelante */
			free(current);           /* Liberer seulement la structure t_list (pas le data) */
			current = tmp;           /* Passer au noeud suivant */
		}
		else
		{
			prev = current;           /* Ce noeud reste: il devient le nouveau precedent */
			current = current->next;  /* Passer au suivant */
		}
	}
}

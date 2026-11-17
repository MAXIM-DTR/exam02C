/*
** ft_list_foreach - applique une fonction a chaque element d'une liste chainee
** La fonction f est un "function pointer" (pointeur de fonction)
** Elle prend un void* (le data du noeud) et ne retourne rien (void)
**
** Syntaxe du pointeur de fonction: void (*f)(void *)
** - (*f): c'est un pointeur
** - (void *): il prend un void* en parametre
** - void: il retourne void
** Pour appeler: (*f)(ptr) OU simplement f(ptr) en C moderne
**
** Parcours simple: avancer de noeud en noeud jusqu'a NULL
*/
#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	/* Parcourir la liste du debut (begin_list) jusqu'a la fin (NULL) */
	while (begin_list)
	{
		(*f)(begin_list->data);        /* Appliquer f sur le data du noeud courant */
		begin_list = begin_list->next; /* Passer au noeud suivant */
	}
}

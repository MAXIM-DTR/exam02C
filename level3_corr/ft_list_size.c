/*
** ft_list_size - retourne le nombre de noeuds dans une liste chainee
** Parametre begin_list: pointeur vers le premier noeud (NULL si liste vide)
**
** Structure t_list:
** - next: pointeur vers le noeud suivant (NULL si dernier noeud)
** - data: donnee stockee (void* = peut etre n'importe quel type)
**
** Principe: parcourir la liste noeud par noeud et compter
** On avance en faisant begin_list = begin_list->next
** On s'arrete quand begin_list == NULL (fin de la liste)
*/
#include <stdlib.h>

typedef struct	s_list
{
	struct s_list	*next;  /* Pointeur vers le noeud suivant */
	void			*data;  /* Donnee de ce noeud (type generique void*) */
}	t_list;

int	ft_list_size(t_list *begin_list)
{
	int		len;  /* Compteur de noeuds */

	len = 0;
	while (begin_list != NULL)  /* Continuer tant qu'on n'est pas au bout */
	{
		len++;                           /* Compter ce noeud */
		begin_list = begin_list->next;   /* Passer au noeud suivant */
	}
	return (len);
}

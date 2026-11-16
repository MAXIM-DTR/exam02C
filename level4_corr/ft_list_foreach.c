/* ft_list_foreach - applique une fonction a chaque element
** Parcourt la liste et appelle f(node->data) pour chaque noeud */
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_list
{
	struct s_list	*next;
	void		*data;
}	t_list;

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		f(begin_list->data);       /* Appliquer f sur les donnees */
		begin_list = begin_list->next;
	}
}

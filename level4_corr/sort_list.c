/* sort_list - trie une liste chainee
** Utilise cmp pour comparer: si cmp(a, b) > 0, a doit venir apres b
** Methode bubble sort: echanger les DATA (pas les noeuds)
** C'est plus simple que de reorganiser les pointeurs */
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_list
{
	struct s_list	*next;
	void		*data;
}	t_list;

t_list	*sort_list(t_list *begin_list, int (*cmp)(int, int))
{
	t_list	*current;
	void	*temp;
	int		swapped;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		current = begin_list;
		while (current && current->next)
		{
			/* Si cmp dit que current->data doit venir apres le suivant */
			if (cmp((int)(long)current->data,
				(int)(long)current->next->data) > 0)
			{
				/* Echanger les donnees */
				temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
				swapped = 1;
			}
			current = current->next;
		}
	}
	return (begin_list);
}

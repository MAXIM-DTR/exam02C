/* ft_list_remove_if - supprime les noeuds ou cmp(data, ref) == 0
** Le premier parametre est un double pointeur pour pouvoir
** modifier le debut de la liste
** Libere les noeuds supprimes avec free_fct puis free */
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_list
{
	struct s_list	*next;
	void		*data;
}	t_list;

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
						int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*to_free;

	/* Supprimer les noeuds du debut qui matchent */
	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		to_free = *begin_list;
		*begin_list = (*begin_list)->next;
		free_fct(to_free->data);
		free(to_free);
	}
	if (!*begin_list)
		return ;
	/* Supprimer les noeuds du milieu/fin */
	current = *begin_list;
	while (current->next)
	{
		if (cmp(current->next->data, data_ref) == 0)
		{
			to_free = current->next;
			current->next = to_free->next;
			free_fct(to_free->data);
			free(to_free);
		}
		else
			current = current->next;
	}
}

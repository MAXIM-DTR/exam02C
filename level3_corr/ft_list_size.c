/* ft_list_size - compte les elements d'une liste chainee
** Parcourt la liste en suivant les pointeurs 'next' jusqu'a NULL */
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_list
{
	struct s_list	*next;
	void		*data;
}	t_list;

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list)  /* Tant qu'on n'est pas a la fin */
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

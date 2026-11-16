/* ft_list_size - compte les elements d'une liste chainee
** Parcourir jusqu'a NULL en incrementant un compteur */
#include <stdlib.h>

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

int	ft_list_size(t_list *begin_list)
{
	int		len;

	len = 0;
	while (begin_list != NULL)
	{
		len++;
		begin_list = begin_list->next;
	}
	return (len);
}

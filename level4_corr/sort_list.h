#ifndef LIST_H
# define LIST_H

/* Structure de liste chaînée avec data entier */
typedef struct s_list
{
	struct s_list	*next;
	int				data;
}	t_list;

#endif

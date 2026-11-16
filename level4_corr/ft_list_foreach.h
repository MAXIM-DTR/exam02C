#ifndef FT_LIST_H
# define FT_LIST_H

/* Structure de liste chaînée avec data générique (void *) */
typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

#endif

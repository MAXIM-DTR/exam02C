/*
** ft_list.h - header pour les fonctions de liste chainee (ft_list_foreach, ft_list_remove_if...)
** La structure t_list utilise void* pour data -> peut stocker n'importe quel type
*/
#ifndef FT_LIST_H
# define FT_LIST_H

/*
** t_list - noeud d'une liste chainee generique
** next: pointeur vers le noeud suivant (NULL si dernier noeud)
** data: donnee stockee (void* = pointeur generique, peut pointer vers n'importe quoi)
*/
typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

#endif

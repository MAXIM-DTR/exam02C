/*
** ft_list.h - header pour ft_list_remove_if
** Meme structure que ft_list_foreach mais dans un fichier separe car
** ft_list_remove_if a son propre header (selon le sujet)
*/
#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

#endif
